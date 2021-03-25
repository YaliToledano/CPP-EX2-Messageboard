 

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#include "Board.hpp"

namespace ariel
{
        void Board::post(unsigned int row, unsigned int column, Direction direction, string message) {
        message = message + ",";
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int numToRead) {
        return "to be continued";
    }

    void Board::show() {
    }
};