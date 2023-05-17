
#include "driver.hpp"

using namespace std;

bool Driver::is_mission_repeated(Mission mission)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (mission.get_mission_id() == missions[i].get_mission_id())
            return true;
    }
    return false;
}

bool Driver::is_a_mission_completed()
{
    bool result = false;
    for (int i = 0; i < missions.size(); i++)
    {
        if (!missions[i].get_complete_status())
        {
            if (missions[i].is_mission_complete(travels))
            {
                result = true;
            }
        }
    }
    return result;
}