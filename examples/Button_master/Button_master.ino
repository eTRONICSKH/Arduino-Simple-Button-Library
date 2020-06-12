/*
 * Writer:  Theara Kong
 * email :  theara729@gmail.com
 * Web   : https://etronicskh.com
 * Github: https://github.com/eTRONICSKH/Arduino-Simple-Button-Library
 */

#include <button.h>

button button1(2, HIGH);         // button pin, normal state HIGH and LOW when push down (pull-up)
button button2(3, LOW);          // button pin, normal state LOW and HIGH when push down (pull-down)

void setup() {
  Serial.begin(9600);
  
  button1.init(); //Initialize button1
  button2.init(); //Initialize button2

  button2.debounce(200); //(Optional) Set button2 debounce delay to 200ms, defualt delay is 100ms.
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  /*
   * .push()  : return true once after button is pushed down.
   * .press() : return true whenever the button is being pressed.
   * .release() : return true once after button is released.
   */

  //Test push event
  if(button1.push()) Serial.println("button1 Pushed!");
  if(button2.push()) Serial.println("button2 Pushed!");

  //Test release event
  if(button1.release()) Serial.println("button1 Released!");
  if(button2.release()) Serial.println("button2 Released!");

  //Test hold event
  if(button1.press()){
    Serial.print("Holding for: ");
    Serial.print(button1.onHold());
    Serial.println(" ms.");
    digitalWrite(13, HIGH);
  }else digitalWrite(13, LOW);
  
  if(button2.onHold() >= 300){
    button2.resetHold();
    Serial.print("button2 longer than 300ms, reseted hold state!");
  }
}
