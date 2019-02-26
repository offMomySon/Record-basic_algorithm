#include<iostream>
#include<vector>
#include<queue>
#include<utility> 

using namespace std;

struct Point
{
	int row;
	int col;
}; 

struct Current
{
	Point point;
	int depth;
};


int search_path(Point start, Point end); 

// 위 우 하 좌
int move_row[4] = { 1, 0, -1,0 };
int move_col[4] = { 0, 1, 0, -1 };
int map_size;


vector<vector<int>> map;
vector<vector<int>> is_visited;
Point start_point;
Point end_point;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for(int k =0 ;k< N; k++)
	{
		cin >> map_size;
		
		map.assign(map_size, vector<int>(map_size, 0));
		is_visited.assign(map_size, vector<int>(map_size, 0));


		for (int i = 0; i < map_size; i++)
			for (int j = 0; j < map_size; j++)
				cin >> map[i][j];
		
		cin >> start_point.row >> start_point.col;
		cin >> end_point.row >> end_point.col;

		int ans = search_path(start_point, end_point);
		//cout << ans << "\n";

		cout<<"#" << k + 1 << " " << ans<<"\n";

		for (int i = 0; i < map_size; i++)
		{
			map[i].clear();
			is_visited[i].clear();
		}
		map.clear();
		is_visited.clear();
	}
}


int search_path(Point start, Point end)
{
	queue<Current>q;

	if (map[start.row][start.col] == 0)
	{
		is_visited[start.row][start.col] = 1;
		q.push({ {start.row,start.col}, 1 });
	}

	while (!q.empty())
	{
		Current current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_row = current.point.row + move_row[i];
			int next_col = current.point.col + move_col[i];

			// 맵 이탈시, 이미 방문했을시 , 방문할수 없는 곳일시
			// 중지
			if ((next_row < 0 || next_row > map_size - 1) ||
				(next_col < 0 || next_col > map_size - 1) ||
				map[next_row][next_col] == 1 ||
				is_visited[next_row][next_col] == 1)
				continue;

			// 다음이 목적지 일시 멈추고 결과 값 반환.
			if ((next_row == end_point.row) &&
				(next_col == end_point.col))
				return current.depth;

			
			is_visited[next_row][next_col] = 1;
			q.push({ {next_row ,next_col}, current.depth + 1 });

		}

	}


	return -1;
}
