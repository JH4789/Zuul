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
    {1, 2},
    {2, 3},
    {7, 1},
    {6, 5},
    {5, 4},
    {8, 7},
    {9, 8},
    {11, 10},
    {15, 16},
    {14, 15},
    {17, 14}
  };
  map <int, int> southexits = {
    {2, 1},
    {3, 2},
    {1, 7},
    {5, 6},
    {4, 5},
    {7, 8},
    {8, 9},
    {10 , 11},
    {16, 15},
    {15, 14},
    {14, 17}
  };
  
  map <int , int> eastexits = {
    
    {2, 5},
    {1, 13},
    {3, 4},
    {8, 10},
    {6, 1},
    {10, 12},
    {13, 14}
  };

  map < int , int> westexits = {
    {13, 1},
    {5, 2},
    {4, 3},
    {1, 6},
    {14, 13},
    {12, 10},
    {10, 8}
  };
  
  vector <Room*> zuul;
  bool inventorytri;
  bool inventorychemtank;
  bool inventorysunfire;
  bool inventoryslayer;
  bool inventoryriftmaker;
  int currentroom = 1;
  //North is 1, East is 2, South is 3, West is 4
  for(int i = 1 ; i < 17 ; i++) {
    Room* newroom = new Room();
    newroom->setID(i);
    if(i == 1) {
      char description[] = "You arrive at a crossroad of regions. In all directions there seem to be bustling cities and dying slums";
      newroom->setDescription(description);
      newroom->changetri();
    }
    if(i == 2) {
      char description[] = "This is the Hextech Foundry. The source of the magical energy source that powers much of Piltover.";
      newroom->setDescription(description);
    }
    if(i == 3) {
      char description[] = "You are in the Immortal Bastion. The legends say that a metal revenant was imprisoned here long ago.";
      newroom->setDescription(description);
    }
    if(i == 4) {
      char description[] = "You are in Ghulfrost. This is the coldest part of Runeterra, but in the hearth besides you is a cape of flames.";
      newroom->setDescription(description);
      newroom->changesunfire();
    }
    if(i == 5) {
      char description[] = "You are in Frostheld, home of the Frostguard. They seek to protect a terrible secret that will tear the Frelijord asunder.";
      newroom->setDescription(description);
    }
    if(i == 6) {
      char description[] = "You are in the City of Demacia, the streets are empty as people cower in their homes after the death of their king.";
      newroom->setDescription(description);
    }
    if(i == 7) {
      char description[] = "You are in the Sump. Noxious fumes make it hard to breathe, instead of hextech the power here comes from more nefarious sources.";
      newroom->setDescription(description);
      newroom->changechemtank();
    }
    if(i == 8) {
      char description[] = "You are in Ixaocan. Once Runeterra's greatest hope against a common evil, now it hides in the shadows of its own hubris.";
      newroom->setDescription(description);
    }
    if(i == 9) {
      char description[] = "You are in Icathia. A former vassal state to Shurima, Icathia's leaders undid their city with a strange artifcat in a desperate bid for independence.";
      newroom->setDescription(description);
      newroom->changeriftmaker();
    }
    if(i == 10) {
      char description[] = "You are before the Sun Disk. The now dormant device was once used by emperors to transcend their mortality.";
      newroom->setDescription(description);
    }
    if(i == 11) {
      char description[] = "You are in Zurima. The dessert winds buffet any who stray here.";
      newroom->setDescription(description);
    }
    if(i == 12) {
      char description[] = "You are at the base of Mount Targon. Those who can survive the climb may find their place among the stars.";
      newroom->setDescription(description);
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
      else if(strcmp(direction, "SOUTH") == 0 && southexits[currentroom] !=0) {
        currentroom = southexits[currentroom];
      }
      else if(strcmp(direction, "EAST") == 0 && eastexits[currentroom] !=0) {
        currentroom = eastexits[currentroom];
      }
      else if(strcmp(direction, "WEST") == 0 && westexits[currentroom] !=0) {
        currentroom = westexits[currentroom];
      }
      else {
	cout << "Please enter a valid direction" << endl;
      }
      continue;
    }
    if(strcmp(commandinput, "GET") == 0) {
      bool tripresent = false;
      bool chemtankpresent = false;
      bool riftmakerpresent = false;
      bool slayerpresent = false;
      bool sunfirepresent = false;
      for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	if((*it)->getID() == currentroom) {
	  if((*it)->returntri() == true) {
          tripresent = true;
          }
	  if((*it)->returnchemtank() == true) {
	    chemtankpresent = true;
	  }
	  if((*it)->returnriftmaker() == true) {
	    riftmakerpresent = true;
	  }
	  if((*it)->returnsunfire() == true) {
	    sunfirepresent = true;
	  }
	  if((*it)->returnslayer() == true) {
	    slayerpresent = true;
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
	       inventorytri = true;
	       cout << "You have picked up the Trinity Force" << endl;
	     }
          }   
      }
      else if(strcmp(item, "Turbo Chemtank") == 0 && chemtankpresent == true) {
          for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	     if((*it)->getID() == currentroom) {
	       (*it)->changechemtank();
	       inventorychemtank = true;
	       cout << "You have picked up the Turbo Chemtank" << endl;
	     }
          }   
      }
      else if(strcmp(item, "Riftmaker") == 0 && riftmakerpresent == true) {
          for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	     if((*it)->getID() == currentroom) {
	       (*it)->changeriftmaker();
	       inventorychemtank = true;
	       cout << "You have picked up the Riftmaker" << endl;
	     }
          }   
      }
      else if(strcmp(item, "Kraken Slayer") == 0 && slayerpresent == true) {
          for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	     if((*it)->getID() == currentroom) {
	       (*it)->changeslayer();
	       inventoryslayer = true;
	       cout << "You have picked up the Kraken Slayer" << endl;
	     }
          }   
      }
      else if(strcmp(item, "Sunfire Cape") == 0 && sunfirepresent == true) {
          for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
	     if((*it)->getID() == currentroom) {
	       (*it)->changesunfire();
	       inventorysunfire = true;
	       cout << "You have picked up the Sunfire Cape" << endl;
	     }
          }   
      }
      else {
	cout << "The item you requested is not here" << endl;
      }
  
    }
    if(strcmp(commandinput, "DROP") == 0) {
      char dropitem[100];
      cout << "Please enter the name of the item you want to drop." << endl;
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cin.get(dropitem, 100);
      //Tri Force
      if(strcmp(dropitem, "Trinity Force") == 0 && inventorytri == true) {
	for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
          if((*it)->getID() == currentroom) {
	    (*it)->changetri();
	    inventorytri = false;
	    cout << "You have dropped the Trinity Force" << endl;
	  }
	}
      }
      //Chemtank
      if(strcmp(dropitem, "Turbo Chemtank") == 0 && inventorychemtank == true) {
	for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
          if((*it)->getID() == currentroom) {
	    (*it)->changechemtank();
	    inventorychemtank = false;
	    cout << "You have dropped the Turbo Chemtank" << endl;
	  }
	}
      }
      //Riftmaker
      if(strcmp(dropitem, "Riftmaker") == 0 && inventoryriftmaker == true) {
	for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
          if((*it)->getID() == currentroom) {
	    (*it)->changeriftmaker();
	    inventoryriftmaker = false;
	    cout << "You have dropped the Riftmaker" << endl;
	  }
	}
      }
      //Sunfire
      if(strcmp(dropitem, "Sunfire") == 0 && inventorysunfire == true) {
	for(vector<Room*>:: iterator it = zuul.begin(); it < zuul.end(); ++it) {
          if((*it)->getID() == currentroom) {
	    (*it)->changesunfire();
	    inventorysunfire = false;
	    cout << "You have dropped the Riftmaker" << endl;
	  }
	}
      }
      //Slayer
    }
  }
}


