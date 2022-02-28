void setup() {
    //Columns
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(25, OUTPUT);
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
  pinMode(37, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // run gate for AOM with known rise/fall time
  // maximum amount of time the AOD takes to effect a change
  // on its part (ie apply change in RF and allow incoming
  // laser to respond to change) is the minimum amount of time
  // the AOM period can theoretically be (plus AOM's own rise/fall
  // time). (AOM period should be considerd with pulse towards end
  // of the period to allow changes to take effect).
  // verify maximum amount of time required for AOD to effect change
  // on its part and write code to set AOM period to this time st.
  // once change takes effect gate opens and displays pulse for min
  // amount of time possible and then closes. When AOM gate closes
  // this is the signal to the AOD to begin applying an RF sequence
  // change.
  // verify experimentlay possible limitations:
  //    AOM time to effect
  //    AOD time to effect
  //    account for and quantify AOD ?us delay

  digitalWriteFast(AOM_PIN, HIGH);
  digitalWriteFast(AOD_PIN_N, HIGH);
  delayMicroseconds(10); // delay is sum of AOM rise time, AOD Rise time, and electronic delay
  digitalWriteFast(AOM_PIN, LOW);
  digitalWriteFast(AOD_PIN_N, LOW);
  delayMicroseconds(990);

  
}
