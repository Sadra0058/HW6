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

enum
{
    ADD_TIME_MISSION,
    ADD_DISTANCE_MISSION,
    ADD_COUNT_MISSION
};

vector<string> seperate_words(const string line, string separate_char)
{
    vector<string> words;
    string temp = line;
    size_t pos = 0;
    while ((pos = temp.find(separate_char)) != string::npos)
    {
        words.push_back(temp.substr(0, pos));
        temp.erase(0, pos + separate_char.length());
    }
    words.push_back(temp);
    return words;
}

void add_time_mission(vector<Mission> &missions, vector<int> inputs)
{
    try
    {
        TimeMission tmp(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void add_distance_mission(vector<Mission> &missions, vector<int> inputs)
{
    try
    {
        DistanceMission tmp(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void add_count_mission(vector<Mission> &missions, vector<int> inputs)
{
    try
    {
        CountMission tmp(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

int read_command_convert_to_int(string input)
{
    if (input == "add_time_mission")
        return ADD_TIME_MISSION;
    if (input == "add_distance_mission")
        return ADD_DISTANCE_MISSION;
    if (input == "add_count_mission")
        return ADD_COUNT_MISSION;
    return -1;
}

void command_manager(int command , vector<Mission> & missions , vector<int> inputs)
{
    switch (command)
    {
    case ADD_TIME_MISSION:
        add_time_mission(missions , inputs);
        break;
    case ADD_DISTANCE_MISSION:
        add_distance_mission(missions , inputs);
        break;
    case ADD_COUNT_MISSION:
        add_count_mission(missions , inputs);
        break;
    }
}

class Input
{
public:
    bool set_input()
    {
        string line;
        getline(cin, line);
        vector<string> temp = seperate_words(line, " ");
        if (line == "")
            return false;
        int int_command = read_command_convert_to_int(temp[0]);
        command = int_command;
        for (int i = 1; i < temp.size(); i++)
            value.push_back(stoi(temp[i]));
        return true;
    }

    void input_clear()
    {
        int command = 0;
        value.clear();
    }

    void process(vector<Mission> &missions)
    {
        while (set_input())
        {
            command_manager(command , missions, value);
            input_clear();
        }
    }

private:
    int command;
    vector<int> value;
};

int main()
{
    vector<Mission> missions;
    //vector<Driver> drivers;
    Input input;
    input.process(missions);
}