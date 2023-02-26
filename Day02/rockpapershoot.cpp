#include <map>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
  map<char, char> strategy;
  char opponent, action;
  int score = 0;
  // Read the encrypted strategy guide from input.txt
  // Read the encrypted strategy guide from input.txt
  ifstream inputFile("input.txt");
  while (inputFile >> opponent >> action){
    strategy[opponent] = action;
  }

  // Going through each round
  char round;
  while (cin >> round){
  char iChoose = strategy[round];

    // Based of the input, choose which score will be given
    switch (iChoose){
      case 'X':
        if (round == 'A'){
          score += 1;
        }
        else if (round == 'B'){
          score += 6;
        }
        else {
          score += 3;
        }
        break;
      case 'x':
        if (round == 'a'){
          score += 1;
        }
        else if (round == 'b'){
          score += 6;
        }
        else {
          score += 3;
        }
        break;
      case 'Y':
        if (round == 'A'){
          score += 6;
        }
        else if (round == 'B'){
          score += 3;
        }
        else {
          score += 1;
        }
        break;
      case 'y':
        if (round == 'a'){
          score += 6;
        }
        else if (round == 'b'){
          score += 3;
        }
        else
            {
          score += 1;
        }
        break;
      case 'Z':
        if (round == 'A'){
          score += 3;
        }
        else if (round == 'B'){
          score += 1;
        }
        else {
          score += 6;}
        break;
      case 'z':
        if (round == 'a'){
          score += 3;
        }
        else if (round == 'b'){
          score += 1;
        }
        else {
          score += 6;
        }
        break;
    }
  }


  cout << "Total Score: " << score << endl;

  return 0;
}
