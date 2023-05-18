#include "handle_inputs.hpp"

using namespace std;

enum
{
    ADD_TIME_MISSION,
    ADD_DISTANCE_MISSION,
    ADD_COUNT_MISSION,
    ASSIGN_MISSION,
    RECORD_RIDE,
    SHOW_MISSIONS_STATUS
};

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
    if (input == "show_missions_status")
        return SHOW_MISSIONS_STATUS;
    return -1;
}

void command_manager(int command, vector<Mission *> &missions, vector<Driver> &drivers, vector<int> inputs)
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
        record_ride(drivers, inputs);
        break;
    case SHOW_MISSIONS_STATUS:
        show_missions_status(drivers , inputs);
        break;
    }
}

bool Input::set_input()
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

void Input::input_clear()
{
    int command = 0;
    value.clear();
}

void Input::process(vector<Mission *> &missions, vector<Driver> &drivers)
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

int main()
{
    vector<Mission *> missions;
    vector<Driver> drivers;

    Input input;
    input.process(missions, drivers);
    //cerr << "end of main" << endl;
}
