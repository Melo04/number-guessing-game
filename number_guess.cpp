#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int totalSecrets = 4;
    int secret1, secret2, secret3, secret4;
    int guess1, guess2, guess3, guess4;
    char abort, restart, repeat;

    cout << "Let's Play!" << endl << endl;
    cout << "I have 4 secret numbers!" << endl;
    cout << "Each number is in range of 1 to 6." << endl;
    cout << "Repeating secret numbers? Type 'Y' for 'Yes' => ";
    cin >> repeat;
    if(repeat == 'Y'){
        srand(time(NULL));
        secret1 = rand() % 6 + 1;
        secret2 = rand() % 6 + 1;
        secret3 = rand() % 6 + 1;
        secret4 = rand() % 6 + 1;
    }else{
        bool validSecrets;
        do
        {
            secret1 = rand() % 6 + 1;
            secret2 = rand() % 6 + 1;
            secret3 = rand() % 6 + 1;
            secret4 = rand() % 6 + 1;
            if (secret1 == secret2 ||
                secret1 == secret3 ||
                secret1 == secret4 ||
                secret2 == secret3 ||
                secret2 == secret4 ||
                secret3 == secret4)
            {
                validSecrets = false;
            }
            else{
                validSecrets = true;
            }
        } while (!validSecrets);
    }

    bool win = false;
    int maxTrials;
    int trialNum = 1;
    cout << "Maximum number of trials => ";
    cin >> maxTrials;

    while (trialNum <= maxTrials)
    {
        cout << "\nTrial number = " << trialNum << endl;
        int totalCorrect = 0;
        int totalWrong = 0;
        cout << "Your guesses => ";
        cin >> guess1 >> guess2 >> guess3 >> guess4;
        cout << "guesses = " << guess1 << " " << guess2 << " " << guess3 << " " << guess4 << endl;

        if (guess1 == secret1){
            totalCorrect = totalCorrect + 1;
        }if (guess2 == secret2){
            totalCorrect = totalCorrect + 1;
        }if (guess3 == secret3){
            totalCorrect = totalCorrect + 1;
        }if (guess4 == secret4){
            totalCorrect = totalCorrect + 1;
        }else if((guess1 != secret1) && (guess1 == secret2 || guess1 == secret3 || guess1 == secret4)){
            totalWrong = 1;
        }else if((guess2 != secret2) && (guess2 == secret1 || guess2 == secret3 || guess2 == secret4)){
            totalWrong = 1;
        }else if((guess3 != secret3) && (guess3 == secret1 || guess3 == secret2 || guess3 == secret4)){
            totalWrong = 1;
        }else if((guess4 != secret4) && (guess4 == secret1 || guess4 == secret2 || guess4 == secret3)){
            totalWrong = 1;
        }

        if (guess1 == 0 && guess2 == 0 && guess3 == 0 && guess4 == 0){
            cout << "Abort game? Type 'Y' to confirm => ";
            cin >> abort;
            cout << endl;
            if (abort == 'Y')
            {
                cout << "You aborted the game!\n" << endl;
                cout << "The secret numbers are = " << secret1 << " " << secret2 << " " << secret3 << " " << secret4 << endl;
                break;
            }
            else{
                continue;
            }
        }
        if (guess1 > 6 || guess2 > 6 || guess3 > 6 || guess4 > 6 || guess1 < 1 || guess2 < 1 || guess3 < 1 || guess4 < 1){
            cout << "Invalid input." << endl;
            cout << "Number must be in range of 1 to 6.\n" << endl;
        }
        else{
            cout << "Correct Number, Correct Position: Total = " << totalCorrect << endl;
            cout << "Correct Number, Wrong Position: Total = " << totalWrong;
            cout << endl;
            trialNum = trialNum + 1;
        }

        if (totalCorrect == totalSecrets){
            win = true;
            break;
        }
    }

    if (win){
        cout << "\nYou win!" << endl;
        cout << "\nThe secret numbers are = " << secret1 << " " << secret2 << " " << secret3 << " " << secret4 << endl;
        cout << "\nRestart game? Type 'Y' to restart => ";
        cin >> restart;
        if (restart == 'Y'){
            cout << endl;
            main();
        }else{
            cout << "\nGood bye!";
        }
    }
    else{
        cout << "\nYou lose!" << endl;
        cout << "\nThe secret numbers are = " << secret1 << " " << secret2 << " " << secret3 << " " << secret4 << endl;
        cout << "\nRestart game? Type 'Y' to restart => ";
        cin >> restart;
        if (restart == 'Y'){
            cout << endl;
            main();
        }else{
            cout << "\nGood bye!";
        }
    }
}