//button.h
#ifndef button_master
#define button_master

#include "Arduino.h"

class button{
  public:
    button(uint8_t pin, bool n_stat);
    void init();
    boolean push();
    boolean press();
    boolean release();
    unsigned long onHold();
    void resetHold();
    
  private:
    uint8_t _pin;
    bool _stat;
    
    //push variable
    bool _varP;
    bool _pStat;
    long _pTimer;

    //Release variable
    bool _varR;
    bool _rStat;
    long _rTimer;

    //Holding variable
    bool _rstHold;
    bool _varCount;

    long _pushTimer=0;
    long _releaseTimer=0;

    long _hTimer;
};

#endif
