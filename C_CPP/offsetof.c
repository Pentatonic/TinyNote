/*
   Macro to calculate offset of variable in a structure.
   Let the base address to be zero, then the member's addresses are exactly their offset in
   this structure.
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
    int offset = offsetof(aa, a);
    printf("%d\n", offset);
    offset = offsetof(aa, b);
    printf("%d\n", offset);
    offset = offsetof(aa, c);
    printf("%d\n", offset);
}
