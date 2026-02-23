# Introduction

In this homework assignment, you will implement a circular buffer for characters. It provides you practice with smart pointers, C++ strings, and a widely used data structure.

# Background: Circular Buffer

As an electrical engineer, you may write programs/firmware for resource-constrained platforms such as a microcontroller. The circular buffer (or ring buffer) is a data structure often used in this situation.

The circular buffer is a fixed-sized buffer that treats the memory as if it is a circular structure. Two indices are used for this buffer:
1. Insertion location (head) for putting values
2. Extraction location (tail) for getting values

Upon initialization of a circular buffer, the head and tail locations are the same.
When a value is inserted into the buffer, the head location is updated.
When a value is extracted from the buffer, the tail location is updated. 
It is possible that the circular buffer can become full.
When inserting into a full buffer, the head and tail are updated, causing values to be overwritten.
When implementing the circular buffer, the head/tail locations often go past the capacity and will wrap back around.
Valid data are between tail and head locations.
See the figure below.

![hw5](https://github.com/user-attachments/assets/2f2ebd0e-051e-467f-b817-dffb1d18773c)

(image source: https://www.sciencedirect.com/topics/computer-science/circular-buffer)

More details on circular buffers can be found at: https://www.embedded.com/ring-buffer-basics/.

# Tasks
1. Read all the comments in CharCircularBuffer.h, which explain what each function is/does.
2. Implement the incomplete functions in CharCircularBuffer.cpp (`create()`, `put()`, `get()`, `isEmpty()`, and `getSize()`). DO NOT shift values by copying them down. That is NOT a circular buffer.

# Pseudocode
```
function put(character to put)

    Place a new character at the head location

    if full
        Move tail up one location

    Move head up one location

    Set full if head == tail
```

```
function get() // Return the oldest value

    if empty
        return char(); // returns a null character

    Grab the character at the tail location

    Update full to false

    Move tail up one location

    return the character that was taken from the buffer
```

# Hints

* Incrementing the tail/head can cause their locations to wrap around. The modulus operator can be used to handle the wrap-around. Consider the following equation:
```
next_position = (current_position + 1) % total_positions
```
* `getSize()` calculations change based on head >= tail or not.
* `isEmpty()` returns True when the buffer is not full AND head == tail.
* A globally declared unique pointer `buffer` exists in `CharCircularBuffer.cpp` but remains uninitialized. To dynamically allocate memory for an array and have the unique pointer point to this array in the `create()` function, you may need to use the following:
```
make_unique<char[]>(SIZE)
```

# Compile and Test

1. Type the following commands on Terminal.

```
g++ -o main *.cpp
```
```
./main
```

2. Input
* The first input is an integer to specify the circular buffer capacity.
* The second input is a string to push into the circular buffer.
* Example:
```
20
Spring is coming
```

Here are inputs and expected outputs for testing your program:

Test 1:
```
# inputs
20
Hello World!
# outputs
------------------------------------
Buffer Capacity: 20
Buffer Size: 12
Buffer isEmpty: 0
Buffer isFull: 0
------------------------------------
Buffer contents:
Hello World!
```

Test 2:
```
# inputs
5
ABCDEFGHIJK
# outputs
------------------------------------
Buffer Capacity: 5
Buffer Size: 5
Buffer isEmpty: 0
Buffer isFull: 1
------------------------------------
Buffer contents: 
GHIJK
```

Test 3:
```
# inputs
500
Clem then attempts to get access to Doctor Memory (the master control), and confuse the system with a riddle: "Why does the porridge bird lay his egg in the air?" This causes the President to shut itself down.
# outputs
------------------------------------
Buffer Capacity: 500
Buffer Size: 209
Buffer isEmpty: 0
Buffer isFull: 0
------------------------------------
Buffer contents: 
Clem then attempts to get access to Doctor Memory (the master control), and confuse the system with a riddle: "Why does the porridge bird lay his egg in the air?" This causes the President to shut itself down.
```

Test 4:
```
# inputs
50
Call me Ishmael. Some years ago—never mind how long precisely—having little or no money in my purse, and nothing particular to interest me on shore, I thought I would sail about a little and see the watery part of the world.
# outputs
------------------------------------
Buffer Capacity: 50
Buffer Size: 50
Buffer isEmpty: 0
Buffer isFull: 1
------------------------------------
Buffer contents: 
out a little and see the watery part of the world.
```

# Submit

Please upload your `CharCircularBuffer.cpp` file to `myCourses > Assignments > HW5`. Do not submit *.docx, *.pdf, *.txt, or *.zip file. Do not change other files.
