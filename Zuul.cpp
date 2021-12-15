#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include <vector>
#include "Room.h"
#include <limits>
using namespace std;



int main() {
  map <int, int> northexits = {
    {1 , 2}
  };
  map<int, int> southexits = {
    {2 , 1}
  };
  vector <Room*> zuul;
  
  int currentroom = 1;
  //North is 1, East is 2, South is 3, West is 4
  for(int i = 1 ; i < 17 ; i++) {
    Room* newroom = new Room();
    newroom->setID(i);
    if(i == 1) {
      char asdf[] = "You arrive at a crossroad of regions. In all directions there seem to be bustling cities and dying slums";
      newroom->setDescription(asdf);
      newroom->changetri();
    }

    zuul.push_back(newroom);
  }

  bool running = true;
  cout << "Welcome to Zuul! You have arrived in the mysterious and magical world of Runeterra. Find 5 artifacts to return to your previous existence." << endl;
  
  
  
  while(running == true) {
    char commandinput[100];
    char direction[100];
    char item[100];
    for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
     if((*it)->getID() == currentroom) {
       (*it)->printdetails();
     }
    }
    cout << "Please enter a command for what you would like to do. Enter GO to choose a direction to go. Enter GET to pick up an item in the room. Enter QUIT to quit." << endl;
    cin >> commandinput;
    if(strcmp(commandinput, "GO") == 0) {
      cout << "Enter the direction that you would like to go" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.get(direction, 100);
      if(strcmp(direction, "NORTH") == 0 && northexits[currentroom] != 0) {
        currentroom = northexits[currentroom];
      }
      if(strcmp(direction, "SOUTH") == 0 && southexits[currentroom] !=0) {
        currentroom = southexits[currentroom];
      }
      continue;
    }
    if(strcmp(commandinput, "GET") == 0) {
      bool tripresent = false;
      for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	if((*it)->getID() == currentroom) {
	  if((*it)->returntri() == true) {
          tripresent = true;
          }
	}
      }
      
      cout << "Please enter the name of the item that you would like to pick up" << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.get(item, 100);
      if(strcmp(item, "Trinity Force") == 0 && tripresent == true) {
          for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	     if((*it)->getID() == currentroom) {
	       (*it)->changetri(); 
	     }
          }   
      }






      else {
	cout << "The item you requested is not here" << endl;
      }
    }
  }
}


