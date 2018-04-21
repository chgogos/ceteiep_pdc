CC=g++
CFLAGS=-Wall -std=c++11 -pthread

all:example01a example01b \
	example02a example02b example02c example02d \
	example03 \
	example04a example04b

%:%.cpp
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f example01a example01b \
		example02a example02b example02c example02d \
		example03 \
		example04a example04b
