/*
快速排序：利用了分治的思想，先找到一个基准，将序列划分为比它小和比他大的两个部分，再对两个部分进行上述的相似的操作，就可以得到最终的排序结果
思路：一般选定第一个元素作为基准，分别定义两根指针(l和r)分别指向基准的后一个元素和最后一个元素，当l和r没有遇到的时候遍历元素，先让r指针移动，先和基准比较，如果大于基准，就继续向左移动，
直到遇到小于基准的数字就停下来，然后移动l指针，先和基准比较，如果小于基准就继续向右移动，直到遇到比基准大的元素就停下，此时交换l和r所指向的元素，再继续先移动r指针再移动l指针，直到l和r指向
同一个元素，此时交换该元素和基准元素，就可以得到基准左侧的元素小于基准，右侧的元素大于基准，再对左右两个部分分别执行上述的同样的操作，最终得到排序结果
*/

#include<iostream>
using namespace std;
#include<vector>

int partition(vector<int>&arr,int start,int end)
{
    int pivot = arr[start];  //取第一个元素作为基准
    int l=start;  //左边的指针
    int r = end;  //右边的指针
    while(l != r)
    {
        //控制右边的指针并移动
        while(l < r && arr[r] > pivot)   //右边的元素大于基准，继续移动指针
        {
            r--;
        }

        //控制左边的指针并移动
        while(l < r && arr[l] <= pivot)
        {
            l++;
        }

        //上述两个指针都停下来的时候进行交换
        if(l < r)
        {
            int temp = arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
        }
    }

    //当两根指针相遇的时候将基准和当前指针所指的元素交换
    arr[start]=arr[l];
    arr[l]=pivot;

    return l;  //将当前基准的位置返回
}

void quicksort(vector<int>&arr,int start,int end)  //start和end表示数组的开始和结尾
{
    //递归结束的条件：当l大于或者等于r时
    if(start >= end)
    {
        return;
    }

    //获取基准位置
    int pivotindex = partition(arr,start,end);

    //分别对前半部分和后半部分进行上述的一样的操作，即递归
    quicksort(arr,start,pivotindex-1);  //前半部分
    quicksort(arr,pivotindex+1,end);  //后半部分


}

int main()
{
    vector<int>arr={4,4,6,5,3,2,8,1};
    cout << "排序前的数组为：" << endl;
    for(auto i:arr)
    {
        cout << i << " " ;
    }
    cout << endl;

    quicksort(arr,0,arr.size()-1);  //函数调用
    cout << "排序后的数组为：" << endl;
    for(auto i:arr)
    {
        cout << i << " " ;
    }
    cout << endl;

    return 0;
}

/*
时间复杂度：O（nlogn)
空间复杂度：O（n）
稳定性：稳定的
*/