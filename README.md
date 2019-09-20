# Data Logger (and using cool sensors!)

*A lab report by Eva Pilar Esteban Velasco.*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

From 0 to 1023, which is 1024 different values.
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

It has 10 bits of resolution because 1024 = 2^10.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

By plugging the common anode to power, and each of the LED legs to the corresponding Arduino pin and to the corresponding resistor. The resistor is then connected to ground. We could use this system as party lights, or to create an original ambient light.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

 When I apply force I can see form 0 to 1,002, but I assume it can go up until 1023 (I am unable to provide enough force manually for it to reach that value).

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

To find this out, I first looked at the relationship between force and resistance. When the force increases, the resistance increases but not in a linear way. Also, the voltage is inversely proportional to the resistance because it is a voltage divider. The mathematical formula for the output voltage is Vout = Vcc*(R/(R+FSR)). Therefore, the voltage varies inversely to the resistance, which increases in a logarithmic fashion with the force.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

Yes, I used the Arduino map() function for this. I decided to use the Red component of the RGB led to demonstrade the code for simplicity. The link to the code can be found below.

[Link to Fade Mapped Code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/Fade_Map.ino)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

Photo cell: 10K pull-down resistor from A0 to GND.

Softpot: 10K in series from one side pin to GND and 10K from the other side to Vcc.

Flex sensor: 10K, because it is similar to FSR.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

Flex sensor: Linearly with bent angle.

Photo cell: Logarithmic with illumination.

Softpot: Linearly with touch position.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

For this question, instead of using the in-built map() function, I did the mapping manually because I wanted to understand the mathematics behind it. 

[Link to Accelerometer LED Code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/LCD_Accel.ino)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

I really want to do this but I have too many deadlines this week, so I will probably just do it later on over a weekend or Fall Break!

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes. We need to know what actions correspond to each state because, if not, you can clear what you write. For example, if clear was the second state, whenever you try to read or write you will always clear it when going from one state to the other and it will not work. This is because the potentiometer uses a continuous range of values.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

Because we only want to perform the tasks once.

**c. How many byte-sized data samples can you store on the Atmega328?**

 You can store 1024 byte-sized data samples.

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

For analog data, since 2^10 = 1024 and 2^8 = 256, we need to divide the data by 2^2 which is 4. This way, 1024/4 = 256 is the maximum value and 0/4 = 0 is the minimum value, mapping the whole range.

For data from I2C devices, since each devices outputs values in a different range we could use the map() function if we know the range, or my mathematical approach for the accelerometer if we don't exactly know the range.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

We could use the put() function, indicating the address where we want to store the data. If you want to store several values linked to each other, you can create a structure, fill in its fields, and then use the put() function to store it.

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

For this part, I used the photocell as the sensor to vary from the accelerometer. 

[Link to SwitchState2 code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/SwitchState2.ino)
[Link to state0 code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/state0.ino)
[Link to state1 code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/state1.ino))
[Link to state2 code](//github.com/evaesteban/IDD-Fa19-Lab3/blob/master/state2.ino))


### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
