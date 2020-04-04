#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



const int MAX = 100 + 1;



typedef struct

{

	int y, x;

}Dir;



//right, up, left, down

Dir moveDir[4] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };



bool visited[MAX][MAX];



int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N;

	cin >> N;



	for (int i = 0; i < N; i++)

	{

		int y, x, d, g;

		cin >> x >> y >> d >> g;



		vector<int> curve;

		//방향 구성

		curve.push_back(d);

		for (int j = 0; j < g; j++)

		{

			vector<int> temp = curve;

			for (int k = temp.size() - 1; k >= 0; k--)

				curve.push_back((temp[k] + 1) % 4);

		}



		visited[y][x] = true;

		for (int j = 0; j < curve.size(); j++)

		{

			y += moveDir[curve[j]].y;

			x += moveDir[curve[j]].x;



			//범위 내에만 표시

			if (0 <= x && x < MAX && 0 <= y && y < MAX)

				visited[y][x] = true;

		}

	}



	int result = 0;

	for (int j = 0; j < MAX - 1; j++)

		for (int k = 0; k < MAX - 1; k++)

			//정사각형

			if (visited[j][k] && visited[j][k + 1] && visited[j + 1][k] && visited[j + 1][k + 1])

				result++;



	cout << result << "\n";

	return 0;

}