#ifndef FIZZ_H
#define FIZZ_H
#include <stdio.h>
#include <stdlib.h>
typedef struct FizzBuzzEngine {
	void (*fizz)(void);
	void (*buzz)(void);
} FizzBuzzEngine;
void fizz() { printf("fizz"); }
void buzz() { printf("buzz"); }
static inline FizzBuzzEngine* initialize(void) {
	FizzBuzzEngine* fbe = (FizzBuzzEngine*)malloc(sizeof(FizzBuzzEngine));
	fbe->fizz = fizz;
	fbe->buzz = buzz;
	return fbe;
}
static inline void uninitialize(FizzBuzzEngine** fbe) {
	if (fbe && *fbe) { free(*fbe); *fbe = NULL; }
}
#endif /* FIZZ_H */