CC = g++
CPPFLAGS = -Wall -g

all: ulliststr_test
	-@echo "--- All Built!---"

ulliststr.o: ulliststr.cpp ulliststr.h
	$(CC) $(CPPFLAGS) -c ulliststr.cpp -o ulliststr.o

ulliststr_test: ulliststr_test.cpp ulliststr.o
	$(CC) $(CPPFLAGS) ulliststr_test.cpp ulliststr.o -o ulliststr_test

.PHONY: clean tests

tests: ulliststr_test
	-@./ulliststr_test
	-@echo "--- All Tested!---"

clean:
	-@rm -rf ulliststr_test ulliststr.o
	-@echo "--- All Clean!---"