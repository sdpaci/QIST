// Program to bitmap any sequnce of points by displying only one point at a time in order.
// This program will output a user defined sequence or the BNL, SBU preprogrammed sequence to the grid
// User must enter points in sequence one by one and press 0 when finished (points in grid are indexed 1-64)
#include <stdio.h>
//#include <iostream>
//#include <StandardCplusplus.h> // https://github.com/maniacbug/StandardCplusplus
//#include <serstream>
//#include <string>
//#include <vector>
//#include <iterator>

//LIST OF PINS CORRESPONDING TO EACH ROW & COLUMN:
//|------------------------------------------|
//|Port B Pins: 16, 17, 19, 18,  0, 1, 32, 25|
//|____Columns:  1,  2,  3,  4,  5, 6,  7,  8|
//|------------------------------------------|
//|Port D Pins:  2, 14,  7,  8, 6, 20, 21,  5|
//|_______Rows:  1,  2,  3,  4, 5,  6,  7,  8|
//|------------------------------------------|

int portBPins[8] = { 16, 17, 19, 18, 0, 1, 32, 25 };  //Cols
int portDPins[8] = { 2, 14, 7, 8, 6, 20, 21, 5 };     //Rows
const int BLANKING_1 = 36;
const int BLANKING_2 = 37;
int seq[64][2];
//int **seq = new int*[1];
//seq[0] = new int[2];
// Vectors to output the characters B, N, L, S, and U to the grid.
int B[][2] = { {19,2},{19,14},{19,7},{19,8},{19,6},{19,20},{19,21},{19,5},{18,2},{18,6},{18,5},{0,2},{0,6},{0,5},{1,14},{1,7},{1,8},{1,20},{1,21} };
int brows = sizeof(B) / sizeof(B[0]);

int N[][2] = { {17,2},{17,14} ,{17,7} ,{17,8} ,{17,6} ,{17,20} ,{17,21} ,{17,5},{32,2},{32,14} ,{32,7} ,{32,8} ,{32,6} ,{32,20} ,{32,21} ,{32,5},{19,21},{18,20},{18,6},{0,8},{0,7},{1,14} };
int nrows = sizeof(N) / sizeof(N[0]);

int L[][2] = { {19,2},{19,14},{19,7},{19,8},{19,6},{19,20},{19,21},{19,5},{18,2},{0,2},{1,2} };
int lrows = sizeof(L) / sizeof(L[0]);

int S[][2] = { {19,14}, {18,2},{0,2},{1,14},{1,7},{1,8},{0,6},{18,6},{19,20},{19,21},{18,5},{0,5},{1,21} };
int srows = sizeof(S) / sizeof(S[0]);

int U[][2] = { {19,14},{19,7},{19,8},{19,6},{19,20},{19,21},{19,5},{18,2},{0,2},{1,14},{1,7},{1,8},{1,6},{1,20},{1,21},{1,5} };
int urows = sizeof(U) / sizeof(U[0]);






//const int cols = sizeof(B[0]) / sizeof(int);
int (*pts)[2];
int nextChar = 0;
int rows;
//int ind = 1;
int SIZE;


void setup() {
  // put your setup code here, to run once:
  // Set all cols/row pins to outputs
  for (int i = 0; i < 8; i++) {
    pinMode(portBPins[i], OUTPUT);
    pinMode(portDPins[i], OUTPUT);
  }
  // Write all pins to low (selected point will be gated later)
  for (int i = 0; i < 8; i++) {
    digitalWriteFast(portBPins[i], LOW);
    digitalWriteFast(portDPins[i], LOW);
  }
  // Set up Serial Monitor for user input
  Serial.begin(57600); //9600
  Serial.setTimeout(10);
  while (!Serial);
}

