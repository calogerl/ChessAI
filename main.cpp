#include <SFML/Graphics.hpp>

#include "Board.h"
#define BOARDWIDTH 800
#define BOARDLENGTH 800

void draw_pieces(sf::RenderWindow window);
void load_pngs();





int main()
{
    sf::RenderWindow window(sf::VideoMode(BOARDLENGTH, BOARDWIDTH), "Chess");

    //load all texture global vars, must be global as need to persist throughout runtime, sprite usuage can be local to function
    sf::Texture WPawn;
    sf::Texture BPawn;
    sf::Texture WBishop;
    sf::Texture BBishop;
    sf::Texture WRook;
    sf::Texture BRook;
    sf::Texture WKnight;
    sf::Texture BKnight;
    sf::Texture WQueen;
    sf::Texture BQueen;
    sf::Texture WKing;
    sf::Texture BKing;
    WPawn.loadFromFile("./pawn.png");
    BPawn.loadFromFile("./pawn1.png");
    WBishop.loadFromFile("./bishop.png");
    BBishop.loadFromFile("./bishop1.png");
    WRook.loadFromFile("./rook.png");
    BRook.loadFromFile("./rook1.png");
    WKnight.loadFromFile("./knight.png");
    BKnight.loadFromFile("./knight1.png");
    WQueen.loadFromFile("./queen.png");
    BQueen.loadFromFile("./queen1.png");
    WKing.loadFromFile("./king.png");
    BKing.loadFromFile("./king1.png");

    Board GameBoard;
    GameBoard.Display_Board();

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) //true if there is an event in the event handler
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //clear previous contents

        GameBoard.DrawOnScreen(window);
       
        //draw new stuff
        window.display(); //display to screen
    }

    return 0;
}
