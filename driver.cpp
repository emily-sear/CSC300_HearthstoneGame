#include "Card.hpp"

int main(int argc, char** argv)
{
    Card* kingKrush = new Card("King Krush", 9, 8, 8);
    kingKrush->display();
    return 0;
}