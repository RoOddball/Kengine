build:
	gcc -Wfatal-errors \
	-std=c99 \
	./*.c \
	-I"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\include" \
	-L"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\lib" \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer \
	-o sdl.exe