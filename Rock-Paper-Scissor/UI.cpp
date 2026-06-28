#include <iostream>
#include"player.cpp"
#include"AI.cpp"
#include"organizer.cpp"
using namespace std;
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