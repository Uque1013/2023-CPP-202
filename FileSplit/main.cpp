#include "animal.h"
#include "dog.h"
#include "cat.h"

int main(void) {
	Animal a;
	Dog poppy;
	Cat nabi;

	a.bark();
	poppy.bark();
	nabi.bark();

	return 0;
}