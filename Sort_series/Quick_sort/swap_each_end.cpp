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

	//O(n^2) ȸ���ϱ� ���� index�� �߰��� �� ������.
	SWAP( (*list)[(left + right) / 2], (*list)[left], temp);
	pivot = (*list)[left];

	/* low�� high�� ������ ������ �ݺ�(low<high) */
	do
	{
		/* list[low]�� �ǹ����� ������ ��� low�� ���� */
		while (low < right && (*list)[low] < pivot)
			low++;
		/* list[high]�� �ǹ����� ũ�� ��� high�� ���� */
		while (left < high && pivot <= (*list)[high])
			high--;

		// ���� low�� high�� �������� �ʾ����� list[low]�� list[high] ��ȯ
		if (low < high)
			SWAP((*list)[low], (*list)[high], temp);
	} while (low < high);

	// low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
	SWAP((*list)[left], (*list)[high], temp);

	// �ǹ��� ��ġ�� high�� ��ȯ
	return high;
}