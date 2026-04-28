#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void showpage()
{
    cout << "\n\n\t\t\t\t\t\tWelcome to Stone Paper Scissor\n\n";
    cout << "Game Roles\n\n";
    cout << "We have three scenarios\n\n";
    cout << "Rock vs Paper => Paper wins.\n\n";
    cout << "Paper vs scissor => Scissor wins.\n\n";
    cout << "Scissor vs Rock => Rock wins.\n\n";
}
void check(char &letter)
{
    if (letter != 'r' && letter != 'p' && letter != 's')
    {
        while (letter != 'r' && letter != 'p' && letter != 's')
        {
            system("cls");
            cout << "Choose a letter\n\n";
            cout << "r for Rock\n\n";
            cout << "p for Paper\n\n";
            cout << "s for Scissor\n\n";
            cout << "invalid letter\n\n";
            cout << "Enter letter => ";
            cin >> letter;
            cout << "\n";
        }
    }
}
char computer()
{
    char AI_char;
    srand(time(0));
    int number = rand() % 3;
    if (number == 0)
        AI_char = 'r';
    else if (number == 1)
        AI_char = 'p';
    else
        AI_char = 's';
    return AI_char;
}
int AI_score = 0;
int player_score = 0;
void score(int AI_score, int player_score, string name)
{
    cout << "\t\t\t\t\t\tTotal Score\n\n";
    cout << "\t\t\t\t\t\tAI Score => " << AI_score << "\n\n";
    cout << "\t\t\t\t\t\t" << name << " Score => " << player_score << "\n\n";
}
void winner(char letter, string name)
{
    char AI_char = computer();
    if (letter != AI_char)
    {
        system("cls");
        if (AI_char == 'r' && letter == 'p')
        {
            player_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.\n\n";
            score(AI_score, player_score, name);
        }
        else if (AI_char == 'p' && letter == 'r')
        {
            AI_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.\n\n";
            score(AI_score, player_score, name);
        }
        else if (AI_char == 'r' && letter == 's')
        {
            AI_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.\n\n";
            score(AI_score, player_score, name);
        }
        else if (AI_char == 's' && letter == 'r')
        {
            player_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.\n\n";
            score(AI_score, player_score, name);
        }
        else if (AI_char == 'p' && letter == 's')
        {
            player_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.\n\n";
            score(AI_score, player_score, name);
        }
        else if (AI_char == 's' && letter == 'p')
        {
            AI_score++;
            cout << "Your choice : " << letter << "\n\n";
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.\n\n";
            score(AI_score, player_score, name);
        }
    }
    else
    {
        system("cls");
        cout << "Choose letter\n\n";
        cout << "r for Rock\n\n";
        cout << "p for Paper\n\n";
        cout << "s for Scissor\n\n";
        cout << "AI choice : " << AI_char << "\n\n";
        cout << "This round is draw\n\n";
        cout << "Enter letter => ";
        cin >> letter;
        cout << "\n";
        check(letter);
        winner(letter, name);
    }
}
void game(string name)
{
    char letter;
    system("cls");
    cout << "Choose a letter\n\n";
    cout << "r for Rock\n\n";
    cout << "p for Paper\n\n";
    cout << "s for Scissor\n\n";
    cout << "Enter letter => ";
    cin >> letter;
    cout << "\n";
    check(letter);
    winner(letter, name);
}
bool checker = true;
void playagain(string name)
{
    string again = "yes";
    cout << "Do you want to play again?\n";
    cin >> again;
    if (again == "yes" || again == "Yes" || again == "YES")
    {
        game(name);
    }
    else
    {
        checker = false;
        system("cls");
        showpage();
    }
}
int main()
{
    // To increase (cin,cout) compilation process
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///////////////////////////////
    string name;
    showpage();
    cout << "Enter Player name : ";
    cin >> name;
    game(name);
    while (checker)
    {
        playagain(name);
    }
    return 0;
}