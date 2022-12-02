#ifndef __AOC_DAY_3__
#define __AOC_DAY_3__

#include "aoc_day.h"

class AocDay3 : public AocDay
{
    private:
        vector<long> read_input(string filename);
    public:
        AocDay3();
        ~AocDay3();
        string part1(string filename, vector<string> extra_args);
        string part2(string filename, vector<string> extra_args);
};


#endif
