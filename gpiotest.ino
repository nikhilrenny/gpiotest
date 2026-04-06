// SAFE GPIOs for XIAO nRF52840 Sense Plus
const uint8_t testPins[] = {
  D0,
  D1,
  D2,
  D3,
  D4,
  D5,
  D6,
  D7,
  D8,
  D9,

};

const uint8_t NUM_PINS = sizeof(testPins) / sizeof(testPins[0]);

void setup() {
  Serial.begin(115200);
  while (!Serial) {}

  Serial.println("XIAO Sense Plus GPIO test");

  for (uint8_t i = 0; i < NUM_PINS; i++) {
    pinMode(testPins[i], INPUT_PULLUP);
  }

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, HIGH);    // LEDs are active-LOW
  digitalWrite(LED_GREEN, HIGH);
}

void loop() {
  bool anyLow = false;

  for (uint8_t i = 0; i < NUM_PINS; i++) {
    int state = digitalRead(testPins[i]);

    Serial.print("Pin[");
    Serial.print(i);
    Serial.print("] = ");
    Serial.println(digitalRead(testPins[i]) == LOW ? "LOW" : "HIGH");


    if (state == LOW) {
      anyLow = true;
    }
  }

  Serial.println("----------------");

  if (anyLow) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }

  delay(300);
}
