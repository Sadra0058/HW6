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

class Mission
{
protected:
    int mission_id;
    int start_timestamp;
    int end_timestamp;
    int reward_amount;

public:
    Mission(int start_timestamp_, int end_timestamp_, int reward, int mission_id_);
    void set_mission_time(int start_timestamp_, int end_timestamp_);
    void set_mission_reward(int reward);
    void set_mission_id(int mission_id_) { mission_id = mission_id_;};
};
