//#include "Sabertooth.ino"
#include <Kangaroo.h>
#include "RMCKangaroo1.h"
#include <Wire.h>

#define MESSAGE_LENGTH 8
#define I2CAddress 7
#define LINEAR_ACTUATOR_1 1
//
RMCKangaroo1 linearK(11, 10);
RMCKangaroo1 motorK(22, 23);

void setup() {
	pinMode(4, OUTPUT);
	digitalWrite(4, HIGH);
	Serial.begin(9600);
	i2cSetup();
	linearK.targetVal1 = 1000;
	motorK.targetVal1 = 1000;
}
void loop() {
	digitalWrite(4, LOW);
	linearK.loop();
	motorK.loop();
	digitalWrite(4, HIGH);
	delay(100);
}


void i2cSetup() {
	Wire.begin(I2CAddress);
	Wire.setClock(96000L);
	Wire.onReceive(onI2CReceive);
	Wire.onRequest(onI2CRequest);
}

void onI2CReceive(int numByte) {
	int message[MESSAGE_LENGTH];
	int i = 0;

	for (int i = 0; i < numByte; i++) {
		message[i] = Wire.read();

	}
	/*int command = message[0];
	switch (command)
	{
	case 1:
		linearK.targetVal1 = map(message[2], 0, 100, 143, 4450);
		break;
	case 2:
		motorK.targetVal1 = map(message[2], 0, 100, 143, 4450);
		break;
	default:
		break;
	}*/
}

void onI2CRequest() {
	//int scaledTargerVal = map(linearK.targetVal1, 143, 4450, 0, 100);
	//int scaledCurrentVal = map(linearK.status1.value(), 143, 4450, 0, 100);
	//int scaledSpeed = map(linearK.speed1, 0, 500, 0, 5);
	//Wire.write(LINEAR_ACTUATOR_1); // Device ID
	//Wire.write(scaledTargerVal); //Set Value
	//Wire.write(scaledCurrentVal); //Current Value
	//Wire.write(scaledSpeed); // Speed for L.Actuator, motor will ignore
}

