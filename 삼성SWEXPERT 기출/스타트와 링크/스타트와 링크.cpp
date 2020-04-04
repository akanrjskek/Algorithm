#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#define max_int 21

#define max_val 2147483647
using namespace std;

/*
 �ð� ���⵵: O(2^n*n^2)
 ���� ���⵵: O(n^2)
 ����� �˰���: ���(DFS)
 ����� �ڷᱸ��: �迭, ����Ʈ
 */

int n, a[max_int][max_int], start_sum, link_sum, start_first, start_second, link_first, link_second, result = max_val;

// ��ŸƮ, ��ũ ���� ���� ������� ��ȣ�� ������ ����Ʈ�� ���ͷ� ����
vector<int> start, link;

// �ּҰ� ��ȯ
int min(int a, int b) {
	return a < b ? a : b;
}

// ���밪 ��ȯ
int abs(int a) {
	if (a < 0) a = a * -1;
	return a;
}

// ��� O(2^n)
// �� ���̽��� ���� 1) start�� �ְų�, 2) link�� �ְų�
void go(int idx) {
	if (start.size() != 0) {
		if (start[0] != 1) return;
	}
	/*for (int i = 0; i < (int)start.size(); ++i)
		cout << start[i] << " ";
	cout << endl;*/
	// 1 ~ n��° ������ ���� ���̽��� ����������
	if (idx == n + 1) {

		// start, link�� ������ ũ�Ⱑ n/2�� �� �����϶�
		if (start.size() == n / 2 && link.size() == n / 2) {

			// ���� �ʱ�ȭ
			start_sum = 0;
			link_sum = 0;

			// 2�� for������ ���鼭 �� ���� ������ ���ϴ�. O(n^2)
			for (int i = 0; i < n / 2; i++) {
				for (int j = i + 1; j < n / 2; j++) {
					if (i == j)continue;

					// 1) ��ŸƮ�� 2�� ���
					start_first = start[i];
					start_second = start[j];

					// ��ŸƮ�� ���� ���
					start_sum += a[start_first][start_second] + a[start_second][start_first];

					// 2) ��ũ�� 2�� ���
					link_first = link[i];
					link_second = link[j];

					// ��ũ�� ���� ���
					link_sum += a[link_first][link_second] + a[link_second][link_first];
				}
			}

			// ���밪�� �����ְ�, �ּҰ��� �������ݴϴ�.
			result = min(result, abs(start_sum - link_sum));

		}
		return;
	}

	// idx������ ���� �ΰ��� ���̽��� �����Ѵ�.
	// 1) ��ŸƮ ���� �ִ´�.
	start.push_back(idx);
	go(idx + 1);
	start.pop_back();

	// 2) ��ũ ���� �ִ´�.
	link.push_back(idx);
	go(idx + 1);
	link.pop_back();
}

int main() {
	// 1. �Է�
	ifstream input;
	input.open("��ŸƮ�� ��ũ.txt");
	input >> n;

	// 2���� �迭�� ���� ������ �Է¹޽��ϴ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			input >> a[i][j];
		}
	}

	// 2. ��� ����
	go(1);

	// 3. ���
	printf("%d\n", result);
}


/*
 �ּҰ� ���Ҷ� ���� ū������ �ʱ�ȭ�ϴµ�
 ������ ����ϱ� ��������, ��, ������ �ִ� ũ�Ⱑ int���� �ȿ� ���ö�
 2147483647 �� �ʱ�ȭ �մϴ�.

 ���밨 �ְ� �ܿ�� 20�� �̳��� �ܿ����ϴ�.
 ����~ ��ĥ����~ ������ĥ~
 */
/*#define max_val 2147483647
using namespace std;


 �ð� ���⵵: O(nCn/2 + n^2)
 ���� ���⵵: O(n^2)
 ����� �˰���: ����(next_permutation)
 ����� �ڷᱸ��: �迭, ����Ʈ
 */

/*int n, a[max_int][max_int], start_sum, link_sum, start_first, start_second, link_first, link_second, result = max_val;

// ��ŸƮ, ��ũ ���� ���� ������� ��ȣ�� ������ ����Ʈ�� ���ͷ� ����
vector<int> start, link;

// �ּҰ� ��ȯ
int min(int a, int b) {
	return a < b ? a : b;
}

// ���밪 ��ȯ
int abs(int a) {
	if (a < 0) a = a * -1;
	return a;
}

int main() {
	// 1. �Է�
	scanf("%d", &n);

	// 2���� �迭�� ���� ������ �Է¹޽��ϴ�.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	// 2. ���� ����
	// ������ ������ ����Ʈ v�� ���ͷ� �����մϴ�.
	vector<int> v;
	for (int i = 0; i < n / 2; i++) v.push_back(0);
	for (int i = 0; i < n / 2; i++) v.push_back(1);
	do {
		//��ŸƮ��, ��ũ���� �����
		vector<int> start, link;
		for (int i = 0; i < (int)v.size(); i++) {
			// 0�϶� ��ŸƮ���� �־��ݴϴ�.
			if (v[i] == 0) start.push_back(i + 1);
			// 1�϶� ��ũ���� �־��ݴϴ�.
			else link.push_back(i + 1);
		}

		start_sum = 0;
		link_sum = 0;

		// 2�� for������ ���鼭 �� ���� ������ ���ϴ�. O(n^2)
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				if (i == j)continue;

				// 1) ��ŸƮ�� 2�� ���
				start_first = start[i];
				start_second = start[j];

				// ��ŸƮ�� ���� ���
				start_sum += a[start_first][start_second] + a[start_second][start_first];

				// 2) ��ũ�� 2�� ���
				link_first = link[i];
				link_second = link[j];

				// ��ũ�� ���� ���
				link_sum += a[link_first][link_second] + a[link_second][link_first];
			}
		}

		// ���밪�� �����ְ�, �ּҰ��� �������ݴϴ�.
		result = min(result, abs(start_sum - link_sum));

	} while (next_permutation(v.begin(), v.end()));

	// 3. ���
	printf("%d\n", result);
}*/