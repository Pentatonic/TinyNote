/*
	Macro to calculate offset of variable in a structure.
	Tested on gcc.
*/

#include <stdio.h>
#define offsetof(s, m) (size_t)(&(((s *)0)->m))

typedef struct _aa {
	int a;
	int b;
	int c;
} aa;

int main() {
	int tt = offsetof(aa, a);
	printf ("%d\n", tt);
	tt = offsetof(aa, b);
	printf ("%d\n", tt);
	tt = offsetof(aa, c);
	printf ("%d\n", tt);
}
