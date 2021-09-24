# Ladybird Software Snippets

* [Ladybird RISC-V Core](https://github.com/harihitode/ladybird#ladybird)
* libgloss backend (BSP)

## How to set up for libgloss in newlib

### Requirements.

* Any C lang ~ RISC-V compiler, like clang or gcc, 
  especially for target `riscv32-unknown-elf` and ISA `rv32i` .

* Clone [newlib](https://sourceware.org/newlib/).

1. Edit `newlib-cygwin/config.sub` to add ladybird-elf system.


```
diff --git a/config.sub b/config.sub
index 63c1f1c8b..1cbfdf045 100755
--- a/config.sub
+++ b/config.sub
@@ -1731,6 +1731,8 @@ case $os in
        sco3.2v2 | sco3.2v[4-9]* | sco5v6*)
                # Don't forget version if it is 3.2v4 or newer.
                ;;
+       ladybird)
+               ;;
        none)
                ;;
        *)
@@ -1760,6 +1762,8 @@ case $kernel-$os in
                ;;
        os2-emx)
                ;;
+       ladybird-elf)
+               ;;
        *-eabi* | *-gnueabi*)
                ;;
        -*)
```

2. Edit `newlib-cygwin/libgloss/configure` to add this backend and select it.


```
diff --git a/libgloss/configure b/libgloss/configure
index 816b9c4b8..a03b11ea0 100755
--- a/libgloss/configure
+++ b/libgloss/configure
@@ -681,6 +681,7 @@ sparc
 wince
 mips
 riscv
+ladybird-libgloss
 rs6000
 mn10200
 mn10300
@@ -2463,6 +2464,11 @@ case "${target}" in
   mips*-*-*)
        subdirs="$subdirs mips"

+       ;;
+  riscv*-ladybird-*)
+       subdirs="$subdirs ladybird-libgloss"
+
+       config_libnosys=false
        ;;
   riscv*-*-*)
        subdirs="$subdirs riscv"
```

3. Build

  * note; example uses llvm which is in `${HOME}/llvm-riscv/` .
  * note; change `--prefix` as your wish ;).

```
mkdir build; cd build
../configure --target=riscv32-harihitode-ladybird-elf CC_FOR_TARGET="${HOME}/llvm-riscv/bin/clang" AR_FOR_TARGET="${HOME}/llvm-riscv/bin/llvm-ar" RANLIB_FOR_TARGET="${HOME}/llvm-riscv/bin/llvm-ar -s" --disable-multilib CFLAGS_FOR_TARGET="--target=riscv32-unknown-elf -march=rv32i -mabi=ilp32 -O3 -fPIC" --prefix=${HOME}/ladybird_newlib
make -jN
```

## Appendix

This project uses autoconf. You can re-generate configure file below steps.

```
aclocal -I ../
autoheader
autoconf
```
