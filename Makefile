CC=gcc
TEST_FLAG?=OFF
CFLAGS= -lm -D _DEBUG -ggdb3 -std=c11 -O0 -Wall -Wextra -Waggressive-loop-optimizations -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wopenmp-simd -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-varargs -Wstack-protector -fcheck-new -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Wvla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
FLAGS = -I ./src/headers
FILES=main.c tests.c prepare_data.c analysis_data.c accuracy_analysis_data.c
FILES_DIR=src
OBJECTS_DIR=build
SOURCES=$(addprefix $(FILES_DIR)/, $(FILES))
OBJECTS=$(addprefix $(OBJECTS_DIR)/, $(FILES:.c=.o))
EXECUTABLE=build/main

.PHONY: all run clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(FLAGS) $(CFLAGS) -o $@

$(OBJECTS_DIR)/%.o: $(FILES_DIR)/%.c $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -c $< $(FLAGS) -o $@

$(OBJECTS_DIR):
	mkdir ./build/

run: $(EXECUTABLE)
	cd ./build; ./main; cd ..

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
