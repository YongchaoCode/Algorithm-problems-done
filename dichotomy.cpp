//
// Created by 泳钞 on 2024/1/25.
//


/*#include<bits/stdc++.h>
using namespace std;
int l,r,mid,target,ans,arr[]={1,2,3,4,5,6,7,8,8,8,9};

int main()
{
    cin>>target;
    int len=sizeof(arr)/sizeof(int);
    l=0,r=len-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(arr[mid]>=target){//左
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
// 右              if(arr[mid]<=target){
//                   ans=mid;
//                    l=mid+1;
//               }
//               else{
//                   r=mid-1;
//               }
    }
    cout<<ans;
    return 0;
}*/



//找到数组中第一个数小于target的位置(下标从0开始)
/*#include<bits/stdc++.h>
using namespace std;
int l, r, mid, target, ans, arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9};

int main()
{
    cin >> target;
    int len = sizeof(arr) / sizeof(int);
    l = 0, r = len - 1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] < target)
        { //将判断条件改为arr[mid]<target，向右查找
            ans = mid;
            l = mid + 1; //更新ans的位置
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}*/

//找到数组中第一个数大于target的位置(下标从0开始)
#include<bits/stdc++.h>

using namespace std;
int arr[] = {1, 2, 3, 5, 6, 7, 8, 9};

int main() {
    int target, ans;
    int len = sizeof(arr) / sizeof(int);
    int l = 0, r = len - 1;
    cin >> target;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > target) {//为什么这里不能加=？？？ ：target=2,应该输出2，如果加了=，就会输出1。
            ans = mid;           //当arr[mid(1)]=2时，arr[mid]==target，ans=mid(1),右边界就会r=mid-1，
            r = mid - 1;         //后面的搜索数组的元素都会是小于目标值的，最终结果ans=1。(the result is error!!!)
        } else {
            l = mid + 1;         //不加+，判定就会到这里，左边界=mid+1,搜索数组完全跳过小于等于target的所有元素，
        }                        //后面的搜索值，都会是大于target的元素值(right)
    }
    cout << ans << endl;
    return 0;
}