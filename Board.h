#include <SFML/Graphics.hpp>
#include <string>
#include <bitset>
#include <iostream>

#ifndef b
#define b

class Board 
{
    private:
        int screen_width;
        int screen_height;
        sf::Texture Black;
        sf::Texture brown;
        //bitboards
        long int WP,WN,WB,WR,WQ,WK,BP,BN,BB,BR,BQ,BK;
        char chessBoard[8][8];
        void arraytoBitBoard();
        int convertStringToBitBoard(std::string bin_num);


    public:
        Board(); //default constructor
        void Display_Board();
        
        

};



#endif