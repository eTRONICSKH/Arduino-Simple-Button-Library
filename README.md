# Arduino Simple Button Library
Visit my website [www.etronicskh.com](https://www.etronicskh.com/).
## Quickstart
You can use the number of button as the Arduino possibility pin either `digital` or `analog` pins. Also possible to use the mixing both `pull-up` or `pull-down`.
>The library uses `millis()` as denouncing and holding timer, any action of changing Timer0 will effect your button features.
## Button Initailization
You need to initiate the button independently by `pin` and `button-initial`. The button initail state is dependent on pulling-up or pulling-down. `HIGH` or `true` if pulled-up and `LOW` or `false` if pulled-down.

**Note: Initiate as `HIGH`, the library already initiate Arduino pin as `INPUT_PULLUP`.**

- **Create new buttons**:
  ```c++
  #inclue <button.h>

  button BUTTON_ONE(3, HIGH); //pull-up button
  button BUTTON_TWO(A0, LOW); //pull-down button
  ```

- **Initialize buttons**:
  ```c++
  void setup(){
    BUTTON_ONE.init();
    BUTTON_TWO.init();
  }
  ```

- **Set debounce delay (Optional)**

  The defualt debounce delay is 100ms, it's optional to set if the delay is okay. Possible to set to `Zero`.
  ```c++
  BUTTON_ONE.debounce(200);
  ```

## Button Features
Integrated with essential actions while using buttons and making each function works independently. You can call any function any time and any where in your code but please note `There's no interrupt action`.
- **Push Detection**:

  This function detects when the button is pushed, same as detecting `falling-edge` with pull-up button or `rising-edge` with pull-down button.

  Return `boolean`.
  ```c++
  bool button_one_push = BUTTON_ONE.push();
  bool button_two_push = BUTTON_TWO.push();
  ```
- **Pressing Detection**:

  This function detects whenever button is pushed down, same as detection `LOW` with pull-up button or `HIGH` with pull-down button.
  
  Return `boolean`.
  ```c++
  bool button_one_press = BUTTON_ONE.press();
  bool button_two_press = BUTTON_TWO.press();
  ```
- **Release Detection**:
  This function detects when button is released, same as `rising-edge` with pull-up button or `falling-edge` with pull-down button.
  
  Return `boolean`.
  ```c++
  bool button_one_released = BUTTON_ONE.release();
  bool button_two_released = BUTTON_TWO.release();
  ```
- **Holding Timer**:
  
  This function returns timer in `milliseconds`, starts counting when button is pushed down till `reset holding` or released.
  
  Return `long`.
  ```c++
  long button_one_hold_time = BUTTON_ONE.onHold();
  long button_two_hold_time = BUTTON_TWO.onHold();
  ```
- **Reset Holding**:

  This function resets and stop the `onHold()` timer. holding timer will start again till new push.
  
  Return `none`.
  ```c++
  if(button_one_hold_time >= 5000){
    BUTTON_ONE.resetHold();
    Serial.println("Holding button 1 longer than 5 second.");
  }
  ```
  
  -------------------------------------------------------------------------------------------------------------------
  
  This library will update to match the most use button function with Arduino by [Theara](https://github.com/Ktheara).
