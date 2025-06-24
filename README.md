# Head First C - Lab 2
Need to install OpenCV library to work! (Give path in CMakeList.txt)
Using OpenCV library we need to make a image saving software when movement is detected through webcam.
---

## The program "Intruder detector"
- Opens up the webcam and starts taking pictures with a interval of ~10ms
- Calculates a flow index between the 2 latest pictures using dense optical flow algorithm
- If there is a high amount of movement compared to the mean of the last 10 calculated indexes, saves the image to a specified filepath

---
**The lab is coded with C++ because from OpenCV version 2.0 upwards there is no C API anymore**. 
Workaround is to use ``ccv`` by liuliu (C lib for computer vision), but needs an external library for coms with webcam for ex. ``libucv`` (needs also ``libusb``)
