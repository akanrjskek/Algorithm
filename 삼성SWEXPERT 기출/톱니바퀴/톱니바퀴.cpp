#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int wheel;
int num; // 회전 횟수
int wheelnum[101]; // 먼저 회전할 톱니바퀴
int dir[101]; // (반)시계 방향
int topni[5][9]; // 톱니바퀴
queue <pair <int,int> > q;
bool bb[5] = { false, };


//N극 = 0, S극 = 1;
//시계방향 = 1, 반시계방향 = -1;

//12시 방향 S극이면 점수
//1번 : 1점, 2번 : 2점, 3번 : 4점, 4번 : 8점 

void input_file()
{
	ifstream input;
	input.open("톱니바퀴.txt");

	for (int i = 1; i <= 4; ++i) {
		cin >> wheel;
		int temp2 = wheel;
		for (int j = 8; j >= 1; --j) {
			int temp1 = temp2 % 10;
			temp2 /= 10;
			topni[i][j] = temp1;
		}
	}
	cin >> num; 
	for (int i = 1; i <= num; ++i) {
		cin >> wheelnum[i];
		cin >> dir[i];
	}
	
}

void BFS(int n) {
	for (int c = 1; c <= n; ++c) {
		bool btopni[5] = { false, };
		q.push(make_pair(wheelnum[c],dir[c]));
		int temptopni[5][9];
		if (dir[c] == 1) {
			for (int j = 1; j <= 8; ++j) {
				if (j == 8) temptopni[wheelnum[c]][1] = topni[wheelnum[c]][8];
				else temptopni[wheelnum[c]][j + 1] = topni[wheelnum[c]][j];
			}
		}
		else {
			for (int i = 1; i <= 8; ++i) {
				if (i == 1) temptopni[wheelnum[c]][8] = topni[wheelnum[c]][1];
				else temptopni[wheelnum[c]][i - 1] = topni[wheelnum[c]][i];
			}
		}
		btopni[wheelnum[c]] = true;
		while (!q.empty()) {
			int wnum = q.front().first;
			int tempdir = q.front().second;
			btopni[wnum] = true;
			q.pop();
			if (tempdir == 1) {
				if (wnum == 2 || wnum == 3) {
					if (topni[wnum][7] != topni[wnum - 1][3] && !btopni[wnum - 1]) {
						if (wnum == 2) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 1) temptopni[1][8] = topni[wnum - 1][1];
								else temptopni[1][j - 1] = topni[wnum - 1][j];
							}
							btopni[1] = true;
							q.push(make_pair(1, -1));
						}
						if (wnum == 3) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 1) temptopni[2][8] = topni[wnum - 1][1];
								else temptopni[2][j - 1] = topni[wnum - 1][j];
							}
							btopni[2] = true;
							q.push(make_pair(2, -1));
						}
					}
					if (topni[wnum][3] != topni[wnum + 1][7] && !btopni[wnum + 1]) {
						if (wnum == 2) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 1) temptopni[3][8] = topni[wnum + 1][1];
								else temptopni[3][j - 1] = topni[wnum + 1][j];
							}
							btopni[3] = true;
							q.push(make_pair(3, -1));
						}
						if (wnum == 3) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 1) temptopni[4][8] = topni[wnum + 1][1];
								else temptopni[4][j - 1] = topni[wnum + 1][j];
							}
							btopni[4] = true;
							q.push(make_pair(4, -1));
						}
					}
				}
				else if (wnum == 1) {
					if (topni[wnum][3] != topni[wnum + 1][7] && !btopni[wnum + 1]) {
						for (int j = 1; j <= 8; ++j) {
							if (j == 1) temptopni[2][8] = topni[wnum + 1][1];
							else temptopni[2][j - 1] = topni[wnum + 1][j];
						}
						btopni[2] = true;
						q.push(make_pair(2, -1));
					}
				}
				else {
					if (topni[wnum][7] != topni[wnum - 1][3] && !btopni[wnum - 1]) {
						for (int j = 1; j <= 8; ++j) {
							if (j == 1) temptopni[3][8] = topni[wnum - 1][1];
							else temptopni[3][j - 1] = topni[wnum - 1][j];
						}
						btopni[3] = true;
						q.push(make_pair(3, -1));
					}
				}
			}
			else {
				if (wnum == 2 || wnum == 3) {
					if (topni[wnum][7] != topni[wnum - 1][3] && !btopni[wnum-1]) {
						if (wnum == 2) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 8) temptopni[1][1] = topni[wnum - 1][8];
								else temptopni[1][j + 1] = topni[wnum - 1][j];
							}
							btopni[1] = true;
							q.push(make_pair(1, 1));
						}
						if (wnum == 3) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 8) temptopni[2][1] = topni[wnum - 1][8];
								else temptopni[2][j + 1] = topni[wnum - 1][j];
							}
							btopni[2] = true;
							q.push(make_pair(2, 1));
						}
					}
					if (topni[wnum][3] != topni[wnum + 1][7] && !btopni[wnum+1]) {
						if (wnum == 2) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 8) temptopni[3][1] = topni[wnum + 1][8];
								else temptopni[3][j + 1] = topni[wnum + 1][j];
							}
							btopni[3] = true;
							q.push(make_pair(3, 1));
						}
						if (wnum == 3) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 8) temptopni[4][1] = topni[wnum + 1][8];
								else temptopni[4][j + 1] = topni[wnum + 1][j];
							}
							btopni[4] = true;
							q.push(make_pair(4, 1));
						}
					}
				}
				else if (wnum == 1) {
					if (topni[wnum][3] != topni[wnum + 1][7] && !btopni[wnum + 1]) {
						for (int j = 1; j <= 8; ++j) {
							if (j == 8) temptopni[2][1] = topni[wnum + 1][8];
							else temptopni[2][j + 1] = topni[wnum + 1][j];
						}
						btopni[2] = true;
						q.push(make_pair(2, 1));
					}
				}
				else {
					if (topni[wnum][7] != topni[wnum - 1][3] && !btopni[wnum - 1]) {
						if (wnum == 4) {
							for (int j = 1; j <= 8; ++j) {
								if (j == 8) temptopni[3][1] = topni[wnum - 1][8];
								else temptopni[3][j + 1] = topni[wnum - 1][j];
							}
							btopni[3] = true;
							q.push(make_pair(3, 1));
						}
					}
				}
				
			}
			if (q.empty()) {
				for (int a = 1; a <= 4; ++a) {
					if (btopni[a]) {
						for (int b = 1; b <= 8; ++b) {
							topni[a][b] = temptopni[a][b];
						}
					}
				}
			}
		}
	}
}
int main(void)
{
	int sum = 0;
	input_file();
	BFS(num);
	for (int i = 1; i <= 4; ++i) {
		if(topni[i][1])
		switch (i) {
		case 1:
		{
			sum += 1;
			break;
		}
		case 2:
		{
			sum += 2;
			break;
		}
		case 3:
		{
			sum += 4;
			break;
		}
		case 4:
		{
			sum += 8;
			break;
		}
		}
	}
	cout << sum << endl;
	return 0;
}