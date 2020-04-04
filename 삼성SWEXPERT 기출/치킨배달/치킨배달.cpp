#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y;
}point;

int N;
int M;
int min_value = 98765432;
int house[51][51];
int answer = 0;
vector <point> chi;
vector <point> home;
vector <point> temp;
vector <int> p;
vector <int> ind;
bool bp[51][51] = { false, };

void input_file()
{
	ifstream input;
	input.open("치킨배달.txt");
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j) {
			cin >> house[i][j];
			if (house[i][j] == 1) home.push_back({ i,j });
			if (house[i][j] == 2) {
				bp[i][j] = true;
				chi.push_back({ i,j });
				house[i][j] = 0;
			}
		}
}

void permutation(vector <point > tv) {
	int sum = 0;
	for (unsigned i = 0; i < home.size(); ++i) {
		int t = 98765432;
		for (int j = 0; j < M; ++j) {
			int distance = abs(home[i].x - tv[j].x) + abs(home[i].y - tv[j].y);
			t = min(t, distance);
		}
		sum += t;
	}
	//cout << "sum : " << sum << endl;
	min_value = min(sum, min_value);
	return;
}
int main(void)
{
	input_file();
	for (unsigned i = 0; i < chi.size(); ++i) p.push_back(i);
	for (int i = 0; i < M; ++i) ind.push_back(1);
	for (unsigned i = 0; i < chi.size() - M; ++i) ind.push_back(0);

	sort(ind.begin(), ind.end());
	do {
		vector < int > a;
		vector <point> ppp;
		for (unsigned i = 0; i < ind.size(); ++i) {
			if (ind[i] == 1) {
				a.push_back(p[i]);
				ppp.push_back({ chi[a[a.size() - 1]].x,chi[a[a.size() - 1]].y });
				//cout << chi[a[a.size() - 1]].x << " " << chi[a[a.size() - 1]].y << endl;
			}
		}
		permutation(ppp);
	} while (next_permutation(ind.begin(), ind.end()));
	cout << min_value << endl;

	return 0;
}