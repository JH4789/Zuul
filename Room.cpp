#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"
using namespace std;

void Room::setID(int newid){
  id = newid;
}
void Room::setDescription(char* newdescription) {
  description = new char[100];
  strcpy(description, newdescription);
}
void Room::printdetails() {
  cout << description << endl;
  if(id == 1) {
    cout << "The exits from this room are: " << endl;
    cout << "NORTH EAST SOUTH WEST" << endl;
  }


  cout << "The items in this room are: ";
  if(tri == true) {
    cout << "Trinity Force" << endl;
  }
  //Add other items here
}
/*
void Room::setNorthExit() {
  northexit = true;
}
void Room::setWestExit() {
  westexit = true;
}
void Room::setSouthExit() {
  southexit = true;
}
void Room::setEastExit() {
  eastexit = true;
}
*/
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
