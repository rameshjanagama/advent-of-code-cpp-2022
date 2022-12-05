#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>

#include "aoc_day_4.h"
#include "file_utils.h"
#include "set"

using namespace std;

AocDay4::AocDay4():AocDay(4)
{
}

AocDay4::~AocDay4()
{
}

auto AocDay4::split_string_to_nums(string str)
{
    vector<long> nums;
    cout << str << endl;
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found) {
            cout << found << " ";
            nums.push_back(found);
        }

        /* To save from space at the end of string */
        temp = "";
    }

    return nums;
}

// for string delimiter
vector<string> AocDay4::split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

auto AocDay4::read_input(string filename)
{
    FileUtils fileutils;
    vector<string> raw_lines;
    vector<vector<int> > data;
    if (!fileutils.read_as_list_of_strings(filename, raw_lines))
    {
        cerr << "Error reading in the data from " << filename << endl;
        return data;
    }
    for (vector<string>::iterator iter = raw_lines.begin(); iter != raw_lines.end(); ++iter)
    {
        vector<string> v=split(*iter,",");
        vector<string> v2=split(v[0],"-");
        vector<string> v3=split(v[1],"-");
        vector<int> v4{std::stoi(v2[0]),stoi(v2[1]),stoi(v3[0]),stoi(v3[1])};
        data.push_back(v4);
        /*auto v=split_string_to_nums(*iter);
        data.push_back(v);*/
    }
    return data;
}

string AocDay4::part1(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    long count = 0;
    for (auto v:data)
    {
       //std::cout << v[0] << "," << v[2] << "," << v[1] << "," <<  v[3] <<endl;
       if ( (v[0] <= v[2] && v[1] >= v[3] ) ||(v[2] <= v[0] && v[3] >= v[1])){
           //std::cout << " ==> matched " << endl;
           count++;
       }
    }
    ostringstream out;
    out << count;
    return out.str();
}

string AocDay4::part2(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    long count = 0;
    for (auto v:data)
    {
       //std::cout << v[0] << "," << v[1] << "," << v[2] << "," <<  v[3];
       if ( (v[0] <= v[2] && v[1] >= v[3] ) ||(v[2] <= v[0] && v[3] >= v[1])){
           //std::cout << " ==> contained " << endl;
           count++;
           continue;
       }
       else if ( (v[2]<=v[1] && v[0]<= v[3]) ){
           //std::cout << " ==> left overlapped " << endl;
           count++;
           continue;
       }
       //std::cout << "" << endl;
    }
    ostringstream out;
    out << count;
    return out.str();
}
