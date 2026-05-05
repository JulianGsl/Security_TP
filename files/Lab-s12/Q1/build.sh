#!/bin/sh
echo Building files...
cd src
gcc -o cleanware_1 cleanware_1.c
i686-w64-mingw32-gcc  -o cleanware_1.exe cleanware_1.c
gcc -o cleanware_2 cleanware_2.c
i686-w64-mingw32-gcc  -o cleanware_2.exe cleanware_2.c
gcc -o cleanware_3 cleanware_3.c
i686-w64-mingw32-gcc  -o cleanware_3.exe cleanware_3.c
gcc -o cleanware_4 cleanware_4.c
i686-w64-mingw32-gcc  -o cleanware_4.exe cleanware_4.c
gcc -o malware_1 malware_1.c
i686-w64-mingw32-gcc  -o malware_1.exe malware_1.c
gcc -o malware_2 malware_2.c
i686-w64-mingw32-gcc  -o malware_2.exe malware_2.c
g++ -o malware_3 malware_3.cc 2>/dev/null
i686-w64-mingw32-gcc  -o malware_3.exe malware_3.c
gcc -o malware_4 malware_4.c
i686-w64-mingw32-gcc  -o malware_4.exe malware_4.c
mv *_1 ../bin/
mv *_2 ../bin/
mv *_3 ../bin/
mv *_4 ../bin/
mv *_1.exe ../bin/
mv *_2.exe ../bin/
mv *_3.exe ../bin/
mv *_4.exe ../bin/
cd ..
echo Done!
