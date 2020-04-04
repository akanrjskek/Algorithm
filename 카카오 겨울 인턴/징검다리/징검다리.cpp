#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int bridge[200000];
int k;
void input_file()
{
	ifstream input;
	input.open("Â¡°Ë´Ù¸®.txt");
	input >> k;
	for (int i = 0; i < 10; ++i) {
		input >> bridge[i];
	}
	
}
int main(void)
{
	input_file();
	int answer = 0;
	while (1) {
		int i;
		int j=1;
		for (i = 0; i < 10; ++i) {
			if (bridge[i] > 0) bridge[i]--;
			else {
				for (j = 1; j < k-1; ++j) {
					if (bridge[i + j] || i+j > 10) {
						i += j;
						break;
					}
				}
				if (j == k - 1) break;
			}
		}
		if (j == k - 1) break;
		answer++;
		for (int a = 0; a < 10; ++a) {
			cout << bridge[a] << " " << endl;
		}
		cout << endl;
		cout << i << endl;
	}
	cout << answer << endl;
	return 0;
}