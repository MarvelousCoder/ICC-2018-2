#!/bin/bash

    cd ../../
    cp -r T1/ T1-submit-cmake
    cd T1-submit-cmake
    rm -rf .git 
    rm -rf .idea
    rm -rf bin
    rm -rf res/
    rm -rf sh/
    rm -rf specs/
    cd ..
    zip -r 110032829_$1.zip T1-submit-cmake
    rm -rf T1-submit-cmake

