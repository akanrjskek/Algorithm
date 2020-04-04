#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <utility>
//#include <algorithm>

using namespace std;

int board[101][101];
int apple[101][101];
int dir[4] = { 0,1,2,3 };
int d = dir[0];
vector < pair< int, char > > lotate;
queue <pair <int, int> > q;
int N, K, L;
int x = 1, y = 1, cou = 0;
bool flag = true;

void input_file()
{
	ifstream input;
	input.open("snake2.txt");
	input >> N >> K;
	int tmp1, tmp2;
	board[1][1] = 1;
	for (int i = 0; i < K; ++i) {
		input >> tmp1 >> tmp2;
		apple[tmp1][tmp2] = 1;
	}
	input >> L;
	int tmp3;
	char tmp4;
	for (int i = 0; i < L; ++i) {
		input >> tmp3 >> tmp4;
		lotate.push_back(make_pair(tmp3, tmp4));
	}
	lotate.push_back(make_pair(1, 'd'));
}

void snake(int index) {
	int walk;
	if (index == 0) {
		d = dir[0];
		walk = lotate[index].first;
	}
	else if (index == lotate.size()-1) {
		walk = 100;
	}
	else walk = lotate[index].first - lotate[index - 1].first;

	switch (d) {
	case 0:
		for (int i = 0; i < walk; ++i) {
			if (!flag) break;
			y++;
			if (!apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				if (!q.empty()) {
					board[q.front().first][q.front().second] = 0;
					//cout << q.front().first << " " << q.front().second << endl;
					q.push(make_pair(x, y));
					q.pop();
				}
				cou++;
				if (y > N) flag = false;
				//cout << walk << endl;
			}
			else if (apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				q.push(make_pair(x, y));
				cou++;
				apple[x][y] = 0;
				if (y > N) flag = false;
				//cout << cou << " ";
			}
			/*for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		if (lotate[index].second == 'L') d = dir[3];
		else d++;
		break;
	case 1:
		for (int i = 0; i < walk; ++i) {
			if (!flag) break;
			++x;
			if (!apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				if (!q.empty()) {
					board[q.front().first][q.front().second] = 0;
					q.push(make_pair(x, y));
					q.pop();
				}
				cou++;
				if (x > N) flag = false;
			}
			else if (apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				q.push(make_pair(x, y));
				cou++;
				apple[x][y] = 0;
				if (x > N) flag = false;
			}
			/*for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		if (lotate[index].second == 'L') d--;
		else d++;
		break;
	case 2:
		for (int i = 0; i < walk; ++i) {
			if (!flag) break;
			--y;
			if (!apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				if (!q.empty()) {
					board[q.front().first][q.front().second] = 0;
					q.push(make_pair(x, y));
					q.pop();
				}
				cou++;
				if (y == 0) flag = false;
			}
			else if (apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				q.push(make_pair(x, y));
				cou++;
				apple[x][y] = 0;
				if (y == 0) flag = false;
			}
			/*for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		if (lotate[index].second == 'L') d--;
		else d++;

		break;
	case 3:
		for (int i = 0; i < walk; ++i) {
			if (!flag) break;
			--x;
			if (!apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				if (!q.empty()) {
					board[q.front().first][q.front().second] = 0;
					q.push(make_pair(x, y));
					q.pop();
				}
				cou++;
				if (x == 0) flag = false;
			}
			else if (apple[x][y]) {
				if (board[x][y]) flag = false;
				board[x][y] = 1;
				q.push(make_pair(x, y));
				cou++;
				apple[x][y] = 0;
				if (x == 0) flag = false;
			}
			/*for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= 10; ++j) {
					cout << board[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/
		}
		if (lotate[index].second == 'L') d--;
		else d = 0;
		break;
	}

}
void LS() {
	for (size_t i = 0; i < lotate.size(); ++i) {
		if (!flag)  break;
		snake(i);
	}
}


int main(void)
{
	input_file();
	q.push(make_pair(1, 1));
	LS();
	cout << cou << endl;
	/*for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}