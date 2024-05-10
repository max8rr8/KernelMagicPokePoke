echo "===== Staring"
# gdb -x qemugdb --args \
./qemu_install/bin/qemu-system-x86_64 -M microvm,auto-kernel-cmdline=on,acpi=off -enable-kvm -m 1024 \
  -kernel linux/arch/x86/boot/bzImage \
  -blockdev node-name=rootdsk,driver=qcow2,file.driver=file,file.filename=rootfs.img \
  -device virtio-blk-device,drive=rootdsk \
  -append "root=/dev/vda rw console=ttyS0" \
  -netdev user,id=net0,hostfwd=tcp::5555-:22 \
  -device virtio-net-device,netdev=net0 \
  -fsdev local,path=shared,security_model=mapped,id=shareddir \
  -device virtio-9p-device,mount_tag=shareddir,fsdev=shareddir \
  --nographic -s \
  --device virtio-rpc \
