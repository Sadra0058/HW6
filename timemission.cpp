#include "timemission.hpp"

using namespace std;

const int MIN = 60;

void TimeMission::set_target_time(int target_time_)
{
    if (target_time_ < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    target_time = target_time_;
}

TimeMission::TimeMission(int target_time_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
    : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
{
    set_target_time(target_time_);
}

//mission complete methods
int TimeMission::calculate_total_min(vector<Travel> &travels)
{
    int total_min = 0;
    for (int i = 0; i < travels.size(); i++)
    {
        total_min += travels[i].get_total_min(start_timestamp , end_timestamp); 
    }
    return total_min;
}

bool TimeMission::is_mission_complete(vector<Travel> &travels)//
{
    if (calculate_total_min(travels) >= target_time)
    {
        complete = true;
    }
    return complete;
}

Mission * TimeMission::copy_mission()
{
    TimeMission * temp = new TimeMission(*this);
    return temp;
}