#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int N,time = 0;
pair<int,int> nemo[21][21];
pair <int, int> shark;
vector <pair<int, int>> fish;
int cnt = 0
;

int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };

void input_file() {
	ifstream input;
	input.open("아기상어.txt");
	input >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			input >> nemo[i][j].first;
			if (nemo[i][j].first) {
				nemo[i][j].second = nemo[i][j].first;
				nemo[i][j].first = 1;
				fish.push_back(make_pair(i, j));
			}
			else nemo[i][j].second = 0;
			if (nemo[i][j].first == 9) {
				shark.first = i;
				shark.second = j;
				nemo[i][j].second = 2;
			}
		}
	}
}

int main(void)
{
	input_file();
	BFS();
	cout << time << endl;
	return 0;
}