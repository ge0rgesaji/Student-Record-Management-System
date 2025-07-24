# Student Record Management System 
<p align="center">
<img src="https://img.shields.io/badge/Made%20with-C-blue)">
</p>

## Overview

The Student Record Management System is a simple console-based program written in C that allows you to:

* Add student records

* View all student records

* Search for a student by roll number

* Delete student records

The data is stored in a binary file (Stud.dat) using C structs and file I/O. This project is ideal for learning:

* Structs

* File handling (fopen, fwrite, fread)

* Functions

* Menu-driven programs

## Features

* Add New Student: Enter roll number, name, course, and marks.

* View All Students: Displays all records in a tabular format.

* Search Student: Find a student by roll number 

* Delete Student: Remove a record by roll number 

* Data stored persistently in Stud.dat (binary file).

* Clean and formatted table output using printf alignment tricks.

## How to Compile and Run
1. Compile
If using GCC:
```bash
gcc main.c -o student_mgmt
```
2. Run
```bash
./student_mgmt
```

## Future Improvements

* Add Update Student Details feature.

* Add Sorting (by name or marks).

* Export data to a CSV file for Excel.

* Add login system (basic username/password).
