#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int board[500][500];
bool visit[500][500];

int n, m;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

//DFS를 할 수 있는 경우의 도형들
int tetromino(int x, int y, int cnt) {
	if (cnt >= 5) {
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if (visit[nx][ny] == false) {
				visit[nx][ny] = true;
				ans = max(ans, tetromino(nx, ny, cnt + 1) + board[x][y]);
				visit[nx][ny] = false;
			}
		}
	}
	return ans;
}
//ㅗ모양은 DFS를 사용할 수 없으므로 따로 구해준다.
int exShape(int x, int y) {
	int ans = 0;
	// ㅗ모양
	if (x >= 1 && y >= 1 && y < m - 1)
		ans = max(ans, board[x][y] + board[x - 1][y] + board[x][y - 1] + board[x][y + 1]);
	// ㅜ모양
	if (x < n - 1 && y >= 1 && y < m - 1)
		ans = max(ans, board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1]);
	// ㅏ모양
	if (x < n - 1 && x >= 1 && y < m - 1)
		ans = max(ans, board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y + 1]);
	// ㅓ모양
	if (x < n - 1 && x >= 1 && y >= 1)
		ans = max(ans, board[x][y] + board[x + 1][y] + board[x - 1][y] + board[x][y - 1]);
	return ans;
}
int main() {
	ifstream input;
	input.open("테트로미노.txt");
	input >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			input >> board[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			ans = max(ans, exShape(i, j));
			ans = max(ans, tetromino(i, j, 1));
			visit[i][j] = false;
		}
	}

	printf("%d\n", ans);
	return 0;
}

