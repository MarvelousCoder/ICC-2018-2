#!/bin/bash

    cd ../../
    cp -r T1/ T1-submit-cmake
    cd T1-submit-cmake
    rm .git 
    rm -rf bin
    rm -rf specs/
    rm -rf sh/
    cd ..
    zip -r 110032829.zip T1-submit-cmake
    rm -rf T1-submit-cmake

