#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

vector<vector<int>> board;
vector<int> moves;

void input_file()
{
	ifstream input;
	input.open("ÀÎÇü»Ì±â.txt");
	for (int i = 0; i < 5; ++i) {
		int temp;
		vector< int > tv;
		for (int j = 0; j < 5; ++j) {
			input >> temp;
			tv.push_back(temp);
		}
		board.push_back(tv);
	}
	int temp;
	for (int i = 0; i < 8; ++i) {
		input >> temp;
		moves.push_back(temp);
	}
}
int main() {
	input_file();
	int answer = 0;
	stack <int> result;
	vector <stack < int > > toys;
	vector<vector<int>> tempboard;
	for (unsigned i = 0; i < board[0].size(); ++i) {
		stack<int> temp;
		for (int j = signed(board[0].size() - 1); j >= 0; --j) {
			if (board[j][i]) temp.push(board[j][i]);
		}
		toys.push_back(temp);
	}
	for (unsigned i = 0; i < moves.size(); ++i) {
		int d = moves[i];
		int target;
		if (toys[d - 1].size()) target = toys[d - 1].top();
		else {
			cout << "continue" << endl;
			continue;
		}
		toys[d - 1].pop();
		if (result.size()) {
			if (result.top() == target) {
				result.pop();
				answer += 2;
			}
			else result.push(target);
		}
		else {
			result.push(target);
		}
		cout << answer << endl;
	}
	cout << answer << endl;
}