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

// Initialize a Node
Node* initNode(int val, Node* right) {
	Node* n = (Node*) calloc(1, sizeof(Node));

	n->_val = val;
	n->_isThreaded = 1;
	n->_right = right;

	return n;
}

// free up memory taken by tree
void freeTree(Tree* t) {
	if(t->_size > 0) {
		Node* ptr = t->_root->_left;

		while(ptr->_left)
			ptr = ptr->_left;
	}

	free(t->_root);
	free(t);

	return;
}

// insert into tree or increment count variable if already in the tree.
int insert(Tree* t, int val) {
	// Insert node to left of root if empty.
	if (t->_size == 0) {
		Node* n = initNode(val, t->_root);

		t->_root->_left = n;
		t->_size ++;
	} else {
		Node* ptr = t->_root->_left;
		Node* parent = t->_root;

		while(1) { // loop to insert
			if(ptr->_val == val) {
				ptr->_count ++;
				return 1;
			} else if (ptr->_val > val) {
				if(!ptr->_left) { // insert to left
					Node* n = initNode(val, parent);

					ptr->_left = n;
					t->_size ++;
					return 1;
				} else { // traverse left
					parent = ptr;
					ptr = ptr->_left;
				}
			} else {
				if (ptr->_isThreaded) { // insert to right
					ptr->_isThreaded = 0;
					ptr->_right = initNode(val, parent);
					t->_size ++;
					return 1;
				} else {
					ptr = ptr->_right;
				}
			}
		}
	}

	return 1;
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

void printTree(Tree* t) {
	Node* n = t->_root;
	
	while(n->_left)
		n = n->_left;
}

int main() {
	Tree *t = initTree();
	insert(t, 1);
	insert(t, 1);

	printf("%d\n", t->_size);
	
	return 0;
}
