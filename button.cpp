#include "button.h"

button::button(uint8_t pin, bool n_stat):_pin(pin), _stat(n_stat){
	
}

void button::init(){
	if(_stat) pinMode(_pin, INPUT_PULLUP);
	else pinMode(_pin, INPUT);

	_varP = false;
	_varR = true;
	_rstHold=false;
    _varCount=false;

	_pTimer = millis();
	_rTimer = millis();
    _hTimer = millis();
    _pprTimer = millis();
    _rprTimer = millis();
}

void button::debounce(long _delay){
	_debounce_delay = _delay;
}

boolean button::push(){
	bool _pStat = false;
	if(digitalRead(_pin)!=_stat){
		if(!_varP && (millis()-_pTimer>=_debounce_delay)){
			_pStat = true;
			_varP = true;
		}
	}else{
		_pTimer = millis();
		_varP = false;
	}
	return _pStat;
}

boolean button::press(){
	if (digitalRead(_pin)!=_stat) {
		if (!_prStat && (millis()-_pprTimer>=_debounce_delay)) {
			_prStat = true;
		}
		_rprTimer = millis();
	}else{
		if (_prStat && (millis()-_rprTimer>=_debounce_delay)){
			_prStat = false;
		}
		_pprTimer = millis();
	}
  return _prStat;
}

boolean button::release(){
  bool _rStat = false;
  if(digitalRead(_pin)==_stat){
  	if(!_varR &&(millis()-_rTimer>=_debounce_delay)){
  		_rStat = true;
  		_varR = true;
  	}
  }else{
  	_rTimer  =  millis();
  	_varR = false;
  }
  return _rStat;
}

unsigned long button::onHold(){
	if ((digitalRead(_pin) != _stat)){
		if(!_varCount && (millis()-_pushTimer>=_debounce_delay)){
			_varCount = true;	//Enable Counter
			_rstHold = true; 	//Reset holding state, new holding
		}
		_releaseTimer = millis();
	}else{
		if(_varCount && (millis()-_releaseTimer>=_debounce_delay)) _varCount = false;	//Disable counter, Holding is released
		_pushTimer = millis();
	}
	if (!_rstHold || !_varCount) _hTimer=millis();	//rst Holding timer

	return (_varCount && _rstHold) ? (millis()-_hTimer) : 0;
}

void button::resetHold(){
	_rstHold = false;	//Disable counter, wait for new holding to start timer again
}
