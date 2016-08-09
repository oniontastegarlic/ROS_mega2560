#include "Arduino.h"
#include "ros.h"

//ROS Publisher Test
/*
#include "std_msgs/Int16.h"

ros::NodeHandle nh;

std_msgs::Int16 adc_msg;
ros::Publisher adc_publisher("adc_publisher", &adc_msg);

void setup()
{
  nh.initNode();
  nh.advertise(adc_publisher);

}

void loop()
{
  adc_msg.data += 1;
  adc_publisher.publish(&adc_msg);
  nh.spinOnce();
  delay(50);
}
*/
//ROS Subscriber Test

#include "std_msgs/UInt16.h"

ros::NodeHandle nh;

void led_cb(const std_msgs::UInt16 &cmd_msg){
  digitalWrite(13, cmd_msg.data);
}

ros::Subscriber<std_msgs::UInt16> sub("led", led_cb);

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
