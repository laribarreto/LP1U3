CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
SRCS = main.cpp corretor.cpp cliente.cpp imovel.cpp agenda.cpp

imobiliaria: $(SRCS)
	$(CXX) $(CXXFLAGS) -o imobiliaria $(SRCS)

clean:
	rm -f imobiliaria
