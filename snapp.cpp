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
    ADD_COUNT_MISSION,
    ASSIGN_MISSION,
    RECORD_RIDE
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

Mission *find_mission_by_id(vector<Mission> &missions, int id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i].get_mission_id() == id)
            return &missions[i];
    }
    return NULL;
}

Driver *find_driver_by_id(vector<Driver> &drivers, int id)
{
    for (int i = 0; i < drivers.size(); i++)
    {
        if (drivers[i].get_driver_id() == id)
            return &drivers[i];
    }
    return NULL;
}

bool is_mission_duplicate(vector<Mission> &missions, int id)
{
    if (find_mission_by_id(missions, id) == NULL)
        return false;
    return true;
}

void add_time_mission(vector<Mission> &missions, vector<int> inputs)
{
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
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
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
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
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
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

void assign_mission(vector<Mission> &missions, vector<Driver> &drivers, vector<int> inputs) // long function
{
    Mission *target_mission = find_mission_by_id(missions, inputs[0]);
    if (target_mission == NULL)
    {
        cout << "MISSION_NOT_FOUND" << endl;
        return;
    }
    Driver *target_driver = find_driver_by_id(drivers, inputs[1]);
    if (target_driver == NULL)
    {
        Driver driver;
        driver.set_driver_id(inputs[1]);
        driver.set_new_mission(*target_mission);
        drivers.push_back(driver);
    }
    else
    {
        if (target_driver->is_mission_repeated(*target_mission))
        {
            cout << "DUPLICATE_DRIVER_MISSION" << endl;
            return;
        }
        target_driver->set_new_mission(*target_mission);
    }
    cout << "--OK" << endl;
}

void init_new_travel(vector<Driver> &drivers, int driver_id, int start_timestamp, int end_timestamp, int distance)
{
    Driver *target_driver = find_driver_by_id(drivers, driver_id);
    if (target_driver == NULL)
    {
        throw runtime_error("DRIVER NOT FOUND");
    }
    Travel travel(start_timestamp, end_timestamp, distance);
    target_driver->set_new_travel(travel);
}

void record_ride(vector<Driver> &drivers, vector <int> input)
{
    try
    {
        init_new_travel(drivers, input[2], input[0] , input[1], input[3]);
        Driver *target_driver = find_driver_by_id(drivers, input[2]);
        if (!target_driver->is_a_mission_completed())
        {
            target_driver->clear_last_travel();
            cout << "nothing happend" << endl;
            return;
        }
        else
        {
            cout << "some missions completed" << endl;
            return;
        }
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
        return;
    }
}

// process input
int read_command_convert_to_int(string input)
{
    if (input == "add_time_mission")
        return ADD_TIME_MISSION;
    if (input == "add_distance_mission")
        return ADD_DISTANCE_MISSION;
    if (input == "add_count_mission")
        return ADD_COUNT_MISSION;
    if (input == "assign_mission")
        return ASSIGN_MISSION;
    if (input == "record_ride")
        return RECORD_RIDE;
    return -1;
}

void command_manager(int command, vector<Mission> &missions, vector<Driver> &drivers, vector<int> inputs)
{
    switch (command)
    {
    case ADD_TIME_MISSION:
        add_time_mission(missions, inputs);
        break;
    case ADD_DISTANCE_MISSION:
        add_distance_mission(missions, inputs);
        break;
    case ADD_COUNT_MISSION:
        add_count_mission(missions, inputs);
        break;
    case ASSIGN_MISSION:
        assign_mission(missions, drivers, inputs);
        break;
    case RECORD_RIDE:
        record_ride(drivers , inputs);
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

    void process(vector<Mission> &missions, vector<Driver> &drivers)
    {
        while (set_input())
        {
            if (value.size() != 0)
                command_manager(command, missions, drivers, value);
            else
                cout << "INVALID_ARGUMENTS" << endl;
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
    vector<Driver> drivers;

    Input input;
    input.process(missions, drivers);
}