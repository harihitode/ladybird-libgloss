extern char _uart;

int _write (int fd, char * buf, int nbytes) {
  // We currently only have UART FDs.
  // write each byte to UART
  for (int i = 0; i < nbytes; i++) {
    if (*(buf + i) == '\n') {
      _uart = '\r';
    }
    _uart = *(buf + i);
  }
  return nbytes;
}
