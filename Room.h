#ifndef ROOMHEADER
#define ROOMHEADER
#include <iostream>
#include <cstring>

using namespace std;

class Room {
  //Boring header file
 public:
  virtual void setID(int);
  virtual int getID();
  virtual void setDescription(char*);
  virtual void printdetails();
  virtual bool returntri();
  virtual bool returnchemtank();
  virtual bool returnriftmaker();
  virtual bool returnslayer();
  virtual bool returnsunfire();
  virtual void changetri();
  virtual void changechemtank();
  virtual void changeriftmaker();
  virtual void changeslayer();
  virtual void changesunfire();
protected:
  char* description;
  int id;
  bool tri;
  bool chemtank;
  bool riftmaker;
  bool slayer;
  bool sunfire;
 private:
  
};
#endif
