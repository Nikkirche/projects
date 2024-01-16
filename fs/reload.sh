#!/bin/zsh
sudo make clean
sudo make
sudo umount /mnt/ct 
sudo rmmod networkfs
sudo insmod networkfs.ko
sudo mount -t networkfs fc50c12a-a7e5-45b8-b579-17a00252fc8a /mnt/ct
