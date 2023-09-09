int ledPins[] = {13, 12, 11, 10}; // Array to hold the LED pin numbers
int userValue = 0; // Variable to hold the user input value

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  
  // Set the LED pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Prompt the user to enter a number between 0 and 15
  Serial.println("\nPlease enter a number between 0 and 15:");
}

void loop() {
  if (Serial.available()) { // Check if any data is available on the serial port
    userValue = Serial.parseInt(); // Read the incoming data as an integer
    
    // Check if the user input is within the range of 0-15
    if (userValue >= 0 && userValue <= 15) {
      // Convert the user input to binary and update the LED states
      for (int i = 0; i < 4; i++) {
        if (bitRead(userValue, i)) {
          digitalWrite(ledPins[i], HIGH);
        } else {
          digitalWrite(ledPins[i], LOW);
        }
      }
    } else {
      Serial.println("Invalid input.");
      // Prompt the user to enter a number between 0 and 15
      Serial.println("Please enter a number between 0 and 15:");
    }
  }
}
