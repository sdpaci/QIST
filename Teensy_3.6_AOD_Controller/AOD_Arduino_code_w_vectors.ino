#include <ArduinoComponents.h>

//#include <StandardCplusplus.h>
//#include <system_configuration.h>
//#include <unwind-cxx.h>
//#include <utility.h>

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

std::vector<int> portBPins { 16, 17, 19, 18, 0, 1, 32, 25 };  //Cols
std::vector<int> portDPins { 2, 14, 7, 8, 6, 20, 21, 5 };     //Rows
const int BLANKING_1 = 36;
const int BLANKING_2 = 37;
std::vector<std::vector<int>> seq;
// Vectors to output the characters B, N, L, S, and U to the grid.
std::vector<std::vector<int>> B { {19, 2}, {19, 14}, {19, 7}, {19, 8}, {19, 6}, {19, 20}, {19, 21}, {19, 5}, {18, 2}, {18, 6}, {18, 5}, {0, 2}, {0, 6}, {0, 5}, {1, 14}, {1, 7}, {1, 8}, {1, 20}, {1, 21} };
std::vector<std::vector<int>> N { {17, 2}, {17, 14} , {17, 7} , {17, 8} , {17, 6} , {17, 20} , {17, 21} , {17, 5}, {32, 2}, {32, 14} , {32, 7} , {32, 8} , {32, 6} , {32, 20} , {32, 21} , {32, 5}, {19, 21}, {18, 20}, {18, 6}, {0, 8}, {0, 7}, {1, 14} };
std::vector<std::vector<int>> L { {19, 2}, {19, 14}, {19, 7}, {19, 8}, {19, 6}, {19, 20}, {19, 21}, {19, 5}, {18, 2}, {0, 2}, {1, 2} };
std::vector<std::vector<int>> S { {19, 14}, {18, 2}, {0, 2}, {1, 14}, {1, 7}, {1, 8}, {0, 6}, {18, 6}, {19, 20}, {19, 21}, {18, 5}, {0, 5}, {1, 21} };
std::vector<std::vector<int>> U { {19, 14}, {19, 7}, {19, 8}, {19, 6}, {19, 20}, {19, 21}, {19, 5}, {18, 2}, {0, 2}, {1, 14}, {1, 7}, {1, 8}, {1, 6}, {1, 20}, {1, 21}, {1, 5} };
int brows = B.size();
int nrows = N.size();
int lrows = L.size();
int srows = S.size();
int urows = U.size();
const int cols = B[0].size();
std::vector<int> nextPoint(std::vector<std::vector<int>>, int);
std::vector<std::vector<int>> pair(std::vector<int>, std::vector<int>);
std::vector<std::vector<int>>allpoints = pair(portBPins, portDPins); // vector containing vectors of column/row pairs for all 64 points in the grid
std::vector<std::vector<int>> charvec;
int nextChar = 0;
int rows;


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
    // Output preprogrammed BNL/SBU sequence
    switch (nextChar) {
      case 0:
        charvec = B;
        rows = brows;
        break;
      case 1:
        charvec = N;
        rows = nrows;
        break;
      case 2:
        charvec = L;
        rows = lrows;
        break;
      case 3:
        charvec = S;
        rows = srows;
        break;
      case 4:
        charvec = B;
        rows = brows;
        break;
      case 5:
        charvec = U;
        rows = urows;
        break;
    }
  }
  else {
    // Output user defined sequence
    charvec = seq;
    rows = seq.size();
  }
  int countp = 0;
  unsigned long startTimeChar = millis();
  unsigned long endTimeChar = startTimeChar;
  unsigned long goalTimeChar = 4000; // Run each character sequence for 4 Seconds
  while ((endTimeChar - startTimeChar) <= goalTimeChar) {
    std::vector<int> point;
    if (countp < rows) {
      point = nextPoint(charvec, countp); // Get next point in character
    }
    else { // if countp > length of vector for current character sequence, loop back to beginning of sequence
      countp = 0;
      point = nextPoint(charvec, countp);
    }
    unsigned long startTimePt = millis();
    unsigned long endTimePt = startTimePt;
    unsigned long goalTimePt = 10; // Run each point in character sequence for 10 ms
    while ((endTimePt - startTimePt) <= (goalTimePt)) {
      digitalWriteFast(BLANKING_1, HIGH);
      digitalWriteFast(BLANKING_2, HIGH);
      digitalWriteFast(point.at(0), HIGH);
      digitalWriteFast(point.at(1), HIGH);
      delay(0.01); // Blanking and point high for 10 us (for 90% duty cycle)
      digitalWriteFast(BLANKING_1, LOW);
      digitalWriteFast(BLANKING_2, LOW);
      digitalWriteFast(point.at(0), LOW);
      digitalWriteFast(point.at(1), LOW);
      delay(0.09); // Blanking and point low for 90 us (for 90% duty cycle)
      endTimePt = millis();
    }
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
  Serial.print("You entered: ");
  Serial.println(receivedInt);
  while ((receivedInt != 1) && (receivedInt != 2)) {
    Serial.println("INVLAID INPUT. Try Again: Enter 1 or 2");
    Serial.println("Would you like to (1) use the preprogrammed sequence or (2) create your own? ");
    while (Serial.available() == 0) {}
    receivedInt = Serial.parseInt();
    Serial.print("You entered: ");
    Serial.println(receivedInt);
  }
  if (receivedInt == 1) {
    loop(receivedInt);
  }
  else if (receivedInt == 2) {
    int ind = 1;
    Serial.println("Enter your sequence:");
    while (receivedPt != 0) {
      while (Serial.available() == 0) {}
      Serial.print("Enter point #");
      Serial.print(ind);
      Serial.println(" If you are finished press 0):");
      receivedPt = Serial.parseInt();
      Serial.print("You entered: ");
      Serial.println(receivedPt);
      while ((receivedPt < 0) || (receivedPt > 64)) {
        Serial.println("INVLAID INPUT. Try Again: Enter a number from 1 to 64.");
        Serial.print("Enter point #");
        Serial.print(ind);
        Serial.println(" If you are finished press 0):");
        receivedPt = Serial.parseInt();
        Serial.print("You entered: ");
        Serial.println(receivedPt);
      }
      if (receivedPt == 0) {
        Serial.println("Sequence Entered.");
        goto label;
      }
      std::vector<int> v1;
      // Add user input point to seq vector
      v1.push_back(allpoints.at(receivedPt).at(0));
      v1.push_back(allpoints.at(receivedPt).at(1));
      seq.push_back(v1);
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


std::vector<int> nextPoint(std::vector<std::vector<int>> vec, int count)
{
  // Takes in 2D vector and count and returns sub-vector at count index
  // from inside 2D vector
  std::vector<int> newvec;
  newvec.push_back(vec.at(count).at(0));
  newvec.push_back(vec.at(count).at(1));
  return newvec;
}


std::vector<std::vector<int>> pair(std::vector<int> a, std::vector<int> b)
{
  // Takes in two 1D vectors of col pins and row pins and returns a 2D
  // vecotr containing all possible pairs of those pins
  std::vector<std::vector<int>> result;
  for (int j = 0; j < a.size(); j++) {
    for (int k = 0; k < b.size(); k++) {
      std::vector<int> v1;
      v1.push_back(a.at(j));
      v1.push_back(b.at(k));
      result.push_back(v1);
    }
  }
  return result;
}
