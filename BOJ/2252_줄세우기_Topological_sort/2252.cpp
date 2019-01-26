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

	// 인접함을 그래프로 모델링
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		adj_list[a].push_back(b);
		inDegree[b]++;
	}

	// 자신의 앞에 먼저 실행되어야하는 Node 없으면
	// queue 에 삽입
	for (int i = 1; i < inDegree.size(); i++)
		if (inDegree[i] == 0) 
			q.push(i);

	while (!q.empty())
	{
		// Node 꺼내와서 위상정렬 시킨다.
		int node = q.front();
		q.pop();
		cout << node << " ";

		// 정렬시킨 Node 의 인접 Node의 inDegree를 한차수 낮춤
		for (int i = 0; i < adj_list[node].size(); i++)
		{
			int adj_node = adj_list[node][i];
			// 낮춤 수행.
			inDegree[adj_node]--;

			// 해당 Node의 Indegree 가 더이상 없다는 뜻은,
			// 앞서 수행해야하는 Node가 없다는 뜻.
			if (inDegree[adj_node] == 0)
				// Queue 에 넣는다.
				q.push(adj_node);
		}
	}





}










