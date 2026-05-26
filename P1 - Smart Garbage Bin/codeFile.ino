#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo lidServo;
LiquidCrystal_I2C lcd(0x20, 16, 2);

const int trigPinLid = 9;
const int echoPinLid = 10;

const int trigPinBin = 12;
const int echoPinBin = 11;

const int ledPin = 3;
const int buzzerPin = 4;

int distanceLid;
int distanceBin;


void BinStatus(int distanceBin)
{
    lcd.setCursor(0,1);

    if(distanceBin >= 150)
    {
        lcd.print("Bin: EMPTY   ");
    }
    else if(distanceBin >= 50)
    {
        lcd.print("Bin: NORMAL  ");
    }
    else
    {
        lcd.print("Bin: FULL    ");
    }
}


void lidStatus(int distance){
  if(distance>0 && distance <= 50)
    {
        lidServo.write(90);
      	digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 1000);
        delay(200);
        noTone(buzzerPin);
      
        lcd.setCursor(0,0);
        lcd.print("Lid: OPEN   ");

    } else {
      	lidServo.write(0);
      	digitalWrite(ledPin, LOW);
      
      	lcd.setCursor(0,0);
        lcd.print("Lid: CLOSE   ");
    }
}


int ultrasonicDistance(int trigPin, int echoPin){
  	int distance;
    long duration;
  	// Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    // Read echo
    duration = pulseIn(echoPin, HIGH);

    // Convert to distance
    distance = (duration/2) * 0.034;
  
  	return distance;
}
  

void setup()
{
    pinMode(trigPinLid, OUTPUT);
    pinMode(echoPinLid, INPUT);
  
  	pinMode(trigPinBin, OUTPUT);
    pinMode(echoPinBin, INPUT);

    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);

    lidServo.attach(6);
    lidServo.write(0);
  
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("SYSTEM BOOTING");
    delay(3000);
    lcd.clear();

    Serial.begin(9600);
}

void loop()
{
  	// Bin EMPTY/FULL Detection
    distanceBin = ultrasonicDistance(trigPinBin, echoPinBin);
    Serial.print("Distance inside Bin: ");
    Serial.println(distanceBin);
  
  	BinStatus(distanceBin);
  
  	// HAND DETECTION
  	distanceLid = ultrasonicDistance(trigPinLid, echoPinLid);
    Serial.print("Distance: ");
    Serial.println(distanceLid);
    
  	lidStatus(distanceLid);
    
  	delay(1000);
}