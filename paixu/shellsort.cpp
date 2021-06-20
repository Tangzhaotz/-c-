/*
希尔排序：插入排序的改进版
思路：选择一个间距，将序列分成很多子序列并进行插入排序，降低间距并重复插入排序，直到间距降为1完成排序
*/

#include<iostream>
using namespace std;
#include<vector>

void shellinsert(vector<int>&arr,int beg,int gap)
{
    for(int i= beg+gap;i < arr.size();i+=gap)  //只需要把插入排序的gap=1改成gap即可
    {
        int temp = arr[i];
        int j= i- gap;
        for(;j>=0 && temp < arr[j];j-=gap)
        {
            arr[j+gap]=arr[j];
        }
        arr[j+gap]=temp;
    }
}

void shell(vector<int>&arr)
{
    int gap=arr.size() / 2;
    while(gap>0)
    {
        int beg = gap-1;    //从中间开始往前
        while(beg >=0)
        {
            shellinsert(arr,beg,gap);
            beg--;
        }
        gap = gap/2;
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

    shell(arr);
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
时间复杂度：O（n×n）
空间复杂度：O（1）
稳定性：非稳定的
*/