#include <sys/types.h>
#include <errno.h>

off_t _lseek (int fd, off_t offset, int whence) {
  // we have only UART, we could not seek.
  errno = ESPIPE; // FD is a FIFO (pipe or socket) which is not seekable
  return ((off_t)-1);
}

