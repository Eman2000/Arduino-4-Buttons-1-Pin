// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A5;
const int outPin = 13; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the buttons
int state = 0;              // used for storing what button was pressed

void setup() {
  Serial.begin(9600);       // initialize serial communications at 9600 bps
  pinMode(outPin, OUTPUT);  // set pin 13 as an output
}

void loop() {
  // print the results to the Serial Monitor:
  readSwitch();
  Serial.print("Value = ");
  Serial.println(sensorValue);
  Serial.print("State = ");
  Serial.println(state);

  if (state == 0) {                         //turns the LED off if a certain button is pressed
    digitalWrite(outPin, LOW);
    readSwitch();                           //contuines to poll the switch circuitry
  }

  if (state == 1) {                         //runs a program similar to the blink schetch if a certain button is pressed
    for (int i = 0; i < 2000; i++) {        //set a for loop that counts up to 2000
      if (i < 1000) {                       //if the for loop value is less than 1000 turn on the LED
        digitalWrite(outPin, HIGH);
        readSwitch();                       //contuines to poll the switch circuitry also provides about a 1 ms delay
      }
      if (i > 1000) {
        digitalWrite(outPin, LOW);          //if the for loop value is more than 1000 turn off the LED
        readSwitch();                       //contuines to poll the switch circuitry also provides about a 1 ms delay
      }
    }
  }

  if (state == 2) {                         //creates the 2 flash sequence of the LED and polls the switches between delays
    digitalWrite(outPin, HIGH);
    delay(100);
    readSwitch();
    digitalWrite(outPin, LOW);
    delay(100);
    readSwitch();
    digitalWrite(outPin, HIGH);
    delay(100);
    readSwitch();
    digitalWrite(outPin, LOW);
    delay(250);
    readSwitch();
  }

  if (state == 3) {                         //Creates the fast blink effect and polls the switches after one cycle of the blink effect
    digitalWrite(outPin, HIGH);
    delay(75);
    digitalWrite(outPin, LOW);
    delay(75);
    readSwitch();
  }
}


void readSwitch () {                                  //creates the function to read the switch states
  sensorValue = analogRead(analogInPin);              //read the analog pin the switches are connected to 

  if (sensorValue < 800 && sensorValue > 750) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 0;
    delay(100);                                       //delay for debounce purposes
  }

  if (sensorValue < 749 && sensorValue > 650) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 1;
    delay(100);                                       //delay for debounce purposes
  }

  if (sensorValue < 649 && sensorValue > 425) {       //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 2;
    delay(100);                                       //delay for debounce purposes
  }

  if (sensorValue < 425 && sensorValue >= 0) {        //if the analog reading is within a certain range we know which button was pressed and set the state accordingly
    state = 3;
    delay(100);                                       //delay for debounce purposes
  }

  delay(1);                                           //delay for timeing purposes
}

