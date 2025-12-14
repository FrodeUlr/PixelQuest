PROJECT_NAME = raylibtest

.PHONY: all build run clean format test lint doc

all: build run

build:
	@mkdir -p bin
	@cc -o ./bin/raylibtest -I./include src/*.c -L./lib -l:libraylib.a -lm
run:
	@./bin/raylibtest
