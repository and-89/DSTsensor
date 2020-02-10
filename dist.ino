// # Editor     : AND
// # Date       : 06/11/19

#define  MAX_RANG      (520)//the max measurement vaule of the module is 520cm(a little bit longer than  effective max range)
#define  ADC_SOLUTION      (1023.0)//ADC accuracy of Arduino UNO is 10bit
//#define SPEAKER 3

//int BassTab[]={1911,1702,1516,1431,1275,1136,1012};//bass 1~7 speaker setup
int sensityPin = A0;
//int sensityPin2 = A1;
int Buzzerrelay = 2; 
void setup() {
  // Serial init
  Serial.begin(9600);
  pinMode(Buzzerrelay, OUTPUT);
}
float dist_t, sensity_t;
//float dist_t2, sensity_t2;
void loop() {
  // read the value from the sensor:
 sensity_t = analogRead(sensityPin);
// sensity_t2 = analogRead(sensityPin2);
  // turn the ledPin on

 dist_t = sensity_t * MAX_RANG  / ADC_SOLUTION;
// dist_t2 = sensity_t2 * MAX_RANG  / ADC_SOLUTION;
 if (dist_t > 100) 
 {
  digitalWrite(Buzzerrelay, LOW);
 }
 else
 {
    digitalWrite(Buzzerrelay, HIGH);
  }
 /*  if (dist_t2 > 100) 
 {
  digitalWrite(Buzzerrelay, LOW);
 }
 else
 {
    digitalWrite(Buzzerrelay, HIGH);
  }
  */
 Serial.print(dist_t, 0);
// Serial.println((String)"d1:"+dist_t+" d2:"+dist_t2);
 Serial.println("cm");

 delay(100);

}
