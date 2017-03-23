/*-------------------------------------------------------------

Author: Cory J. Engdahl
Created: 03/23/17

Description:

This Arduino library wraps the interface of the Adafruit_Neopixel
library into a new interface better suited for handling circular
arrangments of Neopixels.

An up-to-date version of the Adafruit_Neopixel libary can be found
at <https://github.com/adafruit/Adafruit_NeoPixel> 

  -----------------------------------------------------------*/

#include "Arduino.h"
#include "PixelRing.h"
#include "Adafruit_Neopixel.h"

PixelRing::PixelRing(Adafruit_NeoPixel *strip, uint16_t start, uint16_t size){
	// Adafruit_NeoPixel *_strip;
	_strip = strip;
	_start = start;
	_end = (start+size-1);
	_size = size;
}

uint16_t PixelRing::getRingSize(){
	return _size;
}

uint16_t PixelRing::getRingStart(){
	return _start;
}

uint16_t PixelRing::getRingEnd(){
	return _end;
}

void PixelRing::clearRing(){

	for(uint16_t i = _start; i<=_end; i++){
		(*_strip).setPixelColor(i,0);
	}

}

void PixelRing::setRingColor(uint32_t c){

	for(uint16_t i = _start; i<=_end; i++){
		(*_strip).setPixelColor(i,c);
		(*_strip).show();
	}

}

void PixelRing::setRingPixelColor(uint16_t i, uint32_t c){

	if(i>_size){
		return;
	}

	(*_strip).setPixelColor(_start + i,c);
}

uint32_t PixelRing::getRingPixelColor(uint16_t i){
	return (*_strip).getPixelColor(i+_start);
}

void PixelRing::shiftCW(){

	uint32_t temp = (*_strip).getPixelColor(_end);

	// shift each pixel CW, one-by-one
	for (uint16_t i=_end; i>_start; i--){
		(*_strip).setPixelColor(i, (*_strip).getPixelColor(i-1));
	}

	// first pixel gets original last pixel
	(*_strip).setPixelColor(_start, temp);

}

void PixelRing::shiftCCW(){

	uint32_t temp = (*_strip).getPixelColor(_start);

	// shift each pixel CCW, one-by-one
	for (uint16_t i=_start; i<_end; i++){
		(*_strip).setPixelColor(i, (*_strip).getPixelColor(i+1));
	}

	// last pixel gets original first pixel
	(*_strip).setPixelColor(_end, temp);

}

PixelRing::~PixelRing(){
}





