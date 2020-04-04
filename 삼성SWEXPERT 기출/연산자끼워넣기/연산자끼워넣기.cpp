#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int N;
int number[12];
int oper[4]; // ���� [0], ����[1], ����[2], ������[3]
int depth = 0;
long long max_value = -1000000001;
long long min_value = 1000000001;

void input_file() {

	ifstream input;
	input.open("�����ڳ����ֱ�.txt");
	input >> N;
	for (int i = 0; i < N; ++i) input >> number[i];
	for (int i = 0; i < 4; ++i) input >> oper[i];

}

void DFS(int dep, int result) {
	if (dep == N -1) {
		if (result > max_value) max_value = result;
		if (result < min_value) min_value = result;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			if (oper[i]>0) {
				int num;
				if (i == 0) {
					num = result + number[dep + 1];
				}
				else if (i == 1) {
					num = result - number[dep + 1];
				}
				else if (i == 2) {
					num = result * number[dep + 1];
				}
				else if (i == 3) {
					num = result / number[dep + 1];
				}
				oper[i]--;
				DFS(dep + 1, num);
				oper[i]++;
			}
		}
	}
}

int main(void)
{
	input_file();
	DFS(depth,number[0]);
	cout << max_value << "\n" << min_value << endl;
	return 0;
}