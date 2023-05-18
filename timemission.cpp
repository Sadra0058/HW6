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
bool TimeMission::is_mission_complete(Travel travel)//
{
    total_time += travel.get_total_min(start_timestamp , end_timestamp);
    if (total_time >= target_time)
    {
        end = end_timestamp;
        complete = true;
    }
    return complete;
}

Mission * TimeMission::copy_mission()
{
    TimeMission * temp = new TimeMission(*this);
    return temp;
}