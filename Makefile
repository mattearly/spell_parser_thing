TARGET = sparser
CC = g++
#~ OBJECTS = $(patsubst %.o,%,$(wildcard *.cpp))
OBJECTS = spell_parser.o spell_model.o

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)


*.o: *.cpp
	$(CC) -c *.cpp -std=c++11


.PHONY: test1
test1:
	+$(MAKE) $(TARGET)
	+$(MAKE) run


.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGET)*

.PHONY: run
run:
	./$(TARGET) < test.txt

