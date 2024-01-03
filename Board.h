#include <SFML/Graphics.hpp>
#define b
#ifndef b
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
        void convertStringToBitBoard(bin_num);

    public:
        Board(); //default constructor
        
        

};



#endif