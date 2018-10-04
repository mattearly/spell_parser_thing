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
	./$(TARGET) < test.txt

.PHONY: test2
test2:
	+$(MAKE) $(TARGET)
	./$(TARGET) < test2.txt


.PHONY: clean
clean:
	rm $(OBJECTS) $(TARGET)*

