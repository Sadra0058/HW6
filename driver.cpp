
#include "driver.hpp"

using namespace std;

bool Driver::is_mission_repeated(Mission *mission)
{
    for (int i = 0; i < missions.size(); i++)
    {
        if (mission->get_mission_id() == missions[i]->get_mission_id())
            return true;
    }
    return false;
}

bool Driver::is_a_mission_completed()
{
    bool result = false;
    for (int i = 0; i < missions.size(); i++)
    {
        if (!missions[i]->get_complete_status())
        {
            if (missions[i]->is_mission_complete(travels))
            {
                completed_missions.push_back(missions[i]->get_mission_completed_info());
                result = true;
            }
        }
    }
    return result;
}

bool compareByStartTime(const map<string, string>& map1, const map<string, string>& map2)
{
    return stoi(map1.at("start timestamp")) < stoi(map2.at("start timestamp"));
}

void sortByStartTime(vector<map<string, string>>& vecMap)
{
    sort(vecMap.begin(), vecMap.end(), compareByStartTime);
}

vector<map<string, string>> Driver::get_completed_missions()
{
   sortByStartTime(completed_missions);
   return completed_missions;
}

vector<map<string, string>> Driver::get_all_missions()
{
    vector<map<string, string>> temp;
    for (int i = 0 ; i < missions.size() ; i++)
    {
        temp.push_back(missions[i]->get_mission_info());
    }
    sortByStartTime(temp);
    return temp;
}