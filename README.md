# ATM Simulation — C Programming Mini Hackathon

## Project Title and Problem Statement
**Project Title:** ATM Simulation  
**Problem Statement:** Implement a basic ATM simulation that provides essential banking operations for a single demonstration account (`Rs. 5000.00` initial balance), allowing users to check balance, deposit money, withdraw money, reject invalid amounts or withdrawals exceeding available balance, view updated balances after each transaction, and exit the menu.

## Team Details
* **Batch:** Batch 40
* **Team Number:** 00
* **Team Members:** 3
  1. Alok Kumar
  2. Pranjal Tyagi
  3. Soham Joshi

## Objectives and Features
* Provide a menu-driven ATM interface using a `do-while` loop and `switch-case` branching.
* Support balance inquiry, cash deposit, cash withdrawal, and exiting when option `4` is selected.
* Reject non-positive deposit/withdrawal amounts (`amount <= 0`) and block withdrawals exceeding the current `balance`.
* Display clear transaction messages along with updated or remaining balance after valid operations.

## Algorithm / Pseudocode
1. Start the program and initialize `balance = 5000.00`.
2. Print the `WELCOME TO ATM` header.
3. Repeat using a `do-while` loop while `choice != 4`:
   a. Display options `1. Check Balance`, `2. Deposit Money`, `3. Withdraw Money`, and `4. Exit`.
   b. Read integer `choice` using `scanf("%d", &choice)`.
   c. Evaluate `choice` using `switch`:
      * **Case 1:** Print `Your balance is: Rs. <balance>`.
      * **Case 2:** Read `amount`. If `amount > 0`, add `amount` to `balance` and print `Money deposited successfully!` and `Updated balance: Rs. <balance>`; otherwise print `Invalid amount!`.
      * **Case 3:** Read `amount`. If `amount <= 0`, print `Invalid amount!`; else if `amount > balance`, print `Insufficient balance!`; else subtract `amount` from `balance` and print `Please collect your cash.` and `Remaining balance: Rs. <balance>`.
      * **Case 4:** Print `Thank you for using our ATM!` and `Please visit again.`.
      * **Default:** Print `Invalid choice! Please try again.`.
4. Exit the loop when `choice == 4` and return `0`.

### Flowchart Overview
```text
[Start] --> [balance = 5000.00] --> [Print Header]
                                         |
                                         v
                                 [Display Menu]
                                         |
                                         v
                                 [Read choice]
                                         |
          +------------------------------+------------------------------+
          |                              |                              |
     [choice == 1]                [choice == 2]                [choice == 3]
          |                              |                              |
  [Print balance]              [Read amount]                  [Read amount]
          |                       /         \                   /     |     \
          |                 [amount > 0]  [else]        [<= 0] [> bal] [valid]
          |                   /                 \           |       |       |
          |         [Add & Print]      [Invalid amount!] [Inv] [Insuff] [Sub & Print]
          +------------------------------+------------------------------+
                                         |
                                  [choice == 4?]
                                    /         \
                                  No           Yes
                                  |             |
                            [Repeat Loop] [Print Exit & End]

## C Programming Concepts Used
 * Variables and data types (int choice, float balance, float amount)
 * Input / Output (printf, scanf with %d and %.2f formatting)
 * Looping construct (do-while loop running until choice != 4 is false)
 * Conditional statements (switch-case for menu options and if-else / else if for transaction validation)
 
## Compilation and Execution Instructions
 * Open a terminal in the folder containing atm_simulation.c.
 * Compile the C program using gcc:
   gcc -Wall -Wextra -o atm_simulation atm_simulation.c

 * Run the compiled program:
   ./atm_simulation

## Sample Test Cases
| Test ID | Scenario | Sample Input Sequence | Expected Output Summary | Actual Output Summary | Status |
|---|---|---|---|---|---|
| TC-01 | Check initial balance and exit | 1, 4 | Prints Your balance is: Rs. 5000.00, then Thank you for using our ATM! and Please visit again. | Prints Your balance is: Rs. 5000.00, then Thank you for using our ATM! and Please visit again. | Pass |
| TC-02 | Valid deposit and balance check | 2, 1500, 1, 4 | Prints Money deposited successfully! and Updated balance: Rs. 6500.00; subsequent check shows Rs. 6500.00 | Prints Money deposited successfully! and Updated balance: Rs. 6500.00; subsequent check shows Rs. 6500.00 | Pass |
| TC-03 | Valid withdrawal | 3, 2000, 4 | Prints Please collect your cash. and Remaining balance: Rs. 3000.00, then exits | Prints Please collect your cash. and Remaining balance: Rs. 3000.00, then exits | Pass |
| TC-04 | Withdrawal exceeding balance | 3, 6000, 1, 4 | Prints Insufficient balance! and keeps balance at Rs. 5000.00 | Prints Insufficient balance! and keeps balance at Rs. 5000.00 | Pass |
| TC-05 | Zero or negative deposit/withdrawal | 2, 0, 3, -250, 4 | Prints Invalid amount! for both 0 deposit and -250 withdrawal without changing Rs. 5000.00 | Prints Invalid amount! for both 0 deposit and -250 withdrawal without changing Rs. 5000.00 | Pass |
| TC-06 | Invalid menu choice | 7, 4 | Prints Invalid choice! Please try again. and continues menu until 4 is entered | Prints Invalid choice! Please try again. and continues menu until 4 is entered | Pass |



