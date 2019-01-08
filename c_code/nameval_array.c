#include <stdlib.h>

typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
};

struct Nvtab {
	int nval;
	int max;
	Nameval *nameval;
} nvtab;

enum { NVINIT = 1, NVGROW = 2 };

//Creates a new nameval
Nameval *new_nameval(char *name, int value)
{
	Nameval *temp;
	
	temp = (Nameval *)malloc(sizeof(Nameval));
	if (temp == NULL) {
		fprintf(stderr, "Error mallocing a Nameval");
		exit(1);
	}
	/* temp->name === (*temp).name */
	temp->name = (char *)malloc((strlen(name)+1) * sizeof(char));
		if (temp->name == NULL) {
		fprintf(stderr, "Error mallocing a memory for string");
		exit(1);
	}
	strncpy(temp->name, name, strlen(name)+1);
	temp->value = value;
	return temp;
}

//Adding name
int addname(Nameval newname)
{
	Nameval *nvp;
	
	if (nvtab.nameval == NULL) { /* first use of array */
		nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
		if (nvtab.nameval == NULL) { return -1; }
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	} else if (nvtab.nval >= nvtab.max) {
		nvp = (Nameval *) realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeofNameval);
		if (nvp == NULL) { return = -1; }
		nvtab.max = NVGROW * nvtab.max;
		nvtab.nameval = nvp;
	}
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}

int delname (char *name)
{
	int i;
	
	for (i = 0; i < nvtab.nval; i++) { //nvtab.nval address to a char
		if (strcmp(nvtab.nameval[i].name, name) == 0) { //0 = false, 1 = true
			memmove(nvtab.nameval + i, nvtab.nameval + i + 1, (nvtab.nval-(i+1)) * sizeof(Nameval));
			nvtab.nval--;
			return 1;
		}
	}
	return 0;
}