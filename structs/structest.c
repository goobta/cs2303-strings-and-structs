#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	struct Employee* mike = makeEmployee(1952, 1999, "Mike Ciaraldi");
	struct Employee* ankur = makeEmployee(1999, 2008, "Ankur Gupta");

	printEmployee(mike);
	printEmployee(ankur);

	return 0;
}
