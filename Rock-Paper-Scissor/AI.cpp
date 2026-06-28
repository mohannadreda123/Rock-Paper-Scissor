#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
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