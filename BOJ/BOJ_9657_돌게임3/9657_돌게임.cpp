#include<iostream>

#define SK 1
#define CY 0

using namespace std;

int dol[1010];

int win(int dol_num);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (register int i = 0; i < 1010; i++)
		dol[i] = -1;

	dol[1] = 1;
	dol[2] = 0;
	dol[3] = 1;
	dol[4] = 1;

	int N;
	cin >> N;

	if (win(N) == 1)
		cout << "SK" << "\n";
	else
		cout << "CY" << "\n";

}

int win(int dol_num) 
{
	if (dol[dol_num] != -1)
		return dol[dol_num];

	//모든 수를 선택했을때
	//모두 지는 수가 나온다면 
	//현재에서 이길수 없다.
	if (win(dol_num - 1) == 1 &&
		win(dol_num - 3) == 1 &&
		win(dol_num - 4) == 1)
	{
		dol[dol_num] = 0;
		return 0;
	}
	else
	{
		dol[dol_num] = 1;
		return 1;
	}
}
