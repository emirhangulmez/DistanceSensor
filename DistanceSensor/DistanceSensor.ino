
// Distance Sensor
// Developer: Emirhan Gulmez
// 12.05.2022 

#define echoPin 6
#define trigPin 7
#define buzzerPin 8
#define red 4
#define green 5

int maxRange = 50;
int minRange = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
 int measurement = distance(maxRange, minRange);
 buzzerMelody(measurement*10);
 digitalWrite(green, HIGH);
}

int distance(int maxrange, int minrange) {
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculate Distance
  distance = duration / 58.2;
  delay(50);

  if(distance >= maxrange || distance <= minrange)     
  return 0;
  return distance;
}

int buzzerMelody(int timeout) {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(green, LOW);
  delay(timeout);
  digitalWrite(green, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(timeout);
}
