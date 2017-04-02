//
// Created by jasf on 3/16/16.
//

#include "Util.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class JTest {

public:
    static void run() {

        //test getkeys and getValues
        map<int, string> m{{1,"um"},{2,"dois"}};

        vector<int> keys = Util::getKeys(m);
        vector<string> values = Util::getValues(m);

        for(auto k : keys)
            cout << k << " ";

        cout << endl;

        for(auto v : values)
            cout << v << " ";
    }
};

int main() {

    JTest::run();
}

