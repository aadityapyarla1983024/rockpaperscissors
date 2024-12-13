#include <iostream>
#include <ctime>
using std::cout, std::cin, std::endl, std::string;

namespace score {
    int user = 0;
    int computer = 0;
}

int prompt();
void checker(int userguess, int computerguess);
int computerguess();
int wincheck();
int replay();

int main()
{

    cout << "***************************" << endl;
    cout << "    ROCK PAPER SCISSORS    " << endl;
    cout << "***************************" << endl;
    cout << "    3 point ka match       " << endl;
    cout << "\n";
    do {
        if (wincheck())
        {
            cout << "See you again, have a nice day" << endl;
            break;
        }
        
        int userguess = prompt();
        if (userguess != 4)
        {
            checker(userguess, computerguess());
            cout << "-------------------------------------------------" << endl;
        }
        else
        {
            cout << "Thank you , Have a nice day!" << endl;
            break;
        }
        
        
    } while (true);
    
    return 0;
}


int replay()
{
    int response;
    cout << "Wanna play again ? It'll be fun.." << endl;
    cout << "Yes -> 1, No -> 2" << endl;
    cout << "Your response: ";
    cin >> response;
    if (response == 1)
    {
        score::user = 0, score::computer = 0;
        return 0;
    }
    else if(response == 2)
    {
        return 1;
    }
    else
    {
        cout << "Enter a valid response from the above list" << endl;
        return replay();
    }

}

int wincheck()
{
    if (score::user == 3)
    {
        cout << "This was crazy!" << endl;
        return replay();
    }
    else if (score::computer == 3)
    {
        cout << "You are a looser!" << endl;
        return replay();
    }
    else 
    {
        return 0;
    }
    
}

int computerguess(){
    srand(time(0));
    return (rand() % 3 + 1);
}

void checker(int userguess, int computerguess) {
    if (computerguess == 1 && userguess == 1)
    {
        cout << "Rock" << endl;
        cout << "No luck!" << endl;
    }
    else if(computerguess == 2 && userguess == 2){
        cout << "Paper" << endl;
        cout << "No luck!" << endl;
    }
    else if(computerguess == 3 && userguess == 3){
        cout << "Scissors" << endl;
        cout << "No Luck!" << endl;
    }
    else if(computerguess == 1 && userguess == 2){
        cout << "Rock" << endl;
        cout << "Nooo!" << endl;
        score::user += 1;
    }
    else if(computerguess == 1 && userguess == 3){
        cout << "Rock" << endl;
        cout << "Lala Lala" << endl;
        score::computer += 1;
    }
    else if(computerguess == 2 && userguess == 1){
        cout << "Paper" << endl;
        cout << "That's my boi!" << endl;
        score::computer += 1;
    }
    else if(computerguess == 2 && userguess == 3){
        cout << "Paper" << endl;
        cout << "Ayyyy!" << endl;
        score::user += 1;
    }
    else if(computerguess == 3 && userguess == 1){
        cout << "Scissors" << endl;
        cout << "Ohh shit!" << endl;
        score::user += 1;
    }
    else if(computerguess == 3 && userguess == 2){
        cout << "Scissors" << endl;
        cout << "HeeeHeehaawhaaw" << endl;
        score::computer += 1;
    }
}


int prompt(){
    int userguess;
    cout << "Rock -> 1, Paper -> 2, Scissors -> 3, Exit -> 4" << endl;
    cout << "Computer: " << score::computer << " You: " << score::user << endl;
    cout << "\n";
    cout << "\n";
    cout << "Enter your guess: ";
    cin >> userguess;
    return userguess;
}