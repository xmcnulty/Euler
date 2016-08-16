// used to find triangle numbers and the number of factors that number has

// node in a threaded binary tree.
typedef struct Node {
	int _val, _count, _isThreaded;
	struct Node *_left, *_right;
} Node;

typedef struct Tree {
	Node *_root;
	int _size;
} Tree;

// initialize a prime factor tree
Tree* initTree();

// initialize a Node, each new node will be threaded
Node* initNode(int val, Node* right);

// clean up a tree
void freeTree(Tree* t);

// insert into tree return true/false
int insert(Tree* t, int val);

// checks if a number is prime
int isPrime(long n);

// gets the nth triangle number
long getNthTriangleNumbers(int n);

// DEBUG ONLY
void printTree(Tree* t);
