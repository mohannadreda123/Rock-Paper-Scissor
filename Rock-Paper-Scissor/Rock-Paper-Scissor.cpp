#include <iostream>
#include <cstdlib>
#include <ctime>
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
class AI
{
private:
    char AI_letter;
public:
    friend class UI;
    void set_AIletter()
    {
        char AI_char;
        srand(time(0));
        int number = rand() % 3;
        if (number == 0) { AI_char = 'r'; }
        else if (number == 1) { AI_char = 'p'; }
        else { AI_char = 's'; }
        AI_letter = AI_char;
    }
    char get_AIletter()
    {
        return AI_letter;
    }
};
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
    void set_winner(Player player ,AI ai)
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
class UI
{
private:
    string name;
    char letter;
public:
    Player player;
    void Intro()
    {
        cout << "\n\n\t\t\t\t\t\tWelcome to Rock Paper Scissor\n\n";
        cout << "Game Roles\n\n";
        cout << "We have three scenarios\n\n";
        cout << "Rock vs Paper => Paper wins.\n\n";
        cout << "Paper vs scissor => Scissor wins.\n\n";
        cout << "Scissor vs Rock => Rock wins.\n\n";
    }
    void set_letter()
    {
        system("cls");
        char letter;
        cout << "Choose a Letter\n\n";
        cout << "r for Rock\n\n";
        cout << "p for Paper\n\n";
        cout << "s for Scissor\n\n";
        cout << "Enter letter => ";
        cin >> letter;
        cout << "\n";
        if (letter != 'r' && letter != 'p' && letter != 's')
        {
            do
            {
                cout << "invalid letter\n\n";
                cout << "Choose a valid letter\n\n";
                cout << "r for Rock\n\n";
                cout << "p for Paper\n\n";
                cout << "s for Scissor\n\n";
                cout << "Enter letter => ";
                cin >> letter;
                cout << "\n";
            } while (letter != 'r' && letter != 'p' && letter != 's');
        }
        this->letter = letter;
    }
    char get_letter()
    {
        return letter;
    }
    void set_name()
    {
        string name;
        cout << "Enter Player name : ";
        cin >> name;
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    void winner(Organizer org, AI ai)
    {
        system("cls");
        if (org.get_checker() == 'T')
        {
            cout << "Your choice : " << get_letter() << "\n\n";
            cout << "AI choice : " << ai.get_AIletter() << "\n\n";
            cout << get_name() << " Wins.\n\n";
        }
        else if (org.get_checker() == 'F')
        {
            cout << "Your choice : " << get_letter() << "\n\n";
            cout << "AI choice : " << ai.get_AIletter() << "\n\n";
            cout << "AI Wins.\n\n";
        }
        else
        {
            cout << "AI choice : " << ai.get_AIletter() << "\n\n";
            cout << "This round is draw\n\n";
        }
    }
    bool playagain(Organizer org)
    {
        string again;
        cout << "Do you want to play again?\n";
        cin >> again;
        for (int i = 0; i < again.size(); i++)
        {
            again[i] = tolower(again[i]);
        }
        if (again == "yes")
        {
            return true;
        }
        else
        {
            system("cls");
            cout << "\t\t\t\t\t\tGame Over!\n\n";
            cout << "\t\t\t\t\t\tFinal Score : \n\n";
            cout << "\t\t\t\t\t\t" << get_name() << " Score => " << org.get_playerScore() << "\n\n";
            cout << "\t\t\t\t\t\tAI Score => " << org.get_AIscore() << "\n\n";
            return false;
        }
    }
};
int main()
{
    UI ui;
    Organizer org;
    AI ai;
    ui.Intro();
    ui.set_name();
    do
    {
        ui.set_letter();
        ai.set_AIletter();
        Player player(ui.get_name(), ui.get_letter());
        org.set_winner(player, ai);
        ui.winner(org, ai);
    } while (ui.playagain(org));
    return 0;
}