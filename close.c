#include <errno.h>

int _close(int fd) {
  // currently, ladybird has not valid file descriptor to be closed
  errno = EBADF;
  return -1;
}
