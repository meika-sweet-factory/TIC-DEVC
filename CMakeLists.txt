cmake_minimum_required(VERSION 3.7)
project(snake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Headers/chain/file.h
        Headers/chain/pile.h
        Headers/helpers/print.h
        Headers/helpers/random.h
        Headers/helpers/string.h
        Headers/helpers/type.h
        Headers/structures/game.h
        Headers/structures/geometry.h
        Headers/structures/player.h
        Headers/structures/type.h
        Headers/file.h
        Headers/game.h
        Headers/map.h
        Headers/memory.h
        Headers/player.h
        Ressources/map.txt
        Sources/chain/file.c
        Sources/chain/pile.c
        Sources/helpers/print.c
        Sources/helpers/random.c
        Sources/helpers/string.c
        Sources/helpers/type.c
        Sources/file.c
        Sources/game.c
        Sources/main.c
        Sources/map.c
        Sources/memory.c
        Sources/player.c)

add_executable(snake ${SOURCE_FILES})