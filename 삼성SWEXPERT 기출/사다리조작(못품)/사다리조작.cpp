#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int N, M, H; // 세로줄, 가로선, 가로줄 개수 
int ladder[31][11] = {0, };
int answer = 4;
int min = 98765432;
bool bladder[31][11] = { false, };
stack <pair <int, int> > s;
void input_file()
{
	ios::sync_with_stdio(0);
	ifstream input;
	input.open("사다리조작.txt");
	input >> N >> M >> H;
	int a, b;
	for (int i = 1; i <= M; ++i) {
		input >> a >> b;
		ladder[a][b] = 1;
	}
	
}

void copy(int arr1[][11], int arr2[][11]) {
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= N; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void bcopy(bool arr1[][11], bool arr2[][11]) {
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= N; ++j) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void DFS(int cnt,int arr[][11], unsigned ct) {
	int copyladder[31][11];
	//bool bcopyladder[31][11];
	copy(copyladder, arr);
	//bcopy(bcopyladder, bl);
	for (int i = 1; i <= N; ++i) {
		pair <int, int> p = make_pair(1, i);
		while (p.first < H + 1) {
			cout << "show me the money" << endl;
			cout << p.first << " " << p.second << endl;
			//cout << p.second << endl;
			if (p.second != N && p.second != 1) {
				if (copyladder[p.first][p.second]) {
					//bcopyladder[p.first][p.second] = true;
					p.second++;
					p.first++;
					if (p.second != N) {
						while (1) {
							if (!copyladder[p.first][p.second]) p.first++;
							else if (!copyladder[p.first][p.second-1]) p.first++;
							if (copyladder[p.first][p.second] || copyladder[p.first][p.second - 1]) break;
						}
					}
					else {
						while (1) {
							if (!copyladder[p.first][p.second-1]) p.first++;
							if(copyladder[p.first][p.second - 1]) break;
						}
					}
				}
				else if (copyladder[p.first][p.second - 1]) {
					//bcopyladder[p.first][p.second-1] = true;
					p.second--;
					p.first++;
					if (p.second != 1) {
						while (1) {
							if (!copyladder[p.first][p.second]) p.first++;
							else if (!copyladder[p.first][p.second-1]) p.first++;
							if (copyladder[p.first][p.second] || copyladder[p.first][p.second - 1]) break;
						}
					}
					
					else {
						while (1) {
							if (!copyladder[p.first][p.second]) p.first++;
							if (copyladder[p.first][p.second]) break;
						}
					}
				}
				else p.first++;
			}
			else if (p.second == 1) {
				if (copyladder[p.first][p.second]) {
					//bcopyladder[p.first][p.second] = true;
					p.second++;
					p.first++;
					while (1) {
						if (!copyladder[p.first][p.second]) p.first++;
						else if (!copyladder[p.first][p.second - 1]) p.first++;
						if (copyladder[p.first][p.second] || copyladder[p.first][p.second - 1]) break;
					}
				}
				else p.first++;
			}
			else if (p.second == N) {
				if (copyladder[p.first][p.second - 1]) {
					//bcopyladder[p.first][p.second-1] = true;
					p.second--;
					p.first++;
					while (1) {
						if (!copyladder[p.first][p.second]) p.first++;
						else if (!copyladder[p.first][p.second - 1]) p.first++;
						if (copyladder[p.first][p.second] || copyladder[p.first][p.second - 1]) break;
					}
					//cout << p.second << endl;
				}
				else p.first++;
				//cout << p.second << endl;
			}
		}
		if (p.second != i) break;
		if (i == N && p.second == i) {
			cout << "abcd" << endl;
			if (answer < 0) answer = cnt;
			if (answer > cnt) answer = cnt;
			return;
		}
	}
	if (s.size() <= ct && s.size() < unsigned(H * (N/2))) {
		cout << "H*(N/2) : " << H * (N / 2) << endl;
		for (int i = 1; i <= H; ++i) {
			for (int j = 1; j < N; ++j) {
				if (j != 1) {
					if (!copyladder[i][j] && !copyladder[i][j - 1] && !copyladder[i][j + 1]) {
						cout << "Hello " << i << " " << j << endl;
						copyladder[i][j] = 1;
						s.push(make_pair(i, j));
						DFS(cnt + 1, copyladder, ct);
						copyladder[i][j] = 0;
					}
					else cout << '\n';
				}
				else {
					if (!copyladder[i][j] && !copyladder[i][j + 1]) {
						copyladder[i][j] = 1;
						s.push(make_pair(i, j));

						cout << "hello " << i << " " << j << endl;
						DFS(cnt + 1, copyladder, ct);
						copyladder[i][j] = 0;
					}
				}

			}
		}
	}
	else {
		cout <<"bye " << s.top().first <<" "<<s.top().second <<endl;
		s.pop();
		if(answer == 4) answer = -1;
		return;
	}
}
int main(void)
{
	input_file();
	for(int i = 0; i <= 3; ++i)
	DFS(0, ladder,i);
	cout << answer << endl;
	return 0;
}