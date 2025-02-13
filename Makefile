# Target to build the final executable
bin/encodeProject: obj/main.o obj/fileIo.o obj/binary_to_asm.o
	gcc obj/main.o obj/fileIo.o obj/binary_to_asm.o -o bin/encodeProject

# Rule for implementation.o
obj/implementation.o: src/implementation.c inc/encodeInput.h
	gcc -c src/implementation.c -Iinc -o obj/implementation.o

# Rule for fileIo.o
obj/fileIo.o: src/fileIo.c inc/fileIo.h
	gcc -c src/fileIo.c -Iinc -o obj/fileIo.o

# Rule for binary_to_asm.o
obj/binary_to_asm.o: src/binary_to_asm.c inc/binary_to_asm.h
	gcc -c src/binary_to_asm.c -Iinc -o obj/binary_to_asm.
	
# Rule for command_parser.o
obj/command_parser.o: src/command_parser.c inc/command_parser.h
	gcc -c src/command_parser.c -Iinc -o obj/command_parser.o

# Rule for encode.o
obj/encode.o: src/encode.c inc/encode.h
	gcc -c src/encode.c -Iinc -o obj/encode.o

# Rule for binary_to_srec.o
obj/encode.o: src/binary_to_srec.c inc/binary_to_srec.h
	gcc -c src/binary_to_srec.c -Iinc -o obj/binary_to_srec.o

# Default target to build everything
all: bin/encodeProject

# Clean up generated files
clean:
	rm -f obj/*.o bin/encodeProject
