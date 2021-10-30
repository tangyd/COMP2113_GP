#include <iostream>
#include <fstream>
#include <sstream>
#include "project.h"
#include <string>

using namespace std;

void load_list(Player * &plist, int &list_size, int &nRec );
void print_list(Player plist[], int nRec);
void sort_list(Player plist[], int nRec);
void add_record(Player * &plist, int &nRec, Player player, int &list_size);
void grow_list(Player * &plist, int &list_size, int n);
int search_list(Player plist[], int nRec, Player player);
void store_list(Player * plist, int nRec);

void IOfile(Player player1, Player player2)
{
	int list_size = 3;
  Player * head = new Player[list_size];
  int nRec = 0;

  load_list(head, list_size, nRec);
  if (search_list(head, nRec, player1) == -1) add_record(head, nRec, player1, list_size);
  if (search_list(head, nRec, player2) == -1) add_record(head, nRec, player2, list_size);
	sort_list(head, nRec);
  print_list(head, nRec);
  store_list(head, nRec);

	delete [] head;
	head = 0;
}

void load_list(Player * &plist, int &list_size, int &nRec)
{
  string line;

  ifstream fin;
  fin.open("result.txt");
  if ( fin.fail() ) {
    ofstream fout("result.txt");
    fout.close();
    fin.open("result.txt");
  }

  while (getline(fin, line)) {
		if (nRec >= list_size) grow_list(plist, list_size, 2);
		if (nRec < list_size) {
      istringstream iss(line);
      iss >> plist[nRec].name;
      iss >> plist[nRec].score;
      nRec++;
    }
  }
  fin.close();
}

void print_list(Player plist[], int nRec)
{
    int i;
    cout << "The top five players are :" << endl;
    for (i = 0; i < nRec && i < 5; i++)
    {
        cout << "Name: " << plist[i].name << "\t";
        cout << "Score: " << plist[i].score << endl;
    }
    cout << endl;
}

void sort_list(Player plist[], int nRec)
{
  int i, j ,idx, max; // selection sort
  for (i = 0; i < nRec - 1; i++) {
    max = plist[i].score;
    idx = i;
    for (j = i + 1; j < nRec; j++) {
      if (plist[j].score > max) {
        max = plist[j].score;
        idx = j;
      }
    }
    if (idx != i) {
      Player temp; // swap pb[i] & pb[idx]
      temp = plist[i];
      plist[i] = plist[idx];
      plist[idx] = temp;
    }
  }
}

int search_list(Player plist[], int nRec, Player player)
{
	for (int i = 0; i < nRec; i++) {
		if (plist[i].name != player.name) continue;
    else {
      plist[i].score += player.score;
      return i;
    }
	}
	return -1;
}

void add_record(Player * &plist, int &nRec, Player player, int &list_size)
{
  if (nRec >= list_size) grow_list(plist, list_size, 2);
  plist[nRec].name = player.name;
  plist[nRec].score = player.score;
  nRec++;
}

void store_list(Player * plist, int nRec) {
  ofstream fout("result.txt");
  for (int i = 0; i < nRec; i++) {
    fout << plist[i].name << "\t" << plist[i].score << endl;
  }
  fout.close();
}

void grow_list(Player * &plist, int &list_size, int n)
{
	// create a new dynamic array with a new size = max_size + n
	Player * plist_new = new Player[list_size + n];
	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < list_size; i++) plist_new[i] = plist[i];
	// destroy the old dynamic array to free up the memory allocated to it
	delete [] plist;
	// assign the pointer to the new dynamic array to the pointer variable
	plist = plist_new;
	// update the size of the array
	list_size += n;
	return;
}
