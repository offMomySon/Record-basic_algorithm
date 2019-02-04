#include<iostream>
#include<vector>

#define SWAP(X,Y,TEMP) (TEMP=X, X=Y, Y=TEMP)

using namespace std;


int pop(vector<int> *arr);
void push(vector<int> * arr, int item);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	vector<int> arr;
	cin >> N;

	arr.push_back(0);

	while (N--)
	{
		int t;
		cin >> t;
		push(&arr, t);
	}

	int result = 0;
	while ( arr.size() >=3 )
	{
		int cmp_time = pop(&arr) + pop(&arr);
		result += cmp_time;
		push(&arr, cmp_time);
	}

	cout << result << endl;
}




void push(vector<int> * arr, int item)
{
	int now, parent;
	int temp;

	(*arr).push_back(item);
	now = (*arr).size()-1;
	parent = now / 2;

	while (1 <= parent)
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
int pop(vector<int> *arr)
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
		if (r_child <= size)
		{
			int smaller_index;

			if ((*arr)[l_child] < (*arr)[r_child])
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


//
//#include<iostream>
//#include<vector>
//#define SWAP(X,Y,TEMP) (TEMP = X, X= Y, Y= TEMP)
//
//using namespace std;
//
//int pop(vector<int> *vec);
//void push(vector<int> *vec, int item);
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N;
//	vector<int> vec;
//	
//	cin >> N;
//
//
//	vec.push_back(0);
//
//	while (N--)
//	{
//		int d;cin >> d;
//		push(&vec, d);
//	}
//
//	int sol = 0;
//	while ( 2 < vec.size())
//	{
//		int a = pop(&vec);
//		int b = pop(&vec);
//
//		sol += a + b;
//		
//		push(&vec, a+b);
//	}
//
//	
//	cout << sol << endl;
//
//	return 0;
//}
//
//
//
//void push(vector<int> *vec, int item)
//{
//	int now, parent;
//	int temp;
//
//	(*vec).push_back(item);
//	now = (*vec).size() - 1;
//	parent = now / 2;
//
//	while (parent >= 1)
//	{
//		if ((*vec)[now] < (*vec)[parent])
//		{
//			SWAP((*vec)[now], (*vec)[parent], temp);
//			now = parent;
//			parent /= 2;
//		}
//		else
//			break;
//	}
//}
//
//int pop(vector<int> *vec)
//{
//	int item;
//	int temp;
//	int now, l_child, r_child, size;
//	
//	item = (*vec)[1];
//	
//	(*vec)[1] = (*vec).back();
//	(*vec).pop_back();
//
//	now = 1, l_child = 2, r_child = 3;
//	size = (*vec).size() - 1;
//
//	while (l_child <= size)
//	{
//		if (l_child < size)
//		{
//			int smaller_index;
//
//			if ((*vec)[l_child] < (*vec)[r_child])
//				smaller_index = l_child;
//			else
//				smaller_index = r_child;
//
//			if ((*vec)[smaller_index] < (*vec)[now])
//				SWAP((*vec)[smaller_index], (*vec)[now], temp);
//			else
//				break;
//
//			now = smaller_index;
//	
//		}
//		else
//		{
//			if ((*vec)[l_child] < (*vec)[now])
//				SWAP((*vec)[l_child], (*vec)[now], temp); 
//			else
//				break;
//			now = l_child;
//		}
//
//		l_child = now * 2;
//		r_child = now * 2 + 1;
//	}
//
//	return item;
//}
//
//
//
