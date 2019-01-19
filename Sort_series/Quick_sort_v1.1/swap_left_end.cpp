#include<iostream>
#include<vector>

using namespace std;
#define SWAP(x,y,temp) ((temp)=(x) , (x) = (y) , (y) = (temp) )


int partition(int left, int right, vector<int> *list);
void quick_sort(int start, int end, vector<int> *arr);


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
		cout << arr[i] << "\n";

}


int partition(int left, int right, vector<int> *list)
{
	int low_v_point, check_point;
	int pivot,temp;

	low_v_point = left;
	check_point = left;
	SWAP((*list)[(left+right)/2],(*list)[right] , temp);
	pivot = (*list)[right];

	//right에 pivot을 넣었으니
	//right 전까지만 비교수행
	while (check_point < right)
	{
		if ((*list)[check_point] < pivot)
		{
			SWAP((*list)[check_point], (*list)[low_v_point], temp); 
			low_v_point++;
		}
		check_point++;
	}
	SWAP((*list)[right], (*list)[low_v_point], temp);
	return  low_v_point;
}

void quick_sort(int start, int end, vector<int> *arr)
{
	if (start < end)
	{
		int partitions = partition(start, end, arr);
		//print_part(start, end, arr);

		quick_sort(start, partitions - 1, arr);
		quick_sort(partitions + 1, end, arr);
	}
}