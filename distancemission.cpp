#include "distancemission.hpp"

using namespace std;

void DistanceMission::set_target_distance(int target_distance_)
{
    if (target_distance_ < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    target_distance = target_distance_;
}

DistanceMission::DistanceMission(int target_distance_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
    : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
{
    set_target_distance(target_distance_);
}

// complete methods
bool DistanceMission::is_mission_complete(Travel travel)
{
    if (travel.get_start_timestamp() >= start_timestamp && travel.get_end_timestamp() <= end_timestamp)
    {
        total_distance += travel.get_distance();
        if (total_distance >= target_distance)
        {
            end = travel.get_end_timestamp();
            complete = true;
            return true;
        }
    }
    return false;
}

Mission * DistanceMission::copy_mission()
{
    DistanceMission * temp = new DistanceMission(*this);
    return temp;
}