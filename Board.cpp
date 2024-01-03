#include "Board.h"
#include <string.h>
Board::Board()
{
    //bitboards
    WP=0L,WN=0L,WB=0L,WR=0L,WQ=0L,WK=0L,BP=0L,BN=0L,BB=0L,BR=0L,BQ=0L,BK=0L;
    //chesssboard representation
    chessBoard={{'r','n','b','q','k','b','n','r'},
               {'p','p','p','p','p','p','p','p'},
               {' ',' ',' ',' ',' ',' ',' ',' ',},
               {' ',' ',' ',' ',' ',' ',' ',' ',},
               {' ',' ',' ',' ',' ',' ',' ',' ',},
               {' ',' ',' ',' ',' ',' ',' ',' ',},
               {'P','P','P','P','P','P','P','P'},
               {'R','N','B','Q','K','B','N','R'}}

}

Board::arraytoBitBoard() //convert current board into bitboards
{

    std::string binary;
    for(int i=0 ; i<64 ; i++)
    {
        Binary="0000000000000000000000000000000000000000000000000000000000000000"; //64 bit binary number

        switch (chessBoard[i/8][i%8])
        {
            case "P":
            break;
            case "N":
            break;
            case "B":
            break;
            case "R":
            break;
            case "Q":
            break;
            case "K":
            break;
            case "P":
            break;
            case "n":
            break;
            case "b":
            break;
            case "r":
            break;
            case "q":
            break;
            case "k":
            break;

            
        }
    }

    //1 generate string for piece, for start white r is "10000000100000000000000000000000000000"
    //2. Convert string into binary
    //3. assign number to board, numerical value irrelevent, binary relevent

}

Board:: convertStringToBitBoard(bin_num)
{

}