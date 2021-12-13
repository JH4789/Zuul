#ifndef ROOMHEADER
#define ROOMHEADER
#include <iostream>
#include <cstring>

using namespace std;

class Room {

 public:
  virtual void setID(int);
  virtual int getID();
  virtual void setDescription(char*);
  virtual void printdetails();
  virtual void setNorthExit();
  virtual void setSouthExit();
  virtual void setEastExit();
  virtual void setWestExit();
 protected:
  char* description;
  int id;
  bool northexit;
  bool westexit;
  bool eastexit;
  bool southexit;
  

 private:
  
};











#endif
