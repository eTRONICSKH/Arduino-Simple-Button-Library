//button.h
#ifndef button_master
#define button_master

#include "Arduino.h"

class button{
  public:
    button(uint8_t pin, bool n_stat);
    void init();
    void debounce(long _delay=100);
    boolean push();
    boolean press();
    boolean release();
    unsigned long onHold();
    void resetHold();
    
  private:
    uint8_t _pin;
    bool _stat;

    long _debounce_delay = 100;
    
    //push variable
    bool _varP;
    long _pTimer;

    //Press variable
    bool _prStat = false;
    long _pprTimer; //start pressing timer
    long _rprTimer; //release pressing timer

    //Release variable
    bool _varR;
    long _rTimer;

    //Holding variable
    bool _rstHold;
    bool _varCount;

    long _pushTimer=0;
    long _releaseTimer=0;

    long _hTimer;
};

#endif
