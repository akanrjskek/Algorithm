#include<iostream>
#include<string>

#define endl "\n"
#define MAX 20
using namespace std;

int N, Oper_Num;
int Answer = -987654321987654321;
int Num[MAX], Oper[MAX];

int Bigger(int A, int B) { return A > B ? A : B; }

void Input()
{
	cin >> N;
	int Idx = 0;
	int Idx2 = 0;

	string Inp;
	cin >> Inp;
	for (int i = 0; i < Inp.length(); i++)
	{
		if (i % 2 == 0) Num[Idx++] = Inp[i] - '0';
		else Oper[Idx2++] = Inp[i];
	}
	Oper_Num = N / 2;
}

int Calculate(int N1, int N2, char B)
{
	if (B == '+') return N1 + N2;
	else if (B == '-') return N1 - N2;
	else if (B == '*') return N1 * N2;
}

void DFS(int Idx, int Result)
{
	if (Idx >= Oper_Num)
	{
		Answer = Bigger(Answer, Result);
		return;
	}

	int Cur_Result = Calculate(Result, Num[Idx + 1], Oper[Idx]);
	DFS(Idx + 1, Cur_Result);

	if (Idx + 1 < Oper_Num)
	{
		int After_Result = Calculate(Num[Idx + 1], Num[Idx + 2], Oper[Idx + 1]);
		int Cur_Result = Calculate(Result, After_Result, Oper[Idx]);
		DFS(Idx + 2, Cur_Result);
	}
}

void Solution()
{
	if (N == 1)
	{
		cout << Num[0] << endl;
		return;
	}
	else if (N == 3)
	{
		cout << Calculate(Num[0], Num[1], Oper[0]) << endl;
		return;
	}

	DFS(0, Num[0]);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("Input.txt", "r", stdin);
	Solve();

	return 0;
}