#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace ariel;
using namespace std;


TEST_CASE("throw test") {
    Board board;

    CHECK_NOTHROW(board.post(23,12,Direction::Horizontal,"ok!boomer"));
    CHECK_NOTHROW(board.read(23,12,Direction::Horizontal,9));
    CHECK_NOTHROW(board.read(23,12,Direction::Horizontal,2));
    CHECK_NOTHROW(board.read(23,12,Direction::Horizontal,0));
    CHECK_NOTHROW(board.post(21,15,Direction::Vertical,"nnnn"));
    CHECK_NOTHROW(board.read(21,15,Direction::Vertical,4));
    CHECK_NOTHROW(board.read(21,15,Direction::Vertical,3));
    CHECK_NOTHROW(board.post(10000,541,Direction::Horizontal,"stonks"));
    CHECK_NOTHROW(board.read(10000,541,Direction::Horizontal,6));
    CHECK_NOTHROW(board.read(10003,541,Direction::Horizontal,3));
    CHECK_NOTHROW(board.show());
}

TEST_CASE("failed") {
    
}



TEST_CASE("Testing") {
    Board board;

    CHECK(board.read(10,10,Direction::Horizontal,1).compare("_"));
    CHECK(board.read(355,46,Direction::Horizontal,3).compare("___"));//checking if the board scaled
    CHECK_NOTHROW(board.post(6,8,Direction::Horizontal,"abcdef"));
    CHECK(board.read(6,8,Direction::Horizontal,6).compare("abcdef"));
    CHECK_NOTHROW(board.post(3,10,Direction::Vertical,"lmnop"));
    CHECK(board.read(3,10,Direction::Vertical,5).compare("lmnop"));
    CHECK(board.read(6,8,Direction::Horizontal,6).compare("abodef"));
    CHECK_NOTHROW(board.post(5555,3333,Direction::Vertical,"farfar"));
    CHECK(board.read(5555,3333,Direction::Vertical,6).compare("farfar"));
    //cheching edges
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"sssssss"));
    CHECK(board.read(0,4,Direction::Horizontal,5).compare("sss__"));
    CHECK_NOTHROW(board.post(0,2,Direction::Vertical,"ffff"));
    CHECK(board.read(0,4,Direction::Vertical,5).compare("ssf__"));
    //size 1 
    CHECK_NOTHROW(board.post(33,34,Direction::Horizontal,"y"));
    CHECK(board.read(33,34,Direction::Horizontal,1).compare("y"));
    CHECK_NOTHROW(board.post(5,5,Direction::Vertical,"k"));
    CHECK(board.read(5,5,Direction::Vertical,1).compare("k"));
    //empty check
    CHECK(board.read(33,34,Direction::Horizontal,1).compare(""));
    CHECK(board.read(5,5,Direction::Vertical,1).compare(""));
    board.show();

}