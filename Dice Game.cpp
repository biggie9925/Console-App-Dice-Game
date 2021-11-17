// Dice Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


struct Player {
    string name = "unset";
    int score = 0;
    int total = 0;
};

struct Dice {
    int throw_value = 0;
};


void instructionsFunction () {
    cout << "\n\t\t\t\tInstructions\n";
    cout << "**********************************************************************************\n\n";
    cout << "1. Players must feed their names and pre-set the Maximum score before game starts.\n";
    cout << "2. Each player has two 6 face dice to roll, and the players get turns to earn score.\n";
    cout << "3. For each roll, dice 1 and dice 2 values will be added for the corresponding players.\n";
    cout << "4. If both dice values are same then the score will be two times the sum of the value\n";
    cout << "\tE.g. : dice 1 returns 2 and dice 2 returns 2 then 2 + 2 = 4 * 2 = 8.\n";
    cout << "5. Whoever reaches the maximum score first will be declared winner,\n";
    cout << "\tand the game will be finished.";
    cout << "6. After each roll, each player score board will be updated and displayed.\n\n";
    cout << "**********************************************************************************\n";
}


int* diceFunction(Dice GGdice1)
{
    GGdice1.throw_value = rand() % 6 + 1;
    int* roll = &GGdice1.throw_value;
    return roll;
}


void playFunction(struct Player *player1, struct Player *player2, int maxscore) {

    bool play = true;
    char input;
    int i = 0;
    Dice GGdice1;
    Dice GGdice2;
    Dice GGdice3;
    Dice GGdice4;
    player1->total = 0;
    player2->total = 0;

    while (play) {
        srand((unsigned)time(NULL));

        int dice1 = *diceFunction(GGdice1);
        int dice2 = *diceFunction(GGdice2);
        int dice3 = *diceFunction(GGdice3);
        int dice4 = *diceFunction(GGdice4);

        cout << "\n" << player1->name << " roll number " << i + 1 << " :\n\n";
        cout << player1->name << " rolls " << dice1 << " and " << dice2 << endl;
        player1->score = dice1 + dice2;
        if (dice1 == dice2) {
            cout << "Double points!\n";
            cout << player1->name << " scores : " << player1->score * 2 << endl;
            player1->total += player1->score * 2;
        }
        else {
            cout << player1->name << " scores : " << player1->score << endl;
            player1->total += + player1->score;
        }
        cout << player1->name << "'s total : " << player1->total << "\n\n";


        cout << player2->name << " roll number " << i + 1 << " :\n\n";
        cout << player2->name << " rolls " << dice3 << " and " << dice4 << endl;
        player2->score = dice3 + dice4;
        if (dice3 == dice4) {
            cout << "Double points!\n";
            cout << player2->name << " scores : " << player2->score * 2 << endl;
            player2->total += player2->score * 2;
        }
        else {
            cout << player2->name << " scores : " << player2->score << endl;
            player2->total += player2->score;
        }
        cout << player2->name << "'s total : " << player2->total << "\n\n";

        if (player1->total > maxscore || player2->total > maxscore) {
            break;
        }

        else {
            cout << "Roll again? (Y/N) : ";
            cin >> input;
            if (input == 'y' || input == 'Y') {
                i++;
                continue;
            }
            else {
                cout << "GOOD GAME";
                break;
            }
        }
    }

    if (player1->total >= maxscore && player2-> total >= maxscore) {
        cout << "Draw!";
        cout << player1->name << " has " << player1->total << " and " << player2->name << " has " << player2->total << " points.\n";
    }

    else if (player1->total >= maxscore) {
        cout << "Congratulations " << player1->name << " you won with " << player1->total << " points.\n";
    }

    else {
        cout << "Congratulations " << player2->name << " you won with " << player2->total << " points.\n";
    }

}


void scoreboardFunction(Player player1) 
{
    cout << player1.name << " total points: " << player1.total << endl;
}


int main()
{
    bool game = true;
    int input;
    int maxscore = 0;
    Player player1;
    Player player2;

    cout << "Two Players Dice Game-- Pre set Maximum Score\n";
    cout << "*********************************************\n";

    while (game) {
        cout << "\n1. Instruction\n";
        cout << "2. Set Maximum Score\n";
        cout << "3. Read Players\n";
        cout << "4. Play\n";
        cout << "5. Display Scoreboard\n";
        cout << "6. End\n\n";
        cout << "Enter your option : ";
        cin >> input;

        if (input == 1) {
            instructionsFunction();
            continue;
        }

        else if (input == 2) {
            cout << "\nPlease set Maximum Score : ";
            cin >> maxscore;
            continue;
        }

        else if (input == 3) {
            cout << "\nPlayer 1 name: ";
            cin.ignore();
            getline(cin, player1.name);

            cout << "Player 2 name: ";
            getline(cin, player2.name);
            continue;
        }

        else if (input == 4) {

            if (maxscore == 0) {
                cout << "\nPlease set Maximum Score first\n";
                continue;
            }
            
            else if (player1.name == "unset" || player2.name == "unset") {
                cout << "\nPlease set names first\n";
                continue;
            }

            else {
                playFunction(&player1, &player2, maxscore);
            }

        }

        else if (input == 5) {
            scoreboardFunction(player1);
            scoreboardFunction(player2);
            continue;
        }

        else if (input == 6) {
            cout << "\nGame Over";
            game = false;
            break;
        }

        else {
            cout << "\nInvalid input, please try again\n";
            continue;
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
