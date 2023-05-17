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
public:
    int get_driver_id() {return driver_id;};

    void set_new_mission(Mission * mission) {missions.push_back(mission);};
    void set_driver_id(int driver_id_) {driver_id = driver_id_;};
    void set_new_travel(Travel travel) {travels.push_back(travel);};
    
    void clear_last_travel() {travels.pop_back();};

    bool is_mission_repeated(Mission * mission);
    bool is_a_mission_completed();
};
