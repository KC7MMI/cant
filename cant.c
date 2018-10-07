/*
CALCULANT/CANT - C Antenna Calculator created by Benjamin Russell KC7MMI
prev version 0.5 - 2018-09-08
current version 1.0 - 2018-09-10 
*/

#include <stdio.h>
#include <stdlib.h>

void clrscr(void) {
	printf("\033[H");  //brings cursor home
	printf("\x1b[2J"); //clears screen
}

float getFreq(void) {                       //ran only if invalid or no valid argument received
	float freq;
	clrscr();
	printf("No Valid Argument - Enter desired resonant frequency (MHz): ");
	scanf("%f",&freq);
	return(freq);
}

void wHeader(void) {                       //header  for wavelengths
	printf("\nWAVELENGTH   FULL*        5/8          1/2          1/4");
	printf("\n----------------------------------------------------------------");
}

void hHeader(void) {                       //header for harmonics
	printf("\n            *Free Space");
	printf("\n================================================================");
	printf("\nHARMONICS    (3rd)        (5th)        (7th)        (9th)");
	printf("\n----------------------------------------------------------------");
}

void iLength(float freq) {                //provides imperial output with feet and inches
	float w11ft,w58ft,w12ft,w14ft;
	int w11ftFloor,w58ftFloor,w12ftFloor,w14ftFloor,w11in,w58in,w12in,w14in;
	w11ft = 984 / freq;
	w11ftFloor = w11ft;
	w11in = (w11ft - w11ftFloor) * 12;
	w58ft = 585 / freq;
	w58ftFloor = w58ft;
	w58in = (w58ft - w58ftFloor) * 12;
	w12ft = 468 / freq;
	w12ftFloor = w12ft;
	w12in = (w12ft - w12ftFloor) * 12;
	w14ft = 234 / freq;
	w14ftFloor = w14ft;
	w14in = (w14ft - w14ftFloor) * 12;
	printf("\nImperial: %5ift %2iin %5ift %2iin %5ift %2iin %5ift %2iin",w11ftFloor,w11in,w58ftFloor,w58in,w12ftFloor,w12in,w14ftFloor,w14in);
}

void mLength(float freq) {                //provides metric output in meters only
	float w11m,w58m,w12m,w14m;
	w11m = 299.792 / freq;
	w58m = 178.309 / freq;
	w12m = 142.647 / freq;
	w14m = 71.324 / freq;
	printf("\nMetric  : %9.3fm   %9.3fm   %9.3fm   %9.3fm",w11m,w58m,w12m,w14m);
}

void oddHarmonics(float freq) {           //displays odd harmonics of inputted freq--for determining add'l possible reasonant freqs
	float h3,h5,h7,h9;
	h3 = freq * 3;
	h5 = freq * 5;
	h7 = freq * 7;
	h9 = freq * 9;
	printf("\n          %8.2fMHz  %8.2fMHz  %8.2fMHz  %8.2fMHz\n",h3,h5,h7,h9);
}

void intro(float freq) {                  //provides program name and provides inputted value
	printf("CANT - C Antenna Calculator - Results for %.3fMHz\n",freq);
}

void close(void) {                        //gives space between program output and command prompt
	printf("\n");
}

int main(int argc,char *argv[]) {         //main function which calls all sub-functions
	float MHz;
	if (argc < 2) {                   //if no argument supplied, run getFreq function
		MHz = (getFreq());
	}
	else {
		MHz = atof(argv[1]);
	}
	if (MHz == 0) {                   //if supplied argument is not a valid number, run getFreq function
		MHz = (getFreq());
	}
	clrscr();
	intro(MHz);
	wHeader();
	iLength(MHz);
	mLength(MHz);
	hHeader();
	oddHarmonics(MHz);
	close();
	return 0;
}
