#include "Card.hpp"

int main(int argc, char** argv)
{
    Card* kingKrush = new Card("King Krush", 9, 8, 8);
    kingKrush->display();

    Card* swordOfJustice = new Card("Sword of Justice", 3, 1, 5);
    swordOfJustice->display();

    Card* murlocKnight = new Card("Murloc Knight", 4, 3, 4);
    murlocKnight->display();

    Card* wandThief = new Card("Wand Thief", 1, 1, 2);
    wandThief->display();

    return 0;
}