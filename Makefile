all: call
.PHONY: all

libhello.so: shared.go
	go build -o $@ -buildmode=c-shared $<
call: call.c libhello.so
	gcc -Wall -ldl -o call call.c
clean:
	rm -f call libhello.so libhello.h


