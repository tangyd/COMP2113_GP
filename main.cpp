#include <iostream>
#include <string>
#include "project.h"

using namespace std;

int a, b, c, d, i = 0, p[15][15], n, turn;
Player player1, player2;
bool isNew, isEnd;

int main()
{
  initiate(p, isEnd, isNew, n, turn);
  player1.score = 0, player2.score = 0;
  while (isNew)
  {
    initiate(p, isEnd, isNew, n, turn);
    Modeselect(player1, player2);
    Printboard(p);
    if (n%2 == 0) cout << player1.name << " goes first." << endl;
    else cout << player2.name << " goes first." << endl;
    while (isEnd == false)
      {
      string player;
      if (n%2 == 0) player = player1.name;
      else player = player2.name;
      if (player != "Computer")
      {
          cout << "(" << player << "\'s turn) Please input the chess: ";
          cin >> a >> b;
          c = a, d = b;
      }
      else
      {
        computer_input(a, b, c, d, p, turn); // search from (c, d) to judge where to put (a,b) of computer.
        cout << "(Computer's turn)" << endl;
      }
      if (Validinput(a, b, p) == true)
      {
        n++;
        if (turn%2 != 0)
            p[a][b]= -1;
        else
            p[a][b]= 1;
      }
      else
      {
        cout << "Invalid input" <<  endl;
        continue;
      }
      turn++;
      Printboard(p);
      Endgame(a, b, isEnd, p);
    }
    cout << "End of the turn." << endl;
    addpoint(n, player1, player2);
    IOfile(player1, player2);
    cout << "Do you want to play again?" << endl;
    cout << "1: Yes; 0: No " << endl;
    cin >> isNew;
  }
}
