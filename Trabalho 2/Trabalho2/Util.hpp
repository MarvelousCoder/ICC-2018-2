#ifndef UTILHPP
#define UTILHPP

#include <vector>
#include <map>
#include <cmath>

using namespace std;

namespace Util {
    vector<int> getKeys(map<int, string> &m);
    vector<string> getValues(map<int,string> &m);

    inline float rad2deg(float rad){return rad * 180/3.14159265358979323846;}
    inline float deg2rad(float deg){return deg * 3.14159265358979323846/180.0;}

}

#endif // UTILHPP
