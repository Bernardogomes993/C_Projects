# Local Password Manager in C
This project is a manager password developed in C it can manage credentials in RAM memory through the 
use of an array with a fixed length.
The program can encrypt the passwords from the user using a simple `Cesar Cypher` function and stores
the credentials in a `txt file`.

## Functionalities
* **Autenthication with a master password**: There is a initial barrier in the program, the user
  must enter a master or key password in order to access the functionalities of the program.

* **Efficient Persistence**: The program restores the data when is initializing and saves it when
  the user quits the program.

* **Cryptography**: The passwords are never stored in plein text in the file, the algorithm
  aplies a `Cesar Cypher (+3)` in the moment that the data are written in the file.

## Code architecture

1. **Dinamic Data Structures**: Use of `struct` to modulate the aspects of each account.
   Use of `removeEnter()` function to eliminate the `enter` strokes , and the use of `fgets` to
   read the inputs from the user
2.**Inverter cryptography**: The use of functions `cesarCypher()` and `uncipher()` guarantees that
   the integrity of the system.
3.**Data persistence**:
     * **`loadData()`**: Loads the data to the array when the program begins.
     * **`saveCrdential()`**: Cleans the file and rewrites the file with the data. 
