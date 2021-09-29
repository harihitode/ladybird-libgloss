#include <signal.h>

void _ladybird_trap_handler_c() {
	void (*func)(int) = signal(SIGINT, SIG_DFL);
	func(SIGINT);
	return;
}
