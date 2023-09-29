# $@ 表示目标文件
# $^ 表示所有的依赖文件
# $< 表示第一个依赖文件
# $? 表示比目标还要新的以来文件列表

#如果需要定义宏，在CFLAGS后面加 -DDEBUG（定义名称为DEBUG的宏）
CFLAGS += -g -o3 -Wall
PROGS = double_link_list.out link_list.out
TORT = microbench.h
LIBS = 

all: $(PROGS)

double_link_list.out: double_link_list.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<

link_list.out: link_list.cpp $(TORT)
	g++ $(CFLAGS) -o $@ $<


%: %.cpp $(TORT) $(LIBS)
	g++ $(CFLAGS) -o $@ $<

clean:
	rm -rf *.out
