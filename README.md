# Head First C - Lab 2
Need to install OpenCV library to work! (Give path in CMakeList.txt)
Using OpenCV library we need to make a image saving software when movement is detected through webcam.

---
**The lab is coded with C++ because from OpenCV version 2.0 upwards there is no C API anymore**. 
Workaround is to use ``libccv`` (C lib for computer vision), but needs an external library for coms with webcam for ex. ``libucv`` (needs also ``libusb``)
