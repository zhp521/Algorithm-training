#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>chosen;
void calc(int x)
{
    //如果chosen已经大于m个数或者哪怕把剩余所有的数都算上也不够m的话就直接返回就OK
    //“剪枝”
    if(chosen.size()>m or chosen.size()+n-x+1<m)return;

    if(x==n+1)
    {
        for(int i=0;i<chosen.size();i++)
        {
            cout<<chosen[i]<<" ";
        }
        cout<<'\n';
    }

    //x选
    chosen.push_back(x);
    calc(x+1);//接着判断x+1
    chosen.pop_back();

    //x不选
    calc(x+1);//接着判断x+1
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    calc(1);
}