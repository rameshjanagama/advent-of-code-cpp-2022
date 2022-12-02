#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include "aoc_day_3.h"
#include "file_utils.h"
#include "set"

using namespace std;

AocDay3::AocDay3():AocDay(3)
{
}

AocDay3::~AocDay3()
{
}

vector<long> AocDay3::read_input(string filename)
{
    FileUtils fileutils;
    vector<string> raw_lines;
    vector<long> data;
    if (!fileutils.read_as_list_of_strings(filename, raw_lines))
    {
        cerr << "Error reading in the data from " << filename << endl;
        return data;
    }
    for (vector<string>::iterator iter = raw_lines.begin(); iter != raw_lines.end(); ++iter)
    {
        long l;
        string to_convert = *iter;
        l = strtol(to_convert.c_str(), NULL, 10);
        data.push_back(l);
    }
    data.push_back(0);
    return data;
}

string AocDay3::part1(string filename, vector<string> extra_args)
{
    vector<long> data = read_input(filename);
    long sum = 0;
    long max = 0;
    for (vector<long>::iterator iter = data.begin(); iter != data.end(); ++iter)
    {
        if  (*iter != 0){
           sum+=*iter;
        }
        else {
           max=std::max(max,sum);
           sum=0;
	}

    }
    ostringstream out;
    out << max;
    return out.str();
}

string AocDay3::part2(string filename, vector<string> extra_args)
{
    if (extra_args.size() > 0)
    {
        cout << "There are " << extra_args.size() << " extra arguments given:" << endl;
        for (vector<string>::iterator iter = extra_args.begin(); iter != extra_args.end(); ++iter)
        {
            cout << "[" << *iter << "]" << endl;
        }
    }
    
    vector<long> data = read_input(filename);

    long sum = 0;
    std::vector<long> vec{0,0,0};
    for (vector<long>::iterator iter = data.begin(); iter != data.end(); ++iter)
    {
        if  (*iter != 0){
           sum+=*iter;
        }
        else 
	{
           vec.push_back(sum);
           sum=0;
        }

    }
    std::sort(vec.rbegin(),vec.rend());
    ostringstream out;
    out << vec[0]+vec[1]+vec[2];
    return out.str();
}
