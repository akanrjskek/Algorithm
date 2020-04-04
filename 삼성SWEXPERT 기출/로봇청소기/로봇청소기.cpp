#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int N, M;
int map[50][50];
pair <int, int> robot;
int dx[4] = { 0,1,0,-1 }; // 서, 남 ,동, 북 순서
int dy[4] = { -1,0,1,0 };
int dir;
int cnt = 1;
void input_file()
{
	ifstream input;
	input.open("로봇청소기.txt");
	input >> N >> M;
	int temp1, temp2, dir;
	input >> temp1 >> temp2 >> dir;
	robot = make_pair(temp1, temp2);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			input >> map[i][j];
}

void BFS() {
	queue <pair <int, int> > q;
	q.push(robot);

	int rotate = 0;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		if ((0 <= nx + dx[dir] && nx + dx[dir] < N) && (0 <= ny + dy[dir] && ny + dy[dir] < M)) {
			//cout << "( " << nx << ", " << ny << " )";
			map[nx][ny] = 2;
			//int count = 0;

			if (map[nx + dx[dir]][ny + dy[dir]] == 0) {
				q.push(make_pair(nx + dx[dir], ny + dy[dir]));
				map[nx + dx[dir]][ny + dy[dir]] = 2;
				cnt++;
				if (dir != 3) dir++;
				else dir = 0;
				q.pop();
				/*for (int i = 0; i < N; ++i) {
					cout << endl;
					for (int j = 0; j < M; ++j)
						cout << map[i][j] << " ";
				}
				cout << endl;*/
				rotate = 0;
				//cout << cnt << endl;
			}

			else if ((map[nx + dx[dir]][ny + dy[dir]] == 1 ||
				map[nx + dx[dir]][ny + dy[dir]] == 2)) {
				if (rotate == 4) {
					if (dir != 3)
						if (map[nx + dx[dir + 1]][ny + dy[dir + 1]] == 2) {
							q.push(make_pair(nx + dx[dir + 1], ny + dy[dir + 1]));
							q.pop();
							rotate = 0;
						}
						else {
							break;
						}
					else {
						if (map[nx + dx[0]][ny + dy[0]] == 2) {
							q.push(make_pair(nx + dx[0], ny + dy[0]));
							q.pop();
							rotate = 0;
						}
						else {
							break;
						}
					}
				}
				if (dir != 3) dir++;
				else dir = 0;
				rotate++;
			}
		}
		else {
				//cout<<"hello"<<endl;
				if (dir != 3)
					if (map[nx + dx[dir + 1]][ny + dy[dir + 1]] == 2) {
						q.push(make_pair(nx + dx[dir + 1], ny + dy[dir + 1]));
						q.pop();
						rotate = 0;
					}
					else {
						//cout << rotate << endl;
						if(rotate == 4) break;
					}
				else {
					if (map[nx + dx[0]][ny + dy[0]] == 2) {
						q.push(make_pair(nx + dx[0], ny + dy[0]));
						q.pop();
						rotate = 0;
					}
					else {
						cout << rotate << endl;
						if (rotate == 4) break;
					}
				}

			
			if (dir != 3) dir++;
			else dir = 0;
			rotate++;

		}
	}

}
int main(void)
{
	input_file();
	BFS();
	cout << cnt << endl;
	return 0;
}