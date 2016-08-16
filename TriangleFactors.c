#include "TriangleFactors.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// checks if a number is prime.
int isPrime(long n) {
	int i;

	for(i=2; i < ceil(sqrt(n)); i++) {
		if(n%i == 0)
			return 0;
	}

	return 1;
}

// gets the nth triangle number
long getNthTriangleNumbers(int n) {
	return (n*(n+1)) / 2;
}

int main() {
}
