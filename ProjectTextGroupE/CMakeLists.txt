cmake_minimum_required(VERSION 3.29)
project(VerifyTextString C)

set(CMAKE_C_STANDARD 11)

add_executable(VerifyTextString main.c
        endswith.c
        palindroma.c
        endswith.h
        palindroma.h
        splitString.h
        splitString.c
        lastMeeting.h
        lastMeeting.c
        formatNumeric.c
        formatNumeric.h
)

add_executable(main main.c
        endswith.c
        palindroma.c
        splitString.c
        lastMeeting.c
        formatNumeric.c
)