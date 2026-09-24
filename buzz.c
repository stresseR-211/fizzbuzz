#include "fizz.h"
int main(int argc, char** argv) {
	FizzBuzzEngine* fizzBuzz = initialize();
	if (argc < 2) {
		fputs("No arguments provided.", stderr);
		return -1;
	}
	float n = atoi(argv[1]);
	if (n <= 0) {
		fputs("Invalid argument; should be a positive non-zero integer.", stderr);
		return -2;
	}
	if (divisible_by(n, 15)) {
		fizzBuzz->fizz();
		fizzBuzz->buzz();
	} else if (divisible_by(n, 5)) {
		fizzBuzz->buzz();
	} else if (divisible_by(n, 3)) {
		fizzBuzz->fizz();
	} else {
		fizzBuzz->nukeZimbabwe(); //segfault
	}
	uninitialize(&fizzBuzz);
	return 0;
}