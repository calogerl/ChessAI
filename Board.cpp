#include "Board.h"

Board::Board()
{
    //bitboards
    WP=0L,WN=0L,WB=0L,WR=0L,WQ=0L,WK=0L,BP=0L,BN=0L,BB=0L,BR=0L,BQ=0L,BK=0L;
    //chesssboard representation, capital = white pieces
    chessBoard[0][0]='r', chessBoard[0][7]='r',chessBoard[7][0]='R',chessBoard[7][7]='R';
    chessBoard[0][1]='n',chessBoard[0][6]='n',chessBoard[7][1]='N',chessBoard[7][6]='N';
    chessBoard[0][2]='b',chessBoard[0][5]='b', chessBoard[7][2]='B',chessBoard[7][5]='B';
    chessBoard[0][3]='q',chessBoard[7][3]='Q';
    chessBoard[0][4]='k',chessBoard[7][4]='K';
    for ( int i = 1 ; i < 7 ; i++)
    {
        for( int j = 0 ; j < 8 ; j++ )
        {
            if ( i == 1)
            {
                chessBoard[i][j]='p';
            }
            else if ( i == 6)
            {
                chessBoard[i][j]='P';
            }
            else { chessBoard[i][j]=' '; }
            
        }
    }
    initRectArr();

    /*
                {'r','n','b','q','k','b','n','r'},
                {'p','p','p','p','p','p','p','p'},
                {' ',' ',' ',' ',' ',' ',' ',' '},
                {' ',' ',' ',' ',' ',' ',' ',' '},
                {' ',' ',' ',' ',' ',' ',' ',' '},
                {' ',' ',' ',' ',' ',' ',' ',' '},
                {'P','P','P','P','P','P','P','P'},
                {'R','N','B','Q','K','B','N','R'}   
*/
    
}

void Board::arraytoBitBoard() //convert current board into bitboards
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
            case 'P':
            WP += convertStringToBitBoard(binary);
            break;
            case 'N':
            WN += convertStringToBitBoard(binary);
            break;
            case 'B':
            WB += convertStringToBitBoard(binary);
            break;
            case 'R':
            WR += convertStringToBitBoard(binary);
            break;
            case 'Q':
            WQ += convertStringToBitBoard(binary);
            break;
            case 'K':
            WK += convertStringToBitBoard(binary);
            break;
            case 'p':
            BP += convertStringToBitBoard(binary);
            break;
            case 'n':
            BN += convertStringToBitBoard(binary);
            break;
            case 'b':
            BB += convertStringToBitBoard(binary);
            break;
            case 'r':
            BR += convertStringToBitBoard(binary);
            break;
            case 'q':
            BQ += convertStringToBitBoard(binary);
            break;
            case 'k':
            BK += convertStringToBitBoard(binary);
            break;

            
        }
    }

    //1 generate string for piece, for start white r is "10000000100000000000000000000000000000"
    //2. Convert string into binary
    //3. assign number to board, numerical value irrelevent, binary relevent

}
// will have to doule check the functionality of this
long long int Board:: convertStringToBitBoard(std::string bin_num)
{
    
    if (bin_num[0] == '0')
    {
        return std::stoll(bin_num, nullptr ,2); //binary number string, radix 2;
    }
    else
    {
        return std::stoll("1" + bin_num.substr(2), nullptr, 2)*2; // 1 represents negative number, taking 2's complement.
    }
}

void Board::Display_Board()
{

    arraytoBitBoard();

    std::cout << std::bitset<64>(BP).to_string() << std::endl;

    std::cout << std::bitset<64>(WP).to_string() << std::endl;

    std::cout << std::bitset<64>(BB).to_string() << std::endl;

    std::cout << std::bitset<64>(WB).to_string() << std::endl;

    std::cout << std::bitset<64>(BR).to_string() << std::endl;

    std::cout << std::bitset<64>(WR).to_string() << std::endl;

    std::cout << std::bitset<64>(BN).to_string() << std::endl;

    std::cout << std::bitset<64>(WN).to_string() << std::endl;

    std::cout << std::bitset<64>(BQ).to_string() << std::endl;

    std::cout << std::bitset<64>(WQ).to_string() << std::endl;

    std::cout << std::bitset<64>(BK).to_string() << std::endl;

    std::cout << std::bitset<64>(WK).to_string() << std::endl;

    
    char board[8][8]; //2d array of characters
    for( int i = 0 ; i < 64 ; i++ )
    {
        board[i/8][i%8] = ' ';
    }

    for( int i = 0 ; i < 64 ; i++ )
    {
        //check each bitboard for a 1 at current position
        if (std::bitset<64>(BP).to_string()[63-i] == '1') {board[i/8][i%8]='p';}

        if (std::bitset<64>(WP).to_string()[63-i] == '1') {board[i/8][i%8]='P';}

        if (std::bitset<64>(WB).to_string()[63-i] == '1') {board[i/8][i%8]='B';}

        if (std::bitset<64>(BB).to_string()[63-i] == '1') {board[i/8][i%8]='b';}

        if (std::bitset<64>(WN).to_string()[63-i] == '1') {board[i/8][i%8]='N';}

        if (std::bitset<64>(BN).to_string()[63-i] == '1') {board[i/8][i%8]='n';}

        if (std::bitset<64>(WR).to_string()[63-i] == '1') {board[i/8][i%8]='R';}

        if (std::bitset<64>(BR).to_string()[63-i] == '1') {board[i/8][i%8]='r';}

        if (std::bitset<64>(WQ).to_string()[63-i] == '1') {board[i/8][i%8]='Q';}
        
        if (std::bitset<64>(BQ).to_string()[63-i] == '1') {board[i/8][i%8]='q';}
 
        if (std::bitset<64>(WK).to_string()[63-i] == '1') {board[i/8][i%8]='K';}

        if (std::bitset<64>(BK).to_string()[63-i] == '1') {board[i/8][i%8]='k';}
    }
    for( int i = 0 ; i < 8; i++ )
    {
        std::cout << "\n {";
        for(int j =0 ; j< 8 ; j++)
        {
            std::cout << " " << board[i][j];
        }
        std::cout << "}\n";
    }
} 

void Board::initRectArr()
{
    for (int i = 0 ; i < 8 ; i++)
        {
            for (int j = 0 ; j < 8 ; j++)
            {
                double x= BOARDWIDTH/8*(i); 
                double y= BOARDLENGTH/8*(j); //middle of square
                //create rect object with color and position
                sf::RectangleShape rect(sf::Vector2f(100.0f, 100.f));
                rect.setPosition(x,y);
                rect.setOutlineThickness(1.f);
                rect.setOutlineColor(sf::Color(0,0,0));
                if ((i%2==0 && j%2!=0) || (i%2!=0 && j%2==0))
                {
                    rect.setFillColor(sf::Color(92, 64, 51));
                }
                else
                {
                    rect.setFillColor(sf::Color(196, 164, 132));
                }
                RectArr[i][j]=rect;
            }
        }  
}
void Board::DrawOnScreen(sf::RenderWindow & screen)
    {
        for (int i = 0 ; i < 8 ; i++)
        {
            for (int j = 0 ; j < 8 ; j++)
            {
                screen.draw(RectArr[i][j]);
            }
        }
    }


