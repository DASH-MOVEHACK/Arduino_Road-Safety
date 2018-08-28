#define START_CMD_CHAR '>'
#define END_CMD_CHAR '\n'
#define DIV_CMD_CHAR ','

#define DEBUG 1 // Set to 0 if you don't want serial output of sensor data

String inText;
float value0, value1, value2;
const int trigPin = 6;
const int echoPin = 5;
// defines variables
long duration;
int distance,i;

void setup() {
  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(9,OUTPUT);
  Serial.begin(9600);
  //Serial.flush();
}

void loop()
{

 digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
//Serial.println(distance);
delay(500); 
if(distance<3)
{
  digitalWrite(9,HIGH);
  delay(80);
  digitalWrite(9,LOW);
  //Serial.flush();
  int inCommand = 0;
  int sensorType = 0;
  //while(true){
  unsigned long logCount = 0L;

  char getChar = ' ';  //read serial

  // wait for incoming data
  if (Serial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag 
  getChar = Serial.read();
  if (getChar != START_CMD_CHAR) return; // if no command start flag, return to loop().

  // parse incoming pin# and value  
  sensorType = Serial.parseInt(); // read sensor typr
  logCount = Serial.parseInt();  // read total logged sensor readings
  value0 = Serial.parseFloat();  // 1st sensor value
  value1 = Serial.parseFloat();  // 2rd sensor value if exists
  value2 = Serial.parseFloat();  // 3rd sensor value if exists

  if (DEBUG) {
    
    if(sensorType==98)
    {
      Serial.print("Sensor type: ");
      Serial.println("GPS");
//      Serial.print("Sensor log#: ");
//      Serial.println(logCount);
      Serial.print("Latitude ");
      Serial.println(value0);
      Serial.print("Longitude ");
      Serial.println(value1);
      Serial.print("Altitude ");
      Serial.println(value2);
      Serial.println("-----------------------");
      delay(1000);
    }
  }
  else
  {
    digitalWrite(9,LOW);
  }
    
    
  
  }
}



