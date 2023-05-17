struct SSBay {
    unsigned time_to_repair;  // время, необходимое для устранения неполадки, неотрицательное целое число
    SSBay * next_bay;         // указывает на отсек, в который может перейти ремонтная группа
};

#include <iostream>
#include <vector>

// функция формирует кольцо из отсеков по количеству отсеков и собранным данным о времени ремонта
SSBay* read_space_station(std::istream &is) {
    unsigned N;
    is >> N;
    SSBay *station = nullptr;
    for (unsigned cnt = 0; cnt != N; ++cnt) {
        auto bay = new SSBay{0, nullptr};
        if (nullptr == station) {
            bay->next_bay = bay;
        }
        else {
            bay->next_bay = station->next_bay;
            station->next_bay = bay;
        }
        station = bay;
        is >> bay->time_to_repair;
    }
    return station;
}

// функция освобождает память, выделенную под кольцо из отсеков
void erase_space_station(SSBay *station) {
    SSBay *current = station;
    while (current != current->next_bay) {
        auto extract = current->next_bay;
        current->next_bay = current->next_bay->next_bay;
        delete[] extract;
    }
    delete[] current;
}

unsigned min_time_to_repair(SSBay* station, unsigned L) {
    SSBay* start = station;
    std::vector<unsigned> time(L);
    unsigned sum = 0;
    unsigned got = 0;
    for (unsigned i = 0; i < L; ++i) {
        time[i] = station->time_to_repair;
        sum += time[i];
        station = station->next_bay;
    }
    unsigned ans = sum;
    unsigned start_ind = 0;
    while(true) {
        sum -= time[start_ind];
        time[start_ind] = station->time_to_repair;
        sum += time[start_ind];
        start_ind = (start_ind + 1) % L;
        ans = std::min(ans, sum);
        station = station->next_bay;
        if (station == start) {
            got += 1;
            if (got == 2) {
                break;
            }
        }
    }
    return ans;
}

#include <sstream>

bool test() {
    std::stringstream space_station_description("10 1 0 1 4 12 3 1 2 1 1");
    unsigned const number_to_repair = 5u;
    unsigned const expected = 4u;
    auto station = read_space_station(space_station_description);
    auto actual = min_time_to_repair(station, number_to_repair);
    erase_space_station(station);
    return actual == expected;  
}