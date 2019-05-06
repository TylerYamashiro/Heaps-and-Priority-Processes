//Tyler Yamashiro
//Project4.cpp
//Purpose: Driver file for the program.  Tests the functions of the Heap class
//Output:Outputs the tests and the results of the test.
#include "Process.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void readFile(Heap &h, Process p);

int main()
{
  Process p1;//Process object
  Process p2(9999, 9);
  Heap h1(15);//heap of capacity 15
  readFile(h1, p1);
  cout << endl;  
  //testing print function
  cout << "Now printing Heap in level order." << endl;
  h1.print(); //Printing the heap
  cout << endl;
  
  //Testing the isEmpty()
  cout <<"Now testing the isEmpty()funciton. " << endl;
  if( h1.isEmpty())
	cout << "The Heap is empty." << endl;
  else{
	cout << "The Heap is not empty." << endl;
  }
  cout << endl;

  //Testing the insert function
  cout << "Now inserting Process object with ID: 9999 and Priority: 9." <<
	endl;
  h1.insert(p2);
  h1.print();
  cout << endl;

  //Testing the getMin()
  cout <<"Now testing getMin()function." << endl;
  h1.getMin();
  cout << endl;

  //Testing the addValToPos()
  cout <<"Now testing addValToPos()" << endl;
  cout <<"Adding 5 to the Process at position 9." << endl;
  h1.addValToPos(9, 5);
  h1.print();
  cout << endl;

  //Testing the replaceMin()
  cout <<"Now testing replaceMin()" << endl;
  cout << "Replacing with ID: 1002 and Priority:11" << endl;
  Process temp(1002, 11);
  h1.replaceMin(temp);
  h1.print();
  cout << endl;

  //Testing the deleteAtPos()
  cout <<"Now testing deleteAtPos()" << endl;
  cout <<"Deleting node at position 9" << endl;
  h1.deleteAtPos(9);
  h1.print();
  cout << endl;

  //Testing the flushEvenVal()
  cout <<"Now testing flushEvenVal()" << endl;
  cout <<"Now deleting all even priorities" << endl;
  h1.flushEvenVal();
  h1.print();
  cout <<endl;

  //Testing HeapSort()
  cout <<"Now testing the HeapSort() function" << endl;
  cout <<"Now printing sorted Heap" << endl;
  h1.heapSort();
  h1.print();
  cout << endl;
  
 
}

void readFile(Heap &h, Process p)//read in the file and store in the heap
{
  string temp;
  int count = 1;
  ifstream infile;
  int i;
  int index = 0;
  infile.open("input.txt");
  while(!infile.eof()){
	getline(infile, temp);//get each line
	stringstream ss(temp);
	while(ss >> i){
	  if(ss.peek() == ',')//ignore the' ,'
		ss.ignore();
	
	  if( count % 2 == 0) //sets the priority of the item
		p.setPriority(i);
	
	  else{
		p.setID(i);//sets teh id of teh item
	  }
	  count ++;
	}
	h.insert(p);
	index++;
  }
	infile.close();
}
	
