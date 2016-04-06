#define PULSE_PIN 8      // Pin for synchronising communication
#define SYNC_DELAY 64    // Delay (us) for synchronizing pulse


// Pins to use for parallel communication
int inputPins[] = {
  0, 1, 2, 3, 4, 5, 6, 7
};

// Buffer for input values
int inputValues[8];


// Simulate NAROM rocket radio
// Set synchronising pin high, wait 64 ms, set low, wait 64 ms
void sendPulseAndWait() {
    Serial.println("Sending pulse!");
    
    digitalWrite(PULSE_PIN, HIGH);
    
    delayMicroseconds(SYNC_DELAY);
    
    digitalWrite(PULSE_PIN, LOW);
    
    delayMicroseconds(SYNC_DELAY);
}

// Read values from parallel pins
void readValues() {
    Serial.println("Reading values...");
  
    for (int i = 0; i < 8; i++) {
        inputValues[i] = digitalRead(i);
    }
}

// Print values from parallel pins
void printValues() {
    Serial.print("Values: ");
  
    for (int i = 0; i < 8; i++) {
        Serial.print(inputValues[i]);
    }

    Serial.println();
}


void setup() {
    Serial.begin(9600);
  
    // Set up input pins
    for (int i = 0; i < 8; i++) {
        pinMode(inputPins[i], INPUT);
    }
    
    // Set up pulse pin
    pinMode(PULSE_PIN, OUTPUT);
    
    // Set pulse pin low
    digitalWrite(PULSE_PIN, LOW);
}

void loop() {    
    sendPulseAndWait();
    readValues();
    printValues();
}
