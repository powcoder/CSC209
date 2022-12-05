FLAGS = -Wall -g -std=gnu99

all: classifier  test_load_data

classifier : dectree.o classifier.o
	gcc ${FLAGS} -o classifier dectree.o classifier.o -lm

test_load_data : dectree.o test_load_data.o
	gcc ${FLAGS} -o test_load_data dectree.o test_load_data.o -lm

classifier.o : classifier.c dectree.h
	gcc ${FLAGS} -c classifier.c 

test_load_data.o : test_load_data.c dectree.h
	gcc ${FLAGS} -c test_load_data.c 

dectree.o : dectree.c dectree.h
	gcc ${FLAGS} -c dectree.c 

datasets : datasets.tgz
	tar xzf datasets.tgz

.PHONY: clean all

clean:	
	rm classifier test_load_data *.o
