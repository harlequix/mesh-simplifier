all:
	g++ -o simplifier main.cpp Graphicobject.cpp FileReader.cpp Edge.cpp  Vertex.cpp Triangle.cpp -std=c++11

clean:
	    rm *o simplifier

