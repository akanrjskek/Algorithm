#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int N;
vector <int> numvector;
vector < vector <pair < char, char> > > cb;
char tempcube[4][3];
char cube[6][3][3];
void input_file()
{
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 3; ++j) {
			switch (i) {
			case 0:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'w';
				break;
			case 1:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'y';
				break;
			case 2:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'r';
				break;
			case 3:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'o';
				break;
			case 4:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'g';
				break;
			case 5:
				for (int k = 0; k < 3; ++k) cube[i][j][k] = 'b';
				break;
			}
		}
	}
	ifstream input;
	input.open("Å¥ºù.txt");
	input >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		input >> temp;
		vector < pair < char, char > > tv;
		for (int j = 0; j < temp; ++j) {
			char tc1, tc2;
			input >> tc1 >> tc2;
			tv.push_back(make_pair(tc1, tc2));
		}
		cb.push_back(tv);
	}
}

void rotate(int index) {
	for (int i = 0; i < signed(cb[index].size()); ++i) {
		char space = cb[index][i].first, dir = cb[index][i].second;
		switch (space) {
		case 'U':
			switch (dir) {
			case '+':
				for (int j = 0; j < 6; ++j) {
					for (int k = 0; k < 3; ++k) {
						if (j != 0 || j != 1) {
							tempcube[j][k] = '';
						}
					}
				}
			case '-':

			}
		}
	}
}
int main(void)
{
	input_file();
	for(int i = 0; i < N; ++i) rotate(i);

	return 0;
}