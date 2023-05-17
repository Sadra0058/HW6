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


//complete methods
int DistanceMission::calculate_total_distance(vector<Travel> & travels)
{
    int total_distance = 0;
    for (int i = 0 ; i < travels.size() ; i++)
    {
        if (travels[i].get_start_timestamp() >= start_timestamp && travels[i].get_end_timestamp() <= end_timestamp)
        {
            total_distance += travels[i].get_distance();
        }
    }
    return total_distance;
} 

bool DistanceMission::is_mission_complete(vector<Travel> & travels)
{
    cout << "distance mission" << endl;
    if (calculate_total_distance(travels) >= target_distance)
    {
        complete = true;
    }
    return complete;
}