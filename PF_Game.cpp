#include <iostream>
#include<string>
#include<cstring>
#include<ctime>
const int r = 6;
const int c = 7;
char board[r][c];
void initializeBoard();
void patron();
bool isColumnFull(int col);
bool isValidMove(int col);
void dropPiece(int col, char player);
bool checkWin(char player);
bool isBoardFull();
int toss();
void readrule();

int main()
{
    char currentPlayer, player2;
    int c;
    std::cout << "----- Programming Fundamental Project -------\n";
    std::cout << "------------ Welcome to Game ------------\n";
    std::cout << "         " << std::endl;
    std::cout << "Here is the result of toss: " << std::endl;
    c = toss();
    readrule();
    if (c == 1)
    {
        currentPlayer = 'A';
        player2 = 'B';
    }
    else
    {
        currentPlayer = 'B';
        player2 = 'A';
    }
    initializeBoard();
    while (true)
    {

        std::cout << "Player " << currentPlayer << "'s turn. Enter number From 0 to 6: ";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "NOW HAVE SOME FUN:\n" << std::endl;
        patron();
        int column;
        std::cin >> column;
        if (isValidMove(column) == 1)
        {
            dropPiece(column, currentPlayer);
            if (checkWin(currentPlayer))
            {
                patron();
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull())
            {
                patron();
                std::cout << "It's a tie!\n";
                break;
            }
            system("cls");

            currentPlayer = ((currentPlayer == 'A') ? 'B' : 'A');
        }
        else
        {
            std::cout << "Invalid move. Try again.\n";
        }
    }
    std::cout << "Developed By: " << std::endl;
    std::cout<<"1. Abdur Rafay Baig Rafay\n2.Abu Bakar\n3.Hafiz Rizwan" << std::endl;
    std::cout << std::endl;
    return 0;
}
int toss()
{
    int Toss;
    char currentPlayer = 'A', player2 = 'B';
    srand((int)time(0));
    Toss = rand() % 2;
    if (Toss == 1)
    {
        std::cout << currentPlayer << " win the toss.\n" << currentPlayer << " is the first player.\n";
        std::cout << "                          " << std::endl;
        return Toss;
    }
    else
    {
        std::cout << player2 << " win the toss.\n" << player2 << " is the first player.\n";
        std::cout << "                                                  " << std::endl;
        return 0;
    }
}
void initializeBoard()
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            board[i][j] = '  ';
        }
    }
}
void patron()
{
    std::cout << "0   1   2    3    4    5    6  \n";
    std::cout << "++++++++++++++++++++++++++++++++\n";
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            std::cout << board[i][j] << "    ";
        }
        std::cout << std::endl;
        if (i == 5) {
            std::cout << "++++++++++++++++++++++++++++++++\n";
        }
    }
}
bool isColumnFull(int col)
{
    return board[0][col] != ' ';
}
bool isValidMove(int col)
{
    return col >= 0 && col < c && !isColumnFull(col);
}
void dropPiece(int col, char player)
{
    for (int i = r - 1; i >= 0; --i)
    {
        if (board[i][col] == ' ')
        {
            board[i][col] = player;
            break;
        }
    }
}
void readrule()
{
    std::cout << " ####### You Have To Play Game By Following These Rules:" << std::endl;
    std::cout << "1. The game is played on a vertical board" << std::endl;
    std::cout << "2. Players take turns to make their symbols from the top into any of the columns." << std::endl;
    std::cout << "3. The game ends when a player connects four of their symbols horizontally, vertically, or diagonally." << std::endl;
    std::cout << "4. player who won the toss will take first turn" << std::endl;
    std::cout << "5. player who leaves the game will not get any victory" << std::endl;
    std::cout << "              " << std::endl;
}
bool checkWin(char player)
{

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j <= c - 4; ++j)
        {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player)
            {
                return true;
            }
        }
    }

    for (int i = 0; i <= r - 4; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player)
            {
                return true;
            }
        }
    }

    for (int i = 0; i <= r - 4; ++i)
    {
        for (int j = 0; j <= c - 4; ++j)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
            {
                return true;
            }
        }
    }

    for (int i = 3; i < r; ++i)
    {
        for (int j = 0; j <= c - 4; ++j)
        {
            if (board[i][j] == player && board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player && board[i - 3][j + 3] == player)
            {
                return true;
            }
        }
    }
    return false;
}
bool isBoardFull()
{
    for (int i = 0; i < c; ++i)
    {
        if (!isColumnFull(i))
        {
            return false;
        }
    }
    return true;
}