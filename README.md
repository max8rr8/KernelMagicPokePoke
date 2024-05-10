# Kernel Magic Poke Poke

Two simple projects aimed to deepen my understanding of hypervisers, operating systems, linux kernel and qemu development.

## simple_kvm

First project is about from-scratch VM and OS. The final result is a simple OS spinning inside custom VM implementing chat functionality. 

VM is located in `src/vm`. It handles creation of virtual CPUs and management of memory by directly talking to KVM. Another task of this VM is accepting messages (over tcp socket) from multiple clients and sending them over MMIO device to OS. 

OS is located in `src/os`. It boots up and constantly listens for incoming messages from MMIO device provided by VM. When the message is recieved it is processed accordingly and sent to all participants, thus providing chat functionality.

## curstom_virtio

Second project is focused on modifying existing systems such as qemu and linux kernel to create simple RPC (Remote Procedure Calling) device. As a result inside a virtual machine running linux there is new device `/dev/virtio_rpc0` that provides userspace programs with ability to call some function inside host with arguments and return result.

First part is QEMU, in which I have created a simple `virtio-rpc` device that recieves requests over virtio, calls some function, and replies over virtio with execution result. The code is based on top of QEMU 8.1.2 (78385bc738108a9b5b20e639520dc60425ca2a5a), the patch with all changes is located in `qemu.patch`. 

Second part is Linux Kernel, in which I have added an in-tree driver that creates userspace interface (`/dev/virtio_rpc0`) that allows calling of functions over provided virtio device. The code is based on top of Linux 6.6 (ffc253263a1375a65fa6c9f62a893e9767fbebfa), the patch with all changes is located in `linux.patch`. 

Third part is a small userspace program that accesses provided kernel device to call function.
