#include "countmission.hpp"

using namespace std;

void CountMission::set_target_number(int target_number_)
{
    if (target_number_ < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    target_number = target_number_;
}

CountMission::CountMission(int target_number_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
    : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
{
    set_target_number(target_number_);
}

int CountMission::calculate_total_travels(vector<Travel> & travels)
{
    int counter = 0;
    for (int i = 0 ; i < travels.size() ; i++)
    {
        if (travels[i].get_start_timestamp() >= start_timestamp && travels[i].get_end_timestamp() <=  end_timestamp)
        {
            counter++;
        }
    }
    return counter;
}

bool CountMission::is_mission_complete(vector<Travel> & travels)
{
    if (calculate_total_travels(travels) >= target_number)
    {
        complete = true;
    }
    return complete;
}