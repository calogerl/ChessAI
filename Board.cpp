#include "Board.h"
#include <string.h>
using
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
        binary="0000000000000000000000000000000000000000000000000000000000000000"; //64 bit binary number
        //need to add the concatenation method
        //not sure if this is correct for concatenation: can check later
        binary = binary.substr(i+1) + "1" + binary.substr(0, i); 
        switch (chessBoard[i/8][i%8])
        {
            case "P":
            WP += convertStringToBitBoard(binary);
            break;
            case "N":
            WN += convertStringToBitBoard(binary);
            break;
            case "B":
            WB += convertStringToBitBoard(binary);
            break;
            case "R":
            WR += convertStringToBitBoard(binary);
            break;
            case "Q":
            WQ += convertStringToBitBoard(binary);
            break;
            case "K":
            WK += convertStringToBitBoard(binary);
            break;
            case "p":
            BP += convertStringToBitBoard(binary);
            break;
            case "n":
            BN += convertStringToBitBoard(binary);
            break;
            case "b":
            BB += convertStringToBitBoard(binary);
            break;
            case "r":
            BR += convertStringToBitBoard(binary);
            break;
            case "q":
            BQ += convertStringToBitBoard(binary);
            break;
            case "k":
            BK += convertStringToBitBoard(binary);
            break;

            
        }
    }

    //1 generate string for piece, for start white r is "10000000100000000000000000000000000000"
    //2. Convert string into binary
    //3. assign number to board, numerical value irrelevent, binary relevent

}
// will have to doule check the functionality of this
int Board:: convertStringToBitBoard(bin_num)
{
    if (binary[0] == '0')
    {
        return std::stol(bin_num, 2); //binary number string, radix 2;
    }
    else
    {
        return std::stol("1" + bin_num.substr(2), 2)*2; // 1 represents negative number, taking 2's complement.
    }
}