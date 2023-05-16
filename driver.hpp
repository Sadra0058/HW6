#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <iterator>

#include "mission.hpp"
#include "travel.hpp"

using namespace std;



class Driver
{
private:
    vector<Travel> travels;
    vector<Mission> missions;
};
