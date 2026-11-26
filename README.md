# ATM Simulation — C Programming Mini Hackathon

## Project Title and Problem Statement
**Project Title:** ATM Simulation  
**Problem Statement:** Implement a basic ATM simulation that provides essential banking operations for a single demonstration account, allowing users to check balance, deposit money, withdraw money, reject invalid amounts or withdrawals exceeding available balance, view updated balances after each transaction, and exit the menu.

## Team Details
* **Batch:** 40
* **Team Number:** 00
* **Team Members: 3
  1. Pranjal Tyagi
  2. Alok Kumar
  3. Soham Joshi

## Objectives and Features
* Provide a menu-driven interface using a loop and conditional branching (`switch-case` and `if-else`).
* Support balance inquiry, cash deposit, cash withdrawal, and graceful exit.
* Validate user inputs to block non-numeric menu/amount entries, non-positive amounts (`<= 0`), and withdrawals greater than the current balance.
* Display clear transaction feedback and the updated account balance after every operation.

## Algorithm / Pseudocode
1. Initialize `balance = 10000.00` and set `running = 1`.
2. Repeat while `running == 1`:
   a. Display the menu (`1. Check Balance`, `2. Deposit Money`, `3. Withdraw Money`, `4. Exit`).
   b. Read user `choice`. If input is invalid, clear the input buffer and continue.
   c. If `choice == 1`: print current `balance`.
   d. Else if `choice == 2`: read `amount`. If invalid or `amount <= 0`, print error and keep `balance` unchanged; otherwise add `amount` to `balance` and print updated `balance`.
   e. Else if `choice == 3`: read `amount`. If invalid or `amount <= 0` or `amount > balance`, print error and keep `balance` unchanged; otherwise subtract `amount` from `balance` and print updated `balance`.
   f. Else if `choice == 4`: print exit message and set `running = 0`.
   g. Else: print invalid menu option message.
3. Terminate the program.

### Flowchart Overview
```text
[Start] --> [Initialize Balance & Loop]
                 |
                 v
        [Display ATM Menu]
                 |
                 v
        <Valid (1-4)? Choice> --No--> [Show Error & Loop]
                 |Yes
                 v
     +-----------+-----------+-----------+
     |           |           |           |
 [1: Balance] [2: Deposit] [3: Withdraw] [4: Exit]
     |           |           |           |
     |      <Amount> 0?>  <0 < Amt <= Bal?> |
     |       /       \       /         \   |
     |     Yes      No     Yes        No   |
     |      |        |      |          |   |
     | [Add & Print] [Err] [Sub & Print] [Err]
     +------+--------+------+----------+---+
            |                            |
            +---------> [Loop] <---------+
                                         |
                                    [End Program]

C Programming Concepts Used
 * Functions (displayMenu, checkBalance, depositMoney, withdrawMoney) and pass-by-value / return values
 * Loops (while loop for menu execution and input buffer clearing)
 * Conditional statements (switch-case and if-else for menu routing and transaction validation)
 * Standard I/O and data types (double, int, printf, scanf, getchar)
Compilation and Execution Instructions
 * Open a terminal in the folder containing atm_simulation.c.
 * Compile the program using GCC:
   gcc -Wall -Wextra -o atm_simulation atm_simulation.c

 * Run the executable:
   ./atm_simulation

Sample Test Cases
| Test ID | Scenario | Sample Input Sequence | Expected Output Summary | Actual Output Summary | Status |
|---|---|---|---|---|---|
| TC-01 | Initial balance check and exit | 1, 4 | Displays Rs. 10000.00 balance, then exits cleanly | Displays Rs. 10000.00 balance, then exits cleanly | Pass |
| TC-02 | Valid deposit | 2, 2500, 1, 4 | Deposits Rs. 2500.00; balance becomes Rs. 12500.00 | Deposits Rs. 2500.00; balance becomes Rs. 12500.00 | Pass |
| TC-03 | Valid withdrawal | 3, 4000, 4 | Withdraws Rs. 4000.00; balance becomes Rs. 6000.00 | Withdraws Rs. 4000.00; balance becomes Rs. 6000.00 | Pass |
| TC-04 | Withdrawal exceeding balance | 3, 15000, 1, 4 | Rejects withdrawal due to insufficient balance; balance stays Rs. 10000.00 | Rejects withdrawal due to insufficient balance; balance stays Rs. 10000.00 | Pass |
| TC-05 | Zero or negative deposit/withdrawal | 2, 0, 3, -500, 4 | Rejects both amounts (<= 0) without changing balance | Rejects both amounts (<= 0) without changing balance | Pass |
| TC-06 | Invalid menu choice & non-numeric input | 9, abc, 4 | Displays invalid option/input messages and recovers cleanly without infinite loop | Displays invalid option/input messages and recovers cleanly without infinite loop | Pass |

<FollowUp label="Want an outline or slide content for presentation.pptx?" query="Draft the slide-by-slide content for presentation.pptx for the ATM Simulation mini hackathon project."/>


                                         
