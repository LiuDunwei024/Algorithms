# $@ 表示目标文件
# $^ 表示所有的依赖文件
# $< 表示第一个依赖文件
# $? 表示比目标还要新的以来文件列表

PROGS = double_link_list.out link_list.out

all: $(PROGS)

double_link_list.out: double_link_list.cpp
	g++ -o $@ $<

link_list.out: link_list.cpp
	g++ -o $@ $<

clean:
	rm -rf *.out
