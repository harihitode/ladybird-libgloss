ENTRY(_zerokara_hajimeru)
STARTUP(libgloss.a)

MEMORY {
	bram (rw)  : ORIGIN = 0x80000000, LENGTH = 8k
	iram (rwx) : ORIGIN = 0x90000000, LENGTH = 72k
	uart (rw)  : ORIGIN = 0xFFFFFFFF, LENGTH = 1
}

SECTIONS {
	.text : { *(.text) } > iram
	.data : { *(.data) } > iram
	.bss  : { *(.bss) _end = .; } > bram
	.uart : { _uart = .; } > uart
	}
