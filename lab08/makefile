CC=g++
CFLAGS=-Wall -std=c++11 -pthread

all:example01 \

%:%.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f example01
