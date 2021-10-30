#include <iostream>
#include "project.h"

using namespace std;

void Modeselect(Player & player1, Player & player2) {
  string mode;
  cout << endl << "******************** Welcome to the Gomoku! ********************" << endl << endl;
  cout << "Please select a mode you want to play: " << endl;
  cout << "1: Man-man Mode, 2: Man-Machine Mode" << endl << "Your choice is: ";
  cin >> mode;
  while (mode != "1" && mode != "2") {
    cout << "Invalid mode. Please input it again. " << endl << endl;
    cout << "Please select a mode you want to play: " << endl;
    cout << "1: Man-man Mode, 2: Man-Machine Mode" << endl << "Your choice is: ";
    cin >> mode;
  }
  if (mode == "1") {
    cout << endl << "Please input the name of player 1: " << endl;
    cin >> player1.name;
    cout << "Please input the name of player 2: " << endl;
    cin >> player2.name;
    while (player2.name == player1.name) {
      cout << "Invalid name. Please input it again." <<endl;
      cin >> player2.name;
    }
  }
  else if (mode == "2"){
    cout << "Please input the name of player 1: " << endl;
    cin >> player1.name;
    while (player1.name == "Computer") {
      cout << "Invalid name. Please input it again." <<endl;
      cin >> player1.name;
    }
    player2.name = "Computer";
  }
}

void addpoint(int n, Player &player1, Player &player2) {
  if (n%2 == 1) {
    player1.score ++;
    cout << player1.name << " wins." << endl << endl;
  }
  else {
    if (player2.name != "Computer") {
      player2.score ++;
      cout << player2.name << " wins." << endl << endl;
    }
  }
}
