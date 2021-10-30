#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <string>
using namespace std;

#define LT "\u250C"
#define LM "\u251C"
#define LB "\u2514"
#define MT "\u252C"
#define MM "\u253C"
#define MB "\u2534"
#define RT "\u2510"
#define RM "\u2524"
#define RB "\u2518"
#define BL "\u2500"
#define BLACK "\u25C9"
#define WHITE "\u25CE"

struct Player {
  string name;
  int score;
};

bool Validinput(int a, int b, int p[][15]);
void Modeselect(Player &player1, Player &player2);
void Endgame(int a, int b, bool & isEnd, int p[][15]);
void initiate(int p[][15], bool &isEnd, bool &isNew, int &n, int &turn);
void computer_input(int& a, int& b, int c, int d, int p[][15], int &turn);
void Printboard(int p[][15]);
void IOfile(Player player1, Player player2);
void addpoint(int n, Player &player1, Player &player2);

#endif
