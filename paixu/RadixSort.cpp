/*
基数排序：基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前
*/

#include<iostream>
#include<vector>
using namespace std;

int maxbit(int a[], int len) //辅助函数，求数据的最大位数
{
	int maxData = a[0];              ///< 最大数
	/// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
	for (int i = 1; i < len; ++i)
	{
		if (maxData < a[i])
			maxData = a[i];
	}
	int maxDigit = 1;
	int p = 10;
	while (maxData >= p)
	{
		maxData /= 10;
		++maxDigit;
	}
	return maxDigit;
}
void radixsort(int a[], int len) //基数排序
{
	int maxDigit = maxbit(a, len);
	int* temp = new int[len];
	int* count = new int[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= maxDigit; i++) //进行maxDigit次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < len; j++)
		{
			k = (a[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将temp中的位置依次分配给每个桶
		for (j = len - 1; j >= 0; j--) //将所有桶中记录依次收集到temp中
		{
			k = (a[j] / radix) % 10;
			temp[count[k] - 1] = a[j];
			count[k]--;
		}
		for (j = 0; j < len; j++) //将临时数组的内容复制到a中
			a[j] = temp[j];
		radix = radix * 10;
	}
	delete[]temp;
	delete[]count;
}

