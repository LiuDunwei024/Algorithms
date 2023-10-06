CFLAGS += -g -o3 -Wall
PROGS = stack queue
TORT = microbench.h

all: $(PROGS)

stack: stack.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<

queue: queue.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<	

%: %.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<

clean:
	rm -rf $(PROGS)