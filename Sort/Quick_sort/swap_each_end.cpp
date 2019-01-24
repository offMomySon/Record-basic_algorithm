#include<iostream>
#include<vector>

using namespace std;

#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y) = (temp))

int partition(int left, int right, vector<int> *list);
void quick_sort(int start, int end, vector<int> *arr);
void print_part(int start, int end, vector<int> *arr);

int main()
{
	int count;
	vector<int> arr;

	//cout << "Enter array size : ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		int t;

		cin >> t;
		arr.push_back(t);
	}

	quick_sort(0, count - 1, &arr);
		
	for (int i = 0; i < count; i++)
		cout << arr[i]<< "\n";
}

void quick_sort(int start, int end, vector<int> *arr)
{
	if (start < end)
	{
		int partitions = partition(start, end, arr);
		//print_part(start, end, arr);

		quick_sort(start, partitions-1, arr);
		quick_sort(partitions + 1, end, arr);
	}
}
void print_part(int start, int end, vector<int> *arr)
{
	for (int i = 0; i < (*arr).size(); i++)
		cout << (*arr)[i] << " ";
	cout << " start : " << start << " end : " << end;
	cout << "\n";
}

int partition(int left, int right, vector<int> *list)
{
	int pivot, temp;
	int low, high;

	low = left + 1;
	high = right;

	//O(n^2) 회피하기 위해 index의 중간의 값 가져옴.
	SWAP( (*list)[(left + right) / 2], (*list)[left], temp);
	pivot = (*list)[left];

	/* low와 high가 교차할 때까지 반복(low<high) */
	do
	{
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		while (low < right && (*list)[low] < pivot)
			low++;
		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		while (left < high && pivot <= (*list)[high])
			high--;

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low < high)
			SWAP((*list)[low], (*list)[high], temp);
	} while (low < high);

	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	SWAP((*list)[left], (*list)[high], temp);

	// 피벗의 위치인 high를 반환
	return high;
}