# ATM Simulation with MPIN Security — C Programming Mini Hackathon

## Project Title and Problem Statement
**Project Title:** ATM Simulation with MPIN Security  
**Problem Statement:** Implement a basic ATM simulation that provides essential banking operations for a single demonstration account (`Rs. 32500.00` initial balance and default 4-digit MPIN `1234`), allowing users to authenticate within 3 attempts, check balance, deposit money, withdraw money, change MPIN with validation, reject invalid amounts or withdrawals exceeding available balance, view updated balances after each transaction, and exit the menu.

## Team Details
* **Batch:** Batch 40
* **Team Name:** Trimax
* **Team Members:**
  1. Alok Kumar
  2. Pranjal Tyagi
  3. Soham Joshi

## Objectives and Features
* **MPIN Authentication:** Prompts for a 4-digit MPIN (default `1234`) up to 3 attempts and blocks the ATM if all 3 attempts fail.
* **Menu-Driven Operations:** Uses a `do-while` loop and `switch-case` branching for Check Balance, Deposit Money, Withdraw Money, Change MPIN, and Exit.
* **Transaction Validation:** Rejects non-positive deposit/withdrawal amounts (`<= 0`) and prevents withdrawals exceeding the current `balance`.
* **MPIN Change Validation:** Verifies the current MPIN, checks that the new MPIN is a 4-digit number (`1000` to `9999`), and confirms that both new MPIN entries match before updating.
* **Balance & Status Feedback:** Displays clear messages and updated or remaining balance (`Rs. %.2f`) after valid transactions.

## Algorithm / Pseudocode
1. Start the program and initialize `mpin = 1234`, `attempts = 3`, and `balance = 32500.00`.
2. Print the `WELCOME TO ATM` header.
3. Repeat while `attempts > 0`:
   a. Prompt for `enteredPin`.
   b. If `enteredPin == mpin`, print `Login Successful!` and break out of the login loop.
   c. Otherwise decrement `attempts` and print `Incorrect MPIN!` and remaining attempts.
4. If `attempts == 0`, print `ATM BLOCKED! Too many incorrect attempts.` and return `0`.
5. Repeat using a `do-while` loop while `choice != 5`:
   a. Display menu options `1` to `5` (`Check Balance`, `Deposit Money`, `Withdraw Money`, `Change MPIN`, `Exit`).
   b. Read integer `choice` using `scanf("%d", &choice)`.
   c. Evaluate `choice` using `switch`:
      * **Case 1:** Print `Your balance is: Rs. <balance>`.
      * **Case 2:** Read `amount`. If `amount > 0`, add `amount` to `balance` and print `Money deposited successfully!` and `Updated balance: Rs. <balance>`; else print `Invalid amount!`.
      * **Case 3:** Read `amount`. If `amount <= 0`, print `Invalid amount!`; else if `amount > balance`, print `Insufficient balance!`; else subtract `amount` from `balance` and print `Please collect your cash.` and `Remaining balance: Rs. <balance>`.
      * **Case 4:** Read current `enteredPin`. If it matches `mpin`, read `newPin`. If `1000 <= newPin <= 9999`, read `confirmPin`; if `newPin == confirmPin`, update `mpin = newPin` and print `MPIN changed successfully!`, else print `MPIN does not match!`. Handle invalid digit length or wrong current MPIN with error messages.
      * **Case 5:** Print `Thank you for using our ATM!` and `Please visit again.`.
      * **Default:** Print `Invalid choice! Please try again.`.
6. Exit when `choice == 5` and return `0`.

### Flowchart Overview
```
[Start] --> [mpin=1234, attempts=3, balance=32500.00]
                            |
                            v
                   [MPIN Login (<= 3 tries)]
                     /                 \
               [Valid MPIN]        [3 Failed]
                   |                   |
                   v             [ATM BLOCKED]
            [Display Menu]             |
                   |                  [End]
                   v
             [Read choice]
                   |
    +------+-------+-------+-------+-------+
    |      |       |       |       |       |
 [Case 1][Case 2][Case 3][Case 4][Case 5][Default]
    |      |       |       |       |       |
    +------+-------+-------+-------+-------+
                   |
             [choice != 5?]
               /         \
             Yes          No
              |            |
        [Repeat Menu]  [Exit & End]

```

