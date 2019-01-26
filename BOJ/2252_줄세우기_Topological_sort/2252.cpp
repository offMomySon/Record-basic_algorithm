#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<vector<int>> adj_list;
	vector<int> inDegree;
	queue<int> q;
	cin >> N >> M;

	adj_list.assign(N + 1, vector<int>(0));
	inDegree.assign(N + 1, 0);

	// �������� �׷����� �𵨸�
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		inDegree[b]++;
	}

	// �ڽ��� �տ� ���� ����Ǿ���ϴ� Node ������
	// queue �� ����
	for (int i = 1; i < inDegree.size(); i++)
		if (inDegree[i] == 0) 
			q.push(i);

	while (!q.empty())
	{
		// Node �����ͼ� �������� ��Ų��.
		int node = q.front();
		q.pop();
		cout << node << " ";

		// ���Ľ�Ų Node �� ���� Node�� inDegree�� ������ ����
		for (int i = 0; i < adj_list[node].size(); i++)
		{
			int adj_node = adj_list[node][i];
			// ���� ����.
			inDegree[adj_node]--;

			// �ش� Node�� Indegree �� ���̻� ���ٴ� ����,
			// �ռ� �����ؾ��ϴ� Node�� ���ٴ� ��.
			if (inDegree[adj_node] == 0)
				// Queue �� �ִ´�.
				q.push(adj_node);
		}
	}





}










