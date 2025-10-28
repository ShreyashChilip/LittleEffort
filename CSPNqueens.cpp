#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string>> result;
    vector<string> board;

public:
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        result.clear();
        place(0, n);
        return result;
    }

    void place(int col, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, n)) {
                board[i][col] = 'Q';
                place(col + 1, n);
                board[i][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, int n) {
        for (int i = 0; i < col; i++)
            if (board[row][i] == 'Q') return false;

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;

        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q') return false;

        return true;
    }
};

// ---------- DRIVER CODE ----------
int main() {
    int n;
    cout << "Enter N for N-Queens: ";
    cin >> n;

    Solution sol;
    vector<vector<string>> solutions = sol.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n";
    for (auto board : solutions) {
        for (auto row : board)
            cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
