#include <iostream>
#include <vector>
#include <fstream>
#include <queue>


using namespace std;

int N, M;
int r[9][9];
int tempr[9][9];
int max_value = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void input_file() {
	ifstream input;
	input.open("¿¬±¸¼Ò.txt");
	input >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			input >> r[i][j];
		}
	}
}

void mapcopy(int (*a)[9], int (*b)[9]) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			a[i][j] = b[i][j];
		}
	}
}

void virus() {
	int ans = 0;
	int viruslab[9][9];
	mapcopy(viruslab, tempr);
	queue < pair<int, int >> q;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (viruslab[i][j] == 2) q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 < nx && nx <= N && 0 < ny && ny <= M) {
				if (viruslab[nx][ny] == 0) {
					viruslab[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (viruslab[i][j] == 0) ans++;
		}
	}
	max_value = max(ans, max_value);

}

void wall(int cnt) {
	if (cnt == 3) {
		virus();
		return;
	}
	else {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (tempr[i][j] == 0) {
					tempr[i][j] = 1;
					wall(cnt + 1);
					tempr[i][j] = 0;
				}
			}
		}
	}
}

int main(void)
{
	input_file();
	mapcopy(tempr, r);
	wall(0);
	cout << max_value << endl;
	return 0;
}