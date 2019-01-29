#include<iostream>
#include<vector>
#include<cmath>

#define SWAP(X,Y,TEMP) (TEMP = X, X = Y , Y = TEMP)
using namespace std;

int pop(vector<int> *vec);
void push_back(vector<int> * vec, int num);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>  vec;
	int N;

	cin >> N;

	vec.push_back(0);


	while (N--)
	{
		int n;
		cin >> n;

		if (n == 0)
			cout << pop(&vec) << "\n";
		else
			push_back(&vec, n);
	}
}

void push_back(vector<int> * vec ,int num )
{
	int now, parent;
	int temp;

	(*vec).push_back(num);
	now = (*vec).size() - 1;
	parent = now / 2;

	while (parent >= 1)
	{
		if (abs((*vec)[parent]) == abs((*vec)[now]))
		{
			if ((*vec)[parent] > (*vec)[now])
				SWAP((*vec)[parent], (*vec)[now], temp);
			else
				break;
		}
		else if (abs((*vec)[parent]) > abs((*vec)[now]))
			SWAP((*vec)[parent], (*vec)[now], temp);
		else
			break;


		now = parent;
		parent = now / 2;
	}
}

int pop(vector<int> *vec)
{
	if ((*vec).size() == 1)
		return 0;

	int item,temp;
	int now, l_child, r_child;
	int size;

	item = (*vec)[1];
	(*vec)[1] = (*vec).back();
	(*vec).pop_back();

	now = 1, l_child = 2, r_child = 3;
	size = (*vec).size() - 1;

	while (l_child <= size)
	{
		// 왼쪽 오른쪽 둘다 자식이 있을때,
		if (l_child < size)
		{
			int smaller_index;

			//자식 비교 
			//자식 둘다 값이 값다.
			if (abs((*vec)[l_child]) == abs((*vec)[r_child]))
			{

				if ((*vec)[l_child] < (*vec)[r_child])
					smaller_index = l_child;
				else
					smaller_index = r_child;
			}
			else if (abs((*vec)[l_child]) < abs((*vec)[r_child]))
				smaller_index = l_child;
			else
				smaller_index = r_child;

			// 가장 작은 애랑 현재랑 비교
			// 절대 값 같은떄
			if (abs((*vec)[smaller_index]) == abs((*vec)[now]))
			{
				if ((*vec)[smaller_index] < (*vec)[now])
					SWAP((*vec)[smaller_index], (*vec)[now], temp);
				else
					break;
			}
			else if (abs((*vec)[smaller_index]) < abs((*vec)[now]))
				SWAP((*vec)[smaller_index], (*vec)[now], temp);
			else
				break;
			
			now = smaller_index;
			l_child = now * 2;
			r_child = now * 2 + 1;
		}
		// 왼쪽 자식만 있어,           
		else
		{
			if (abs((*vec)[l_child]) == abs((*vec)[now]))
			{
				if ((*vec)[l_child] < (*vec)[now])
					SWAP((*vec)[l_child], (*vec)[now], temp);
				else
					break;
			}
			else if (abs((*vec)[l_child]) < abs((*vec)[now]))
				SWAP((*vec)[l_child], (*vec)[now], temp);
			else
				break;

			now = l_child;
			l_child = now * 2;
			r_child = now * 2 + 1;
		}
	}
	
	return item;
}


