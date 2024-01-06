#include <SFML/Graphics.hpp>
#include <string>
#include <bitset>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#define BOARDWIDTH 800
#define BOARDLENGTH 800

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
        long long int WP,WN,WB,WR,WQ,WK,BP,BN,BB,BR,BQ,BK;
        char chessBoard[8][8];
        void arraytoBitBoard();
        long long int convertStringToBitBoard(std::string bin_num);
        sf::RectangleShape RectArr[8][8]; //used for graphical purposes (drawing pieces at position, drawing game board)

        void initRectArr();

    public:
        Board(); //default constructor
        void Display_Board(); //test bitboard
        void DrawOnScreen(sf::RenderWindow & screen);
        
        

};



#endif