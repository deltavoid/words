
.PHONY : run
run : bin/main
	cd bin && ./main < input1.txt > output1.txt

bin/main : src/*
	g++ -o bin/main src/*

.PHONY : clean
clean :
	rm bin/main
