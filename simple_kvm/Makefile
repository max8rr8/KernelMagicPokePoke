.SILENT: run

build_vm:
	clang++ -g ./src/vm/*.cpp  -o ./vm

build_os:
	clang -O2 -fno-stack-protector -fno-pie -g -c -m32 -o ./build/os_main ./src/os/main.c
	nasm -g ./src/os/asm.s -o ./build/os_asm -felf32
	ld -m elf_i386 --oformat=binary -m elf_i386 -L./build -o ./os -T ./src/os/link

run: build_vm build_os
	echo 
	echo 
	echo "== STARTING VM"
	./vm