extern char _uart; // symbol for UART

int _read(int fd, char * buf, int nbytes) {
  // We currently only have UART FDs.
  // read each byte from UART
  int i;
  for (i = 0; i < nbytes; i++) {
    *(buf + i) = _uart; // serial input
    if ((*(buf + i) == '\n') || (*(buf + i) == '\r')) {
      i++;
      break;
    }
  }
  return i;
}
