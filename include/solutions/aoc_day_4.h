#ifndef __AOC_DAY_4__
#define __AOC_DAY_4__

#include "aoc_day.h"

class AocDay4 : public AocDay
{
    private:
        auto read_input(string filename);
    public:
        AocDay4();
        ~AocDay4();
        auto split_string_to_nums(std::string);
        string part1(string filename, vector<string> extra_args);
        string part2(string filename, vector<string> extra_args);
        // for string delimiter
        vector<string> split (string s, string delimiter);
};


#endif
