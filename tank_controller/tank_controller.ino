#include <Wire.h>
#include <Adafruit_MCP4725.h>
#define voltsIn A0

Adafruit_MCP4725 dac1; // constructor
Adafruit_MCP4725 dac2; // constructor
uint32_t read_value = 3048;

void setup(void) {
  Serial.begin(9600);
  dac1.begin(0x60); // The I2C Address: Run the I2C Scanner if you're not sure  
  
  //setting turn stick to zero position
  dac2.begin(0x61); // The I2C Address: Run the I2C Scanner if you're not sure
  dac2.setVoltage(2048, true);  
}

void loop(void) {

     if (Serial.available() > 0) {
                // read the incoming byte:
                read_value = Serial.readString().toInt();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(read_value);
        }
  
    uint32_t dac_value;

    dac_value = read_value;
    
    dac1.setVoltage(dac_value, true);
    Serial.print("setting dac: ");
    Serial.println(dac_value);
    delay(250);
    

 
}
