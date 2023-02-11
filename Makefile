all:
	g++ -g -Wall -pedantic src/*.cpp -o WFCpp

clean:
	rm WFCpp
