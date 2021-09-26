#include <errno.h>

extern char _end; // end of the BSS
char * heap_ptr = NULL;

// change the program break
char * _sbrk(int nbytes) {
  char * base;
  int stack_heap_length;
  if (!heap_ptr)
    heap_ptr = &_end;
  base = heap_ptr;
  heap_ptr += nbytes;

  // check if heap overflow
  asm volatile("sub %0, sp, %1"
	       : "=r"(stack_heap_length)
	       : "r"(heap_ptr)
	       :
	       );
 
  // Petit implementation of SBRK
  // When stack pointer and heap pointer are crossed each other (overflowed), then 
  // we can detect lack of memory.
  if (stack_heap_length >= 0) {
    return base;
  } else {
    errno = ENOMEM;
    return ((char *)-1);
  }
}
