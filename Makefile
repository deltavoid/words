
.PHONY : run
run : main.exe
	main.exe < input.txt

main.exe : A1.cpp
	g++ -o main.exe A1.cpp

.PHONY : clean
clean :
	rm main.exe
