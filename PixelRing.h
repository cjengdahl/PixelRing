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

#ifndef PIXELRING_H
#define PIXELRING_H
// note, this path may be different depending on development environment
#include "../Adafruit_NeoPixel-master/Adafruit_NeoPixel.h"


class PixelRing{

	public:

		PixelRing(Adafruit_NeoPixel *strip, uint16_t start, uint16_t size);
		~PixelRing();

		void
			clearRing(),
			setRingColor(uint32_t c),
			setRingPixelColor(uint16_t i, uint32_t c),
			shiftCW(),
			shiftCCW();

		uint16_t
			getRingSize(),
			getRingStart(),
			getRingEnd();


		uint32_t
			getRingPixelColor(uint16_t i);


	private:
	
		uint16_t
			_start,
			_end,
			_size;

		Adafruit_NeoPixel *_strip;

};


#endif // PIXELRING_H