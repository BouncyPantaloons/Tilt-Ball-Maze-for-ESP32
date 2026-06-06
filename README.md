# Tilt-Ball-Maze-for-ESP32
A little game built to emulate classic tiltable wooden maze games. This was the result for the hardware Programming class for University.

This project was built for the ESP32-S3.<br/>
I used ILI9488 TFT display in combination with the TFT_eSPI libary to handle rendering.<br/>
I used a gyro (MPU6050) for reading the tilt of the device and the FastIMU library to interface with it.<br/>
Finally I used the ezButton library for button control.<br/>
