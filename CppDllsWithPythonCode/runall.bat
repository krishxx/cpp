@echo deleting previous object files, dll and exe
del *.o
del example_dll.dll
del example_exe.exe

@echo Building example dll which contains python code
g++ -c -DBUILDING_EXAMPLE_DLL example_dll.cpp -IC:\Users\krish\Anaconda3\include

@echo linking with python37 dll
g++ -shared -o example_dll.dll example_dll.o -L. python37.dll -Wl,--out-implib,libexample_dll.a

@echo Building test program
g++ -c example_exe.cpp
g++ -o example_exe.exe example_exe.o -L. -lexample_dll

@echo testing with exe (internally it calles python embedded code)
example_exe.exe