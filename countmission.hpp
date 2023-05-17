#pragma once

#include "mission.hpp"

using namespace std;


class CountMission : public Mission
{
private:
    int target_number;

    void set_target_number(int target_number_);
    int calculate_total_travels(vector<Travel> & travels);

public:
    CountMission(int target_number_, int start_timestamp_, int end_timestamp_, int reward, int mission_id_);
    bool is_mission_complete(vector<Travel> & travels) override;
};
