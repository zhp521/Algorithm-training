//https://www.acwing.com/problem/content/96/
#include<bits/stdc++.h>
using namespace std;
int ans[20];//按顺序依次记录被选择的数
int chosen[20];//标记被选择的整数
int n;
void calc(int x)//判断ans第x个位置应该放那个数
{
    //边界条件
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
    }

    for(int i=1;i<=n;i++)
    {
        //如果i已经被选上了，就不做操作
        if(chosen[i])continue;

        //如果没有选择i,那么先选上i
        chosen[i]=1;
        //第x个位置放i
        ans[x]=i;

        calc(x+1);//判断ans第x+1个位置应该放那个数

        //回溯到上一个问题，复原
        chosen[i]=0;
        ans[x]=0;


    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    calc(1);
}