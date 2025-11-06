.PHONY:all
all:otherExe mycommand

otherExe:otherExe.cpp
	g++ -o $@ $^ -std=c++11
mycommand:mycommand.c
	gcc -o $@ $^ -std=c99
.PHONY:clean
clean:
	rm -f mycommand otherExe
