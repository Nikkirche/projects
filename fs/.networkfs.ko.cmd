cmd_/media/sf_hw4/networkfs.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /media/sf_hw4/networkfs.ko /media/sf_hw4/networkfs.o /media/sf_hw4/networkfs.mod.o;  true
