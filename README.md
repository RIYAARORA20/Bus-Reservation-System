# Bus Reservation System - README

## Description

This README provides a brief overview of the functions used in the Bus Reservation System code.

## Functions

1. **`main()`:**
   - Entry point of the program.
   - Initializes the system, handles user authentication, and displays the main menu.
   - Manages booking, cancellation, and information retrieval processes.

2. **`login()`:**
   - Handles user authentication by prompting for a username and password.
   - Compares entered credentials with predefined values for login.

3. **`int cost(BST *r)`:**
   - Calculates and returns the ticket cost based on the bus route.
   - Extracts bus route information from the seat number in a Binary Search Tree (BST) node.

4. **`status()`:**
   - Displays the status of available buses and their seat occupancy.
   - Calls `busLists()` and `DisplaySeat()` functions to show this information.

5. **`busLists()`:**
   - Lists available buses with their details (bus number, destination, charges, and departure time).
   - Prompts the user to press Enter to continue.

6. **`DisplaySeat(int bus[33])`:**
   - Displays seats of a specific bus along with booking status (EMPTY or BOOKED).
   - Takes an array `bus` as input, representing seat status for a particular bus.

7. **`cancel(int randomNum)`:**
   - Handles cancellation of booked seats.
   - Prompts for a reservation number, verifies it, and asks for confirmation.
   - Allows the user to specify the bus and seats to cancel upon confirmation.

8. **`BST *reservationInfo(BST *r, int s, int *custIDmatched)`:**
   - Searches for reservation information using a customer ID.
   - Traverses the Binary Search Tree (BST) to find a matching customer ID.
   - Returns the corresponding node and sets `custIDmatched` to 1 if a match is found.

9. **`BST *insert(BST **r, int custId)`:**
   - Inserts a new node into the Binary Search Tree (BST) to represent a booked seat.
   - Organizes the tree based on customer IDs.

## Usage

- Compile the code in a C-compatible environment.
- Follow on-screen prompts to navigate through the system.
- Note down your reservation number when booking for future reference.
