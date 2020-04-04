#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int N, M, x, y, K;
int dice[4][3] = { 0, };
int mapp[20][20];
int com[1000];

void input_file() {
	ifstream input;
	input.open("주사위굴리기.txt");
	input >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			input >> mapp[i][j];
		}
	}
	for (int i = 0; i < K; ++i) {
		input >> com[i];
	}
}

void roll(int num) {
	int temp1, temp2, temp3, temp4;
	switch (num) {
	case 1:
		if (y < M - 1) {
			y++;
			temp1 = dice[1][0];
			temp2 = dice[1][1];
			temp3 = dice[1][2];
			temp4 = dice[3][1];
			dice[1][1] = temp1, dice[1][2] = temp2;
			dice[3][1] = temp3, dice[1][0] = temp4;

			if (!mapp[x][y]) {
				mapp[x][y] = dice[3][1];
			}
			else {
				dice[3][1] = mapp[x][y];
				mapp[x][y] = 0;
			}
			cout << dice[1][1] << endl;
		}
		break;
	case 2:
		if (y > 0) {
			
			y--;
			temp1 = dice[1][0], temp2 = dice[1][1];
			temp3 = dice[1][2], temp4 = dice[3][1];
			dice[3][1] = temp1, dice[1][0] = temp2;
			dice[1][1] = temp3, dice[1][2] = temp4;

			if (!mapp[x][y]) {
				mapp[x][y] = dice[3][1];
			}
			else {
				dice[3][1] = mapp[x][y];
				mapp[x][y] = 0;
			}
			cout << dice[1][1] << endl;
		}
		break;
	case 3:
		if (x > 0) {
			x--;
			temp1 = dice[0][1], temp2 = dice[1][1];
			temp3 = dice[2][1], temp4 = dice[3][1];
			dice[3][1] = temp1, dice[0][1] = temp2;
			dice[1][1] = temp3, dice[2][1] = temp4;

			if (!mapp[x][y]) {
				mapp[x][y] = dice[3][1];
			}
			else {
				dice[3][1] = mapp[x][y];
				mapp[x][y] = 0;
			}
			cout << dice[1][1] << endl;
		}
		break;
	case 4:
		if (x < N - 1) {
			x++;
			temp1 = dice[0][1], temp2 = dice[1][1];
			temp3 = dice[2][1], temp4 = dice[3][1];
			dice[1][1] = temp1, dice[2][1] = temp2;
			dice[3][1] = temp3, dice[0][1] = temp4;

			if (!mapp[x][y]) {
				mapp[x][y] = dice[3][1];
			}
			else {
				dice[3][1] = mapp[x][y];
				mapp[x][y] = 0;
			}
			cout << dice[1][1] << endl;
		}
		break;
	}
}
void dice_algorithm() {
	for (int i = 0; i < K; ++i) roll(com[i]);
}

int main(void)
{
	input_file();
	dice_algorithm();
	return 0;
}