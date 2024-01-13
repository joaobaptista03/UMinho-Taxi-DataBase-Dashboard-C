# Taxi Database Dashboard

This project in C is a comprehensive solution for managing and analyzing ride-sharing data. It includes functionalities to process driver, user, and ride information, perform various queries, and conduct both functional and performance testing.

## Description

This project was developed as part of a university course on advanced programming techniques. It includes multiple modules to handle different aspects of a ride-sharing service. Key features include data importation, information retrieval about drivers and users, ride statistics calculation, and a robust testing framework. The project is implemented in C and utilizes GLib for certain data structures and functionalities.

## Getting Started

### Dependencies
- C programming environment (GCC recommended)
- GLib library (version 2.0 or later)
- Linux or Unix-like operating system

## Installing
### 1. Clone the repository to your local machine:
  ```bash
  git clone https://github.com/joaobaptista03/UMinho-Taxi-DataBase-Dashboard-C/
  ```

### 2. Navigate to the project directory:
  ```bash
  cd UMinho-Taxi-DataBase-Dashboard-C
  ```

### 3. Build the project (This will compile the source files and generate two executable files: programa-principal and programa-testes):
  ```bash
  make all
  ```

### 4 Running the Program
#### 4.1 Main App:
  ```bash
  ./programa-principal
  ```
#### 4.2 Tests App
  ```bash
  ./programa-testes
  ```

### 5. Usage
Upon running the main program, you'll be prompted to enter the path to the directory containing your CSV data files (drivers, users, and rides). After loading the data, you can interact with the system through a series of commands corresponding to different queries and operations.

### 6. Testing
The programa-testes executable runs a series of automated tests to verify the correctness of the program. It compares the output of each query with expected results.
