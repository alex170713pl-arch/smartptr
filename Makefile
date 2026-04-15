SRC = ./src/
MODE ?= STATIC

# Выбор флагов в зависимости от MODE
ifeq ($(MODE), STATIC)
    CFLAGS = -c
    TARGET = libsptr.a
else ifeq($(MODE),DYNAMIC)
    CFLAGS = -c -fPIC
    TARGET = libsptr.so
endif

all: $(TARGET)

shared_ptr.o: $(SRC)shared_ptr.c
	@gcc $(CFLAGS) $< -o $@

one_owner.o: $(SRC)one_owner.c
	@gcc $(CFLAGS) $< -o $@

libsptr.a: one_owner.o shared_ptr.o
	@ar rcs $@ $^

libsptr.so: one_owner.o shared_ptr.o
	@gcc -shared -o $@ $^

clear:
	@rm -f *.o