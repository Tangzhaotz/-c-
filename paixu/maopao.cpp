/*
冒泡排序：从第一个元素开始，比较当前元素跟下一个元素的大小，如果不符合排序，交换位置，直到最大或者最小的元素到末尾的位置，再从头开始按照同样的方法找第二大或者第二小的元素，直到整个
序列的元素都有序，结束排序
*/
#include<iostream>
using namespace std;
#include<vector>

void bubble(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)  //表示需要进行比较的轮数，为元素个数减一
    {
        for(int j= 0;j<arr.size()-1;j++)  //每一轮需要比较的次数
        {
            if(arr[j]>arr[j+1])  //发现顺序不合理就交换
            {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
}

int main()
{
    vector<int>arr ={15,28,3,6,58,99,65,88};
    cout << "排序前的数组为：" << endl;
    for(auto i:arr)
    {
        cout << i << " ";   //15 28 3 6 58 99 65 88 
    }
    cout << endl;

    bubble(arr);  //函数调用
    cout << "排序后的元素为：" << endl;
    for(auto i:arr)
    {
        cout << i << " ";   //3 6 15 28 58 65 88 99 
    }
    cout << endl;

}

/*
分析：
时间复杂度：因为用了两个for循环，时间复杂度为O(n*n)
空间复杂度：用了一个临时变量，空间复杂素为O（1）
稳定性：因为在排序的过程中两个相等的变量不会交换，所以是稳定的
*/