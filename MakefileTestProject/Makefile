.SUFFIXES : .c .o

CC = gcc

INC = ./include/#<- include 되는 헤더 파일의 패스를 추가한다.
LIBS = #<- 링크할 때 필요한 라이브러리를 추가한다.
CFLAGS = -std=c11 -O3 -Wall -c -fmessage-length=0 -g0#<- 컴파일에 필요한 각종 옵션을 추가한다.

OBJS = GitTest.o#<- 목적 파일의 이름을 적는다.
SRCS = ./src/GitTest.c#<- 소스 파일의 이름을 적는다.

TARGET = GitTest#<- 링크 후에 생성될 실행 파일의 이름을 적는다.

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o GitTest $(OBJS) $(LIBS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

dep :
	gccmakedep $(INC) $(SRCS)

clean :
	rm -rf $(OBJS) $(TARGET) core