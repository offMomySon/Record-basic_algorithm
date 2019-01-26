#include<iostream>
#include<vector>

#define SWAP(X,Y, TEMP) (TEMP = X, X= Y , Y = TEMP)
using namespace std;

int pop(vector<int> *pq);
void push(int item, vector<int> *pq);
bool empty(vector<int> *pq);

int main()
{
	int N, M;
	vector<int> inDegree;
	vector<vector<int>> pb_seq;
	vector<int> pq;
	
	cin >> N >> M;

	//priority_queue�� ����� ���ϱ� �ϱ� ����.
	pq.push_back(0);
	inDegree.assign(N + 1, 0);
	pb_seq.assign(N + 1, vector<int>(0));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		pb_seq[a].push_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i < inDegree.size() ; i++)
		if (inDegree[i] == 0)
			push(i, &pq);
	
	while ( !empty(&pq) )
	{
		int node = pop(&pq);
		cout << node << " ";

		for (int i = 0; i < pb_seq[node].size(); i++)
		{
			int pd_num = pb_seq[node][i];

			inDegree[pd_num]--;
			if (inDegree[pd_num] == 0)
				push(pd_num, &pq);
		}

	}



}

bool empty(vector<int> *pq)
{
	if ( (*pq).size() == 1)
		return true;
	else
		return false;
}

void push(int item, vector<int> *pq)
{
	int temp;
	int parent, now;

	(*pq).push_back(item);
	now = (*pq).size() - 1;
	parent = now / 2;

	// �θ� ��尡 �����ϸ� ��� ����.
	while (parent >= 1)
	{
		if ((*pq)[now] < (*pq)[parent])
			SWAP((*pq)[now], (*pq)[parent], temp);
		else
			break;

		now = parent;
		parent = now / 2;
	}
}

// pq�� ���� ������ �ۿ��� ó�����ֵ��� �����Ҳ���.
int pop(vector<int> *pq)
{
	int item;
	int temp;
	int now, l_child, r_child;
	int size;

	// REturn �� Item ����
	item = (*pq)[1];
	(*pq)[1] = (*pq).back();
	(*pq).pop_back();

	// Index ����
	now = 1;
	l_child = 2, r_child = 3;
	size = (*pq).size() - 1;

	// �ּ��� �ϳ��� �ڽ��� �ִٸ� 
	//�񱳼���
	while (l_child <= size)
	{
		// ���� �ʵ� �� �ٸ�
		if (l_child < size)
		{
			int smaller_index;

			if ((*pq)[l_child] < (*pq)[r_child])
				smaller_index = l_child;
			else
				smaller_index = r_child;

			if ((*pq)[smaller_index] < (*pq)[now])
				SWAP((*pq)[smaller_index], (*pq)[now], temp);
			else
				break;

			now = smaller_index;
		}
		else
		{
			if ((*pq)[l_child] < (*pq)[now])
				SWAP((*pq)[l_child], (*pq)[now], temp);
			else
				break;
		
			now = l_child;
		}

		l_child = now * 2;
		r_child = now * 2 + 1;
	}
	return item;
}


