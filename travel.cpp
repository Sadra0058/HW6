#include "travel.hpp"

using namespace std;

const int MIN = 60;

void Travel::set_travel_time(int start_timestamp_ , int end_timestamp_)
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

void Travel::set_travel_distance(int distance_)
{
    if (distance_ < 0)
    {
        throw runtime_error("INVALID_ARGUMENTS");
    }
    distance = distance_;
}

Travel::Travel(int start_timestamp_ , int end_timestamp_ , int distance_)
{
    set_travel_time(start_timestamp_ , end_timestamp_);
    set_travel_distance(distance_);
}

int Travel::get_total_min(int start , int end)
{
    int total_min = 0;
    if (start_timestamp < end && end_timestamp > start)
    {        
        if (end_timestamp <= end)
        {
            if (start_timestamp >= start)
                total_min = (end_timestamp - start_timestamp) / MIN;
            else
                total_min = (end_timestamp - start)/ MIN;
        }
        else
        {
            if (start_timestamp >= start)
                total_min = (end - start_timestamp) /MIN ;
            else
                total_min = (end - start) / MIN;
        }
    }
    return total_min;
}