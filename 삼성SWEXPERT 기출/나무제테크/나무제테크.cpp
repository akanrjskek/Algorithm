#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K, cnt = 0;
int A[11][11];
int winter[11][11];
int dir[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
vector<int> tree[11][11];

void input_file() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ifstream input;
	input.open("나무제테크.txt");
	input >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			input >> winter[i][j];
			A[i][j] = 5;
		}
	}
	int x, y,temp;
	for (int i = 1; i <= M; ++i) {
		input >> x >> y >> temp;
		tree[x][y].push_back(temp);
	}
}

void Jaetech() {
	for (int i = 0; i < 3; ++i) {
		switch (i) {
		case 0:
			for (int a = 1; a <= N; ++a) {
				for (int b = 1; b <= N; ++b) {
					if (tree[a][b].size()) {
						sort(tree[a][b].begin(), tree[a][b].end());
						int tempcnt = 0;
						int sum = 0;
						for (int c = 0; c < signed(tree[a][b].size()); ++c) {
							if (A[a][b] - tree[a][b][c] >= 0) {
								A[a][b] -= tree[a][b][c];
								tree[a][b][c]++;
							}
							else {
								tempcnt++;
								sum += (tree[a][b][c] / 2);
							}
						}
						A[a][b] += sum;
						tree[a][b].resize(tree[a][b].size() - tempcnt);
					}
				}
			}
			break;
		case 1:
			for (int a = 1; a <= N; ++a) {
				for (int b = 1; b <= N; ++b) {
						for (int c = 0; c < signed(tree[a][b].size()); ++c) {
							if (tree[a][b][c] % 5 == 0) {
								for (int d = 0; d < 8; ++d) {
									int nx = a + dir[d][0];
									int ny = b + dir[d][1];
									if (1 <= nx && N >= nx && 1 <= ny && N >= ny) {
										tree[nx][ny].push_back(1);
									}
								}
							}
						}
				}
			}
			break;
		case 2:
			for (int a = 1; a <= N; ++a) {
				for (int b = 1; b <= N; ++b) {
					A[a][b] += winter[a][b];
				}
			}
			break;
		}
	}
}

void calcurate() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (tree[i][j].size()) {
				for (int k = 0; k < signed(tree[i][j].size()); ++k)
					cnt++;
			}
		}
	}
}
int main(void)
{
	input_file();
	for(int i = 0; i < K; ++i) Jaetech();
	calcurate();
	cout << cnt << endl;
	return 0;
}