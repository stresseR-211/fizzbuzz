#ifndef FIZZ_H
#define FIZZ_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef struct FizzBuzzEngine {
	void (*fizz)(void);
	void (*buzz)(void);
	void (*nukeZimbabwe)(void);
} FizzBuzzEngine;
enum FB {
	B, F, I, U, Z
};
const char ch[5] = {
	0x42, 0x46, 0x69, 0x75, 0x7A
};
void fizz() {
	printf("%c%c%c%c", ch[F], ch[I], ch[Z], ch[Z]);
}
void buzz() {
	printf("%c%c%c%c", ch[B], ch[U], ch[Z], ch[Z]);
}
static inline FizzBuzzEngine* initialize(void) {
	FizzBuzzEngine* fbe = (FizzBuzzEngine*)malloc(sizeof(FizzBuzzEngine));
	fbe->fizz = fizz;
	fbe->buzz = buzz;
	fbe->nukeZimbabwe = (void*)0;
	return fbe;
}
static inline void uninitialize(FizzBuzzEngine** fbe) {
	if (fbe && *fbe) { free(*fbe); *fbe = NULL; }
}
bool divisible_by(float divisible, float divisor) {
	if (divisor == 0) {
		fputs("Division by zero is not defined.", stderr);
		abort();
	}
	return fmodf(divisible, divisor) == 0.0f;
}
#endif /* FIZZ_H */