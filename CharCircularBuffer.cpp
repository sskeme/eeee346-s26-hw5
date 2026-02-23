#include "CharCircularBuffer.h"

/**
 * Total number of characters allowed in the circular buffer
 */
int capacity;

/**
 * Index of the front (head) of the circular buffer
 * Putting new characters goes here
 */
int head;

/**
 * Index of the end (tail) of the circular buffer
 * Getting characters comes from here
 */
int tail;

/**
 * Keep track of the full state of the circular buffer
 */
bool full;

/**
 * Globally declared smart pointer to point to a dynamic array
 */
unique_ptr<char[]> buffer;


void create(int c) {
  // TODO: write your code
}

void put(char ch) {
  // TODO: write your code
}

char get() {
  if (isEmpty()) {
    return char(); // returns a null character
  }

  // TODO: write your code
}

void reset() {
  head = 0;
  tail = 0;
  full = false;
}

bool isFull() {
  return full;
}

bool isEmpty() {
  // TODO: write your code
}

int getCapacity() {
  return capacity;
}

int getSize() {
  // TODO: write your code
}

void printStatus() {
  cout << "------------------------------------\n";
  cout << "Buffer Capacity: " << getCapacity() << endl;
  cout << "Buffer Size: " << getSize() << endl;
  cout << "Buffer isEmpty: " << isEmpty() << endl;
  cout << "Buffer isFull: " << isFull() << endl;
  cout << "------------------------------------\n";
}
