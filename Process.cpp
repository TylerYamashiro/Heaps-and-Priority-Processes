//Tyler Yamashiro
//Process.cpp
//Purpose: The implementation file of the Process class

#include "Process.h"
#include <iostream>
using namespace std;
Process:: Process()//default constructor initializes the private members to 0
  :ID(0), priority(0)
{}

Process::Process(int i, int p )//constructor
  :ID(i), priority(p){}
  
  
const Process Process:: operator= (const Process& rhs)
{                                   //The OAO copies the members of the 
  ID = rhs.ID;                     //rhs object to the left object
  priority = rhs.priority;
  return *this;
}

int Process::returnID() //returns the ID of the object
{
  return ID;
}

int Process::returnPriority()//returns the priority of the object
{
  return priority;
}

void Process::setID(int i)//sets the ID of the object to i
{
  ID = i;
}

void Process::setPriority(int p)//sets the priority of the object to p
{
  priority = p;
}

bool Process:: operator> (const Process& rhs)//Overlaods the > operator
{
  return( priority > rhs.priority);
}

bool Process:: operator< (const Process& rhs)//overloads the < operator
{
  return( priority < rhs.priority);
}

bool Process:: operator== (const Process& rhs)//overloads the == operator
{
  return( priority == rhs.priority);
}

bool Process:: operator<= (const Process& rhs)//overlaods the <= operator
{
  return( priority <= rhs.priority);
}

bool Process:: operator>= (const Process& rhs)//overloads the >= operator
{
  return( priority >= rhs.priority);
}

void Process::print()//Prints Priority and ID
{
  cout << "Priority: " << priority << ' ';
  cout << "ID: " << ID << endl;
}
