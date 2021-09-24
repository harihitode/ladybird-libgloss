// start up routine, and initialization for C
  .text
  .align 2
  .global _zerokara_hajimeru
  .type	_zerokara_hajimeru, @function
 _zerokara_hajimeru:
  li sp, 0x80002000 // set stack pointer
  jal ra, main      // call main, currently we do not implement BSS clear
1:
  nop               // nop loop (more formally, we should call _exit system call)
  j 1b              // nop loop (back jump to the label)
