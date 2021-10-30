#include <iostream>
#include "project.h"

using namespace std;

void print(int x) {
  if (x == 1) cout << BLACK;
  else if (x == -1) cout << WHITE;
}

void Printboard(int p[][15]) {
  cout << "   0 1 2 3 4 5 6 7 8 9 1011121314" << endl;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      if (i == 0 && j == 0) {
        cout << "0  ";
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << LT << BL;
      }
      else if (i == 0 && j == 14) {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << endl;
        }
        else cout << RT << endl;
      }
      else if (i == 14 && j == 0) {
        cout << "14 ";
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << LB << BL;
      }
      else if (i == 14 && j == 14) {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << endl;
        }
        else cout << RB << endl;
      }
      else if (i == 0) {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << MT << BL;
      }
      else if (i == 14) {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << MB << BL;
      }
      else if (j == 0) {
        if (i < 10) cout << i << "  ";
        else cout << i << " ";
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << LM << BL;
      }
      else if (j == 14) {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << endl;
        }
        else cout << RM << endl;
      }
      else {
        if (p[i][j] != 0) {
          print(p[i][j]);
          cout << BL;
        }
        else cout << MM << BL;
      }
    }
  }
}
