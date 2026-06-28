#include <iostream>
#include"player.cpp"
#include"AI.cpp"
#include"organizer.cpp"
#include"UI.cpp"
using namespace std;
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