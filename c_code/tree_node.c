#include <stdlib.h>
#include <stdio.h>

typedef struct Nameval Nameval;

struct Nameval
{
	char *name;
	int *value;
	Nameval *left; /*lesser*/
	Nameval *right; /*greater*/
};


Nameval *newitem(char *name, int value)
{
	Nameval *newp;
	
	newp = (Nameval *) malloc(sizeof(Nameval));
	if (newp == NULL)
	{
		exit(1);
	}
	newp->name = name;
	newp->value = value;
	newp->left = NULL;
	newp->right = NULL;
	return newp;
}

Nameval *insert(Nameval *treep, Nameval *newp)
{
	int cmp;
	if (treep == NULL) {
		return newp;
	}
	cmp = strcmp(newp->name, treep->name);
	if (cmp == 0) {
		fprintf(stderr, "insert: ignoring duplicate entry %s\n",
		newp->name);
	} else if (cmp < 0) {
		treep->left = insert(treep->left, newp);
	} else {
		treep->right = insert(treep->right, newp);
	}
	return treep;
}

//recursive lookup
Nameval *lookup(Nameval *treep, char *name)
{
	int cmp;
	if (treep == NULL) {
		return NULL;
		printf("Can't find Hero: %s\n", name);
	}
	cmp = strcmp(name, treep->name);
	if (cmp == 0) {
		printf("Found name: %s\n", name);
		return treep;
	} else if (cmp < 0) {
		return lookup(treep->left, name);
	} else {
		return lookup(treep->right, name);
	}
}
//non-recursive lookup
Nameval *nrlookup(Nameval *treep, char *name)
{
	int cmp;
	while (treep != NULL) {
		cmp = strcmp(name, treep->name);
		if (cmp == 0) {
			return treep;
		} else if (cmp < 0) {
			treep = treep -> left;
		} else {
			treep = treep->right;
		}
	}
	printf("Can't find name: %s\n", name);
	return NULL;
}

/* applyinorder: execute fn for each element of treep (root) */
void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg)
{
	if (treep == NULL) {
		return;
	}
	applyinorder(treep->left, fn, arg);
	(*fn)(treep, arg);
	applyinorder(treep->right, fn, arg);
}

void printnv(Nameval *p, void *arg)
{
	char *fmt;
	fmt = (char *) arg;
	printf(fmt, p->name, p->value);
}

int main()
{
	Nameval *root = NULL;
	Nameval *newNode;
	
	newNode = newitem("AElig", 60);
	root = insert(root, newNode);
	newNode = newitem("Aacute", 30);
	root = insert(root, newNode);
	newNode = newitem("Acirc", 40);
	root = insert(root, newNode);
	newNode = newitem("smiley", 80);
	root = insert(root, newNode);
	newNode = newitem("zeta", 100);
	root = insert(root, newNode);
	
	//print tree in inorder traversal
	printf("printing inorder traversal\n");
	applyinorder(root, printnv, "%s: %d\n");
	//lookup
	lookup(root, "zeta");
	nrlookup(root, "Vision");
}