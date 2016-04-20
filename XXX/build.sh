#bin/bin/bash

gcc -shared -o libJNILayer.so JNILayer.c  volume.c -L/home/frank/Downloads/tibeecompare/XXX  -llprprint -fPIC -I/usr/lib/jvm/java-1.8.0-openjdk-amd64/include -I/usr/lib/jvm/java-1.8.0-openjdk-amd64/include/linux
