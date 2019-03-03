#include<iostream>

#define win 1
#define lose 0

using namespace std;


void init();
int win_fun(int n);

int arr[1010];

int n;
int main(void)
{
	cin >> n;

	init();

	if (win_fun(n) == 1)
		cout << "SK" << "\n";
	else
		cout << "CY" << "\n";



	return 0;
}

void init()
{
	for (register int i = 0; i < 1010; i++)
		arr[i] = -1;

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 0;
	arr[4] = 1;
}

int win_fun(int n) 
{	
	if (arr[n] != -1)
		return arr[n];
	// 모든 수중에
	// 상대가 한번이라도 지는 수가있으면
	// 이긴다.
	if (win_fun(n - 1) == lose ||
		win_fun(n - 3) == lose ||
		win_fun(n - 4) == lose)
		arr[n] = 1;
	else
		arr[n] = 0;

	return arr[n];

}























