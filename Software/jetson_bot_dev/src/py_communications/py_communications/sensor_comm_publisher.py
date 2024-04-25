import rclpy
import serial.tools.list_ports
import time
import csv
from rclpy.node import Node
import time

from std_msgs.msg import String
from sensor_msgs.msg import Range, Imu, LaserScan


class SensorCommunication(Node):

    def __init__(self):
        super().__init__('sensor_comm')
        self.publisher_ = self.create_publisher(String, 'sensors', 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.sensor1_callback)
        self.timer = self.create_timer(timer_period, self.data_read_callback)
        self.data = []
        self.serialInst = serial.Serial('/dev/ttyACM0', 115200)

        self.lsb_IR_ = self.create_publisher(Range, 'IRscan', 10)
        self.lsf_IR_ = self.create_publisher(Range, 'IRscan', 10)
        self.bl_IR = self.create_publisher(Range, 'IRscan', 10)
        self.rsb_IR = self.create_publisher(Range, 'IRscan', 10)
        self.br_IR = self.create_publisher(Range, 'IRscan', 10)
        self.fl_IR = self.create_publisher(Range, 'IRscan', 10)
        self.rsf_IR = self.create_publisher(Range, 'IRscan', 10)
        self.fr_IR = self.create_publisher(Range, 'IRscan', 10)

        self.f_ultrasonic = self.create_publisher(Range, 'f_ultrasonic_scan',10)
        self.r_ultrasonic = self.create_publisher(Range, 'b_ultrasonic_scan',10) #CHANGED from back
        self.b_ultrasonic = self.create_publisher(Range, 'r_ultrasonic_scan',10) #CHANGED from right
        self.l_ultrasonic = self.create_publisher(Range, 'l_ultrasonic_scan',10) 

        self.IMU = self.create_publisher(Imu, 'imu', 10)
        self.laser = self.create_publisher(LaserScan, 'scan', 10)

        self.IR_publishers = [self.lsb_IR_, self.lsf_IR_, self.bl_IR, self.rsb_IR, self.br_IR, self.fl_IR, self.rsf_IR, self.fr_IR] #IR_sensor_0 -> IR_sensor_7
        self.ultrasonic_publishers = [self.f_ultrasonic, self.r_ultrasonic, self.b_ultrasonic, self.l_ultrasonic] #ultrasonic_sensor_0 -> ultrasonic_sensor_3

    
   # def listener_callback(self, msg):
   #     self.get_logger().info('I heard: "%s"' % msg.data)

    def data_read_callback(self):
        self.get_logger().info("Reading data")
        #Sensor Code Author: Isaac Hoese
        if self.serialInst.in_waiting:
                self.data.clear()              
                packet = self.serialInst.readline()
                rec = packet.decode('latin-1').rstrip('\n')
                rec = rec.replace('<', '')
                rec = rec.replace('>', '')
                for x in range(20):
                    self.data.append(rec.partition(',')[0])
                    rec = rec.partition(',')[2]
                self.data.append(rec.partition(',')[0])  
                #self.sensor1_callback(self)
        #if self.serialInst.in_waiting > 0:
        #    packet = self.serialInst.readline().decode('latin-1').rstrip()
        #    #data = csv.reader(packet)
        #    print(packet)
                print(self.data[18])
                
    def sensor1_callback(self):
       if(len(self.data) > 0):
            msg = String()
            msg.data = 'Data:' + str(self.data)
            self.publisher_.publish(msg)
            for i in range(12,20): #CHANGED 12,20
                self.publish_range_IR(i)
            for j in range(8,12): #CHANGED -> 11 -> 12 
                self.publish_range_ultrasonic(j)
            self.publish_IMU()
            self.publish_laser()
        
    def publish_range_IR(self, n): #STM vl53l0x  12-19
         sensor = Range()
         sensor.header.frame_id = ("IR_sensor_%d" % (n-12))
         sensor.header.stamp = self.get_clock().now().to_msg() 
         sensor.radiation_type = Range.INFRARED
         sensor.field_of_view = .43633231 #25 degrees in radians
         sensor.min_range = .01
         sensor.max_range = 2.0
         if(self.data[n] != ''):
            sensor.range = float(self.data[n]) / 1000
            if(sensor.range > 2.0):
                sensor.range = 2.0
         else:            sensor.range = 0.0
         self.IR_publishers[n-12].publish(sensor)
         

    def publish_range_ultrasonic(self, p):
        sensor = Range()
        sensor.header.frame_id = ("Ultrasonic_sensor_%d" % (p-8)) 
        sensor.radiation_type = Range.ULTRASOUND
        sensor.field_of_view = 0.2618 # 15 degrees in radians
        sensor.min_range = .02 
        sensor.max_range = 3.5 
        if(self.data[p] != ''):
            sensor.range = float(self.data[p]) / 1000
        else:
            sensor.range = 0.0
        self.ultrasonic_publishers[p-8].publish(sensor)

    def publish_IMU(self):
        imu = Imu()
        imu.header.frame_id = "IMU"
        imu.header.stamp = self.get_clock().now().to_msg()
        imu.orientation.w = float(self.data[4])
        imu.orientation.x = float(self.data[5])
        imu.orientation.y = float(self.data[6])
        imu.orientation.z = float(self.data[7])
        self.IMU.publish(imu)



    #Disclaimer: Buy a LIDAR. For the love of God do NOT do this
    def publish_laser(self):
        msg = LaserScan()
        msg.header.frame_id = "laser"
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.angle_min = 0.0
        msg.angle_max = 2.0
        msg.angle_increment = 0.25
        msg.time_increment = 0.1 # CHANGE IF YOU CHANGE TIME INCREMENT AT TOP
        msg.scan_time = 0.0001
        msg.range_min = 0.167
        msg.range_max = 2.147
        msg.ranges = (float(self.data[17])/1000, float(self.data[19])/1000,float(self.data[18])/1000,float(self.data[15])/1000,float(self.data[16])/1000,float(self.data[14])/1000,float(self.data[12])/1000,float(self.data[13])/1000, 0.0)
        

        self.laser.publish(msg)
         


         
      #  self.subscription = self.create_subscription(
      #      String,
      #      'topic',
      #      self.listener_callback,
      #      10)
      #  self.subscription  # prevent unused variable warning

         
    

        


def main(args=None):
    rclpy.init(args=args)
    
    sensor_communication = SensorCommunication()
    time.sleep(3)
    sensor_communication.serialInst.reset_input_buffer()
    rclpy.spin(sensor_communication)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    sensor_communication.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()