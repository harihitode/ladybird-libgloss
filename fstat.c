#include <sys/stat.h>
#include <unistd.h>

int _fstat (int fd, struct stat * buf) {
  // open as a charactor device for UART
  buf->st_mode = S_IFCHR;
  return 0;
}
