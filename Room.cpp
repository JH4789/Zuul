#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"
using namespace std;
//Set ID
void Room::setID(int newid){
  id = newid;
}
void Room::setDescription(char* newdescription) {
  description = new char[1000];
  strcpy(description, newdescription);
}
//Details need to be manually coded in, alternative could have been digging through the map but that seemed tedious
void Room::printdetails() {
  cout << description << endl;
  cout << "The exits from this room are: " << endl;
  if(id == 1) {
    cout << "NORTH EAST SOUTH WEST" << endl;
  }
  if(id == 2) {
    cout << "NORTH SOUTH WEST" << endl;
  }
  if(id == 3) {
    cout << "WEST SOUTH" << endl;
  }
  if(id == 4) {
    cout << "SOUTH WEST" << endl;
  }
  if(id == 5) {
    cout << "NORTH EAST SOUTH" << endl;
  }
  if(id == 6) {
    cout << "NORTH EAST" << endl;
  }
  if(id == 7) {
    cout << "NORTH SOUTH" << endl;
  }
  if(id == 8) {
    cout << "NORTH EAST SOUTH" << endl;
  }
  if(id == 9) {
    cout << "NORTH" << endl;
  }
  if(id == 10) {
    cout << "EAST SOUTH WEST" << endl;
  }
  if(id == 11) {
    cout << "NORTH" << endl;
  }
  if(id == 12) {
    cout << "WEST" << endl;
  }
  if(id == 13) {
    cout << "EAST WEST" << endl;
  }
  if(id == 14) {
    cout << "NORTH SOUTH WEST" << endl;
  }
  if(id == 15) {
    cout << "NORTH SOUTH" << endl;
  }
  if(id == 16) {
    cout << "SOUTH" << endl;
  }
  if(id == 17) {
    cout << "NORTH" << endl;
  }
  if(tri == true) {
    cout << "Trinity Force" << endl;
  }
  if(sunfire == true) {
    cout << "Sunfire Cape" << endl;
  }
  if (chemtank == true) {
    cout << "Turbo Chemtank" << endl;
  }
  if(slayer == true) {
    cout << "Kraken Slayer" << endl;
  }
  if(riftmaker == true) {
    cout << "Riftmaker" << endl;
  }
}
//Very helpful for just switching the boolean in the class
void Room::changetri() {
  if(tri == false) {
    tri = true;
  }
  else {
    tri = false;
  }
}
void Room::changechemtank() {
  if(chemtank == false) {
    chemtank = true;
  }
  else {
    chemtank = false;
  }
}
void Room::changeriftmaker() {
  if(riftmaker == false) {
    riftmaker = true;
  }
  else {
    riftmaker = false;
  }
}
void Room::changeslayer() {
  if(slayer == false) {
    slayer = true;
  }
  else {
    slayer = false;
  }
}
void Room::changesunfire() {
  if(sunfire == false) {
    sunfire = true;
  }
  else {
    sunfire = false;
  }
}
//Used to check for presence of item in the room
bool Room::returntri() {
  return tri;
}
bool Room::returnchemtank() {
  return chemtank;
}
bool Room::returnriftmaker() {
  return riftmaker;
}
bool Room::returnslayer() {
  return slayer;
}
bool Room::returnsunfire() {
  return sunfire;
}
int Room::getID() {
  return id;
}
