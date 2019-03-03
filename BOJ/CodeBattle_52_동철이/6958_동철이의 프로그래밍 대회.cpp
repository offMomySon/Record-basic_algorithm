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

//���� -> ����      ->         
//n!       2^n - ������ ��Ŀ


//1000000

//���� Ʈ�� ����? �ڱ� ���ʋ� ������ �̱�� �ִ���?
//������ �̱�� true
//��밡 �̱�� ��찡 �߻��ϸ� true ������ ���� false

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