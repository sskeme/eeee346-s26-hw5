#include <string>
#include "CharCircularBuffer.h"

int main() {
  int c;
  string msg;

  // receive the circular buffer capacity
  cin >> c;

  // create a circular buffer
  create(c);

  // receive a message for the circular buffer
  getline(cin >> ws, msg);

  // put each character of the message into the circular buffer
  cout << endl;
  cout << "Putting values in the circular buffer" << endl;
  for (int i=0; i<msg.size(); i++) {
    put(msg.at(i));
  }
  printStatus();

  // print out what is in the circular buffer
  cout << "Buffer contents: " << endl;
  while (!isEmpty()) {
    cout << get();
  }
  cout << endl;

  // reset the circular buffer
  cout << endl;
  cout << "Resetting buffer" << endl;
  reset();

  return 0;
}
