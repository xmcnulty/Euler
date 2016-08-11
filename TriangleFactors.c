#include "TriangleFactors.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// initialize a binary tree.
Tree* initTree() {
	Tree *t = (Tree*) calloc(1, sizeof(Tree));

	t->_root = (Node*) calloc(1, sizeof(Node));
	t->_root->_isThreaded = 1;
	t->_root->_right = t->_root;
	t->_size = 0;

	return t;
}

// insert into tree or increment count variable if already in the tree.
int insert(Tree* t, int val) {

}

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
	Tree *t = initTree();

	printf("%d\n", t->_size);
}
