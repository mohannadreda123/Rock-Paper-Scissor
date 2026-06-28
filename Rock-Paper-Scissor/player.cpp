#include <iostream>
using namespace std;
class Player
{
private:
    string name;
    char player_letter;
public:
    friend class UI;
    Player() {}
    Player(string name, char letter)
    {
        this->name = name;
        player_letter = letter;
    }
    char get_playerLetter()
    {
        return player_letter;
    }
};