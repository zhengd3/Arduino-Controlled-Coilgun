int sensor1 = 10;                     //Setting sensor 1 to digital pin #10.
int sensor2 = 3;                      //Setting sensor 2 to digital pin #3.
int coil1 = 7;                        //Setting signal to coil 1 to digital pin #7.
int coil2 = 5;                        //Setting signal to coil 2 to digital pin #7.

void setup()
{
  Serial.begin(9600);
  pinMode(sensor1, INPUT);            //Signal from sensor 1, as an INPUT.
  pinMode(sensor2, INPUT);            //Signal from sensor 2, as an INPUT.
  pinMode(coil1, OUTPUT);             //Signal to the Comparator to turn on Coil 1, as an OUTPUT.
  pinMode(coil2, OUTPUT);             //Signal to the Comparator to turn on Coil 2, as an OUTPUT.
}

void loop() 
{
  digitalWrite(coil1, 0);             //Turning off coil at initial state.
  while(digitalRead(sensor1)==0);     //Wait to see if the sensor 1 detects something.
  Serial.println("Coil: #1");         //Once sensor 1 detects someone, breaks out of while loop, and print text.
  digitalWrite(coil1, 1);             //Sends a HIGH signal from Arduino to comparator to turn on coil 1.
  delay(20);                          //The delay of 20 millisecond allows coil to be on for 20 millisecond.
  digitalWrite(coil1, 0);             //Sends a LOW signal from Arduino to comparator to turn off coil 1.
  while(digitalRead(sensor2)==0);     //Wait to see if the sensor 2 detects something.
  Serial.println("Coil: #2");         //Once sensor 2 detects someone, breaks out of while loop, and print text.
  digitalWrite(coil2, 1);             //Sends a HIGH signal from Arduino to comparator to turn on coil 2.
  delay(9);                           //The delay of 9 millisecond allows coil to be on for 9 millisecond.
  digitalWrite(coil2, 0);             //Sends a HIGH signal from Arduino to comparator to turn on coil 2.
  delay(1000);                        //Wait for 1 second before looping back to the beginning of the loop().
}

