

#include <iostream>
#include "Board.hpp"
using namespace std;
#define SHOW_SPACER 3
namespace ariel
{
    void adjust(unsigned int &r, unsigned int &c, Direction d)
    {
        if (d == Direction::Vertical)
        {
            r = r + 1;
        }
        else
        {
            c = c + 1;
        }
    }

    void Board::post(unsigned int r, unsigned int c, Direction d, string m)
    {
        if (flag)
        {
            if (d == Direction::Vertical)
            {
                right_boarder = c + m.length() + SHOW_SPACER;
                down_boarder = r + SHOW_SPACER;
            }
            else
            {
                right_boarder = c + SHOW_SPACER;
                down_boarder = r + m.length() + SHOW_SPACER;
            }
            if (c >= SHOW_SPACER)
            {
                left_boarder = c - SHOW_SPACER;
            }
            else
            {
                left_boarder = 0;
            }
            if (r >= SHOW_SPACER)
            {
                up_boarder = c - SHOW_SPACER;
            }
            else
            {
                up_boarder = 0;
            }
            flag = false;
        }
        if (right_boarder < c)

        {
            right_boarder = c;
        }
        if (left_boarder < c)
        {
            left_boarder = c;
        }
        if (up_boarder < r)
        {
            up_boarder = r;
        }
        if (down_boarder < r)
        {
            down_boarder = r;
        }
        for (char ch : m)
        {
            mboard[r][c].note = ch;
            adjust(r, c, d);
        }
    }

    string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int len)
    {
        string str;
        for (unsigned int i = 0; i < len; i++)
        {
            str = str + mboard[r][c].note;
            adjust(r, c, d);
        }
        return str;
    }

    void Board::show()
    {
        for (unsigned int i = down_boarder; i <= up_boarder; i++)
        {
            for (unsigned int j = left_boarder; j <= right_boarder; j++)
            {
                cout << mboard[i][j].note << "-";
            }
            cout << "\n";
        }
    }
}
