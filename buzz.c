#include "fizz.h"
int main(int argc, char** argv) {
	FizzBuzzEngine* fizzBuzz = initialize();
	if (argc < 2) {
		puts("No arguments provided.");
		return -1;
	}
	float n = atoi(argv[1]);
	if (n <= 0) {
		puts("Invalid argument; should be a positive non-zero integer.");
		return -2;
	}
	if ((float)(n/15) == 1.0f) {
		fizzBuzz->fizz();
		fizzBuzz->buzz();
	} else if ((float)(n/5) == 1.0f) {
		fizzBuzz->buzz();
	} else if ((float)(n/3) == 1.0f) {
		fizzBuzz->fizz();
	} else {
		puts("no");
	}
	uninitialize(fizzBuzz);
	return 0;
}