#include <iostream>
#include <vector>
using namespace std;
char board[3][3];

bool checkWin(char player)
{
    for(int i=0;i<3;i++)
    {
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||(board[0][i]==player&&board[1][i]==player&&board[2][i]==player))
        return true;
    }
    return (board[0][0]==player && board[1][1]==player && board[2][2]==player) ||(board[0][2]==player&&board[1][1]==player&&board[2][0]==player);
}

bool isFull()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==' '||board[i][1]==' '||board[i][2] ==' ')
            return false;
    }
    return true;
}

int minimax(bool isMaximizing)
{
    if(checkWin('X')) return -10;
    if(checkWin('O')) return 10;
    if(isFull()) return 0;
    if(isMaximizing)
    {
        int bestScore = -1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==' ')
                {
                    board[i][j] = 'O';
                    int score = minimax(false);
                    board[i][j] = ' ';
                    bestScore = max(score,bestScore);
                }
            }
        }
    return bestScore;
    }
    else{
        int bestScore = 1000;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i][j]==' ')
                {
                    board[i][j] = 'X';
                    int score = minimax(true);
                    board[i][j] = ' ';
                    bestScore = min(bestScore, score);
                }
            }
        }
    return bestScore;
    }
}

pair<int,int> findBestMove()
{
    pair<int, int> result;
    int bestScore = -1000;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j] = 'O';
                int score = minimax(false);
                board[i][j] = ' ';
                if(score>bestScore)
                {
                    bestScore = score;
                    result = {i,j};
                }
            }
        }
    }
    return result;
}

void printBoard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    int i = 0;
    while(true)
    {
        printBoard();
        int i,j;
        cout<<"Your move X\n";
        cout<<"Enter row,col coordinates to place X\n";
        cin>>i>>j;
        board[i][j] = 'X';
        if(checkWin('X')) 
        {
            printBoard();
            cout<<"X wins\n";
            break;
        }
        if(checkWin('O'))
        {
            printBoard();
            cout<<"O wins\n";
            break;
        }
        if(isFull())
        {
            printBoard();
            cout<<"It's a draw\n";
            break;
        }
        printBoard();
        cout<<"AI move O\n";
        pair<int, int> move = findBestMove();
        board[move.first][move.second] = 'O';
        if(checkWin('X')) 
        {
            printBoard();
            cout<<"X wins\n";
            break;
        }
        if(checkWin('O'))
        {
            printBoard();
            cout<<"O wins\n";
            break;
        }
        if(isFull())
        {
            printBoard();
            cout<<"It's a draw\n";
            break;
        }
    }
    return 0;
}