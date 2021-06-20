/*
选择排序：维护一段有序的序列，遍历无序的序列，找最小的元素插入到有序的序列中，直到没有剩余的元素

*/

#include<iostream>
#include<vector>
using namespace std;

void select_sort(vector<int>&arr)
{
    int temp;
    for(int i=0;i<arr.size();i++)
    {
        temp=i;  //记录要交换的元素的位置
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[temp] > arr[j])  //这里利用temp不断的替换，直到找到最小的元素
            {
                temp=j;  //这里需要通过手写实例来看才知道怎么找到最小的元素的
            }
        }
        //找到最小的元素就可以替换
        swap(arr[i],arr[temp]);
    }
}

int main()
{
    vector<int>arr={20,50,35,15,10,60,100,90};
    cout << "排序前：" << endl;
    for(auto i: arr)
    {
        cout << i << " ";
    }
    cout << endl;

    select_sort(arr);
    cout << "排序后：" << endl;
    for(auto i: arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
/*
分析：
时间复杂度：O（n*n)
空间复杂度：O(1)
稳定性：不稳定
*/

