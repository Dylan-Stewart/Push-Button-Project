// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)

#include "MYLIGHTSLIB.h"
#include <bcm2835.h>
#include <stdio.h>

// PINS FOR policeCar and blink
//#define PIN RPI_GPIO_P1_11
//#define PIN2 RPI_BPLUS_GPIO_J8_13

// PINS FOR readButtonPress
#define PIN RPI_BPLUS_GPIO_J8_11
#define PIN2 RPI_BPLUS_GPIO_J8_16
#define PIN3 RPI_BPLUS_GPIO_J8_12
int main(int argc, char **argv)
{
//blink();
//PoliceBlink();
init(PIN, PIN2, PIN3);
readButtonPress(PIN);
return 0;
}



