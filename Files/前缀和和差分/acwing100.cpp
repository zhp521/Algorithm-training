#include<bits/stdc++.h>
using namespace std;
const int N=1e5+0;
int a[N];
int chaifen[N];
using gg=long long;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        chaifen[i]=a[i]-a[i-1];//注意chaifen数组第一个数不表示跟前一个数的差值
    }

    gg zhengshu=0;
    gg fushu=0;
    for(int i=2;i<=n;i++)
    {
        if(chaifen[i]>0)zhengshu+=chaifen[i];
        else if(chaifen[i]<0)fushu+=chaifen[i];
    }

    gg ans=max(zhengshu,abs(fushu));//fabs返回值是double类型
    gg fanganshu=abs(abs(zhengshu)-abs(fushu))+1;//方案数跟第一个数的值的可能的个数有关

    cout<<ans<<'\n'<<fanganshu;

}