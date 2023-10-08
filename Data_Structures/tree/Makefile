CFLAGS += -g -o3 -Wall
PROGS = BinaryTree
TORT = microbench.h

all: $(PROGS)

BinaryTree: BinaryTree.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<

%: %.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<

clean:
	rm -rf $(PROGS)