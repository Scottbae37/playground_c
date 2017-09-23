.SUFFIXES : .c .o

CC = gcc

INC = -I./include -I/usr/local/include/glib-2.0 -I/usr/local/lib/glib-2.0/include -I/usr/local/include/gio-unix-2.0 #<- include 되는 헤더 파일의 패스를 추가한다.
LIBS = -lgio-2.0 \
-lgobject-2.0 \
-lglib-2.0 #<- 링크할 때 필요한 라이브러리를 추가한다.
CFLAGS = -std=c11 -O3 -Wall -c -fmessage-length=0 -g0#<- 컴파일에 필요한 각종 옵션을 추가한다.

OBJS = GdbusExamBjs.o my-gen.o#<- 목적 파일의 이름을 적는다.
SRCS = 	./src/GdbusExamBjs.c \
./src/my-gen.c #<- 소스 파일의 이름을 적는다.
		
TARGET = Output#<- 링크 후에 생성될 실행 파일의 이름을 적는다.

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o Output $(OBJS) $(LIBS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(INC) $(SRCS)

dep :
	gccmakedep $(INC) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET) core