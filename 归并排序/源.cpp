#include <iostream>
using namespace std;

//�鲢����ĺ����ǹ鲢���������ϵش�����������Ԫ�ؼ�����ѡȡ��С��Ԫ�ز��뵽��һ���򼯺ϵ�ĩβ��
//��Ȼ�ֶ���֮Ҳ����ؼ�˼�룺���ϵ�2�֣�ֱ������Ĺ�ģΪ1

//�鲢����
void merge(int* a, int begin, int middle,int end)
{
	//��һ������ begin��middle
	//�ڶ������� middle+1 �� end
	//Ҫ�����ǹ鲢����������begin �� end

	//��һ���µ����鱣���һ���ֺ͵ڶ�����
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
		//�ٽ�λ��
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

		//���ٽ�λ��
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
//������
void merge_sort(int* a, int begin, int end)
{
	//��������ģ��Ϊ1���ֶ���֮
	if (begin < end)
	{
		int middle = (begin + end) / 2;
		merge_sort(a, begin, middle);
		merge_sort(a, middle + 1, end);
		//�鲢����
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
	cout << "δ��������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	merge_sort(a, 0, length - 1);
	cout << "���������飺" << endl;
	for (int i = 0; i < length; i++)
		cout << a[i] << " ";
	cout << endl;
	system("pause");
}