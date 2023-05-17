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

#include "travel.hpp"

using namespace std;

class Mission
{
protected:
    int mission_id;
    int start_timestamp;
    int end_timestamp;
    int reward_amount;
    bool complete = false;

public:
    Mission(int start_timestamp_, int end_timestamp_, int reward, int mission_id_);
    void set_mission_time(int start_timestamp_, int end_timestamp_);
    void set_mission_reward(int reward);
    void set_mission_id(int mission_id_) { mission_id = mission_id_;};
    
    virtual bool is_mission_complete(vector<Travel> & travels){ cout << "mission" << endl;
        return false;};//

    int get_mission_id() {return mission_id;};
    bool get_complete_status() {return complete;};
};
