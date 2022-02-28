#define C_A 16
#define C_B 17
#define C_C 19
#define C_D 18
#define C_E 0
#define C_F 1
#define C_G 32
#define C_H 25


#define R_A 2
#define R_B 14
#define R_C 7
#define R_D 8
#define R_E 6
#define R_F 20
#define R_G 21
#define R_H 5

//int nsfw[][2] = { {C_A,R_A},{C_A,R_B},{C_A,R_C},{C_B,R_A},{C_B,R_C},{C_C,R_A},{C_C,R_B},{C_C,R_C},{C_C,R_D},{C_C,R_E},{C_C,R_F},{C_C,R_G},{C_C,R_H},{C_D,R_A},{C_D,R_H},{C_E,R_A},{C_E,R_H},{C_F,R_A},{C_F,R_B},{C_F,R_D},{C_F,R_E},{C_F,R_F},{C_F,R_C},{C_F,R_H},{C_F,R_G},{C_G,R_A},{C_G,R_C},{C_H,R_A},{C_H,R_B},{C_H,R_C} };
//int nsfwrows = sizeof(nsfw) / sizeof(nsfw[0]);


//int B[][2] = { {19,2},{19,14},{19,7},{19,8},{19,6},{19,20},{19,21},{19,5},{18,2},{18,6},{18,5},{0,2},{0,6},{0,5},{1,14},{1,7},{1,8},{1,20},{1,21} };
int B[][2] = { {C_F,R_A},{C_F,R_B},{C_F,R_C},{C_F,R_D},{C_F,R_E},{C_F,R_F},{C_F,R_G},{C_F,R_H},{C_E,R_A},{C_D,R_A},{C_C,R_B},{C_C,R_C},{C_C,R_D},{C_C,R_F},{C_C,R_G},{C_E,R_E},{C_D,R_E},{C_E,R_H},{C_D,R_H} };
int brows = sizeof(B) / sizeof(B[0]);

int N[][2] = { {32,2},{32,14} ,{32,7} ,{32,8} ,{32,6} ,{32,20} ,{32,21} ,{32,5},{17,2},{17,14} ,{17,7} ,{17,8} ,{17,6} ,{17,20} ,{17,21} ,{17,5},{1,21},{0,20},{0,6},{18,8},{18,7},{19,14} };
//int N[][2] = { {
int nrows = sizeof(N) / sizeof(N[0]);

int L[][2] = { {1,2},{1,14},{1,7},{1,8},{1,6},{1,20},{1,21},{1,5},{0,2},{18,2},{19,2} };
int lrows = sizeof(L) / sizeof(L[0]);

int S[][2] = { {1,14}, {0,2},{18,2},{19,14},{19,7},{19,8},{18,6},{0,6},{1,20},{1,21},{0,5},{18,5},{19,21} };
int srows = sizeof(S) / sizeof(S[0]);

int U[][2] = { {1,14},{1,7},{1,8},{1,6},{1,20},{1,21},{1,5},{0,2},{18,2},{19,14},{19,7},{19,8},{19,6},{19,20},{19,21},{19,5} };
int urows = sizeof(U) / sizeof(U[0]);

int T[][2] = { {C_G,R_H},{C_F,R_H},{C_E,R_H},{C_D,R_H},{C_C,R_H},{C_E,R_A},{C_E,R_B},{C_E,R_C},{C_E,R_D},{C_E,R_E},{C_E,R_F},{C_E,R_G} };
int trows = sizeof(T) / sizeof(T[0]);

int I[][2] = { {C_G,R_A},{C_F,R_A},{C_D,R_A},{C_C,R_A},{C_G,R_H},{C_F,R_H},{C_E,R_H},{C_D,R_H},{C_C,R_H},{C_E,R_A},{C_E,R_B},{C_E,R_C},{C_E,R_D},{C_E,R_E},{C_E,R_F},{C_E,R_G} };
int irows = sizeof(I) / sizeof(I[0]);

int Q[][2] = { {C_F,R_B},{C_F,R_C},{C_F,R_D},{C_F,R_E},{C_F,R_F},{C_F,R_G},{C_C,R_B},{C_C,R_C},{C_C,R_D},{C_C,R_E},{C_C,R_F},{C_C,R_G},{C_E,R_A},{C_D,R_A},{C_E,R_H},{C_D,R_H},{C_D,R_C},{C_B,R_A} };
int qrows = sizeof(Q) / sizeof(Q[0]);

int test[][2] = { {16,2},{19,7} };
int testrows = sizeof(test) / sizeof(test[0]);

const int BLANKING_2 = 37;
int seq[64][2];
int (*pts)[2];
int* point;
//int countp=0;
int nextChar = 0;
int rows;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  delay(100);
  //Columns
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(25, OUTPUT);
  Serial.print(testrows);
  //Rows
  pinMode(2, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(5, OUTPUT);
  //blanking
  //  pinMode(36, OUTPUT);
  pinMode(BLANKING_2, OUTPUT);


  //pts[0]=(int *)new int[50];
  //pts[1]=(int *)new int[50];



  
}

void loop() {
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
//  // put your main code here, to run repeatedly:
//  pts=T;
//  if (countp < trows) {
//    point = *(pts + countp); // Get next point in character
//  }
//  else { // if countp > length of vector for current character sequence, loop back to beginning of sequence
//    countp = 0;
//    point = *(pts + countp);
//  }
//  digitalWriteFast(BLANKING_2, HIGH);
//  Serial.println(*point);
//  Serial.println(*(point+1));
//  digitalWriteFast(*point, HIGH);
//  digitalWriteFast(*(point + 1), HIGH);
//  delayMicroseconds(10); // Blanking and point high for 10 us (for 90% duty cycle)
//  digitalWriteFast(BLANKING_2, LOW);
//  digitalWriteFast(*point, LOW);
//  digitalWriteFast(*(point + 1), LOW);
//  delayMicroseconds(990); // Blanking and point low for 90 us (for 90% duty cycle)
//  
//  countp++;
}
