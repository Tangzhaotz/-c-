/*
计数排序：核心在于将输入的数据转换为键存储在额外开辟的数组空间中，作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数
注意优化：当我们直到数组的范围，即0到10之间的数字排序简单，但是遇到不是从0开始，要考虑范围计算，还有在实际的应用场景中如何比较两个相等的元素的顺序
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int>&arr)
{
    //先计算数列的最大值和最小值
    int max =arr[0];
    int min =arr[0];

    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min =arr[i];
        }
    }

    int d= max-min;  //计算差值

    //创建统计数组并统计对应元素的个数
    vector<int>countArr(d+1,0);  //开辟统计每个元素的次数的数组，初始化为0

    for(int i=0;i<arr.size();i++)
    {
        countArr[arr[i]-min]++;  //统计元素出现的次数
    }

    //统计数组做变形，后面的元素等于前面的元素之和
    for(int i=1;i<countArr.size();i++)
    {
        countArr[i]+=countArr[i-1];
    }

    //倒序遍历原始数列，从统计数组中找到正确的位置，输出到结果数组
    vector<int>sortarr(arr.size(),0);

    for(int i=arr.size()-1;i>=0;i--)
    {
        sortarr[countArr[arr[i]-min]-1]=arr[i];
        countArr[arr[i]-min]--;
    }
    return sortarr;
}


int main()
{
    vector<int>arr={95,94,91,98,99,90,99,93,91,92};

    cout << "排序前：" << endl;
    for(auto i: arr)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int>sortArr=countSort(arr);

    cout << "排序后：" << endl;
    for(auto i:sortArr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}