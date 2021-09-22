#include <errno.h>
#include <unistd.h>

int _isatty (int fd) {
  if ((fd == STDIN_FILENO) || (fd == STDOUT_FILENO) || (fd == STDERR_FILENO)) {
    // All stdin, stdout and stderr are connected te UART (terminal) immediately.
    return 1;
  } else {
    // Others are not a valid fd.
    errno = EBADF;
    return 0;
  }
}
