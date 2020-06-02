# SimpleButton-Arduino-Library
Visit my website [www.etronicskh.com](https://www.etronicskh.com/).
## Quickstart
You can use the number of button as the Arduino possibility pin either `digital` or `analog` pins. Also possible to use the mixing both `pull-up` or `pull-down`.
>The library uses `millis()` as denouncing and holding timer, any action of changing Timer0 will effect your button features.
## Button Initailization
You need to initiate the button independently by `pin` and `button-initial`. The button initail state is dependent on pulling-up or pulling-down. `HIGH` or `true` if pulled-up and `LOW` or `false` if pulled-down.

- Create new buttons:
```c++
#inclue <button.h>

button BUTTON_ONE(3, HIGH); //pull-up button
button BUTTON_TWO(A0, LOW); //pull-down button
```

- Initialize buttons:
```c++
void setup(){
  BUTTON_ONE.init();
  BUTTON_TWO.init();
}
```
## Button Features
