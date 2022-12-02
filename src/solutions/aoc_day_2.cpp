#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include "aoc_day_2.h"
#include "file_utils.h"
#include "map"

using namespace std;

AocDay2::AocDay2():AocDay(2)
{
}

AocDay2::~AocDay2()
{
}

auto AocDay2::read_input(string filename)
{
    FileUtils fileutils;
    vector<string> raw_lines;
    vector<string> data;
    if (!fileutils.read_as_list_of_strings(filename, raw_lines))
    {
        cerr << "Error reading in the data from " << filename << endl;
        return data;
    }
    for (auto iter = raw_lines.begin(); iter != raw_lines.end(); ++iter)
    {
        //long l;
        //string to_convert = *data;
        //l = strtol(to_convert.c_str(), NULL, 10);
        data.push_back(*iter);
    }
    return data;
}
string AocDay2::part1(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    long score = 0;
    std::map<string,long> scoreMap {
	 {"A X", 1+3},
	 {"A Y", 2+6},
	 {"A Z", 3+0},
	 {"B X", 1+0},
	 {"B Y", 2+3},
	 {"B Z", 3+6},
	 {"C X", 1+6},
	 {"C Y", 2+0},
	 {"C Z", 3+3}
    };
    for (int i=0;i<data.size();i++)
    {
        score+=scoreMap[data[i]];
    }
    ostringstream out;
    out << score;
    return out.str();
}

string AocDay2::part2(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    std::map<string,string> shapeMap {
	 {"A X", "A Z"},
	 {"A Y", "A X"},
	 {"A Z", "A Y"},
	 {"B X", "B X"},
	 {"B Y", "B Y"},
	 {"B Z", "B Z"},
	 {"C X", "C Y"},
	 {"C Y", "C Z"},
	 {"C Z", "C X"},
    };
    for (int i=0;i<data.size();i++) {
        data[i]=shapeMap[data[i]];
    }
    long score = 0;
    std::map<string,long> scoreMap {
         {"A X", 1+3},
         {"A Y", 2+6},
         {"A Z", 3+0},
         {"B X", 1+0},
         {"B Y", 2+3},
         {"B Z", 3+6},
         {"C X", 1+6},
         {"C Y", 2+0},
         {"C Z", 3+3}
    };
    for (int i=0;i<data.size();i++) {
        score+=scoreMap[data[i]];
    }
    ostringstream out;
    out << score;
    return out.str();
}
