#include<iostream>
using namespace std;

int findPivot(int *array, int low, int high)
{
	int pivot=array[low];
	int left = low;
	int right = high;
	while(left<right)
	{
		while(array[left]<=pivot)
			left++;
		while(pivot<array[right])
			right--;
		if(left<right)
		{
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}
	array[low] = array[right];
	array[right]=pivot;

	return right;
}

void quicksort(int *array, int left, int right)
{
	if(left<right)
	{
		int pivot = findPivot(array, left, right);
		quicksort(array, left, pivot-1);
		quicksort(array, pivot+1, right);
	}
}

int main()
{	
	int array[]={9, 7, 4, 1, 6, 3, 15, 13, 2, 18, 5};
	int size = sizeof(array)/sizeof(array[0]);
	quicksort(array, 0, size-1);
	for(int i=0; i<size; i++)
		cout<<array[i]<<" ";
	return 0;
}
