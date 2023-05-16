#pragma once

#include "mission.hpp"

using namespace std;

class DistanceMission : public Mission
{
private:
    int target_distance;

    void set_target_distance(int target_distance_)
    {
        if (target_distance_ < 0)
        {
            throw runtime_error("INVALID_ARGUMENTS");
        }
        target_distance = target_distance_;
    }

public:
    DistanceMission(int target_distance_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
        : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
    {
        set_target_distance(target_distance_);
    }
};
