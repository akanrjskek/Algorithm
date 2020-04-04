#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int N, L, R;
int nation[101][101];
int answer = 0;
bool bnation[101][101] = { false ,};
void input_file()
{
	ifstream input;
	input.open("인구이동.txt");
	input >> N >> L >> R;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			input >> nation[i][j];
		}
	}
}

void BFS() {
	int cnt = 0;
	while (1) {
		int flag = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				bnation[i][j] = false;
			}
		}
		int tempcnt = cnt;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (!bnation[i][j]) {
					bnation[i][j] = true;
					vector < pair < int, int > > v;
					int sum = nation[i][j];
					queue <pair <int, int>> q;
					q.push(make_pair(i, j));
					v.push_back(make_pair(i, j));
					while (!q.empty()) {
						for (int k = 0; k < 4; ++k) {
							switch (k) {
							case 0:
								if (q.front().second < N && L <= abs(nation[q.front().first][q.front().second + 1] - nation[q.front().first][q.front().second]) && R >= abs(nation[q.front().first][q.front().second + 1] - nation[q.front().first][q.front().second]) && !bnation[q.front().first][q.front().second + 1]) {
									q.push(make_pair(q.front().first, q.front().second + 1));
									v.push_back(make_pair(q.front().first, q.front().second + 1));
									bnation[q.front().first][q.front().second + 1] = true;
									sum += nation[q.front().first][q.front().second + 1];
									
								}
								break;
							case 1:
								if (q.front().first < N && L <= abs(nation[q.front().first + 1][q.front().second] - nation[q.front().first][q.front().second]) && R >= abs(nation[q.front().first + 1][q.front().second] - nation[q.front().first][q.front().second]) && !bnation[q.front().first + 1][q.front().second]) {
									q.push(make_pair(q.front().first + 1, q.front().second));
									v.push_back(make_pair(q.front().first + 1, q.front().second));
									bnation[q.front().first + 1][q.front().second] = true;
									sum += nation[q.front().first + 1][q.front().second];

								}
								break;
							case 2:
								if (q.front().second > 1 && L <= abs(nation[q.front().first][q.front().second - 1] - nation[q.front().first][q.front().second]) && R >= abs(nation[q.front().first][q.front().second - 1] - nation[q.front().first][q.front().second]) && !bnation[q.front().first][q.front().second - 1]) {
									q.push(make_pair(q.front().first, q.front().second - 1));
									v.push_back(make_pair(q.front().first, q.front().second - 1));
									bnation[q.front().first][q.front().second - 1] = true;
									sum += nation[q.front().first][q.front().second - 1];
									
								}
								break;
							case 3:
								if (q.front().first > 1 && L <= abs(nation[q.front().first - 1][q.front().second] - nation[q.front().first][q.front().second]) && R >= abs(nation[q.front().first - 1][q.front().second] - nation[q.front().first][q.front().second]) && !bnation[q.front().first - 1][q.front().second]) {
									q.push(make_pair(q.front().first - 1, q.front().second));
									v.push_back(make_pair(q.front().first - 1, q.front().second));
									bnation[q.front().first - 1][q.front().second] = true;
									sum += nation[q.front().first - 1][q.front().second];
									
								}
								break;
							}
						}
						q.pop();
					}
					if (v.size() != 1) {
						sum = sum / signed(v.size());
						for (int a = 0; a < (signed)v.size(); ++a) {
							nation[v[a].first][v[a].second] = sum;
						}
						if(tempcnt == cnt)
						answer++;
						tempcnt++;
					}
					else {
						flag++;
					}
				}
				
			}
		}
		if (flag == N * N) break;
	}
}
int main(void)
{
	input_file();
	BFS();
	cout << answer << endl;
	return 0;
}