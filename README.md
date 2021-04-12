# The Jolly Banker

Goals: Working with trees, objects, pointers, and vectors, and File I/O

For this assignment, you will write a banking program that reads from a file, stores the input into a Queue, and 
performs Transactions based on the input. 

The program must read from the Queue and process Transactions in order

When the Queue is depleted, the program will print all open Accounts and balances in those Accounts.

The possible Transactions are Opening an Account, Depositing to an Account, Withdrawing from an Account, Transferring
between Accounts/Funds, and accessing the History of an Account's Transactions.

No duplicate Accounts are allowed. An Account ID cannot be linked to two names. Only one owner per account.

An overdraft Withdrawal should return false, EXCEPT when the Withdrawal is from a Money Market Fund.
If the overdraft Withdrawal is from a Money Market Fund, the program checks the other Money Market Fund to see if the
remaining Amount can be covered.

## Compile and Run

```
./simplecompile.sh
```


### Style Explanation
These options are defined in `.clang-tidy` file.

Perform all check except the following:

-fuchsia-* do not need specific checks for "fuchsia" a modular, capability-based operating system
- cppcoreguidelines-pro-bounds-array-to-pointer-decay: do not give warnings on assert
- google-build-using-namespace: for simplicity allow `using namespace std;`
- google-readability-braces-around-statements: allow compact code without `{`
- readability-braces-around-statements: allow compact code without `{`
This option is not available in CSS Linux lab under LLVM 3.8.1, but is needed on my PC when using 9.0.0
- hicpp-no-array-decay need to use assert
- modernize-use-trailing-return-type: not ready yet for `auto func() -> int` format
- hicpp-braces-around-statements: allow compact code without `{` (this option
- cppcoreguidelines-pro-bounds-pointer-arithmetic,
- llvm-header-guard: not using full directory name
- google-global-names-in-headers: for simplicity allow `using namespace std;`
- cppcoreguidelines-special-member-functions: not defining move operator
- hicpp-special-member-functions: not defining move operator
- cppcoreguidelines-owning-memory: not using gsl

## Misc

This file is part of a repository located at
https://github.com/pisan342/ass5-banker-starter

## Additional Comments

Clang Tidy Warnings intentionally ignored are //NOLINTNEXTLINE
These are warnings ignored based on assignment requirements are are not essential to implement

Could not silence ambiguous warnings for Transfer constructor.

## Clang-Tidy Warnings



