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

auto AocDay3::read_input(string filename)
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
        //long l;
        //string to_convert = *iter;
        //l = strtol(to_convert.c_str(), NULL, 10);
        data.push_back(*iter);
    }
    //data.push_back(0);
    return data;
}

string AocDay3::part1(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    long sum = 0;
    string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int d=0;d<data.size();d++){
       bool found=false;
       for ( int i=0;i<data[d].size() && i<data[d].size()/2 && !found;i++) {
         for ( int j=data[d].size()/2;j<data[d].size() && !found;j++) {
           if ( data[d][i] == data[d][j] ){
                sum+=(alpha.find_first_of(data[d][i])+1);
                found=true;
           }
         }
       }
    }
    ostringstream out;
    out << sum;
    return out.str();
}

string AocDay3::part2(string filename, vector<string> extra_args)
{
    auto data = read_input(filename);
    long sum = 0;
    string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int l=0;l<data.size();l=l+3){
    bool found=false;
    for (int i=0;i<data[l].size() && !found;i++){
       for (int j=0;j<data[l+1].size() && !found;j++){
         for (int k=0;k<data[l+2].size() && !found;k++){
            if ( data[l][i] == data[l+1][j] && data[l+1][j]==data[l+2][k]) {
               sum+=(alpha.find_first_of(data[l][i])+1);
               found=true;
            }
          }
        }
      }
    }

    ostringstream out;
    out << sum;
    return out.str();
}

