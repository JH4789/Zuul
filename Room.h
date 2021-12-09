#ifndef ROOMHEADER
#define ROOMHEADER
#include <iostream>
#include <cstring>

using namespace std;

class Room {

 public:
  virtual void setID(int);
  virtual void setDescription(char*);
  virtual char* getDescription();
 protected:
  char* description;
  int id;

 private:
  
};











#endif
