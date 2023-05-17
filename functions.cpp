#include "functions.hpp"

using namespace std;

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

Mission *find_mission_by_id(vector<Mission *> &missions, int id)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (missions[i]->get_mission_id() == id)
            return missions[i];
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

bool is_mission_duplicate(vector<Mission *> &missions, int id)
{
    if (find_mission_by_id(missions, id) == NULL)
        return false;
    return true;
}

void add_time_mission(vector<Mission *> &missions, vector<int> inputs)
{
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
    try
    {
        TimeMission *tmp = new TimeMission(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void add_distance_mission(vector<Mission *> &missions, vector<int> inputs)
{
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
    try
    {
        DistanceMission *tmp = new DistanceMission(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void add_count_mission(vector<Mission *> &missions, vector<int> inputs)
{
    if (is_mission_duplicate(missions, inputs[0]))
    {
        cout << "DUPLICATE_MISSION_ID" << endl;
        return;
    }
    try
    {
        CountMission *tmp = new CountMission(inputs[3], inputs[1], inputs[2], inputs[4], inputs[0]);
        missions.push_back(tmp);
        cout << "OK" << endl;
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void assign_mission(vector<Mission *> &missions, vector<Driver> &drivers, vector<int> inputs) // long function
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
        driver.set_new_mission(target_mission);
        drivers.push_back(driver);
    }
    else
    {
        if (target_driver->is_mission_repeated(target_mission))
        {
            cout << "DUPLICATE_DRIVER_MISSION" << endl;
            return;
        }

        target_driver->set_new_mission(target_mission);
    }
    cout << "OK" << endl;
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

void print_completed_missions(Driver &driver)
{
    vector<map<string, string>> temp = driver.get_completed_missions();
    cout << "completed missions for driver " << driver.get_driver_id() << ':' << endl;
    for (int i = 0, ent = 1; i < temp.size(); i++, ent++)
    {
        cout << "mission " << temp[i]["mission"] << ':' << endl
             << "start timestamp: " << temp[i]["start timestamp"] << endl
             << "end timestamp: " << temp[i]["end timestamp"] << endl
             << "reward: " << temp[i]["reward"] << endl;
        if (ent < temp.size())
            cout << endl;
    }
    driver.clear_completed_missions();
}

void record_ride(vector<Driver> &drivers, vector<int> input)
{
    try
    {
        init_new_travel(drivers, input[2], input[0], input[1], input[3]);
        Driver *target_driver = find_driver_by_id(drivers, input[2]);

        if(!target_driver->is_a_mission_completed())
            target_driver->clear_last_travel();

        print_completed_missions(*target_driver);
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << endl;
        return;
    }
}

void print_all_missions(Driver &driver)
{
    vector<map<string, string>> temp = driver.get_all_missions();
    cout << "missions status for driver " << driver.get_driver_id() << ':' << endl;
    for (int i = 0, ent = 1; i < temp.size(); i++, ent++)
    {
        cout << "mission " << temp[i]["mission"] << ':' << endl
             << "start timestamp: " << temp[i]["start timestamp"] << endl
             << "end timestamp: " << temp[i]["end timestamp"] << endl
             << "reward: " << temp[i]["reward"] << endl
             << "status: " << temp[i]["status"] << endl;
        if (ent < temp.size())
            cout << endl;
    }
}

void show_missions_status(vector<Driver> &drivers, vector<int> input)
{
    Driver *target_driver = find_driver_by_id(drivers, input[0]);
    if (target_driver == NULL)
    {
        cout << "DRIVER_MISSION_NOT_FOUND" << endl;
        return;
    }
    print_all_missions(*target_driver);
}
