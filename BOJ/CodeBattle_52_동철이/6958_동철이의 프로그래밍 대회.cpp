#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T;
int N, M;
vector<int> score;

bool desc(int a, int b)
{
	return a > b;
}

//순열 -> 조합      ->         
//n!       2^n - 공간도 넘커


//1000000

//위너 트리 문제? 자기 차례떄 무조건 이길수 있는지?
//무조건 이기면 true
//상대가 이기는 경우가 발생하면 true 무조건 지면 false

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> T;

	for (int t_c = 1; t_c <= T; t_c++)
	{
		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			int solve_count = 0;

			for (int j = 0; j < M; j++)
			{
				int is_p_solve;

				cin >> is_p_solve;
				if (is_p_solve == 1)
					solve_count++;
			}

			score.push_back(solve_count);
		}

		sort(score.begin(), score.end(), desc);
	
		int max_n = score[0];
		int same_score_count = 1;
		for (int i = 1; i < score.size(); i++)
		{
			if (score[i] == max_n)
				same_score_count++;
			else
				break;
		}

		
		
		cout << "#" << t_c << " " << same_score_count << " " << max_n << "\n";


		score.clear();
	}

}