const int numReadings = 20;
int ave = 0 ;
int sum = 0 ;
int relay1 = 1;
int* readings;
int index = 0;
int standard = 500; //need to fill your standard


void setup() {
  pinMode(relay1,OUTPUT);
  Serial.print(9600);
  analogRead(A0);
  readings = calloc(numReadings, sizeof(int));
}



void loop() {
  if (index > numReadings - 1){
    index = 0;
  }
  readings[index++] = analogRead(A0);
  ave = sumReading(readings, numReadings) / numReadings;
  Serial.println("H：");Serial.println(analogRead(A0));Serial.println("\n");
  if (ave > standard) {
    digitalWrite(relay1,HIGH);
    delay(3000);
  }else{
    digitalWrite(relay1,LOW);
  }
  delay(1000);
}








int removeExtra(int* A, int num, int avg){
  int i;
  for( i = 0 ; i < num ; i++ ){
    if (A[i] > 2 * avg){
      A[i] = 0;                  
    }
  }
  return 0;
}


int sumReading(int* A, int num){
  int i;
  int sum = 0;
  for( i = 0 ; i < num ; i++ ){
    sum += A[i];
  }
  return sum;
}


