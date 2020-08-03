#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool isClear = false;

void sudoku(int map[][9], int emptyVals[][9][9], vector<set<int>>& emptyPos) {
	if (!isClear) {
		if (emptyPos.size() == 0) {
			
			isClear = true;
		}
		else {
			int y = 0;

			while (y < 9) {
				if (emptyPos[y].size() != 0) {
					auto xIter = emptyPos[y].begin();
					while (xIter != emptyPos[y].end()) {
						int x = *xIter;
						emptyPos[y].erase(x);

						for (int i = 0; i < 9; i++) {
							if (emptyVals[y][x][i] == 0) {
								emptyVals[y][x][i] = 1;
								map[y][x] = i + 1;

								sudoku(map, emptyVals, emptyPos);

								emptyVals[y][x][i] = 0;
								map[y][x] = 0;
							}
						}
					}
				}
			}
		}
	}
}

int main(void) {
	int map[9][9] = { 0 };
	int emptyVals[9][9][9] = { 0 };

	vector<set<int>> emptyPos;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int i = 0; i < 9; i++) {
		emptyPos.push_back(set<int>());
		for (int j = 0; j < 9; j++) {
			int value;
			cin >> value;

			map[i][j] = value;

			if (value == 0)
				emptyPos.back().insert(j);
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j : emptyPos[i]) {
			int cellX = j / 3;
			int cellY = i / 3;

			for (int x = 0; x < 9; x++) {
				if (x != j)
					emptyVals[i][j][map[i][x]-1] = 1;
			}
			for (int y = 0; y < 9; y++) {
				if (y != i)
					emptyVals[i][j][map[y][j]-1] = 1;
			}

			for (int y = cellY; y < cellY + 3; y++) {
				for (int x = cellX; x < cellX + 3; x++) {
					if (y == i && x == j)
						continue;
					emptyVals[i][j][map[y][x] - 1] = 1;
				}
			}
		}
	}

	sudoku(map, emptyVals, emptyPos);

	return 0;

}

/*
1 0 0 0 0 0 9 8 7
0 2 0 0 0 0 0 0 0
0 0 3 0 0 0 0 0 0
0 0 0 4 0 0 0 0 0
0 0 0 0 5 0 0 0 0
0 0 0 9 0 6 0 0 0
0 0 8 0 0 0 7 0 0
0 7 0 0 0 0 0 8 0
3 1 2 0 0 0 0 0 9


*/
