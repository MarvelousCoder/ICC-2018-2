#!/bin/bash

    cd ../../
    cp -r T1/ T1-submit
    cd T1-submit
    rm .git rm -rf cmake
    rm CMake*
    rm -rf game_test
    rm -rf res
    rm -rf bin
    rm game/CMake*
    rm -rf specs/
    rm -rf sh/

    cd ..
    zip -r 110032829.zip T1-submit
    rm -rf T1-submit

