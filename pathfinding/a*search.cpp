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
    double f, g, h;
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

double calculateHValue(int row, int col, Pair dest) {
    return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
}

void tracePath(cell cellDetails[][COL], Pair dest) {
    cout << "\nThe Path is ";
    int row = dest.first;
    int col = dest.second;

    stack<Pair> Path;

    while (!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)) {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col].parent_i;
        int temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }

    Path.push(make_pair(row, col));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        cout << "-> (" << p.first << "," << p.second << ") ";
    }
}

void aStarSearch(int grid[][COL], Pair src, Pair dest) {
    if (!isValid(src.first, src.second)) {
        cout << "Source is invalid\n";
        return;
    }

    if (!isValid(dest.first, dest.second)) {
        cout << "Destination is invalid\n";
        return;
    }

    if (!isUnBlocked(grid, src.first, src.second) || !isUnBlocked(grid, dest.first, dest.second)) {
        cout << "Source or the destination is blocked\n";
        return;
    }

    if (isDestination(src.first, src.second, dest)) {
        cout << "We are already at the destination\n";
        return;
    }

    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    cell cellDetails[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cellDetails[i][j].f = DBL_MAX;
            cellDetails[i][j].g = DBL_MAX;
            cellDetails[i][j].h = DBL_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    int i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    set<pPair> openList;
    openList.insert(make_pair(0.0, make_pair(i, j)));

    bool foundDest = false;

    while (!openList.empty()) {
        pPair p = *openList.begin();
        openList.erase(openList.begin());

        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        double gNew, hNew, fNew;

        // Neighbor directions
        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

        for (int k = 0; k < 8; k++) {
            int newR = i + dx[k];
            int newC = j + dy[k];

            if (isValid(newR, newC)) {
                if (isDestination(newR, newC, dest)) {
                    cellDetails[newR][newC].parent_i = i;
                    cellDetails[newR][newC].parent_j = j;
                    cout << "The destination cell is found\n";
                    tracePath(cellDetails, dest);
                    foundDest = true;
                    return;
                }
                else if (!closedList[newR][newC] && isUnBlocked(grid, newR, newC)) {
                    // Cost is 1.0 for straight, 1.414 for diagonal
                    double stepCost = (dx[k] != 0 && dy[k] != 0) ? 1.414 : 1.0;
                    gNew = cellDetails[i][j].g + stepCost;
                    hNew = calculateHValue(newR, newC, dest);
                    fNew = gNew + hNew;

                    if (cellDetails[newR][newC].f == DBL_MAX || cellDetails[newR][newC].f > fNew) {
                        openList.insert(make_pair(fNew, make_pair(newR, newC)));
                        cellDetails[newR][newC].f = fNew;
                        cellDetails[newR][newC].g = gNew;
                        cellDetails[newR][newC].h = hNew;
                        cellDetails[newR][newC].parent_i = i;
                        cellDetails[newR][newC].parent_j = j;
                    }
                }
            }
        }
    }

    if (!foundDest) cout << "Failed to find the Destination Cell\n";
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

    Pair src = make_pair(8, 0);
    Pair dest = make_pair(0, 0);
    aStarSearch(grid, src, dest);
    return 0;
}