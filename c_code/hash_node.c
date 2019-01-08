#include <stdlib.h>
#include <stdio.h>

typedef struct Nameval Nameval;

struct Nameval
{
	char *name;
	int *value;
	Nameval *next; //in the chain
};

Nameval *symtab[NHASH];

void *emalloc(size_t n)
{
	void *p;
	p = malloc(n);
	if (p == NULL) {
		fprintf(stderr, "malloc of %u bytes failed", n);
		exit(1);
	}
	return p;
}

Nameval *newitem (char *name, int value)
{
	Nameval *newp;
	
	newp = (Nameval *) emalloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *lookup (char *name, int create, int value)
{
	int h;
	Nameval *sym;
	
	h = hash(name);
	for (sym = symtab[h]; sym != NULL; sym = sym->next) {
		if (strcmp(name, sym->name) == 0) { return sym; }
	}
	if (create) {
		sym = (Nameval *) emalloc(sizeof(Nameval));
		sym->name = name; /* assumed allocated elsewhere */
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

int main()
{
	
}