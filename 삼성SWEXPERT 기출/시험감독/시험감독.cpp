#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int N, B, C; // 시험장 , 총감독관이 감독가능한 응시자 수, 부감독관이 감독가능한 응시자 수
long long cou;

queue < int > people;

void input_file() {
	ifstream input;
	input.open("시험감독.txt");
	cin >> N;
	int A;
	for (int i = 0; i < N; ++i) {
		cin >> A;
		people.push(A);
	}
	
	cin >> B >> C;
	if(B != 0) cou = N;
}

void directing() {
	while (!people.empty()) {
		int temp = people.front();
		people.pop();
		temp -= B;
		if (temp <= 0) continue;
		if (temp > 0) {
			int share,remainder;
			share = temp / C;
			remainder = temp % C;
			if (!remainder) cou = cou + share;
			else cou = cou + share + 1;
		}
	}
}

int main(void)
{
	input_file();
	directing();
	cout << cou << endl;
	return 0;
}