void loop(int choice) {
  // put your main code here, to run repeatedly:
  if (choice == 1) {
    // Output preprogrammed BNL/SBU customSequence
    switch (nextChar) {
    case 0:
      pts = B;
      rows = brows;
      break;
    case 1:
      pts = N;
      rows = nrows;
      break;
    case 2:
      pts = L;
      rows = lrows;
      break;
    case 3:
      pts = S;
      rows = srows;
      break;
    case 4:
      pts = B;
      rows = brows;
      break;
    case 5:
      pts = U;
      rows = urows;
      break;
    }
  }
  else {
    // Output user defined sequence
    pts = seq;
    rows = SIZE;
  }
  int countp = 0;
  unsigned long startTimeChar = millis();
  unsigned long endTimeChar = startTimeChar;
  unsigned long goalTimeChar = 4000; // Run each character sequence for 4 Seconds
  while ((endTimeChar - startTimeChar) <= goalTimeChar) {
    int* point;
    if (countp < rows) {
      point = *(pts + countp); // Get next point in character
    }
    else { // if countp > length of vector for current character sequence, loop back to beginning of sequence
      countp = 0;
      point = *(pts + countp);
    }
//    unsigned long startTimePt = millis();
//    unsigned long endTimePt = startTimePt;
//    unsigned long goalTimePt = 10; // Run each point in character sequence for 10 ms
//    while ((endTimePt - startTimePt) <= (goalTimePt)) {
//      digitalWriteFast(BLANKING_1, HIGH);
      digitalWriteFast(BLANKING_2, HIGH);
      digitalWriteFast(*point, HIGH);
      digitalWriteFast(*(point + 1), HIGH);
      delayMicroseconds(10); // Blanking and point high for 10 us (for 90% duty cycle)
//      digitalWriteFast(BLANKING_1, LOW);
      digitalWriteFast(BLANKING_2, LOW);
      digitalWriteFast(*point, LOW);
      digitalWriteFast(*(point + 1), LOW);
      delayMicroseconds(990); // Blanking and point low for 90 us (for 90% duty cycle)
//      endTimePt = millis();
//    }
    countp++;
    endTimeChar = millis();
  }
  nextChar++;
  if (nextChar > 5)
    nextChar = 0;
}


int main(int argc, const char* argv[]) {
  int receivedInt = -1;
  int receivedPt = -1;
  setup();
  Serial.println("Would you like to (1) use the preprogrammed sequence or (2) create your own? ");
  // send data only when you receive data:
  while (Serial.available() == 0) {}
  receivedInt = Serial.parseInt();
  Serial.clear();
  Serial.print("You entered: ");
  Serial.println(receivedInt);
  while ((receivedInt != 1) && (receivedInt != 2)) {
    Serial.println("INVLAID INPUT. Try Again: Enter 1 or 2");
    Serial.println("Would you like to (1) use the preprogrammed sequence or (2) create your own? ");
    delay(10);
    while (Serial.available() == 0) {}
    receivedInt = Serial.parseInt();
    Serial.clear();
    Serial.print("You entered: ");
    Serial.println(receivedInt);
  }
  if (receivedInt == 1) {
    loop(receivedInt);
  }
  else if (receivedInt == 2) {
    int ind = 1;
    Serial.print("Enter the total number of points in your sequnce:");
    while (Serial.available() == 0) {}
    SIZE = Serial.parseInt();
    Serial.clear();
    Serial.println("Enter your sequence:");
    while (receivedPt != 0) {
      Serial.print("Enter point #");
      Serial.print(ind);
      Serial.println(" If you are finished press (0):");
      while (Serial.available() == 0) {}
      receivedPt = Serial.parseInt();
      Serial.clear();
      Serial.print("You entered: ");
      Serial.println(receivedPt);
      while ((receivedPt < 0) || (receivedPt > 64)) {
        Serial.println("INVLAID INPUT. Try Again: Enter a number from 1 to 64.");
        Serial.print("Enter point #");
        Serial.print(ind);
        Serial.println(" If you are finished press (0):");
        receivedPt = Serial.parseInt();
        Serial.clear();
        Serial.print("You entered: ");
        Serial.println(receivedPt);
      }
      if (receivedPt == 0) {
        Serial.println("Sequence Entered.");
        goto label;
      }
      seq[ind - 1][0] = portBPins[(receivedPt - 1) / 8];
      seq[ind - 1][1] = portDPins[(receivedPt - 1) % 8];
      //if (ind > 1) {
      //  int **temp = new int*[ind];
      //  for (int i = 0; i < ind; i++) {
      //    temp[i] = new int[2];
      //  }
      //  for (int i = 0; i < ind - 1; i++) {
      //    // to copy from old array
      //    temp[i][0] = seq[i][0];
      //    temp[i][1] = seq[i][1];
      //  }
      //  // to add new additional value
      //  temp[ind - 1][0] = portBPins[(receivedPt - 1) / 8];
      //  temp[ind - 1][1] = portDPins[(receivedPt - 1) % 8];
      //  delete[] seq;
      //  seq = temp;
      //}
      /*else {
        seq[0][0] = portBPins[(receivedPt - 1) / 8];
        seq[0][1] = portDPins[(receivedPt - 1) % 8];
      }*/
      ind++;
    }
  label:
    loop(receivedInt);
  }
  else {
    Serial.println("A PROBLEM OCCURED");
  }
  return 0;
}
