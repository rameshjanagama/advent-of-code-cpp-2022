#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include "aoc_day_6.h"
#include "file_utils.h"
#include "set"

using namespace std;

AocDay6::AocDay6():AocDay(6)
{
}

AocDay6::~AocDay6()
{
}

vector<string> AocDay6::read_input(string filename)
{
    FileUtils fileutils;
    vector<string> raw_lines;
    vector<string> data;
    if (!fileutils.read_as_list_of_strings(filename, raw_lines))
    {
        cerr << "Error reading in the data from " << filename << endl;
        return data;
    }
    for (vector<string>::iterator iter = raw_lines.begin(); iter != raw_lines.end(); ++iter)
    {
        data.push_back(*iter);
    }
    return data;
}

bool AocDay6::uniqueCharacters(string str)
{
    for (int i = 0; i < str.length() - 1; i++) {
        for (int j = i + 1; j < str.length(); j++) {
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}

string AocDay6::part1(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    std::string in = data[0];

    long pos = 0;
    for (int i=0;i<in.size()-4;i++){
       if(uniqueCharacters(in.substr(i,4))){
             pos= i+4;
             break;
       }
    }

    ostringstream out;
    out << pos;
    return out.str();
}

string AocDay6::part2(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    std::string in = data[0];

    long pos = 0;
    for (int i=0;i<in.size()-14;i++){
       if(uniqueCharacters(in.substr(i,14))){
             pos= i+14;
             break;
       }
    }

    ostringstream out;
    out << pos;
    return out.str();
}
