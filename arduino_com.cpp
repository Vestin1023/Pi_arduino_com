void setup() {
    Serial.begin(9600); // UART baud rate
  }
  
  void loop() {
    Serial.println("HelloWorld"); // Send "HelloWorld" to UART
    delay(1000); // Send every second
  }