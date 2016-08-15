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
int fan01 = 7;
int fan02 = 8;
int fan03 = 9;
int fan04 = 10;
int val = 0;
ros::NodeHandle nh;

void led_cb(const std_msgs::UInt16 &cmd_msg){
  //digitalWrite(13, cmd_msg.data);
  val = cmd_msg.data;
  analogWrite(fan01, val);
  analogWrite(fan02, val);
  analogWrite(fan03, val);
  analogWrite(fan04, val);
  analogWrite(13, val);
}

ros::Subscriber<std_msgs::UInt16> sub("led", led_cb);

void setup(){
  pinMode(13, OUTPUT);
  pinMode(fan01, OUTPUT);
  pinMode(fan02, OUTPUT);
  pinMode(fan03, OUTPUT);
  pinMode(fan04, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
