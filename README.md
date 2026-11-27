
# Secure Bank ATM Simulation — C Programming Mini Hackathon

## Project Title and Problem Statement
**Project Title:** Secure Bank ATM Simulation  
**Problem Statement:** Implement an ATM simulation in C for a demonstration bank account (`SECURE BANK`, initial balance `Rs. 32500.00`, default MPIN `1234`) using structures, pointers, arrays, strings, functions, loops, and conditional statements—supporting MPIN login within 3 attempts, balance inquiry, deposit, withdrawal, MPIN change, transaction history tracking (up to 10 records), and menu exit.

## Team Details
* **Batch:** Batch 40
* **Team Name:** Trimax
* **Team Members:**
  1. Alok Kumar || SAP ID: 590036758
  2. Soham Joshi || SAP ID: 590038293
  3. Pranjal Tyagi || SAP ID: 590038364

## Objectives and Features
* **MPIN Authentication (`login`):** Verifies the user's MPIN (`1234` by default) within a maximum of 3 attempts using `strcmp()`; blocks the ATM if all 3 attempts fail.
* **Structured Account & Transaction Modeling:** Stores account metadata (`name`, `card`, `accountNumber`, `bank`, `ifsc`, `status`, `mpin`, `balance`) and an array of up to `MAX` (`10`) `struct Transaction` records.
* **Deposit & Withdrawal Validation:** Rejects non-positive amounts (`<= 0`) and withdrawals exceeding available `balance`, updating `balance` via pointers and logging valid transactions automatically.
* **MPIN Management (`changeMPIN`):** Validates the current MPIN, checks that the new MPIN is 4 characters long (`strlen(newPin) == 4`), and confirms matching entries before updating `a->mpin`.
* **Transaction History (`history`):** Displays all recorded deposits and withdrawals with transaction type, amount, and post-transaction balance.

## Algorithm / Pseudocode
1. Start the program and initialize `struct Account user` (`bank = "SECURE BANK"`, `mpin = "1234"`, `balance = 32500.00`, `count = 0`).
2. Print the `WELCOME TO SECURE BANK ATM` banner and call `login(user)`:
   a. Allow up to `3` attempts to input `pin`.
   b. If `strcmp(pin, a.mpin) == 0`, print `Login Successful!` and return `1`; otherwise decrement `attempts`.
   c. If `attempts == 0`, print `ATM BLOCKED!` and terminate the program.
3. Repeat using a `do-while` loop while `choice != 6`:
   a. Display menu options `1` to `6` (`Check Balance`, `Deposit Money`, `Withdraw Money`, `Change MPIN`, `Transaction History`, `Exit`).
   b. Read integer `choice` using `scanf("%d", &choice)`.
   c. Evaluate `choice` using `switch`:
      * **Case 1:** Call `checkBalance(user)` to display `Rs. %.2f`.
      * **Case 2:** Call `deposit(&user)`. If `amount > 0`, add to `a->balance`, call `saveTransaction(a, "Deposit", amount)`, and print updated balance; else print `Invalid Amount!`.
      * **Case 3:** Call `withdraw(&user)`. If `amount <= 0`, print `Invalid Amount!`; else if `amount > a->balance`, print `Insufficient Balance!`; else subtract from `a->balance`, call `saveTransaction(a, "Withdrawal", amount)`, and print remaining balance.
      * **Case 4:** Call `changeMPIN(&user)`. Verify `oldPin`, check `strlen(newPin) == 4`, confirm `strcmp(newPin, confirmPin) == 0`, and copy `newPin` into `a->mpin`.
      * **Case 5:** Call `history(user)` to print all stored transactions (`1` to `a.count`) or `No transactions yet.`.
      * **Case 6:** Print exit messages and terminate loop.
      * **Default:** Print `Invalid Choice!`.
4. Return `0` and end program.

### Flowchart Overview
```
[Start] --> [Initialize struct Account user (Bal: 32500.00, MPIN: 1234)]
                                  |
                                  v
                       [login(user) (3 Attempts)]
                         /                    \
                   [Valid MPIN]           [3 Failed]
                       |                      |
                       v               [ATM BLOCKED!]
                [Display ATM Menu]            |
                       |                    [End]
                       v
                 [Read choice]
                       |
    +-------+----------+----------+----------+----------+-------+
    |       |          |          |          |          |       |
 [1:Bal] [2:Dep]    [3:With]   [4:MPIN]   [5:Hist]   [6:Exit] [Def]
    |       |          |          |          |          |       |
    +-------+----------+----------+----------+----------+-------+
                       |
                 [choice != 6?]
                   /         \
                 Yes          No
                  |            |
            [Repeat Menu]  [Exit & End]

```

