//Tyler Yamashiro
//heap.h
//Purpose: The .h file for the heap class contains the methods for
//sorting inserting and deleting process objects from the heaps

#include <iostream>
#include <queue>
using namespace std;
#ifndef HEAP_H
#define HEAP_H

class Heap{
 private:
  Process* theHeap;
  //a dynamic array of Process objects
  int size;
  //the amount of process objects in the heap
  int capacity;
  //size of the array
  void percolateUp(int pos);
  //Shifts the item up into the appropriate spot in the heap
  void percolateDown(int pos);
  //shifts the item down into the appropriate spot in the heap
  void resize();
  //Helper function to resize the array if trying to store more objects than
  //the array can hold
  int getLeftChildIndex(int nodeIndex);
  //gets the index of the left child index
  int getRightChildIndex(int nodeIndex);
  //gets the index of the right child index
  int getParentIndex(int nodeIndex);
  //gets the index of the parent of the node specified
  void swap(Process& i, Process& sn);
  //swaps two values with each other
  void buildHeap();
  //helper function for heapsort()
  void trim();
  //reduces the capacity of the array to the amount of objects in the heap
 public:
  Heap(int cap);
  //constructor for the heap which creates a dynamic array of size cap
  ~Heap();
  //deconstructor for the heap
  bool isEmpty();
  //Returns true if the heap is emtpy and false if it is not
  void insert(const Process& item);
  //Inserts an item into the array then percolates up to the right position
  //  void insertWeiss(const Process& item);
  int getMin();
  //returns the minimum item in the heap
  void deleteMin();
  //deletes the minimum item in the heap
  void print();
  //Prints items in heap in level order
  void heapSort();
  //Sorts the heap in descending order
  void addValToPos(int p, int newValue);
  //Adds the value of newValue to the priority value at index p in the heap
  void replaceMin(Process& newValue);
  //replaces the minimum item with a item passed in as a parameter and sorts  
  void deleteAtPos(int p);
  //deletes a node at the specified position
  void flushEvenVal();
  //deletes all items with even priority
  void printNode(int pos);
  //prints a single node
  
};
#endif
