# Connect-Four
**Connect-Four-Console-Game** <br>
This Connect Four Console Game is a C++ application developed using fundamental programming concepts. It provides a two-player turn-based experience where players drop their pieces into a vertical grid, aiming to connect four symbols horizontally, vertically, or diagonally. The game runs in a terminal environment and uses simple user interaction and board visualization techniques to simulate real gameplay.

 **Game Logic** <br>
**Board Representation** <br>
The board is implemented using a 2D character array (6 rows × 7 columns). Each cell represents an empty slot or a player’s piece ('A' or 'B'). The layout is updated and redrawn after every valid move.

**Turn Management** <br>
Players are assigned their turns using a toss function. The turn alternates after each move unless a win or draw is detected. Input is restricted to valid column numbers (0–6), and full columns are automatically rejected.

**Piece Dropping** <br>
Pieces "fall" from the top of the selected column to the lowest available position. This simulates gravity-based movement similar to the physical Connect Four game.

**Core Functionalities** <br>
Random Toss System: A random generator determines which player starts the game.
Move Validation: Invalid inputs and full columns are handled with user prompts.
Win Detection: The game checks for winning conditions after every move—horizontal, vertical, and both diagonal combinations.
Draw Detection: If the board fills up without a winner, the game ends in a tie.
Rule Display: Basic gameplay rules are printed before the game starts for player clarity.
Console Clearing: The terminal is cleared after each move for a clean game experience using system("cls").

**Key Features** <br>
Modular code structure using separate functions for each game  <br>
Real-time interactive gameplay in the console <br>
Easy-to-understand rules for beginners <br>
Visual board representation after each move <br>
Clear game conclusion messages (win or draw) <br>

**Use Case** <br>
This project is ideal for beginners learning C++ fundamentals, especially those looking to understand:
2D arrays and nested  <br>
Function-based modular design <br>
Conditional logic and control flow <br>
Console-based interaction in C++ <br>
Basic use of standard libraries (ctime, iostream, cstdlib) <br>
