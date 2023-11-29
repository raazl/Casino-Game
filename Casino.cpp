#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
using namespace std;
 
void drawLine(int n, char symbol);
void rules();
 
int main()
{
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
 
    srand(time(0)); // "Seed" the random generator

    drawLine(40,'_');
    cout << "\n\n\n\t\tCASINO\n\n\n\n";
    drawLine(40,'_');
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
 
    cout << "\n\nEnter Deposit amount to play game : Tk ";
    cin >> amount;
    
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is Tk " << amount << "\n";
		
		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter money to bet : Tk ";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter money\n ";
        }while(bettingAmount > amount);
 
		// Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 5 :";
            cin >> guess;
            if(guess <= 0 || guess > 5)
                cout << "Please check the number!! should be between 1 to 5\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 5);
 
        dice = rand()%5 + 1; // Will hold the randomly generated integer between 1 and 5
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Tk." << bettingAmount * 3;
            amount = amount + bettingAmount * 3;
        }
        else
        {
            cout << "Bad Luck this time !! You lost Tk "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have Tk " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing. Your balance amount is Tk " << amount << "\n\n";
    drawLine(70,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout <<endl ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tGAME RULES:\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 5"<<endl;
    cout << "\t2. If you win you will get 3x of money you bet"<<endl;
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
 