## C Programming Concepts Used

* Variables and data types (`int`, `float`)
* Input / Output (`printf`, `scanf` with `%d` and `%.2f`)
* Loops (`while` loop for MPIN attempts and `do-while` loop for menu execution)
* Conditional statements (`switch-case`, `if-else`, `else if`, and logical/relational operators)

## Compilation and Execution Instructions

1. Open a terminal in the folder containing your C source file (for example, `atm_simulation.c`).
2. Compile the program using `gcc`:
```
gcc -Wall -Wextra -o atm_simulation atm_simulation.c

```


3. Run the executable:
```
./atm_simulation

```



## Sample Test Cases

| Test ID | Scenario | Sample Input Sequence | Expected Output Summary | Actual Output Summary | Status |
| --- | --- | --- | --- | --- | --- |
| TC-01 | Valid login, balance check, and exit | `1234`, `1`, `5` | Prints `Login Successful!`, `Your balance is: Rs. 32500.00`, then exit messages | Prints `Login Successful!`, `Your balance is: Rs. 32500.00`, then exit messages | Pass |
| TC-02 | ATM blocked after 3 wrong MPINs | `1111`, `2222`, `3333` | Decrements attempts each time and prints `ATM BLOCKED! Too many incorrect attempts.` | Decrements attempts each time and prints `ATM BLOCKED! Too many incorrect attempts.` | Pass |
| TC-03 | Valid deposit | `1234`, `2`, `2500`, `1`, `5` | Prints `Money deposited successfully!` and `Updated balance: Rs. 35000.00` | Prints `Money deposited successfully!` and `Updated balance: Rs. 35000.00` | Pass |
| TC-04 | Valid withdrawal | `1234`, `3`, `5000`, `5` | Prints `Please collect your cash.` and `Remaining balance: Rs. 27500.00` | Prints `Please collect your cash.` and `Remaining balance: Rs. 27500.00` | Pass |
| TC-05 | Withdrawal exceeding balance | `1234`, `3`, `35000`, `1`, `5` | Prints `Insufficient balance!` and keeps balance at `Rs. 32500.00` | Prints `Insufficient balance!` and keeps balance at `Rs. 32500.00` | Pass |
| TC-06 | Zero or negative transaction amount | `1234`, `2`, `0`, `3`, `-500`, `5` | Prints `Invalid amount!` for both invalid amounts without changing balance | Prints `Invalid amount!` for both invalid amounts without changing balance | Pass |
| TC-07 | Change MPIN successfully and re-login | `1234`, `4`, `1234`, `4321`, `4321`, `5` | Updates MPIN to `4321` and prints `MPIN changed successfully!` | Updates MPIN to `4321` and prints `MPIN changed successfully!` | Pass |
| TC-08 | Change MPIN with mismatch or invalid digits | `1234`, `4`, `1234`, `123`, `4`, `1234`, `5678`, `9999`, `5` | Rejects `123` (`MPIN must contain exactly 4 digits!`) and mismatched `5678`/`9999` (`MPIN does not match!`) | Rejects `123` (`MPIN must contain exactly 4 digits!`) and mismatched `5678`/`9999` (`MPIN does not match!`) | Pass |
| TC-09 | Invalid menu choice | `1234`, `9`, `5` | Prints `Invalid choice! Please try again.` and continues menu until `5` | Prints `Invalid choice! Please try again.` and continues menu until `5` | Pass |

```

<FollowUp label="Want me to update the C code file name or viva notes for MPIN?" query="Give quick viva questions and answers for the MPIN-enabled ATM C code."/>

```
