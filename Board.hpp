 
#pragma once

#include <string>
#include "Direction.hpp"
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        unsigned int size; //decided to make n*n array
    public:
        static void post( unsigned int row,  unsigned int column, Direction direction, string message);
        static string read( unsigned int row,  unsigned int column, Direction direction,  unsigned int numToRead);
        void show();
    };
}