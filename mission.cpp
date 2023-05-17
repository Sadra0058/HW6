#include "mission.hpp"

using namespace std;

Mission::Mission(int start_timestamp_, int end_timestamp_, int reward, int mission_id_)
{
    set_mission_time(start_timestamp_, end_timestamp_);
    set_mission_reward(reward);
    set_mission_id(mission_id_);
    complete = false;
}

void Mission::set_mission_time(int start_timestamp_, int end_timestamp_)
{
    if (end_timestamp_ <= start_timestamp_)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    if (end_timestamp_ < 0 || start_timestamp_ < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    start_timestamp = start_timestamp_;
    end_timestamp = end_timestamp_;
}

void Mission::set_mission_reward(int reward)
{
    if (reward < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    reward_amount = reward;
}

map<string, string> Mission::get_mission_completed_info()
{
    map<string, string> temp;
    temp["mission"] = to_string(mission_id);
    temp["start timestamp"] = to_string(start_timestamp);
    temp["end timestamp"] = to_string(end);
    temp["reward"] = to_string(reward_amount);
    return temp;
}

map<string, string> Mission::get_mission_info()
{
    map<string, string> temp = get_mission_completed_info();
    if (!complete)
        temp["status"] = "ongoing";
    else
        temp["status"] = "completed";
    return temp;
}