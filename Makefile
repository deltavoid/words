
.PHONY : run
run : bin/main
	cd bin && ./main < input.txt > output.txt

bin/main : src/*
	g++ -o bin/main src/*

.PHONY : clean
clean :
	rm bin/main
