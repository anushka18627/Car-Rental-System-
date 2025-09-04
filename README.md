# Car-Rental-System-
he Car Rental System is a console-based application developed in C++ that allows users to rent, return, and manage cars efficiently. This project demonstrates the practical application of Object-Oriented Programming (OOP) concepts like classes, inheritance, polymorphism, file handling, and dynamic data management.

1. Introduction

The Car Rental System is a console-based application developed in C++ that allows users to rent, return, and manage cars efficiently. This project demonstrates the practical application of Object-Oriented Programming (OOP) concepts like classes, inheritance, polymorphism, file handling, and dynamic data management.

It is suitable for beginners and intermediate-level programmers looking to understand real-world problem-solving using C++.

2. Objectives

To manage a fleet of cars for rental purposes.

To provide a user-friendly interface for customers and administrators.

To practice OOP principles and file handling for persistent data storage.

To implement basic validation and error handling.

3. Features
For Customers

View available cars with details like model, brand, rent per day, and status.

Rent a car by specifying the car ID and rental duration.

Return a rented car and calculate total charges.

Generate a receipt after transaction completion.

For Admin

Add new cars to the system.

Remove cars that are no longer available.

Update car details like rent per day or status.

View complete rental history.

4. Technologies and Concepts Used

Language: C++

Paradigm: Object-Oriented Programming

Core Concepts:

Classes and Objects for car and user entities.

Inheritance for differentiating admin and customer modules.

Polymorphism for handling transactions.

File Handling (fstream) for saving and loading car and rental data.

Data Structures like arrays or vectors for storing records dynamically.

Exception Handling for invalid inputs.

5. System Design
Class Structure Example

Class Car

Attributes: id, brand, model, rentPerDay, isAvailable.

Methods: displayCar(), updateStatus().

Class Customer

Attributes: customerID, name, phone, rentedCarID.

Methods: rentCar(), returnCar().

Class Admin (inherits from Customer or CarManager)
