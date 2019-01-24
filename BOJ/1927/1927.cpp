#include<iostream>
#include<vector>

#define SWAP(X,Y, TEMP) (TEMP = X, X= Y, Y = TEMP )

using namespace std;

void push(int num);
int pop(void);

vector<int> heap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, input;
	cin >> n;

	heap.push_back(0);

	for (int i = 0; i < n; i++)
	{

		cin >> input;

		if (input == 0)
		{
			cout << pop() << "\n";
		}
		else
			push(input);
	}
}

int pop(void)
{
	if (heap.size() == 1)
		return 0;

	int max, temp;
	int parent, l_child, r_child, size;

	//������ ���� ����
	//heap�� �ֻ�ܿ� �ִ´�.
	max = heap[1];
	heap[1] = heap.back();
	heap.pop_back();

	size = heap.size() - 1;
	parent = 1, l_child = 2, r_child = 3;

	// �����ڽ��� ������ ���� �ݺ�
	while (l_child <= size)
	{
		//�ڽ� 2��
		if (r_child <= size)
		{
			// ������ �� ������
			if (heap[l_child] < heap[r_child])
			{
				if (heap[l_child] >= heap[parent]) break;
				SWAP(heap[parent], heap[l_child], temp);

				parent = l_child;
			}
			// �������� �� ������
			else
			{
				if (heap[r_child] >= heap[parent]) break;
				SWAP(heap[parent], heap[r_child], temp);

				parent = r_child;
			}
		}
		else
		{
			if (heap[l_child] >= heap[parent]) break;
			SWAP(heap[parent], heap[l_child], temp);

			parent = l_child;
		}
		l_child = parent * 2;
		r_child = parent * 2 + 1;
	}

	return max;
}

void push(int num)
{

	int now, parent, temp;

	//�� Ǫ��,
	//Set Index
	heap.push_back(num);
	now = heap.size() - 1;
	parent = now / 2;

	while (parent > 0)
	{
		if (heap[parent] > heap[now])
		{
			SWAP(heap[parent], heap[now], temp);
			now = parent;
			parent /= 2;
		}
		else
			break;
	}
}
