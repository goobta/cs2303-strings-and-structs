/** mystruct.c
 * @author Mike Ciaraldi
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystruct.h"

int nameLength = 10;

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the emploee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee* e = (struct Employee*) malloc(sizeof(struct Employee));
	e->birth_year = birth;
	e->start_year = start;
	strcpy(e->name, name);

	return e;
}

/**
 * @brief Print an Employee struct in a human readable fashion
 *
 * @param pointer to to the Employee Struct
 */
void printEmployee(struct Employee *e) {
	printf(
			"Employee %s was born in %d and started in %d.\n",
			e->name,
			e->birth_year,
			e->start_year);
}

/**
 * @brief Generate a random age 
 *
 * @return an int which is in the range [1900, 2018]
 */
int randomAge() {
	int offset = rand() % 119;
	return offset + 1900;
}

/**
 * @brief Generate a random string of size 'length'
 *
 * @param length how long the string should be
 *
 * @return A random string of size 'length'
 */
char* randomName(int length) {
	char* name = (char*) malloc(sizeof(char) * (length + 1));

	for(int i = 0; i < length; i++) {
		name[i] = 'A' + (rand() % 26);
	}

	name[length] = '\0';

	return name;
}

/**
 * @brief generate a random employee
 *
 * @return a pointer to an employee struct with start and birthdays in the range
 * [1900, 2018] and names that are of length 'nameLength', as defined above
 */
struct Employee* randomEmployee() {
	return makeEmployee(randomAge(), randomAge(), randomName(nameLength));
}

/**
 * @brief Create a random array of employees
 *
 * @param count the desired length of the array
 *
 * @return a pointer to an array of pointers to an Employee
 */
struct Employee** randomArray(int count) {
	struct Employee** e = (Employee**) malloc(sizeof(struct Employee) * count);

	for(int i = 0; i < count ; i++) {
		e[i] = randomEmployee();
	}

	return e;
}

/**
 * @brief be able to print out an array of pointers to employees in a human
 * readable format
 *
 * @param arr the array of pointers to Employees
 * @param count the length of the array
 */
void printEmployeeArray(struct Employee** arr, int count) {
	for(int i = 0; i < count; i++) {
		printEmployee(arr[i]);
	}
}

struct Employee** shallowCopy(struct Employee** old, int count) {
	struct Employee** new = (Employee**) malloc(sizeof(struct Employee) * count);

	for(int i = 0; i < count; i++) {
		new[i] = old[i];
	}

	return new;
}
