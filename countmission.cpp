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

bool CountMission::is_mission_complete(Travel travel)
{
    if(travel.get_start_timestamp() >= start_timestamp && travel.get_end_timestamp() <=  end_timestamp)
    {
        total_number ++;
        if(total_number >= target_number)
        {
            end = travel.get_end_timestamp();
            complete = true;
        }
    }
    return complete;
}

Mission * CountMission::copy_mission()
{
    CountMission * temp = new CountMission(*this);
    return temp;
}