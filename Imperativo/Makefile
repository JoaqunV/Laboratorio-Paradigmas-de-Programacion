#Este es un archivo de ejemplo para compilar la lista
BIN               := fastClinic
CC                := gcc
LINKER            := gcc
C_SOURCES         := fastClinic.c
C_OBJS            := fastClinic.o
C_FLAGS           := -c

all: $(C_OBJS)
	$(CC) -o $(BIN) $(C_OBJS)

clear:
	rm -f $(BIN) *.o

debug: $(C_SOURCES)
	$(CC) -g -o $(BIN) $(C_SOURCES)

#Aqui se detalla cada uno de los archivos y sus dependencias. Colocar mas si corresponde
fastClinic.o : fastClinic.c funciones.h
	$(CC) $(C_FLAGS) fastClinic.c

#Es para asegurarse que no queden archivos no compilados
%.o : %.c
	$(CC) $(C_FLAGS) $< -o $@
