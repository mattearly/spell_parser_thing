all: spell_parser.o spell_model.o
	g++ spell_parser.o spell_model.o -o sparser

*.o: *.cpp
	g++ -c *.cpp -std=c++11

.PHONY: test1
test1:
	+$(MAKE) all
	./sparser.exe < test.txt

.PHONY: clean
clean:
	rm *.o sparser*