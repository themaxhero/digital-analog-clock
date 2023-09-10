#!/usr/bin/env sh

set -xe

rm -r ./build
mkdir -p ./build/
gcc \
	-mwindows \
	-mconsole \
	-Wall \
	-Wextra \
	-ggdb \
	-Llib/ \
       	-o ./build/rlGame.exe \
	./src/game.c \
	-lraylib \
	-lwinmm \
	-lgdi32 \
	-static
