#include <stdio.h>
#include<iostream>
#include<utility>
#include <functional>
#include <algorithm>
#include<queue>	
#define A 2
using namespace std;

#if A == 1


int number = 6;
int INF = 10000000;

// 전체 그래프를 초기화합니다. 
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};
bool v[6]; // 방문한 노드입니다. 
int d[6]; // 거리입니다. 

// 가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	v[start] = true;
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void) {
	dijkstra(0);
	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);

	}
}


#elif A == 2

int number = 6;
int INF = 10000000;

bool v[7];
int d[7];
vector<pair<int, int>> a[7];

struct cmp {
	bool operator () (pair<int,int> a, pair<int,int> b ) {
		return a.second > b.second;
	}
};

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push(make_pair(start, 0));
	d[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (v[current] == true || distance > d[current])
			continue;

		v[current] = true;
		for (int i = 0; i < a[current].size(); i++)
		{
			int next = a[current][i].first;
			int next_distance = a[current][i].second + distance;

			if (v[next] != true && next_distance < d[next])
			{
				d[next] = next_distance;
				pq.push(make_pair(next, next_distance));
			}
		}

	}
}

int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다. 
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
		v[i] = false;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	// 결과를 출력합니다. 
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}

#else

//int INF = 10000000;
//
//vector<
//
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int>b)
	{
		return a.first < b.first;
	}
};


int number = 6;
int INF = 1000000;

vector<pair<int, int> > a[7];
int d[7];

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>,vector<pair<int,int>>, cmp> pq;
	pq.push(make_pair(start, 0));

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++)
		{
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;

			if (nextDistance < d[next])
			{
				d[next] = nextDistance;
				pq.push(make_pair(next, nextDistance));
			}

		}

	}

}
int main(void) {
	// 기본적으로 연결되지 않은 경우 비용은 무한입니다. 
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	// 결과를 출력합니다. 
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}

#endif
