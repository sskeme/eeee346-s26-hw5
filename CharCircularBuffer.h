#ifndef CHAR_CIRCULAR_BUFFER_H // header guard
#define CHAR_CIRCULAR_BUFFER_H

#include <iostream>
#include <memory> // to use smart pointers

using namespace std;

/**
 * Create a circular buffer for "capacity" characters.
 * Specifically, 1) set the value of the global variable "capacity" to the parameter "c" and 
 * 2) reset the values of the global variables "head", "tail", and "full" by calling reset().
 * 3) For a circular buffer, dynamically allocate memory for an array with "c" (or "capacity") chars
 * and assign its starting address to the global unique pointer "buffer" (hint: you may need "make_unique").
 * @param c - capacity for the circular buffer
 */
void create(int c);

/**
 * Put a single character into the circular buffer.
 * The "head" is moved by one.
 * If the circular buffer is full, the oldest character is overwritten.
 * Update the "full" status after placement in the circular buffer.
 * @param ch - character to place in the circular buffer
 */
void put(char ch);

/**
 * Grab the last character in the circular buffer (at "tail").
 * If the circular buffer is not empty, "tail" is moved by one.
 * @return - the last character in the circular buffer (at "tail")
 */
char get();

/**
 * Reset the circular buffer (reset the values of "head", "tail", and "full")
 */
void reset();

/**
 * @return true if the circular buffer is full
 */
bool isFull();

/**
 * @return true if the circular buffer is empty
 */
bool isEmpty();

/**
 * @return the total capacity allowed for the circular buffer
 */
int getCapacity();

/**
 * @return total characters in the circular buffer
 */
int getSize();

/**
 * A helper function to print the status of the circular buffer
 */
void printStatus();

#endif
