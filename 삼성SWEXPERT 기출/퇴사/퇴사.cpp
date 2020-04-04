#include <fstream>
#include <iostream>
#define max_int 16

using namespace std;

/*
 �ð� ���⵵: O(n^2)
 ���� ���⵵: O(n)
 ����� �˰���: ���� ��ȹ��(bottom-up, tabulation)
 ����� �ڷᱸ��: �迭
 */

 /*
  t�� ���� �Ϸ��ϴµ� �ɸ��� �Ⱓ
  p�� ���� �Ϸ��ϰ� ���� �� �ִ� �ݾ�

  d[n]�� n+1�� ���� �� �ִ� �ִ� �ݾ��� �ǹ��մϴ�.
  �Ʒ��� ���ÿ��� 1�Ͽ� ���� �ϸ� 3�ϵ��� ���� �ϱ� ������ 4�Ͽ� �ݾ��� �޽��ϴ�.
	1  2  3  4
  t 3  5  1  1
  p 10 20 10 20
  d 0  0  0  10
  */
int n, t[max_int], p[max_int], d[max_int], result;

// �μ� a, b���� �ִ밪�� ���ϴ� �Լ� (���� ������ ���)
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	// 1. �Է�
	ifstream input;
	input.open("���.txt");
	input >> n;


	for (int i = 1; i <= n; i++) {
		input >> t[i] >> p[i];
	}


	// 2. DP (bottom-up) ����
	// i��° �� �����ϸ� i + t[j]�� ���� �ޱ� ������,
	// n+1��° ������ �������ݴϴ�.  
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j < i; j++) {
			// 1) j ��° ������ t[j] �Ⱓ ���� �����ϰ� ������ p[j] ���� ���
			// �� ������ j + t[j] �� �޽��ϴ�.
			if (j + t[j] == i) d[i] = max(d[i], d[j] + p[j]);
			// 2) j ��° ������ ���� ���ϰ� i ��° ������ �� ���(j < i)
			else d[i] = max(d[i], d[j]);
		}

		// 3) �ִ밪�� �������ݴϴ�.
		result = max(result, d[i]);
	}

	// 3. ���
	printf("%d\n", result);
}