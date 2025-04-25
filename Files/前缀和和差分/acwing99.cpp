//https://www.acwing.com/problem/content/101/
#include<bits/stdc++.h>
using namespace std;
using gg=long long;
const int N=5e3+10;
int gra[N][N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,r;
    cin>>n>>r;
    r=min(5001,r);
    int x_max=r,y_max=r;
    
    for(int i=1;i<=n;i++)
    {
        int x,y,val;
        cin>>x>>y>>val;
        x++;
        y++;
        x_max=max(x_max,x);
        y_max=max(y_max,y);
        gra[x][y]+=val;
    }

    //下面不正确，因为要保证x_max>=r,这样才能到后面循环中，满足初始条件r<=x_max，
    //否则ans直接就是0
    // int xy_max=max(x_max,y_max);
    // r=min(r,xy_max);

    for(int i=1;i<=x_max;i++)
    {
        for(int j=1;j<=y_max;j++)
        {
            gra[i][j]+=gra[i-1][j]+gra[i][j-1]-gra[i-1][j-1];
        }
    }

    gg ans=0;
    for(int i=r;i<=x_max;i++)
    {
        for(int j=r;j<=y_max;j++)
        {
            gg temp=gra[i][j]-gra[i-r][j]-gra[i][j-r]+gra[i-r][j-r];
            ans=max(ans,temp);
        }
    }

    cout<<ans;

}



/*
#include<iostream>
#include<math.h>
using namespace std;
const int N=5e3+10;
using gg=long long;
int s[N][N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int r;cin>>r;
	r=min(5001,r);//这里要注意min里面的两个数必须是同种类型的都是int或者都是gg
	int chang=r,kuan=r;
	
	for(int i=1;i<=n;i++)
	{
		int x,y,w;cin>>x>>y>>w;
		x++;
		y++;
		chang=max(chang,x);
		kuan=max(kuan,y);
		s[x][y]+=w;
	}
	
	for(int i=1;i<=chang;i++)
	{
		for(int j=1;j<=kuan;j++)
		{
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	
	gg result=0;
	for(int i=r;i<=chang;i++)
	{
		for(int j=r;j<=kuan;j++)
		{
			result=max(result,gg(s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]));
		}
	}
	cout<<result<<'\n';
}




*/