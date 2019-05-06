//Tyler Yamashiro
//Heap.cpp
//Purpose:The implementation file for the Heap class contains all the methods
//for storing and sorting Process type objects in a heap.  
#include "Process.h"
#include "Heap.h"
#include <cmath>
Heap::Heap(int cap)//constructor
{
  theHeap = new Process[cap];//creates an array of type process
  size = 0;                 //amount of objects in the heap
  capacity = cap;          //size of the array
}

Heap::~Heap() //deconstructor
{
  delete[] theHeap;
}


void Heap::resize()//doubles the array size when called
{
  int  newCapacity = capacity * 2;
  Process* newHeap = new Process[newCapacity];
  for(int i = 0 ; i < capacity; i++)
	newHeap[i] = theHeap[i];
  capacity = newCapacity;
  delete[] theHeap;
  theHeap = newHeap;
}

int Heap::getLeftChildIndex(int nodeIndex)
{
  return 2 * nodeIndex + 1;
}

int Heap::getRightChildIndex(int nodeIndex)
{
  return 2* nodeIndex + 2;
}

int Heap::getParentIndex(int nodeIndex)
{
  return (nodeIndex-1) / 2;
}


void Heap::trim()//makes the capacity = size
{
  capacity = size;
  Process* temp = new Process[size];
  for(int i = 0 ; i < capacity; i++)
	temp[i] = theHeap[i];
  delete [] theHeap;
  theHeap = temp;
}

void Heap::swap(Process& i, Process& sn)//swaps two integers
{
  Process temp;
  temp = i;
  i = sn;
  sn = temp;
}

void Heap::percolateUp(int pos)//percoales and item up 
{
  int parentIndex;
  Process temp;
  if(pos != 0){
	parentIndex = getParentIndex(pos);
	if(theHeap[parentIndex] > theHeap[pos]){//if the parent is larger
	  temp = theHeap[parentIndex];
	  theHeap[parentIndex] = theHeap[pos];  //move up
	  theHeap[pos] = temp;
	  percolateUp(parentIndex); //calls percolateUp() again
	}
  }
}


void Heap::percolateDown(int pos)//percolates item down
{
  int lc, rc, minIndex;
  Process temp;
  lc = getLeftChildIndex(pos);
  rc = getRightChildIndex(pos);
  if(rc >= size){  //reaches end of heap return
	if(lc >= size)
	  return;
	else
	  minIndex = lc;
  }
  else{
	if(theHeap[lc] <= theHeap[rc]) //checks for min  of the children
	  minIndex = lc;
	else
	  minIndex = rc;
  }
  if(theHeap[pos] > theHeap[minIndex]){//swaps with min
	temp = theHeap[minIndex];
	theHeap[minIndex] = theHeap[pos];
	theHeap[pos] = temp;
	percolateDown(minIndex);
  }
}

	
bool Heap::isEmpty()//returns whether or not the heap is empty
{
  return( size == 0);
}

void Heap::insert(const Process& item)//inserts an item into the heap
{
  if(size == capacity - 1)
	resize();
  size++;
  theHeap[size - 1] = item;
  percolateUp(size - 1);
}


int Heap::getMin() //returns the min item in the heap
{
  if(isEmpty())
	return -1; 
  else{
	theHeap[0].print();
	return theHeap[0].returnID();
	
  }
}

void Heap::deleteMin()//deletes the minimum value in the heap
{
  if(isEmpty())
	return;
  else{
	theHeap[0] = theHeap[size - 1];
	size--;
	if(size > 0)
	  percolateDown(0);
  }
}


void Heap::print()//prints the heap in level order
{
  queue < int > q;
  q.push(0);
  while(!q.empty()){
	theHeap[q.front()].print();
	if((q.front()*2)+1 <= size -1)
	  q.push((q.front()* 2) +1);
	if((q.front()*2) +2 <= size -1)
	  q.push((q.front()*2)+2);
	q.pop();
  }
}

void Heap::buildHeap()//heapifies all the items above the bottom level
{
  trim(); //reduces capacity to equal size
  size = capacity;
  for(int i = floor(size/2); i >= 0 ; i--)
	percolateDown(i);
}

void Heap::heapSort()//sorts the heap in descending order
{
  buildHeap();
  int temp = size;
  for(int i = capacity -1; i >0; i--){
	swap(theHeap[0], theHeap[i]);
	size = size - 1;
	percolateDown(0);
  }
  size = temp;
}

void Heap::addValToPos(int p, int newValue)//Adds the newValue to the 
{                                        //priority of the item specified
  theHeap[p].setPriority(theHeap[p].returnPriority() + newValue);
  percolateDown(p);
}

void Heap::replaceMin(Process& newValue)//replaces the min with a new item
{
  theHeap[0] = newValue;
  percolateDown(0);
}

void Heap::deleteAtPos(int p)//deletes item at specified index
{
  Process temp = theHeap[size - 1];//gets last item
  theHeap[p] = temp;//replaces deleted item with last item
  Process t;
  size--; //decreases size
  theHeap[size] = t;//sets last item size to default
  if(size > 0 && p != size){//if replacement item is bigger than parent
	int parent = getParentIndex(p);//percolate up else percolate down
	if( temp > theHeap[parent]){
	  percolateDown(p);
	}
	else if( temp < theHeap[parent]){
	  percolateUp(p);
	}
  }
}

void Heap::flushEvenVal()//delete all even values in the heap
{
  bool done = true;
  for(int i = 0 ; i < size ; i++){
	if( theHeap[i].returnPriority() % 2 == 0){	  
	  deleteAtPos(i);
	}
  }
  for(int i = 0; i < size; i++){ //checks to see if all even values have been
	if(theHeap[i].returnPriority() % 2 == 0)//removed
	  done = false;
  }
  if(!done)
	flushEvenVal(); //if not calls again
}  


void Heap::printNode(int pos)//prints a single node
{
  theHeap[pos].print();
}
