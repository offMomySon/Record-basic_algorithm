#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (int t_c = 1; t_c <= T; t_c++)
	{
		string num_str;
		cin >> num_str;

		int count = 0;

		if (num_str.size() > 1)
		{
			int sum = num_str.at(0) - '0';

			for (int i = 1; i < num_str.size(); i++)
			{
				sum += (num_str.at(i) - '0');
				count += 1;

				if (sum >= 10)
				{
					sum = sum / 10 + sum % 10;
					count += 1;
				}
			}

		}
		
		
		cout << "#" << t_c << " ";
		if (count % 2 == 0)
			cout << "B" << "\n";
		else
			cout << "A" << "\n";

	}

}