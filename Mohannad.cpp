#include<iostream>
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
void check(char& letter)
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
    if (number == 0) AI_char = 'r';
    else if (number == 1) AI_char = 'p';
    else AI_char = 's';
    return AI_char;
}
void winner(char letter, string name)
{
    char AI_char = computer();
    if (letter != AI_char)
    {
        system("cls");
        if (AI_char == 'r' && letter == 'p')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.";
        }
        else if (AI_char == 'p' && letter == 'r')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.";
        }
        else if (AI_char == 'r' && letter == 's')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.";
        }
        else if (AI_char == 's' && letter == 'r')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.";
        }
        else if (AI_char == 'p' && letter == 's')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << name << " Wins.";
        }
        else if (AI_char == 's' && letter == 'p')
        {
            cout << "AI choice : " << AI_char << "\n\n";
            cout << "AI Wins.";
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
    return 0;
}
