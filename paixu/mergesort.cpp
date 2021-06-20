/*
归并排序：采用分治的思想，核心思想是将两个有序的序列合并成一个大的有序的序列
思想：先申请一个空间能够存下两个序列的大小的空间
设定两个指针，初始分别为两个已经排序的序列的起始位置
比较元素，选择相对较小的元素加入序列，再移动指针进行比较
重复上述的直到合并完
*/


#include<iostream>
using namespace std;
#include<vector>

vector<int> merge(vector<int> a, vector<int> b){
	vector<int> res;
	int ba = 0;  //指向第一个序列的指针
	int bb = 0;  //指向第二个序列的指针
 
	while(ba<a.size() && bb<b.size()){  //比较大小，那个小就将哪个元素加入
		if(a[ba]<=b[bb]){
			res.push_back(a[ba++]);
		}
		else{
			res.push_back(b[bb++]);
		}
	}
 
	if(ba==a.size()){  //如果第一个序列的元素比较完，而第二个序列还有元素，那么直接将剩余的元素加入序列即可
		while(bb<b.size()) res.push_back(b[bb++]);
	}else if(bb==b.size()){  //第二个序列的元素少，第一个有剩余，直接加入即可
		while(ba<a.size()) res.push_back(a[ba++]);
	}
 
	return res;
}
 
vector<int> mergeSort(vector<int> arr){
	int s = arr.size();  //申请空间的大小
	if(s<2) return arr;  //如果俩个序列的总长度小于2,不用比了
	int mid = s/2;  //取中间的位置，进行分割
	vector<int> front(arr.begin(), arr.begin()+mid);  //分割得到第一个序列
	vector<int> back(arr.begin()+mid, arr.end());  //分割得到第二个序列
	return merge(mergeSort(front), mergeSort(back));  //进行归并
 
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

    vector<int>new_arr;
    new_arr=mergeSort(arr);  //排序后的数组
    cout << "排序后：" << endl;
    for(auto i: new_arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}