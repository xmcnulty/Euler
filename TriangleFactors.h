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

Tree* initTree();

// insert into tree return true/false
int insert(Tree* t, int val);

int isPrime(long n);

long getNthTriangleNumbers(int n);
