# -snow-crash-
security project 42


qemu-system-x86_64 -netdev user,id=net0,hostfwd=tcp::2222-:4242 -device virtio-net-pci,netdev=net0 -enable-kvm -cdrom ~/Downloads/SnowCrash.iso