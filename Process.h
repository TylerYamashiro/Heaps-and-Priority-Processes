//Tyler Yamashiro
//Process.h
//Purpose: The .h file for the Process class

#ifndef PROCESS_H
#define PROCESS_H

class Process{
 private:
  int ID;//Stores the ID of the object
  int priority;//Stores the Priority of the object

 public:
  Process();
  // default constructor initializes private members to 0
  Process(int i, int p);
  //parameterized constructor initializes private members to the parameters
  int returnID();
  //Returns the ID of the Process object
  int returnPriority();
  //Returns the Priority of the Process Object
  void setID(int s);
  //Sets the ID of the Process object by passing in a parameter
  void setPriority(int p);
  //Sets the Priority of the Process object by passing in a parameter
  void print();
  //Prints the ID and the Priority of the process object
  bool operator< (const Process& rhs);
  //Overloads the < operator to compare priorities of process objects
  bool operator> (const Process& rhs);
  //Overloads the > operator to compare priorities of process objects
  const Process operator= (const Process& rhs);
  //Overloaded assignment operator for the process class 
  bool operator == (const Process& rhs);
  //Overloads the == operator to compare the priorities of process objects
  bool operator <= (const Process& rhs);
  //Overloads the <= opertor to compare the priorities of the process objects
  bool operator >= (const Process& rhs);
  //Overloads the >= operator to compare the priorities of the process objects
};

#endif
