#include <IRremote.h>

// Motor 1 Pins
int en1 = 10;
int in1 = 9;
int in2 = 8;

// Motor 2 Pins
int en2 = 5;
int in3 = 4;
int in4 = 3;

int irPin = 11;

void setup() {
  
  Serial.begin(9600);
  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);
  
  pinMode(en1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  
  if (IrReceiver.decode()) { // If the sensor hears a signal...
    
    // Get the code from the remote
	uint8_t code = IrReceiver.decodedIRData.command;
    Serial.print(code, HEX);
	Serial.print(" | ");
    
    // LOGIC: If code matches the UP button
    switch(code)
    {
        case 0xA:
            moveForward();
            Serial.println("FORWARD");
            break;

        case 0x8:
            moveBackward();
            Serial.println("BACKWARD");
            break;

        case 0x0:
            stopMotors();
            Serial.println("STOP");
            break;

        default:
            Serial.println("UNKNOWN COMMAND");
            break;
    }

    IrReceiver.resume();
  }
}

void moveForward(){
  // Set Speeds (0-255)
  analogWrite(en1, 200); 
  analogWrite(en2, 200);

  // Motor 1: Clockwise
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Motor 2: Counter-Clockwise
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveBackward(){
  // Set Speeds (0-255)
  analogWrite(en1, 200); 
  analogWrite(en2, 200);

  // Motor 1: Clockwise
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  // Motor 2: Counter-Clockwise
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void stopMotors(){
  // Set Speeds (0-255)
  analogWrite(en1, 0); 
  analogWrite(en2, 0);

  // Motor 1: Clockwise
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  // Motor 2: Counter-Clockwise
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}