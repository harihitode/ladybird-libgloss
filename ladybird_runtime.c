#include <signal.h>
#include <stdlib.h>

void _ladybird_trap_handler_c() {
	void (*func)(int) = signal(SIGINT, SIG_DFL);
	if ((func != SIG_DFL) && (func != SIG_IGN)) {
		func(SIGINT);
	} else if (func == SIG_ERR) {
		abort();
	}
	return;
}
