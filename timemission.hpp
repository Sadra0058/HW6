#pragma once

#include "mission.hpp"

using namespace std;

class TimeMission : public Mission
{
private:
    int target_time;

    void set_target_time(int target_time_)
    {
        if (target_time_ < 0)
        {
            throw runtime_error("INVALID_ARGUMENTS");
        }
        target_time = target_time_;
    }

public:
    TimeMission(int target_time_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
        : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
    {
        set_target_time(target_time_);
    }
};
