#compiler
CC=gcc
#Compiler Flags
CFLAG=-c -g
#O-flags
OFLAG=-o

#install the binary
INSTALL_PATH=../

#name of the taget
TAR_NAME=app

INCLUDE=-I./

SRC_DIR=/home/phytec/Linuxinternals/pro/make

CUR_DIR=.

app:app.o print.o add.o header.h
	$(CC) $^ $(OFLAG) $@
	@echo "Application binary generated"

app.o:app.c
	@echo "App.o generated"
	$(CC) $(INCLUDE) $(CFLAG) $^ $(OFLAG) $@

add.o:add.c
	@echo "add.o generated"
	$(CC) $(INCLUDE) $(CFLAG) $^ $(OFLAG) $@  

print.o:print.c
	@echo "print.o generated"
	$(CC) $(INCLUDE) $(CFLAG) $^ $(OFLAG) $@ 

install:$(TAR_NAME)
	cp -rf $(CUR_DIR)/$(TAR_NAME) $(INSTALL_PATH)
	@echo "Installed"

clean:
	rm -rf *.o $(CUR_DIR)/$(TAR_NAME) $(INSTALL_PATH)/$(TAR_NAME) 


