PROGS = double_link_list.out link_list.out

all: $(PROGS)

double_link_list.out: double_link_list.cpp
	g++ -o $@ $<

link_list.out: link_list.cpp
	g++ -o $@ $<

clean:
	rm -rf *.out
