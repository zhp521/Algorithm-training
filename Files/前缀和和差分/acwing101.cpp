#include<bits/stdc++.h>
using namespace std;
using gg=long long;
const int N=1e4+10;
//b[N]是a[N]的差分数组
int a[N],b[N];

//用map方便查看到底有多少不重复的关系
map<pair<gg,gg>,bool>mp;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    gg n,p,h,m;
    cin>>n>>p>>h>>m;

    //找一共有多少对不重复的关系,对关系进行加一减一操作
    for(gg i=1;i<=m;i++)
    {
        gg x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        if(mp[make_pair(x,y)])continue;

        //相当于a数组x+1到y-1之间都减一
        b[x+1]--;
        b[y]++;
        mp[make_pair(x,y)]=true;
    }

    //计算出a数组
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+b[i];

        // cout<<a[i]+h<<'\n';这样写也行
    }

    //a数组表示第i个数字跟最大的数之间的差值
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]+h<<'\n';
    }
}