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
#include "mission.hpp"
#include "timemission.hpp"
#include "distancemission.hpp"
#include "countmission.hpp"
#include "driver.hpp"

using namespace std;

vector<string> seperate_words(const string line, string separate_char);
Mission *find_mission_by_id(vector<Mission*> &missions, int id);
Driver *find_driver_by_id(vector<Driver> &drivers, int id);
bool is_mission_duplicate(vector<Mission*> &missions, int id);
void add_time_mission(vector<Mission*> &missions, vector<int> inputs);
void add_distance_mission(vector<Mission*> &missions, vector<int> inputs);
void add_count_mission(vector<Mission *> &missions, vector<int> inputs);
void assign_mission(vector<Mission*> &missions, vector<Driver> &drivers, vector<int> inputs);
void init_new_travel(vector<Driver> &drivers, int driver_id, int start_timestamp, int end_timestamp, int distance);
void record_ride(vector<Driver> &drivers, vector <int> input);
