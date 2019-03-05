#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
#include<set>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int char_to_int(char a);

int TC;
int N, K;
deque<char> dq;
set<int, greater<int>> st;

int main(void)
{	
	cin >> TC;

	for (int t_c = 0; t_c < TC; t_c++)
	{
		cin >> N >> K;
		string str;
		cin >> str;


		for (int i = 0; i < N; i++)
			dq.push_back(str[i]);

		// N/4 회 이동
		for (int i = 0; i < N / 4; i++)
		{
			// 4분면 체크
			for (int section = 0; section < 4; section++)
			{
				int converted_num = 0;

				int ch_index = section * N/ 4;
				// 1분면의 char 을 int 로 변환
				for (int j = 0; j < N / 4; j++)
				{
					converted_num += pow(16, (N / 4 -1-j )) * char_to_int( dq [ch_index + j] ) ;
				}
				st.insert(converted_num);
			}

			int temp = dq.back();
			dq.pop_back();
			dq.push_front(temp);
		}

		int c = 0;
		for (auto it = st.begin(); it != st.end(); it++)
		{
			if (c == K - 1)
			{
				cout <<"#"<< t_c+1 <<" "<< *it << "\n";
				break;
			}
			c++;
		}

		dq.clear();
		st.clear();
	}

}

int char_to_int(char a)
{
	switch (a)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}
}