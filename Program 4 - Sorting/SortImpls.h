
#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int> &arr, int first, int last);
void InsertionSort(vector<int> &arr, int first, int last);
void MergeSort(vector<int> &arr, int first, int last);
void IterativeMergeSort(vector<int> &arr, int first, int last);
void QuickSort(vector<int> &arr, int first, int last);
void ShellSort(vector<int> &arr, int first, int last);

void Merge(vector<int> &itemVector, int first, int mid, int last);

//============================================================================
//
//
//                        Function Definitions
//
//
//============================================================================
//============================================================================
//                        Bubble Sort
//============================================================================
void BubbleSort(vector<int> &arr, int first, int last)
{
	for (int i = first; i < last; ++i)
	{
		for (int j = i; j < last; ++j)
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

//============================================================================
//                         Insertion Sort
//============================================================================
void InsertionSort(vector<int> &arr, int first, int last)
{
	for (int i = first; i < last + 1; i++) 
	{
		int temp = arr[i];
		int j = i;
		while (j > 0 && temp < arr[j - 1])
		{
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = temp;
	}

}

//============================================================================
//                         Merge Sort
//============================================================================
void MergeSort(vector<int> &arr, int first, int last)
{
	if (first < last)
	{
		//int mid = (first + last) / 2;
		int mid = first + ((last - first) / 2);
		MergeSort(arr, first, mid);
		MergeSort(arr, mid + 1, last);
		Merge(arr, first, mid, last);
	}
}

//============================================================================
//                          Merge
//============================================================================
void Merge(vector<int> &itemVector, int first, int mid, int last)
{
	int size = last - first + 1;
	int *tempArr = new int[size];
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int index = 0;
	while((first1 <= last1) && (first2 <= last2))
	{
		if(itemVector[first1] < itemVector[first2])
		{
			tempArr[index] = itemVector[first1];
			first1++;
		}
		else
		{
			tempArr[index] = itemVector[first2];
			first2++;
		}
		index++;
	}
	while (first1 <= last1)
	{
		tempArr[index] = itemVector[first1];
		first1++;
		index++;
	}
	while(first2 <= last2)
	{
		tempArr[index] = itemVector[first2];
		first2++;
		index++;
	}
	for(index = 0; index < size; index++)
	{
		itemVector[first] = tempArr[index];
		first++;
	}
	delete[] tempArr;
}

//============================================================================
//                     Iterative Merge Sort
//============================================================================
void IterativeMergeSort(vector<int> &arr, int first, int last)
{
	int size = (last - first) + 1;

	int *tempArr = new int[(last - first) + 1];
	for (int i = 0; i < first; i++)
	{
		tempArr[i] = arr[i];
	}

	int gap = 1;
	while (gap < size)
	{
		int current = first;
		int first1 = first;
		int index1;
		int	index2;
		while ((first1 + gap) < (last + 1))
		{
			int first2 = (first1 + gap);
			int last1 = (first2 - 1);
			int last2;
			if (!((first2 + (gap - 1)) < (last + 1)))
			{
				last2 = last;
			}
			else
			{
				last2 = ((first2 + gap) - 1);
			}
			index1 = first1;
			index2 = first2;
			while ((index1 <= last1) && (index2 <= last2))
			{
				if (arr[index1] >= arr[index2])
				{
					tempArr[current] = arr[index2];
					index2++;
				}
				else
				{
					tempArr[current] = arr[index1];
					index1++;
				}
				current++;
			}
			while (index1 <= last1)
			{
				tempArr[current] = arr[index1];
				index1++;
				current++;
			}

			while (index2 <= last2)
			{
				tempArr[current] = arr[index2];
				current++;
				index2++;
			}

			first1 = last2 + 1;
		}

		index1 = first1;
		while (current < (last + 1))
		{
			tempArr[current] = arr[index1];
			current++;
			index1++;
		}

		for (int i = first; i < (last + 1); i++)
		{
			arr[i] = tempArr[i];
		}
		gap *= 2;
	}
}

//============================================================================
//                       Quick Sort
//============================================================================
void QuickSort(vector<int> &itemVector, int first, int last)
{
	if (last - first < 6)
	{
		InsertionSort(itemVector, first, last);
		return;
	}
	int mid = (first + last) / 2;
	if (itemVector[first] > itemVector[last])
	{
		swap(itemVector[first], itemVector[last]);
	}
	if (itemVector[first] > itemVector[mid])
	{
		swap(itemVector[first], itemVector[mid]);
	}
	else if (itemVector[mid] > itemVector[last])
	{
		swap(itemVector[mid], itemVector[last]);
	}
	int pivot = itemVector[mid];
	swap(itemVector[mid], itemVector[last - 1]);
	int left = first + 1;
	int right = last - 2;
	bool done = false;
	while (!done)
	{
		while (itemVector[left] < pivot)
		{
			left++;
		}
		while (itemVector[right] > pivot)
		{
			right--;
		}
		if (right > left)
		{
			swap(itemVector[left], itemVector[right]);
			right--;
			left++;
		}
		else
		{
			done = true;
		}
	}
	swap(itemVector[left], itemVector[last - 1]);
	QuickSort(itemVector, first, left - 1);
	QuickSort(itemVector, left + 1, last);
}

//============================================================================
//                       Shell Sort
//============================================================================
void ShellSort(vector<int> &data, int start, int end)
{
	int j, temp;
	int size = end - start + 1;
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; i++)
		{
			temp = data[i];
			for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
			{
				data[j] = data[j - gap];
			}
			data[j] = temp;
		}
	}
}