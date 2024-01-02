#include <stdio.h>
#include <stdlib.h>
#include <bcm2835.h>
#include "MYLIGHTSLIB.h"

#define PIN2 RPI_BPLUS_GPIO_J8_12
#define PIN3 RPI_BPLUS_GPIO_J8_16

extern int init(int PIN, int PIN2, int PIN3){
    if (!bcm2835_init())
      return 1;
 
    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN3, BCM2835_GPIO_FSEL_OUTP);
    return 0;
}

extern int blink(int PIN, int PIN2){

    if (!bcm2835_init())
      return 1;

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    while (1)
    {

    bcm2835_gpio_write(PIN, HIGH);
    bcm2835_delay(500);
    bcm2835_gpio_write(PIN, LOW);
    bcm2835_delay(100);
    bcm2835_gpio_write(PIN2, HIGH);
    bcm2835_delay(500);
    bcm2835_gpio_write(PIN2, LOW);
    bcm2835_delay(500);


    }
    bcm2835_close();
    return 0;
}


extern int PoliceBlink(int PIN, int PIN2){
 
    if (!bcm2835_init())
      return 1;
 
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_fsel(PIN2, BCM2835_GPIO_FSEL_OUTP);

    while (1)
    {
       bcm2835_gpio_write(PIN, HIGH);
       bcm2835_delay(500);
       bcm2835_gpio_write(PIN, LOW);
       bcm2835_delay(500);
       bcm2835_gpio_write(PIN, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN, LOW);
       bcm2835_gpio_write(PIN, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN, LOW);
       bcm2835_gpio_write(PIN, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN, LOW);
       bcm2835_delay(50);
       bcm2835_gpio_write(PIN2, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN2, LOW);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN2, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN2, LOW);
       bcm2835_gpio_write(PIN2, HIGH);
       bcm2835_delay(10);
       bcm2835_gpio_write(PIN2, LOW);
       bcm2835_delay(50);
    }
    bcm2835_close();
    return 0;
}

extern int readButtonPress(int PIN){
	
	if (!bcm2835_init())
		return 1;
	
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP);

	int update = 1; // 0 if the button has not been updated 1 if it has
	int X = 2;

	int binaryvalue = 0;

	printf("Current count = %d\n", binaryvalue);

	while (1){
	// READ DATA
	uint8_t value = bcm2835_gpio_lev(PIN);
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
	
	// when value changes,reposition X and update the counter
	// 0 -> 3 values only
	
	if (value != X){
	X = value;
	}
	if (value == 0 && X == 0){
	binaryvalue = (binaryvalue + 1) % 4;
	printf("Current count = %d\n", binaryvalue);
}

// MAKE LIGHTS BLINK IN CORRECT SEQUENCES
if (binaryvalue == 0){
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, LOW);
}else if (binaryvalue == 1){
	bcm2835_gpio_write(PIN2, LOW);
	bcm2835_gpio_write(PIN3, HIGH);
}else if (binaryvalue == 2){
	bcm2835_gpio_write(PIN2, HIGH);
	bcm2835_gpio_write(PIN3, LOW);
}else{
	bcm2835_gpio_write(PIN2, HIGH);
	bcm2835_gpio_write(PIN3, HIGH);
}

// wait
delay(500);
}

bcm2835_close();
return 0;
}
