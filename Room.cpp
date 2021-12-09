#include <iostraem>
#include <cstring>
#include <map>
#include "Room.h"
using namespace std;

void Room::setID(int newid){
  id = newid;
}
void Room::setDescription(char* newdescription) {
  description = new char[100];
  strcpy(title, newtitle);
}
char* Room::getDescription() {
  return description;
}
