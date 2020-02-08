cmake_minimum_required(VERSION 3.16)
project(CardDeck    VERSION 1.0
                    DESCRIPTION "A library to make card games."
                    LANGUAGES CXX)

set(TARGET test)
set(EXECUTABLES 
    src/card.cpp
    src/deck.cpp
    src/player.cpp
    src/test.cpp
)

add_executable(${TARGET} ${EXECUTABLES})
target_include_directories(${TARGET} PUBLIC include)