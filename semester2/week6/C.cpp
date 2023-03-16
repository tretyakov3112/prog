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

Time plus(Time time1, Time time2) {
    Time result;
    int sec_sum = 3600 * time1.hours + 60 * time1.minits + time1.seconds + (3600 * time2.hours + 60 * time2.minits + time2.seconds);
    result.seconds = sec_sum % 60;
    result.minits = (sec_sum / 60) % 60;
    result.hours = (sec_sum / 3600) % 24;
    return result;
}


int main() {
	Time current_time;
	cin >> current_time.hours;
    cin >> current_time.minits;
    cin >> current_time.seconds;
    Time time_to_end;
	cin >> time_to_end.hours;
    cin >> time_to_end.minits;
    cin >> time_to_end.seconds;
	print_time(plus(current_time, time_to_end));
}