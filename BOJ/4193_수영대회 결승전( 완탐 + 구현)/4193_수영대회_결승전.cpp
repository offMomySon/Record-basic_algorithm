#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Point {
	int row;
	int col;
};

struct Bogibogi {
	Point point;
	int depth;
};

int search_path(Point start, Point end);

// 상 우 하 좌
int move_row[4] = { 1, 0, -1, 0 };
int move_col[4] = { 0, 1, 0, -1 };

vector<vector<int>> map;
vector<vector<int>> is_visited;

vector<Point> sink_hole;


Point start_point;
Point end_point;

int time_i = 0;
int map_size;

int main()
{
	int N;
	cin >> N;

	for (int N_T = 0; N_T < N; N_T++)
	{

		cin >> map_size;

		map.assign(map_size, vector<int>(map_size, 0));
		is_visited.assign(map_size, vector<int>(map_size, 0));

		for (int i = 0; i < map_size; i++)
			for (int j = 0; j < map_size; j++)
			{
				cin >> map[i][j];
				
				if (map[i][j] == 2)
					sink_hole.push_back({ i,j });
			}
		cin >> start_point.row >> start_point.col;
		cin >> end_point.row >> end_point.col;
		
		int ans = search_path(start_point, end_point);
		cout << "#" << N_T + 1 << " " << ans << "\n";

		for (int i = 0; i < map.size(); i++)
		{
			map[i].clear();
			is_visited[i].clear();
		}
		map.clear();
		is_visited.clear();
		sink_hole.clear();
	}


}

int search_path(Point start, Point end)
{
	queue< Bogibogi > q;
	bool before_storm = true;
	bool is_changed = true;

	if (map[start.row][start.col] == 0)
	{
		is_visited[start.row][start.col] = 1;
		q.push({ {start.row, start.col} , 0 });
		time_i = 0;
	}

	// 0 1 *2 3 4 *5 6 7 *8
	while (!q.empty())
	{
		//현재의 위치, 시간 가져옴
		Bogibogi man = q.front();
		q.pop();

		if (man.point.row == end.row && man.point.col == end.col)
			return man.depth;
		//움직이기전 맵처리.!

		//태풍 치는 시기 아님
		if ((man.depth != 0) &&
			((man.depth - 2) % 3 == 0) )
		{
			for (auto it = sink_hole.begin(); it != sink_hole.end(); it++)
			{
				int row = it->row;
				int col = it->col;

				map[row][col] = 0;
			}
			is_changed = false;
		}
		//태풍 치는 시기
		else
		{
			// 이전에 변경 안했으면 바꾼다.
			if (is_changed == false)
			{
				for (auto it = sink_hole.begin(); it != sink_hole.end(); it++)
				{
					int row = it->row;
					int col = it->col;

					map[row][col] = 2;
				}
				is_changed = true;
			}
		}
		
		// 처리된 맵을 바탕으로 시뮬레이션
		for (int i = 0; i < 4; i++)
		{
			int next_row = man.point.row + move_row[i];
			int next_col = man.point.col + move_col[i];



			if ((next_row <0 || next_row > map_size - 1) ||
				(next_col <0 || next_col > map_size - 1) ||
				(map[next_row][next_col] == 1) ||
				(is_visited[next_row][next_col] == 1)
				)
				continue;

			if (map[next_row][next_col] == 2)
			{
				q.push({ {man.point.row, man.point.col}, man.depth + 1 });
				continue;
			}

			is_visited[next_row][next_col] = 1;
			q.push({ {next_row, next_col}, man.depth + 1 });
		}
		
	}

	return -1;

}