## Introduction

This project demonstrates the creation of a **basic Linux character device driver** that serves as a simple counter. Each time the device is accessed (read or write), the driver increments an internal counter and logs how many times it has been invoked. 

The purpose of this driver is to introduce key concepts in Linux kernel module development, such as registering a character device, handling file operations, and maintaining internal state across function calls.