
CXX = g++

SRC = $(wildcard *.cpp)
OBJS = $(SRC:.cpp=.o)

INCLUDE = -I ../include -I ./
LIBS = -L ../lib -lPocoFoundation -lPocoNet -lPocoUtil -lPocoXML -lPocoUtil

TARGET = udp.out

all:$(OBJS)
	$(CXX) $(OBJS) $(LIBS) -o $(TARGET)
$(OBJS):%.o:%.cpp
	$(CXX) -c $< -o $@ $(INCLUDE)

clean:
	rm $(OBJS) $(TARGET) -rf

