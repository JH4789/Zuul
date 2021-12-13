#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include <vector>
#include "Room.h"
using namespace std;



int main() {
  map <pair<int, int>, int> zuulmap = {
    {{ 0,1} , 1}
  };
  vector <Room*> zuul;
  
  int currentroom = 0;
  //North is 1, East is 2, South is 3, West is 4
  for(int i = 0 ; i < 16 ; i++) {
    Room* newroom = new Room();
    newroom->setID(i);
    if(i == 0) {
      char asdf[] = "asdf";
      newroom->setDescription(asdf);
      newroom->setNorthExit();
      newroom->setEastExit();
      newroom->setSouthExit();
      newroom->setWestExit();
    }
    
    zuul.push_back(newroom);
  }
  
  bool running = true;
  cout << "Welcome to Zuul! You have arrived in the mysterious and magical world of Runeterra. Find 5 artifacts to return to your previous existence." << endl;
  /*
  for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
    if((*it)->getID() == currentroom) {
       (*it)->printdetails();
    }   
  }
  */
  while(running == true) {
    char commandinput[100];
    char direction[100];
    
    cout << "Please enter a command for what you would like to do. Enter GO to choose a direction to go. Enter GET to pick up an item in the room. Enter QUIT to quit." << endl;
    cin >> commandinput;
    if(strcmp(commandinput, "GO") == 0) {
      cout << "Enter the direction that you would like to go" << endl;
      cin.get(direction, 100);
      cin.clear();
      if(strcmp(direction, "NORTH") == 0 ) {
         
      }
    }
    if(strcmp(commandinput, "GET") == 0) {
      cout << "Please enter the name of the item that you would like to pick up" << endl;
    }
    if(strcmp(commandinput, "QUIT") == 0) {
      cout << "Thank you for playing!" << endl;
      running = false;
    }
  }
}
