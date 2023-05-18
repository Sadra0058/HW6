#include "functions.hpp"

class Input
{
public:
    bool set_input();
    void input_clear();
    void process(vector<Mission*> &missions, vector<Driver *> &drivers);

private:
    int command;
    vector<int> value;
};

int read_command_convert_to_int(string input);
void command_manager(int command, vector<Mission*> &missions, vector<Driver *> &drivers, vector<int> inputs);


