#include<iostream>
#include<vector>
#define SWAP(X,Y,TEMP) (TEMP=X, X=Y, Y=TEMP)

using namespace std;

int max_pop(vector<int> *arr);
void max_push(vector<int> *arr, int item);
int min_pop(vector<int> *arr);
void min_push(vector<int> *arr, int item);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int temp;
	bool turn = true;
	vector<int> min_vec;
	vector<int> max_vec;

	min_vec.push_back(0);
	max_vec.push_back(0);
	
	cin >> N;

	while (N--)
	{
		int item;
		cin >> item;

		//아이템을 번갈아서 vector에 넣는다.
		if (turn == true)
		{
			max_push(&max_vec, item);
			turn = false;
		}
		else
		{
			min_push(&min_vec, item);
			turn = true;
		}
		
		//넣은후 min queue 와 max queue 의 가장 꼭대기 값 비교.
		if (min_vec.size() >= 2 &&  max_vec.size() >= 2)
		{
			// max queue 에 있는 원소들은
			// min queue 의 꼭대기에 있는 원소보다 값이 적어야한다.
			if (max_vec[1] > min_vec[1])
			{
				int max_top_item = max_pop(&max_vec);
				int min_top_item = min_pop(&min_vec);

				max_push(&max_vec, min_top_item);
				min_push(&min_vec, max_top_item);
			}

		}

		cout << max_vec[1] << "\n";
	}

}




void min_push(vector<int> *arr, int item)
{
	int now,parent;
	int temp;

	(*arr).push_back(item);
	now = (*arr).size() - 1;
	parent = now / 2;

	while (parent >= 1)
	{
		if ((*arr)[now] < (*arr)[parent])
		{
			SWAP((*arr)[now], (*arr)[parent], temp);
			now = parent;
			parent = now / 2;
		}
		else
			break;
	}
}

int min_pop(vector<int> *arr)
{
	int now, l_child, r_child;
	int temp;
	int size;
	int item;

	item = (*arr)[1];
	(*arr)[1] = (*arr).back();
	(*arr).pop_back();

	size = (*arr).size() - 1;
	now = 1, l_child = 2, r_child = 3;

	while (l_child <= size)
	{
		// 자식이 둘다 존재할때
		if (r_child <= size)
		{
			int smaller_index;

			if ((*arr)[l_child] <= (*arr)[r_child])
				smaller_index = l_child;
			else
				smaller_index = r_child;

			if ((*arr)[smaller_index] < (*arr)[now])
				SWAP((*arr)[smaller_index], (*arr)[now], temp);
			else
				break;

			now = smaller_index;
		}
		else
		{
			if ((*arr)[l_child] < (*arr)[now])
				SWAP((*arr)[l_child], (*arr)[now], temp);
			else
				break;

			now = l_child;
		}
		l_child = now * 2;
		r_child = now * 2 + 1;
	}

	return item;
}

void max_push(vector<int> *arr, int item)
{
	int now, parent;
	int temp;

	(*arr).push_back(item);
	now = (*arr).size() - 1;
	parent = now / 2;

	while (parent >= 1)
	{
		if ((*arr)[now] > (*arr)[parent])
		{
			SWAP((*arr)[now], (*arr)[parent], temp);
			now = parent;
			parent = now / 2;
		}
		else
			break;
	}
}

int max_pop(vector<int> *arr)
{
	int now, l_child, r_child;
	int temp;
	int size;
	int item;

	item = (*arr)[1];
	(*arr)[1] = (*arr).back();
	(*arr).pop_back();

	size = (*arr).size() - 1;
	now = 1, l_child = 2, r_child = 3;

	while (l_child <= size)
	{
		// 자식이 둘다 존재할때
		if (r_child <= size)
		{
			int smaller_index;

			if ((*arr)[l_child] >= (*arr)[r_child])
				smaller_index = l_child;
			else
				smaller_index = r_child;

			if ((*arr)[smaller_index] > (*arr)[now])
				SWAP((*arr)[smaller_index], (*arr)[now], temp);
			else
				break;

			now = smaller_index;
		}
		else
		{
			if ((*arr)[l_child] > (*arr)[now])
				SWAP((*arr)[l_child], (*arr)[now], temp);
			else
				break;

			now = l_child;
		}
		l_child = now * 2;
		r_child = now * 2 + 1;
	}

	return item;
}








