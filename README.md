<<<<<<< HEAD
<div align="center">
  <p align="center">
   <h2>This repository covers two systems.</h2>
  </p>
</div>
# 1. Weight and Balance system
* This is the source code for the weight and balce monitoring system
  * wandbloadcell
    * Arduino source code that the load cell measures the weight of the cargo and transmits the weight data through Zigbee
  * wandbsw
    * Source code for calculating the center of gravity coordinates using the weight data received from the load cell system and the measured position information
  * wandbsystemfinalIDE
    * Final switch array system Arduino code using the library you made
# 2. overheadbeansystem
* This is the source code for the smart overheadbean ststem
  * overheadbinloadcell
    * Arduino source code that the load cell measures the weight of the load and determines whether there is space from the switch array system
  * overheadbinsw
    * Arduino source code to determine the available space inside the overhead bean using a switch array
# dot_matrix_with_keypad_library
* Arduino source code that linked switch and dot matrix using keypad library

# libray
name | purpose
--- | --- |
LedControl | dot matrix module use |
OzOLED | OLED module use |
position | Specify weight and C.G coordinates using OLED |
wandb | OLED, LED, dot matrix control functions using switches |

* The switch detects the weight of the cargo according to the on/off signal.
* The dot matrix displays the location of the cargo according to switch presses.
* OzOLED quantifies the overall center of gravity of the cargo.

