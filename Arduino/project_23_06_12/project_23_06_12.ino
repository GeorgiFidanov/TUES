#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <SD.h> // Library for SD card communication

SoftwareSerial bluetooth(0, 1); // RX, TX pins for Bluetooth communication
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // LCD keypad shield pins

String lastMessage = ""; // Variable to store the last received message
boolean newMessageReceived = false; // Flag to indicate if a new message is received
boolean isConnected = false; // Flag to indicate if connected to a device
int messageSize = 0; // Size of the message stored in EEPROM
int startIndex = 0; // Start index for displaying message on LCD
unsigned long lastDataReceivedTime = 0; // Timestamp of the last data received

void inf_display(String Message, String Type){ //this is an infinte loop
  lcd.setCursor(0, 0);
  lcd.print(Type);
  lcd.setCursor(0, 1);
  lcd.print(Message.substring(startIndex, startIndex + 16));
  delay(500); // Display the first 16 characters and add a new one each half a second

  startIndex++; // Increment the start index

  if (startIndex > Message.length()) {
    startIndex = 0; // Reset the start index to loop through the message
  }
}

void setup() {
  lcd.begin(16, 2); // Initialize the LCD display
  bluetooth.begin(9600); // Initialize the Bluetooth communication

  messageSize = EEPROM.read(0); // Read the size of the stored message from EEPROM
  if (messageSize > 0) {
    for (int i = 0; i < messageSize; i++) {
      lastMessage += char(EEPROM.read(i + 1)); // Read the stored message from EEPROM
    }
  }
  else{
    lcd.clear();
    lcd.print("NO SAVED INFO");
    delay(3000);
  }

  // Initialize the SD card
  if (!SD.begin(10)) {
    lcd.clear();
    lcd.print("SD card failed");
    delay(3000);
    return;
  } // even if this fails, now we can use SD options

  // Read the file and set it as the input message
  File file = SD.open("input.txt"); // "input.txt" will be autochanged later on in terminal app
  if (file) {
    while (file.available()) {
      lastMessage += char(file.read());
    }
    file.close();
  }
  else {
    lcd.clear();
    lcd.print("File not found");
    delay(3000);
  }
}

void loop() {
  // case 0: we run for the very first time and it's without Bluetooth
  if (!isConnected && !bluetooth.available() && lastMessage.length() <= 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("First time,");
    lcd.setCursor(0, 1);
    lcd.print("huh?");
    delay(3000);
  }
  // case 1: just started - no established connection at all
  else if (!isConnected && !bluetooth.available() && lastMessage.length() > 0) {
    lcd.clear();
    inf_display(lastMessage, "Saved message:"); //loop through the saved message
  }
  // case 2 - The upload passed but the connection is still up
  else if (isConnected) {
    if (!bluetooth.available()) {
      unsigned long currentTime = millis(); // Get the current time

      // Check if no new data received within 12 seconds
      if (currentTime - lastDataReceivedTime > 12000) {
        lcd.clear();
        lcd.print("Connection down");
        delay(3000); // Display "Connection lost" message for 3 seconds

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Try re-sending");
        lcd.setCursor(0, 1);
        lcd.print("to enable");
        delay(3000);

        isConnected = false; // Reset the flag to indicate disconnected state
      }
      else{
        return;//this is a safety measure to prevent spam
      }
    }
  }
  // case 3: first time uploading (for the boot)
  else if (!isConnected && bluetooth.available()) {
    String receivedMessage = bluetooth.readString(); // Read the complete message from Bluetooth

    lcd.clear();
    lcd.print("Connected");
    delay(3000); // Display "Connected" message for 3 seconds

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Checking if new");
    lcd.setCursor(0, 1);
    lcd.print("message is valid");
    delay(3000);

    if (receivedMessage.length() > 0) {
      lastMessage = receivedMessage; // Store the new message as the last message
      newMessageReceived = true; // Set the flag indicating a new message is received

      if (newMessageReceived) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Saving to EEPROM");
        lcd.setCursor(0, 1);
        lcd.print("the NEW message");
        delay(2000); // Display "Saving to EEPROM the NEW message"

        messageSize = lastMessage.length();
        EEPROM.write(0, messageSize); // Write the size of the message to EEPROM
        for (int i = 0; i < messageSize; i++) {
          EEPROM.write(i + 1, lastMessage.charAt(i)); // Write each character of the message to EEPROM
        }
        lcd.clear();
        lcd.print("Success");
        delay(2000);
      }
      else { // Reset the flag if no new message is received
        newMessageReceived = false;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("No new");
        lcd.setCursor(0, 1);
        lcd.print("message to save");
        delay(3000);
      }
      isConnected = true; // Set the flag to indicate connected state
    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Message length");
      lcd.setCursor(0, 1);
      lcd.print("is invalid!");
      delay(3000);
    }
  }
} // no need for case 4, where state is (+;+)
