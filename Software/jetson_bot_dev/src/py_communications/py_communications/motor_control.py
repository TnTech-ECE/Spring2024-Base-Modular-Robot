import rclpy
import serial
import time
from rclpy.node import Node
from geometry_msgs.msg import Twist

class MotorControl(Node):
    def __init__(self):
        super().__init__('motor_control')
        self.subscription = self.create_subscription(Twist, 'cmd_vel', self.motor_send_callback,10)
        self.subscription  # prevent unused variable warning
        self.ser = serial.Serial('/dev/ttyACM0',115200,timeout=1.0)
        

    def motor_send_callback(self, msg):
        
        lin_vel =  msg.linear.x
        ang_vel = msg.angular.z
        
        if(msg.linear.x > 0):
            lin_vel *= 3
            lin_vel += 30
        elif(msg.linear.x < 0):
            lin_vel *= 3
            lin_vel -= 30
        if (msg.angular.z > 0):
            ang_vel *= 3
            ang_vel += 30
        elif(msg.angular.z < 0):
            ang_vel *= 3
            ang_vel -= 30
            

       # self.get_logger().info('Data Sent')
        if(lin_vel >= 0):
            lin_send = '<' + str(lin_vel) + '>'
        elif(lin_vel < 0):
            lin_send = "<-" + str(lin_vel) + '>'
        
        if(ang_vel >= 0):
            ang_send = '~' + str(ang_vel) + '>'
        elif(ang_vel < 0):
            ang_send = "~-" + str(ang_vel) + '>'
    


        self.ser.write(lin_send.encode('UTF-8'))
        self.ser.write(ang_send.encode('UTF-8'))
        
        self.get_logger().info('lin:' + lin_send)
        self.get_logger().info('ang:' + ang_send)






def main(args=None):
    rclpy.init(args=args)
    node = MotorControl()
    time.sleep(3.0) #Setup Time Wait
    node.ser.reset_input_buffer()
    print("Serial OK")

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
