#include <stdlib.h>
#include <stdio.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int *value;
	Nameval *next; //in list
};


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

Nameval *addfront(Nameval *listp, Nameval *newp)
{
	newp->next = listp;
	return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp)
{
	Nameval *p;
	//checks if there this is the first item in the list
	if (listp == NULL) {
		return newp;
	}
	for (p = listp; p->next != NULL; p = p->next);
	p->next = newp;
	return listp;
}

Nameval *lookup(Nameval *listp, char *name)
{
	for ( ; listp != NULL; listp = listp->next) {
		if (strcmp(name, listp->name) == 0) { //strcmp == 0 means they are equal
			return listp;
		}
	}
	printf("Can't find Hero: %s", name);
	return NULL;
}

/* apply: execute fn for each element of listp */
void apply(Nameval *listp, void (*fn)(Nameval*, void*), void *arg)
{
	for ( ; listp != NULL; listp = listp->next) {
		(*fn)(listp, arg); /* call the function */
	}
}

void printnv(Nameval *p, void *arg)
{
	char *fmt;
	fmt = (char *) arg;
	printf(fmt, p->name, p->value);
}

int main(void)
{
	Nameval *nvlist = NULL;
	Nameval *newnode;
	
	newnode = newitem("Allan", 60);
	nvlist = addfront(nvlist, newnode);
	newnode = newitem("Thanos", 32);
	nvlist = addfront(nvlist, newnode);
	newnode = newitem("Thor", 12);
	nvlist = addend(nvlist, newnode);
	//print out the list
	apply(nvlist, printnv, "%s: %d\n");
	lookup(nvlist, "Hulk");
}
	
