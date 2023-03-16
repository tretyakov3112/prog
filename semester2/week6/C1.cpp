#include <iostream>
using std::cout;
using std::cin;

struct Time {
    int hours;
    int minits;
    int seconds;
};

void print_time(Time time){
    cout << time.hours << ':' << time.minits << ':' << time.seconds;
}

bool greater(Time time1, Time time2) {
    if (time1.hours > time2.hours or time1.hours == time2.hours and 
    (time1.minits > time2.minits or time1.minits == time2.minits and time1.seconds >= time2.seconds)) return true;
    return false;
}

Time calculate_diff(Time begin, Time end) {
    if (!greater(end, begin)) end.hours += 24;
    Time diff;
    int sec_diff = 3600 * end.hours + 60 * end.minits + end.seconds - (3600 * begin.hours + 60 * begin.minits + begin.seconds);
    diff.seconds = sec_diff % 60;
    diff.minits = (sec_diff / 60) % 60;
    diff.hours = diff.minits / 60;
    return diff;
}

int main() {
	Time current_time;
	cin >> current_time.hours;
    cin >> current_time.minits;
    cin >> current_time.seconds;
    Time end_time;
	cin >> end_time.hours;
    cin >> end_time.minits;
    cin >> end_time.seconds;
	print_time(calculate_diff(current_time, end_time));
}