# Guess Who? - This is a game developed in C and it works dynamically with binary trees 
This game uses a binary tree to try guess it what the user was thinking and uses a **real-time algorithm**.
This specific game is based on the subject of animals.
When the computer has the wrong answer, he learns the new question for the next time.

## Functionalities
* **Automatic Guessing**: The computer asks a question and the answer is only yes or no, then the algorithm
  sorts trough the binary tree in order to find the correct animal.(node)
* **Native C Machine Learning:** When the system has the wrong guess he asks the user:
    1. The answer or the correct animal.
    2. One question that diferenciates the wrong guess and the right one.
    3. The answer to the new question for the new animal.
  * **Constant Evolution**: In each wrong guess the binary tree will grow in memory and the system will
    be more intelligent for the next plays.

  ## Data Structures
  * **Struct Tree:**
  * **Internal Nodes:** They keep the new questions
  * **Leaves:** They keep the animal or the character.
  * **Pointers(`left`/`right`):** They represent the paths of yes or no.
 
  ## How the learning algorithm works
  When the computer reaches the node $X$ and the player says the guess is incorrect:
  1. The node $X$ is transformed to a **question node** (the player is responsible for prompting the new question).
  2. The child node is created with the old answer.
  3. The new child node receives the new character or animal given by the player/user.
  4. The pointers `left` and  `right` are reorganised dynamically according to the answer given by the user/player.
  
