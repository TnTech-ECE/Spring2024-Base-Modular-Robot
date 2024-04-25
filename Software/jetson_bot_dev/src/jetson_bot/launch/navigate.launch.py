#!usr/bin/env python3
import os
import launch
from ament_index_python.packages import get_package_share_directory
from launch.substitutions import Command, LaunchConfiguration
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch import LaunchDescription
from launch_ros.substitutions import FindPackageShare

import time


def generate_launch_description():
    pkg_share = FindPackageShare(package='jetson_bot').find('jetson_bot')
    default_model_path = os.path.join(pkg_share, 'urdf/jetson.urdf.xacro')
    #default_rviz_config_path = os.path.join(pkg_share, 'rviz/navigation_config.rviz')
    # WIP map_yaml_file = LaunchConfiguration('map')
    # WIP params_file = LaunchConfiguration('params_file')
    use_sim_time = LaunchConfiguration('use_sim_time')
    #rviz_config = os.path.join(pkg_share, 'rviz', 'navigation_config.rviz')
    jetson_dir = get_package_share_directory('jetson_bot')
    #map_yaml_file = os.path.join(pioneer_dir, 'maps', 'rtt_office.yaml')
    map_yaml_file = os.path.join(jetson_dir, 'maps', 'cafe.yaml')
    params_file = os.path.join(jetson_dir, 'config', 'nav2_test_params_foxy.yaml')
    #use_sim_time = 'false'
    nav2_bringup_dir = os.path.join(
        get_package_share_directory('nav2_bringup'), 'launch', 'bringup_launch.py'
    )


    #declare_map_yaml_cmd = DeclareLaunchArgument(
    #    'map',
    #    default_value=os.path.join(pkg_share, 'maps', 'rrt_office.yaml'),
    #    description='Full path to map yaml file to load',
    #)
    #declare_params_file_cmd = DeclareLaunchArgument(
    #    'params_file',
    #    default_value=os.path.join(pkg_share, 'config', 'test.yaml'),
    #    description='Full path to the ROS2 parameters file to use for all launched nodes',
    #)
    declare_use_sim_time_cmd = DeclareLaunchArgument(
        'use_sim_time', default_value='false', description='Use simulation (Gazebo) clock if true'
    )
 
    #Launches each individual node. Package and executable tell it where to find the files 
    use_sim_time:False
    nav2_bringup_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([nav2_bringup_dir]),
        launch_arguments={
            'map' : map_yaml_file,
            'params_file' : params_file,
             'use_sim_time' : use_sim_time,
        }.items(),
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
        parameters=[{'use_sim_time' : use_sim_time}]
    )

    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': Command(['xacro ', default_model_path])}]
    )

    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        arguments=[default_model_path],
        #condition=launch.conditions.UnlessCondition(LaunchConfiguration('gui'))
    )

    joint_state_publisher_gui_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui',
        name='joint_state_publisher_gui',
        #condition=launch.conditions.IfCondition(LaunchConfiguration('gui'))
    )

    robot_localization_node = Node(
       package='robot_localization',
       executable='ekf_node',
       name='ekf_filter_node',
       output='screen',
       parameters=[os.path.join(pkg_share, 'config/ekf.yaml'), {'use_sim_time': use_sim_time}]
    )



    ld= LaunchDescription()
    #ld.add_action(declare_map_yaml_cmd)
    #ld.add_action(declare_params_file_cmd)
    ld.add_action(declare_use_sim_time_cmd)

    ld.add_action(nav2_bringup_launch)
    ld.add_action(rviz_node)
    #ld.add_action(robot_state_publisher_node)
    #ld.add_action(joint_state_publisher_node)
    #ld.add_action(joint_state_publisher_gui_node)
    ld.add_action(robot_localization_node)

    return ld