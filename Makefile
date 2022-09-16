P0: main.o tree.o empty.o
	g++ main.o tree.o empty.o -o P0
main.o: main.cpp
	g++ -c main.cpp
tree.o: tree.cpp
	g++ -c tree.cpp
empty.o: empty.cpp
	g++ -c empty.cpp

clean:
	rm P0
	rm -f *.o main
	rm *.inorder
	rm *.preorder
	rm *.postorder

