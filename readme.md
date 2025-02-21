## How to Run: 

In order to use these operations, once you have downloaded the repository:
1. Make sure you are in the correct directory in your terminal
2. Input your desired matrix into the test.txt file ***(formatting below)***
3. Use the Makefile by typing make <operation> (operation being rref, rotate, etc.)
4. Once compiled, type in: ./<operation> test.txt
5. Your result should be printed out into the console.

## File Format

Text files representing matrices should follow this format:

1. The **first row** specifies the number of rows.
2. The **second row** specifies the number of columns.
3. For determinant files, provide **only one number** (size of the row or column of square matrix).
