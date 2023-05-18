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

using namespace std;

class Travel
{
private:
    int start_timestamp;
    int end_timestamp;
    int distance;

public:
    Travel(int start_timestamp_ , int end_timestamp_ , int distance_);
    void set_travel_time(int start_timestamp_ , int end_timestamp_);
    void set_travel_distance(int distance_);

    int get_total_min(int start , int end);
    int get_start_timestamp() {return start_timestamp;};
    int get_end_timestamp() {return end_timestamp;};
    int get_distance() {return distance;};
};
