#include <iostream>
#include"player.cpp"
#include"AI.cpp"
using namespace std;
class Organizer
{
private:
    char checker;
    int player_Score = 0;
    int AI_Score = 0;
    bool validation;
public:
    int player_score = 0;
    int AI_score = 0;
    void set_winner(Player player, AI ai)
    {
        char check = ' ';
        if (player.get_playerLetter() != ai.get_AIletter())
        {
            if ((ai.get_AIletter() == 'r' && player.get_playerLetter() == 'p') ||
                (ai.get_AIletter() == 's' && player.get_playerLetter() == 'r') ||
                (ai.get_AIletter() == 'p' && player.get_playerLetter() == 's'))
            {
                player_score++;
                player_Score = player_score;
                check = 'T';
            }
            else if ((ai.get_AIletter() == 'p' && player.get_playerLetter() == 'r') ||
                (ai.get_AIletter() == 'r' && player.get_playerLetter() == 's') ||
                (ai.get_AIletter() == 's' && player.get_playerLetter() == 'p'))
            {
                AI_score++;
                AI_Score = AI_score;
                check = 'F';
            }
        }
        checker = check;
    }
    int get_playerScore()
    {
        return player_Score;
    }
    int get_AIscore()
    {
        return AI_Score;
    }
    char get_checker()
    {
        return checker;
    }
};