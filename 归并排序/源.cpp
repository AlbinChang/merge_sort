#include <iostream>
using namespace std;

//归并排序的核心是归并操作：不断地从两部分有序元素集合中选取最小的元素插入到另一有序集合的末尾。
//当然分而治之也是其关键思想：不断的2分，直到问题的规模为1

//归并函数
void merge(int* a, int begin, int middle,int end)
{
	//第一部分是 begin到middle
	//第二部分是 middle+1 到 end
	//要做的是归并到第三部分begin 到 end

	//用一个新的数组保存第一部分和第二部分
	int length = end - begin + 1;
	int* temp_array = new int[length];
	for (int index = 0; index < length; index++)
	{
		temp_array[index] = a[begin + index];
	}
	int i = 0;
	int j = middle-begin+1;	
	for (int k = begin; k <= end; k++)
	{
		//临界位置
		if (i == middle - begin + 1)
		{
			a[k] = temp_array[j++];
			continue;
		}
		if (j == end - begin + 1)
		{
			a[k] = temp_array[i++];
			continue;
		}

		//非临界位置
		if (temp_array[i] > temp_array[j])
		{
			a[k] = temp_array[j++];
		}
		else
		{
			a[k] = temp_array[i++];
		}
		
	}
	delete[] temp_array;
}
//排序函数
void merge_sort(int* a, int begin, int end)
{
	//如果问题规模不为1，分而治之
	if (begin < end)
	{
		int middle = (begin + end) / 2;
		merge_sort(a, begin, middle);
		merge_sort(a, middle + 1, end);
		//归并操作
		merge(a, begin, middle, end);
	}
}
int main()
{
	int a[] = {
		455,565,89,89,5,0,2,3,6,5,5,5,22,2,-5,48,2,
		-58,-69,-328466,164646,13,22,5,8,4,5,2,0,3,
	};
	int length = sizeof(a) / sizeof(int);
	cout << "未排序的数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	merge_sort(a, 0, length - 1);
	cout << "排序后的数组：" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
}