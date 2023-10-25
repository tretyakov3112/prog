#pragma once
#include<iostream>
#include <random>
#include <algorithm>


class Dice {
public:
    Dice(unsigned max, unsigned seed): reng(seed), dstr(1, max) { }

    virtual unsigned choice() const {
        return dstr(reng);
    }

private:
    mutable std::default_random_engine reng;
    mutable std::uniform_int_distribution<unsigned> dstr;
    friend class DiceWithBonus;
};


class DiceWithBonus : public Dice {
public:
    DiceWithBonus(unsigned max, unsigned seed): Dice(max, seed), max(max) { }

    unsigned choice() const override {
        return std::min(max, dstr(reng) + 1);
    }

private:
    unsigned const max;
    
};


double expected_value(Dice const &d, unsigned number_of_rolls = 1) {
    auto accum = 0ull;
    for (int cnt = 0; cnt != number_of_rolls; ++cnt)
        accum += d.choice();
    return static_cast<double>(accum) / static_cast<double>(number_of_rolls);   
}

int main() {
    Dice d2(2, 1);
    DiceWithBonus d2_bonus(2, 1);
    auto ev = expected_value(d2, 10000);
    auto ev_bonus = expected_value(d2_bonus, 10000);
    std::cout << ev << ' ' << ev_bonus << std::endl;
    return 0;
}