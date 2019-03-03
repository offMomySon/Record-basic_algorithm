#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;



vector<int> m;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second;
}

int N1;

int main()
{

	cin >> N1;


	for (int tc = 0; tc < N1; tc++)
	{
		int N, M;
		cin >> N >> M;

		m.assign(N + M + 1, 0);



		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				m[i + j] ++;

		
		int max = 0;

		for (int i = 2; i <= N + M; i++)
		{
			if (max < m[i])
				max = m[i];
		}

		vector<int> t_v;

		for (int i = 2; i <= N + M; i++)
		{
			if (max == m[i])
				t_v.push_back(i);
		}


		cout <<"#"<< tc+1<< " " ;
		for (int i = 0; i < t_v.size(); i++)
		{
			cout << t_v[i] << " ";
		}
		cout << "\n";
		
		m.clear();
	}
}