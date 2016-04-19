int joy1 = 0;
int joy2 = 0;
String data = "";
int switchPin = 8;
int led;
boolean lastButton = HIGH;
boolean currentButton = HIGH;
boolean ledOn = false;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  if (last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() {
  joy1 = constrain(analogRead(0) + 24, 0, 1023); //correction
  joy2 = analogRead(1);
  
  currentButton = debounce(lastButton);
  if (lastButton == HIGH && currentButton == LOW)
  {
    ledOn = !ledOn;
  }
  lastButton = currentButton;
  
  if (ledOn == HIGH) {
    led = 1;
  } else {
    led = 0;
  }

  data = String(joy1) + "," + String(joy2) + "," + String(led);
  
  Serial.println(data);
  delay(50);
}
