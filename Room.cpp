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
}
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
int Room::getID() {
  return id;
}
