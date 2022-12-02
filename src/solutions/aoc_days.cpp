#include <map>

#include "aoc_days.h"
#include "aoc_day.h"
// includes for each day will go here
#include "aoc_day_0.h"
#include "aoc_day_1.h"
#include "aoc_day_2.h"
#include "aoc_day_3.h"
#include "aoc_day_4.h"
#include "aoc_day_5.h"
#include "aoc_day_6.h"
#include "aoc_day_7.h"

using namespace std;

AocDays::AocDays()
{
    // adding each member to the map goes here
    m_days[0]=new AocDay0();
    m_days[1]=new AocDay1();
    m_days[2]=new AocDay2();
    m_days[3]=new AocDay3();
    m_days[4]=new AocDay4();
    m_days[5]=new AocDay5();
    m_days[6]=new AocDay6();
    m_days[7]=new AocDay7();
}

AocDays::~AocDays()
{
    // delete all of the days solutions
    for (map<int, AocDay *>::iterator days_iter = m_days.begin(); days_iter != m_days.end(); ++days_iter)
    {
        delete days_iter->second;
    }
    m_days.clear();
}

AocDay * AocDays::get_day(int day)
{
    return m_days[day];
}

