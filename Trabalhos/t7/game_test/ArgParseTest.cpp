//
// Created by jasf on 3/25/16.
//

#include "CommandLineParser.h"
#include "TestUtil.h"

#include <vector>
#include <string>

void basic_paser_test(){

    CommandLineParser clp;

    clp.addBoolArg("debug", false, false);
    clp.addIntArg("fps", true, 30);

    std::vector<std::string> argv = {"program_name", "debug", "fps", "30"};

    clp.parseCommandLine(argv);

    assert_equals(30, clp.getIntVal("fps"));
    assert_true(clp.getBoolVal("debug"));
    assert_not_equals(10, clp.getIntVal("fps"));
}


int main(){
    basic_paser_test();
}

