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
    int driver_id;
    vector<Travel> travels;
    vector<Mission *> missions;
    vector<map<string, string>> completed_missions;
    vector<map<string, string>> all_missions;

public:
    int get_driver_id() { return driver_id; };
    vector<map<string, string>> get_completed_missions();
    vector<map<string, string>> get_all_missions();

    void set_new_mission(Mission *mission) { missions.push_back(mission); };
    void set_driver_id(int driver_id_) { driver_id = driver_id_; };
    void set_new_travel(Travel travel) { travels.push_back(travel); };

    void clear_last_travel() { travels.pop_back(); };
    void clear_completed_missions() { completed_missions.resize(0); };

    bool is_mission_repeated(Mission *mission);
    bool is_a_mission_completed();
};
