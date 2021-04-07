
#pragma once

#include <string>
#include "Direction.hpp"
#include "Direction.hpp"
#include <map>
#include <limits>
using namespace std;
struct word{
    char note = '_';
};

namespace ariel {
    class Board {
        unsigned int up_boarder;
        unsigned int down_boarder;
        unsigned int right_boarder;
        unsigned int left_boarder;
        bool flag; //flag if the board is empty
        map<unsigned int, map<unsigned int, word> > mboard;

    public:
        Board() {
            right_boarder=0;
            left_boarder=std::numeric_limits<int>::max();
            up_boarder=0;
            down_boarder=std::numeric_limits<int>::max();
            flag = true;
            map<unsigned int, map<unsigned int, word> > mboard;
        }
        void post(unsigned int r, unsigned int c, Direction d, string m);
        string read(unsigned int r, unsigned int c, Direction d, unsigned int numToRead);
        void show();
        ~Board() {}
    };
}