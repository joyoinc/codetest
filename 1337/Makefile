CC=g++
#CFLAGS=-Wall -ggdb -fPIC
CFLAGS=-ggdb
#LINK = -L/home/nia/bin -lmyutil
LINK =

OBJ = main.o is_palindrome.o anagrams.o triangle.o \
			build_tree.o gray_code.o reverse.o roman.o \
			parenthesis.o array.o
#LIB = util.o

leetcode.ex : $(OBJ)
	$(CC) -o $@ $^ $(LINK) 

#lib : $(LIB)
#	$(CC) -shared -fPCI -o libmyutil.so $<
#	cp libmyutil.so /home/nia/bin

clean:
	rm -rf *.o
	rm -rf *.tmp
	rm -rf *.ex
