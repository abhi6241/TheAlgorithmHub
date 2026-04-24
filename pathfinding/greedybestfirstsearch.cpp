#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <cmath>
#include <cstring>
#include <cfloat>

using namespace std;

#define ROW 9
#define COL 10

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct cell {
    int parent_i, parent_j;
    double h; // Greedy ONLY cares about h
};

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool isUnBlocked(int grid[][COL], int row, int col) {
    return (grid[row][col] == 1);
}

bool isDestination(int row, int col, Pair dest) {
    return (row == dest.first && col == dest.second);
}

// Heuristic: Euclidean Distance
double calculateHValue(int row, int col, Pair dest) {
    return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

void tracePath(cell cellDetails[][COL], Pair dest) {
    cout << "\nPath Found: ";
    stack<Pair> Path;
    int row = dest.first;
    int col = dest.second;

    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_r = cellDetails[row][col].parent_i;
        int temp_c = cellDetails[row][col].parent_j;
        row = temp_r; col = temp_c;
    }
    Path.push(make_pair(row, col));

    while (!Path.empty()) {
        Pair p = Path.top();
        Path.pop();
        cout << "-> (" << p.first << "," << p.second << ") ";
    }
    cout << endl;
}

void greedyBestFirstSearch(int grid[][COL], Pair src, Pair dest) {
    if (!isValid(src.first, src.second) || !isValid(dest.first, dest.second)) return;
    if (!isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second)) return;

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    cell cellDetails[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].h = DBL_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // Initial node
    int i = src.first, j = src.second;
    cellDetails[i][j].h = calculateHValue(i, j, dest);
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    set<pPair> openList;
    openList.insert(make_pair(cellDetails[i][j].h, make_pair(i, j)));

    while (!openList.empty()) {
        pPair p = *openList.begin();
        openList.erase(openList.begin());

        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        // Neighbors (8 directions)
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        for (int k = 0; k < 8; k++) {
            int nR = i + dx[k];
            int nC = j + dy[k];

            if (isValid(nR, nC)) {
                if (isDestination(nR, nC, dest)) {
                    cellDetails[nR][nC].parent_i = i;
                    cellDetails[nR][nC].parent_j = j;
                    tracePath(cellDetails, dest);
                    return;
                } else if (!closedList[nR][nC] && isUnBlocked(grid, nR, nC)) {
                    double hNew = calculateHValue(nR, nC, dest);

                    // Greedy check: only add if we haven't found a "closer" way yet
                    if (cellDetails[nR][nC].h == DBL_MAX || cellDetails[nR][nC].h > hNew) {
                        openList.insert(make_pair(hNew, make_pair(nR, nC)));
                        cellDetails[nR][nC].h = hNew;
                        cellDetails[nR][nC].parent_i = i;
                        cellDetails[nR][nC].parent_j = j;
                    }
                }
            }
        }
    }
    cout << "Failed to find destination." << endl;
}

int main() {
    int grid[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };

    greedyBestFirstSearch(grid, {8, 0}, {0, 0});
    return 0;
}