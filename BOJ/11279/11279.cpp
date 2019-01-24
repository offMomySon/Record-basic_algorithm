#include<iostream>
#include<vector>

#define SWAP(X,Y,TEMP) (TEMP=X, X=Y, Y=TEMP) 
using namespace std;

void push(int item, vector<int> *vec);
int pop(vector<int> *vec);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c;
	vector<int> vec;
	vec.push_back(0);

	cin >> c;

	while (c--)
	{
		int num;
		cin >> num;

		if (num == 0)
			cout << pop(&vec) <<"\n";
		else
			push(num, &vec);
	}
}

int pop(vector<int> *vec)
{
	if ((*vec).size() == 1)
		return 0;

	int item, temp;
	int size;
	int now, l_child, r_child;

	item = (*vec)[1];
	(*vec)[1] = (*vec).back();
	(*vec).pop_back();

	size = (*vec).size() - 1;
	now = 1, l_child = 2, r_child = 3;

	//�ڽ��� ������ ���
	while ( l_child  <= size )
	{
		// �������� ������ ���
		if (l_child < size)
		{
			// ū �༮�� index ������
			int big_index = (*vec)[l_child] >= (*vec)[r_child] ? l_child : r_child;

			// ū�༮�� �θ� ��
			if ((*vec)[big_index] > (*vec)[now])
			{
				SWAP((*vec)[big_index], (*vec)[now], temp);
				now = big_index;
			}
			else
				break;
		}
		// ���ʸ� �����Ұ��
		else if ((*vec)[l_child] > (*vec)[now])
		{
			SWAP((*vec)[l_child], (*vec)[now], temp);
			now = l_child;
		}
		else
			break;
		l_child = now * 2;
		r_child = now * 2 + 1;
	}

	return item;
}

void push(int item, vector<int> *vec)
{
	(*vec).push_back(item);

	int now = (*vec).size()-1;
	int parent = now / 2;
	int temp;

	while (parent > 0)
	{
		// �θ𺸴� ���簡 ��ũ��
		if ((*vec)[parent] < (*vec)[now])
			SWAP((*vec)[parent], (*vec)[now], temp);
		else
			break;

		now = parent;
		parent = now / 2;
	}
}


