## C Programming Concepts Used

* **Structures & Nested Structures:** `struct Transaction` nested inside `struct Account` (`history[MAX]`)
* **Pointers & Pass-by-Reference:** Passing `struct Account *a` to `deposit()`, `withdraw()`, `changeMPIN()`, and `saveTransaction()` using the arrow (`->`) operator to modify account state directly
* **Functions & Modular Programming:** Separate functions for `login`, `checkBalance`, `deposit`, `withdraw`, `changeMPIN`, `history`, and `saveTransaction`
* **Arrays & Strings:** Character arrays (`char[]`) and `<string.h>` functions (`strcmp`, `strcpy`, `strlen`) along with `#define MAX 10`
* **Loops & Conditionals:** `while` loop for login attempts, `do-while` loop for menu, `for` loop for displaying history, and `switch-case` / `if-else` branching

## Compilation and Execution Instructions

1. Open a terminal in the folder containing `atm_simulation.c`.
2. Compile the C program using `gcc`:
```
gcc -Wall -Wextra -o atm_simulation atm_simulation.c

```


3. Run the compiled program:
```
./atm_simulation

```



## Sample Test Cases

| Test ID | Scenario | Sample Input Sequence | Expected Output Summary | Actual Output Summary | Status |
| --- | --- | --- | --- | --- | --- |
| TC-01 | Valid login, balance check, and exit | `1234`, `1`, `6` | Prints `Login Successful!`, `Available Balance: Rs. 32500.00`, then exit messages | Prints `Login Successful!`, `Available Balance: Rs. 32500.00`, then exit messages | Pass |
| TC-02 | ATM blocked after 3 wrong MPINs | `1111`, `2222`, `3333` | Decrements attempts each time and prints `ATM BLOCKED!` | Decrements attempts each time and prints `ATM BLOCKED!` | Pass |
| TC-03 | Valid deposit and balance check | `1234`, `2`, `2500`, `1`, `6` | Prints `Deposit Successful!` and `Updated Balance: Rs. 35000.00` | Prints `Deposit Successful!` and `Updated Balance: Rs. 35000.00` | Pass |
| TC-04 | Valid withdrawal | `1234`, `3`, `5000`, `6` | Prints `Withdrawal Successful!` and `Remaining Balance: Rs. 27500.00` | Prints `Withdrawal Successful!` and `Remaining Balance: Rs. 27500.00` | Pass |
| TC-05 | Withdrawal exceeding balance | `1234`, `3`, `35000`, `1`, `6` | Prints `Insufficient Balance!` and keeps balance at `Rs. 32500.00` | Prints `Insufficient Balance!` and keeps balance at `Rs. 32500.00` | Pass |
| TC-06 | Zero or negative transaction amount | `1234`, `2`, `0`, `3`, `-500`, `6` | Prints `Invalid Amount!` for both inputs without changing `Rs. 32500.00` | Prints `Invalid Amount!` for both inputs without changing `Rs. 32500.00` | Pass |
| TC-07 | Change MPIN successfully | `1234`, `4`, `1234`, `4321`, `4321`, `6` | Updates `a->mpin` to `"4321"` and prints `MPIN Changed Successfully!` | Updates `a->mpin` to `"4321"` and prints `MPIN Changed Successfully!` | Pass |
| TC-08 | Change MPIN with wrong length or mismatch | `1234`, `4`, `1234`, `12`, `4`, `1234`, `5678`, `9999`, `6` | Prints `MPIN must contain exactly 4 characters!` and `MPIN does not match!` | Prints `MPIN must contain exactly 4 characters!` and `MPIN does not match!` | Pass |
| TC-09 | View transaction history after operations | `1234`, `2`, `2500`, `3`, `5000`, `5`, `6` | Displays Transaction 1 (`Deposit`, `Rs. 2500.00`, `Rs. 35000.00`) and Transaction 2 (`Withdrawal`, `Rs. 5000.00`, `Rs. 30000.00`) | Displays Transaction 1 (`Deposit`, `Rs. 2500.00`, `Rs. 35000.00`) and Transaction 2 (`Withdrawal`, `Rs. 5000.00`, `Rs. 30000.00`) | Pass |
| TC-10 | Invalid menu choice | `1234`, `9`, `6` | Prints `Invalid Choice!` and continues displaying menu until `6` is entered | Prints `Invalid Choice!` and continues displaying menu until `6` is entered | Pass |

```

```
