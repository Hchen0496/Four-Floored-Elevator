# 4-Floored-Elevator
- Built this in a team of 2
- Here is the code for both original and remake. What's the difference? Let's find out

# Original Hardware
You need the following hardware:
- H-bridge,
- planetary Gear DC Motor,
- 4x Push Button,
- Arduino,
- Arduino IDE,

# Original Code
- Is basically a Trial and Error of how long the elevator should stop for each floor 
- Upload it on the Arduino IDE to the Arduino Board and then it should run accordingly

# Original: How does it work?
- Once you upload and compile all you have to do is press what floor button you wanted it to go to, the DC Motor will start running based on the duration that you input for each floor, it'll stop once it hit that duration. 

# Remake Version Hardware
You need the following hardware:
- H-bridge,
- planetary Gear DC Motor,
- 3x Push Button,
- Limit Switch,
- 7-Segment Display,
- 3x LEDs,
- Arduino,
- Arduino IDE,

# Remake Version Code
- The Remake is basically where its one less button and has more features

# Remake: How does it work?
- Once you compile and upload the code on the Arduino, and finish setting up the hardware all you have to do is press the push button to what floor you want. While the DC Motor is heading to that floor, a limit switch will activate and it will stop the elevator completely. The 7-segment display will then display the floor number that the user requested

# Troubleshoot

Original and Remake:
- My DC Motor isn't running: Please make sure you have an external 9V battery for the H-bridge, since the Arduino's battery is not enough to give out voltage to all the other components.

Remake:
- My 7-segment Display isn't work: please check that you connected to the proper pins on the Arduino
- My Limit Switch isn't working: Please check that you have solder your wires onto the Limit Switch and they are connected to the right pins
