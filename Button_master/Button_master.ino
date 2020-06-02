/*
 * Writer:  Theara Kong
 * email :  theara729@gmail.com
 * Web   : https://etronicskh.com
 * Github: https://github.com/Ktheara
 * 
 */

#include <button.h>

button LED(2, HIGH);         // button pin, normal state HIGH and LOW when push down (pull-up)

void setup() {
  Serial.begin(9600);
  
  LED.init(); //Initialize button
  
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  /*
   * .push()  : return true once after button is pushed down.
   * .press() : return true whenever the button is being pressed.
   * .release() : return true once after button is released.
   */

  if(LED.push()){
    Serial.println("Pushed!");
  }

  if(LED.release()){
    Serial.println("Released!");
  }

  if(LED.onHold() >= 300){
    Serial.print("Holding for: ");
    Serial.print(LED.onHold());
    Serial.println(" ms.");
  }

  digitalWrite(13, LED.press());

}
