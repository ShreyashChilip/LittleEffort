#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    vector<vector<int>> maze = {
        {0,0,0,1,0,0},
        {0,1,0,0,1,0},
        {0,1,0,0,0,0},
        {0,0,0,1,0,0},
        {0,1,0,0,0,0}
    };

    int rows = maze.size();
    int cols = maze[0].size();
    int str = 0, stc = 0;
    int destr  = 4, destc  = 5;

    auto heuristic = [&](int r, int c) {
        return abs(r - destr) + abs(c - destc);
    };

    vector<vector<int>> g(rows, vector<int>(cols, INT_MAX));
    g[str][stc] = 0;

    using Node = pair<int, pair<int,int>>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({heuristic(str,stc), {str,stc}});

    int dr[4] = {1,-1,0,0};
    int dc[4] = {0,0,1,-1};

    while (!pq.empty()) {
        auto top = pq.top(); 
        pq.pop();
        int r = top.second.first;
        int c = top.second.second;
        int current_g = g[r][c];

        if (r == destr && c == destc) {
            cout << "Shortest path cost: " << current_g << endl;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
            if (maze[nr][nc] == 1) continue;

            int new_g = current_g + 1;
            if (new_g < g[nr][nc]) {
                g[nr][nc] = new_g;
                int f = new_g + heuristic(nr,nc);
                pq.push({f, {nr,nc}});
            }
        }
    }

    cout << "No path found!\n";
    return 0;
}
