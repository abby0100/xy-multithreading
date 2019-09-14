
SHELL		:= /bin/bash
CXX			:= g++
CXX_FLAGS	:= -g -Wall -std=c++11
INCLUDE_PATH:= -I.

LIBRARY		:= pthread
LD_FLAGS	:= -l$(LIBRARY)


SOURCE	:= 1-hello-world.cpp
OBJECT	:=
TARGET	:= xy-multithread

.PHONE: all, target, clean, run
all:
	@$(MAKE) clean	--no-print-directory
	@$(MAKE) target	--no-print-directory
	@$(MAKE) run	--no-print-directory

target:
	@echo
	@echo -e "[+] make target"
	$(CXX) $(CXX_FLAGS) $(INCLUDE_PATH) -o $(TARGET) $(SOURCE) $(LD_FLAGS)
clean:
	@echo
	@echo -e "[+] make clean"
	rm -fr $(TARGET)
run:
	@echo
	@echo -e "[+] make run"
	./$(TARGET)
	@echo
