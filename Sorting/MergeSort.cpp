#include<iostream>
using namespace std;

void merge(int array[], int temp[], int left, int mid, int right)
{
	int i, left_end, temp_pos;
	left_end = mid-1;
	temp_pos = left;
	int size = right - left + 1;

	while((left<=left_end)&&(mid<=right))
	{
		if(array[left]<=array[mid])
			temp[temp_pos++]=array[left++];
		else
			temp[temp_pos++]=array[mid++];
	}
	while(left<=left_end)
		temp[temp_pos++]=array[left++];

	while(mid<=right)
		temp[temp_pos++]=array[mid++];

	for(i=0;i<=size; i++)
	{
		array[right]=temp[right];
		right--;
	}
}

void MergeSort(int array[], int temp[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
		MergeSort(array, temp, left, mid);
		MergeSort(array, temp, mid+1, right);
		merge(array, temp, left, mid+1, right);
	}
}
int main()
{
	int array[]={9, 7, 4, 1, 6, 3, 15, 13, 2, 18, 5};
	int size = sizeof(array)/sizeof(array[0]);
	int *temp = new int[size];
	
	MergeSort(array, temp, 0, size-1);
	for(int i=0; i<size ; i++)
		cout<<array[i]<<" ";
	return 0;
}
