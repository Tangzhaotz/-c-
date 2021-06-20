/*
插入排序：维护一段有序的序列，遍历待排序的序列，将待排序的插入到有序的序列的合适的位置
思路：先从读二个元素开始依次遍历数组，先比较前两个元素的大小并交换，再将后续的元素插入到当前已经排好序的序列中，需要移动元素，移动元素是从当前位置的前一个元素开始从后往前比较
*/

#include<iostream>
using namespace std;
#include<vector>


void insert_sort(vector<int>&arr,int n)
{
    int i,j;
    //外层循环标识并决定要插入的元素
    for(int i=1;i<n;i++)  //从第二个元素开始
    {
        if(arr[i] < arr[i-1])
        {
            int temp=arr[i];  //这个值就是需要插入到有序数组的元素
            //确定插入元素的最终位置
            for(j=i-1;j>=0 && arr[j]>temp;j--)  //从后往前找合适的位置进行插入
            {
                arr[j+1]=arr[j];
            }
            arr[j+1]=temp;  //找到位置，这里因为是上述的循环跳出，说明将j的值小于0,所以j+1为第一个位置，因为遍历的过程中的元素都大于temp
        }
    }
}

int main()
{
    vector<int>arr={1,8,7,5,3,6,2,9};
    cout << "排序前的数组为：" << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    insert_sort(arr,arr.size());
    cout << "排序后的数组为：" << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }


    return 0;
}

/*
分析：
时间复杂度：O（n×n）
空间复杂度：O（1）
稳定性：稳定排序
*/