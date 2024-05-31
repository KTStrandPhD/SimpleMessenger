# SimpleMessenger

## Table of Contents
1. Project Description
2. Project Instructions
3. Installation
4. Program Usage
   
### 1. Project Description
A simple messenger built using boost::interprocess. This is a coding project for an interview Dynon Avionics. This application creates a class object containing all of the project requirements, randomizes the input data, and then sends it through IPC messaging queue. The application then receives the message and prints the output.

C++ standard libraries are used. boost::interprocess is used to handle IPC messaging, boost::archive is utilized to serialize the data to allow for passing of std::string objects through the message_queue.

This has been compiled and tested on Ubuntu 22.04, x86 and MacOS Sonoma 14.2.0, arm64.

### 2. Project Instructions
Dynon Coding Project - Kyle Strand

For this project we would like you to demonstrate an IPC methodology. You are free to choose how you do it as long as it abides by the requirements below.

  Language: C and/or C++
  Must compile and run on Ubuntu 22.04.
  Must pass the following data structure through the IPC process.
  ```
  {
    int,
    float,
    string data (C or C++ formatted your choice)
    enum { type1, type2, type3 }
  }
  ```
  The receiving side should print out at minimum 10 different versions of the structure above in the following format:
    int: {value}, float: {value}, string: {value}, enum {human readable, e.g type1}  
  Code should be in a git repository so we can pull it and compile it for testing.

There is no time limit on this project. Feel free to reach out if you have any questions. We look forward to evaluating your project.

### 3. Installation
To install, simply run 
```
make
```
This makefile creates three separate execuatbles
  1. OneShotSndRcv - This program which will populate the data, send the message, then receive and print message.
  2. SendMessage - This program will populate the data and send the message. This clears any exisiting message queues.
  3. ReceiveMessage - This program will receive any messages in the queue. If no messages exist, nothing happens.

  **NOTE**
  The Makefile in the root folder is used to compile on linux distributions. If you are wishing to install this on MacOS, please use 'MakefileMacOS' found in 'extras' folder.

  ### 4. Program Usage
  This application can be run in a few different ways

  1. Run OneShotSndRcv to send and receive message through a single process
  2. Run SendMessage followed by ReceiveMessage. This will run the send and receive messages across two process.

  The application is currently set to send and receive 10 messages. This can be abstracted, but I had to pass that up due to time constraints.


Kyle Strand, Ph.D
ktstrandphd@gmail.com
30 May 2024
