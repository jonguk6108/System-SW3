#include "time.h"
#include <iostream>
#include <cassert>

//Constructor
Time::Time(unsigned h, unsigned m, unsigned s, bool is_negative)
{
    hour = h;
    minute = m;
    second = s;

    assert( (m >= 0) && (m < 60) && "Mintue must be between 0 ~ 59!");
    assert( (s >= 0) && (s < 60) && "Second must be between 0 ~ 59!" );

    sign = is_negative;
}

//Convert HH:MM:SS -> total seconds
long long Time::get_total_second() {
    long long time = hour * 60 * 60 + minute * 60 + second;

    if (sign) return -time;
    else return time;
}

//Convert total seconds -> Time Class
Time second_to_time(long long sec)
{
    long long abs;
    unsigned h, m, s;

    if (sec < 0) abs = -1 * sec;
    else abs = sec;

    s = abs % 60;
    abs = abs / 60;

    m = abs % 60;
    h = abs / 60;

    Time result = Time(h, m, s, (sec < 0));

    return result;
}

void Time::print()
{
    using namespace std;

    if (sign) cout << "- ";

    cout << hour << ":" << minute << ":" << second << endl;
}

Time Time::operator + (Time rhs) {
    Time result  = second_to_time(get_total_second() + rhs.get_total_second() );

    return result;
    //TODO : Time lhs + Time rhs
}

Time Time::operator - (Time rhs) {
    Time result  = second_to_time(get_total_second() - rhs.get_total_second() );
    return result;
    //TODO : Time lhs - Time rhs
}

void Time::operator += (Time rhs) {
    *this = *this + rhs;
}

void Time::operator -= (Time rhs) {
    *this = *this - rhs;
    //TODO : *this - rhs;
}

bool Time::operator == (Time rhs) {
    return get_total_second() == rhs.get_total_second();
    //TODO : if (lhs == rhs) return true; else return false;
}

bool Time::operator > (Time rhs) {
    return get_total_second() > rhs.get_total_second();
    //TODO : if (lns > rhs) return true; else return false;
}

bool Time::operator < (Time rhs) {
    return get_total_second() < rhs.get_total_second();
    //TODO : if (lhs < rhs) return true; else return false;
}

bool Time::operator >= (Time rhs) {
    return get_total_second() >= rhs.get_total_second();
    //TODO : if (lhs >= rhs) return true; else return false;
}

bool Time::operator <= (Time rhs) {
    return get_total_second() <= rhs.get_total_second();
    //TODO : if (lsh <= rhs) return true; else return false;
}

Time Time::operator + (long long rhs) {
    Time result = second_to_time(get_total_second() + rhs);
    return result;
    //TODO : return Time lhs + rhs[second]
}

Time operator -(Time lhs, long long rhs)
{
    Time result = second_to_time(lhs.get_total_second() - rhs);
    return result;

    //TODO : return lhs - rhs[s]
}

Time operator -(long long lhs, Time rhs)
{
    Time result = second_to_time(lhs - rhs.get_total_second());
    return result;
    //TODO : return rhs[s] - lhs
}
