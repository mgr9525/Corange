# This is zee makefile

CC=gcc

INCS= -I ./include
LIBS= -L ./lib

CFLAGS= $(INCS)
LFLAGS= $(LIBS) -lmingw32 -lSDLmain -lSDL -lSDL_Image -lopengl32 -mwindows

C_FILES= $(wildcard src/*.c)
OBJ_FILES= $(addprefix obj/,$(notdir $(C_FILES:.c=.o)))

corange.exe: $(OBJ_FILES)
	$(CC) -g $(OBJ_FILES) $(LFLAGS) -o $@

obj/%.o: src/%.c
	$(CC) $< -c -g $(CFLAGS) -o $@ 

clean:
	rm $(OBJ_FILES)