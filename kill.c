#include <errno.h>

void _exit(int);

// This implementation is almost a mock.
int _kill(int pid, int sig) {
  if (pid == 1) {
    _exit(sig); // if pid is 1 (we have only 1 thread), exits with signal
    return 0;
  } else {
    errno = ESRCH; // No such a process
    return -1;
  }
}
