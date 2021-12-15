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
  virtual bool returntri();
  virtual bool returnchemtank();
  virtual bool returnriftmaker();
  virtual bool returnslayer();
  virtual bool returnsunfire();
  /*
  virtual void setNorthExit();
  virtual void setSouthExit();
  virtual void setEastExit();
  virtual void setWestExit();
  */
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
  /*
  bool northexit;
  bool westexit;
  bool eastexit;
  bool southexit;
  */

 private:
  
};
#endif
