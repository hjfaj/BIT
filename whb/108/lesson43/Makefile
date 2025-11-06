.PHONY:all
all:servercal clientcal

Flag=#-DMySelf=1
Lib=-ljsoncpp

servercal:ServerCal.cc
	g++ -o $@ $^ -std=c++11 $(Lib) $(Flag)
clientcal:ClientCal.cc
	g++ -o $@ $^ -std=c++11 -g $(Lib) $(Flag)


.PHONY:clean
clean:
	rm -f clientcal servercal