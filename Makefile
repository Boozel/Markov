CXX = g++
CXXFLAGS = -Wall

all: markov clean

markov: main.o
	$(CXX) $(CXXFLAGS) main.o -o markov

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp

clean:
	rm *.o

cleaner: clean
	rm markov

#check bookmarks when editing!
