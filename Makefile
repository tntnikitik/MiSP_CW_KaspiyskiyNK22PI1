CXX := g++
CXXFLAGS := -std=c++11 -Wall
LDFLAGS := -lcryptopp -lboost_program_options

SRCS := errorhandler.cpp getdata.cpp main.cpp md5hash.cpp server.cpp
OBJS := $(SRCS:.cpp=.o)
EXEC := server

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)


