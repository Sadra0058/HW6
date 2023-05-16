#pragma once

#include "mission.hpp"

using namespace std;


class CountMission : public Mission
{
private:
    int target_number;

    void set_target_number(int target_number_)
    {
        if (target_number_ < 0)
        {
            throw runtime_error("INVALID_ARGUMENTS");
        }
        target_number = target_number_;
    }

public:
    CountMission(int target_number_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
        : Mission(start_timestamp_, end_timestamp_, reward, mission_id_)
    {
        set_target_number(target_number_);
    }
};
