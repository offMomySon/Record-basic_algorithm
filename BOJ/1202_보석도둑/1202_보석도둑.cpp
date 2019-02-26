#include<iostream>
#include<vector>
#include<algorithm>
#define SWAP(X,Y,TEMP) (TEMP=X, X=Y, Y= TEMP)

using namespace std;

typedef struct jam_info {
	int weight;
	int value;
}Jam_info;

int partition_jam(vector<Jam_info> *arr, int left, int right);
void quick_sort_jam(vector<Jam_info> *arr, int start, int end);
int partition(vector<int> *arr, int left, int right);
void quick_sort(vector<int> *arr, int start, int end);
int pop(vector<int> *arr);
void push(vector<int> *arr, int item);
bool cmp_w( Jam_info a, Jam_info b);
Jam_info pop_jam(vector<Jam_info> *arr);
void push_jam(vector<Jam_info> *arr, Jam_info item);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, v, c;
	int N, K;
	long long result = 0;
	vector<Jam_info> jam_list;
	vector<Jam_info> jam_temp_list;
	vector<int> jam_heap;
	vector<int> bag_list;

	cin >> N >> K;
	jam_heap.push_back(0);
	jam_temp_list.push_back({ 0, 0 });

	
	while (N--)
	{
		cin >> m >> v;
		//jam_list.push_back({ m,v });

		push_jam(&jam_temp_list, { m,v });
	}
	while (K--)
	{
		cin >> c;
		bag_list.push_back(c);
	}

	sort(bag_list.begin(), bag_list.end()  );
	while (jam_temp_list.size() > 1)
	{
		jam_list.push_back(pop_jam(&jam_temp_list));
	}
	//sort(jam_list.begin(), jam_list.end() , cmp_w);

	//for (auto it = jam_list.begin(); it != jam_list.end(); it++)
	//{
	//	cout << (*it).weight << " ";
	//}
	//cout << "\n";
	//for (auto it = bag_list.begin(); it != bag_list.end(); it++)
	//{
	//	cout << (*it) << " ";
	//}
	//cout << "\n";

	//quick_sort(&bag_list, 0, bag_list.size() - 1);
	//quick_sort_jam(&jam_list, 0, jam_list.size() - 1);

	for (int k = 0, j = 0; k < bag_list.size(); k++)
	{
		while ( j < jam_list.size() && 
			jam_list[j].weight <= bag_list[k] )
		{
			push( &jam_heap, jam_list[j].value);
			j++;
		}

		if (jam_heap.size() > 1)
		{
			result += pop(&jam_heap);
		}
	}

	cout << result << "\n";
}

//bool cmp_w(const Jam_info &a, const Jam_info &b)
//{
//	return a.weight < b.weight;
//}

bool cmp_w(Jam_info a, Jam_info b)
{
	if (a.weight < b.weight)
		return true;
	else
		return false;
	//return a.weight < b.weight;
}

void push(vector<int> *arr, int item)
{
	int temp;
	int parent, now;

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
int pop(vector<int> *arr)
{
	int temp, item;
	int now, l_child, r_child;
	int size;

	item = (*arr)[1];
	(*arr)[1] = (*arr).back();
	(*arr).pop_back();
	size = (*arr).size() - 1;

	now = 1, l_child = 2, r_child = 3;

	while (l_child <= size)
	{
		if (r_child <= size)
		{
			int b_index;

			if ( (*arr)[l_child] < (*arr)[r_child])
				b_index = r_child;
			else
				b_index = l_child;

			if ((*arr)[b_index] > (*arr)[now])
				SWAP((*arr)[b_index], (*arr)[now], temp);
			else
				break;

			now = b_index;
		}
		else
		{
			if ((*arr)[l_child] > (*arr)[now] )
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

void push_jam(vector<Jam_info> *arr, Jam_info item)
{
	Jam_info temp;
	int parent, now;

	(*arr).push_back(item);
	now = (*arr).size() - 1;
	parent = now / 2;

	while (parent >= 1)
	{
		if ((*arr)[now].weight < (*arr)[parent].weight)
		{
			SWAP((*arr)[now], (*arr)[parent], temp);
			now = parent;
			parent = now / 2;
		}
		else
			break;
	}
}
Jam_info pop_jam(vector<Jam_info> *arr)
{
	Jam_info temp, item;
	int now, l_child, r_child;
	int size;

	item = (*arr)[1];
	(*arr)[1] = (*arr).back();
	(*arr).pop_back();
	size = (*arr).size() - 1;

	now = 1, l_child = 2, r_child = 3;

	while (l_child <= size)
	{
		if (r_child <= size)
		{
			int b_index;

			if ((*arr)[l_child].weight > (*arr)[r_child].weight)
				b_index = r_child;
			else
				b_index = l_child;

			if ((*arr)[b_index].weight < (*arr)[now].weight)
				SWAP((*arr)[b_index], (*arr)[now], temp);
			else
				break;

			now = b_index;
		}
		else
		{
			if ((*arr)[l_child].weight < (*arr)[now].weight )
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


void quick_sort(vector<int> *arr, int start, int end)
{
	if (start < end)
	{
		int part_index = partition(arr, start, end);
		quick_sort(arr, start, part_index - 1);
		quick_sort(arr, part_index + 1, end);
	}
}

int partition(vector<int> *arr, int left, int right)
{
	int pivot;
	int temp;
	int smaller_index, search_index;

	SWAP((*arr)[left], (*arr)[(left + right) / 2], temp);
	pivot = (*arr)[left];
	smaller_index = left;
	search_index = left;

	while (search_index <= right)
	{
		if ((*arr)[search_index] <= pivot)
		{
			SWAP((*arr)[smaller_index], (*arr)[search_index], temp);
			smaller_index++;
		}
		search_index++;
	}

	SWAP((*arr)[left], (*arr)[smaller_index - 1], temp);
	return smaller_index - 1;
}

void quick_sort_jam(vector<Jam_info> *arr, int start, int end)
{
	if (start < end)
	{
		int part_index = partition_jam(arr, start, end);
		quick_sort_jam(arr, start, part_index-1);
		quick_sort_jam(arr, part_index+1, end);
	}
}

int partition_jam(vector<Jam_info> *arr, int left, int right)
{
	Jam_info pivot;
	Jam_info temp;
	int smaller_index, search_index;;

	SWAP((*arr)[left], (*arr)[  (left+right)/2    ], temp);
	pivot = (*arr)[left];
	smaller_index = left;
	search_index = left;

	while (search_index <= right)
	{
		if ((*arr)[search_index].weight <= pivot.weight)
		{
			SWAP((*arr)[smaller_index], (*arr)[search_index], temp);
			smaller_index++;
		}
		search_index++;
	}

	SWAP((*arr)[left], (*arr)[smaller_index - 1], temp);
	return smaller_index - 1;   
}

