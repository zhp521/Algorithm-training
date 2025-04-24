
#include<bits/stdc++.h>
using namespace std;
vector<int>chosen;
int n;
void calc(int x)
{
    //边界条件x==n+1
    if(x==n+1)
    {
        for(int i=0;i<chosen.size();i++)
        {
            cout<<chosen[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    //情况一：x不选
    calc(x+1);

    //情况二：x选,当递归到这一步的时候，上面1~n全都不选的情况讨论了
    //下面就是1~x-1不选，x选,递归,求解子问题
    chosen.push_back(x);
    calc(x+1);

    //准备回溯到上一问题之前，还原现场
    chosen.pop_back();
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    calc(1);
}