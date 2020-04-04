#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long long k = 6;
vector<long long> room_number;
vector<long long> answer;
vector < bool > br;

void input_file()
{
	ifstream input;
	input.open("¹æ¹èÁ¤.txt");
	long long t, num;
	input >> num;
	for (long long i = 0; i < num; ++i) br.push_back(false);
	for (long long i = 0; i < 6; ++i) {
		input >> t;
		room_number.push_back(t);
	}
	
}
int main(void)
{
	input_file();
	for (long long i = 0; i < long long(room_number.size()); ++i) {
		if (!br[room_number[i]-1]) {
			answer.push_back(room_number[i]);
			br[room_number[i]-1] = true;
		}
		else {
			long long temp = room_number[i];
			while (br[temp-1]) {
				temp++;
			}
			answer.push_back(temp);
			br[temp-1] = true;
		}
	}
	for (long long i = 0; i < long long(room_number.size()); ++i) {
		cout << answer[i] << " " << endl;
	}
	cout << endl;
	return 0;
}