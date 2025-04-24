#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;

//由于给的数据中有情况：1  3 和1  3这样重复出现的关系，所以利用map易于查询的特点
//给出现过的<a,b>关系打上标记，防止重复计算，而且map里面bool值自动赋初值false
map<pair<int,int>,bool>ensure;

//这里N=10000,不能是5000,因为题目中可能有A,B>N的情况，防止数组越界，超过N的部分不要就是了
const int N=1e4+10;

//b数组是a数组的差分数组，将对a数组的区间维护变为对b数组的两端维护
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,p,h,m;cin>>n>>p>>h>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		
		//这一步别忘了，防止关系如：3 1情况，保证x一定是小于y的才行
		if(x>y)swap(x,y);
		
		//make_pair返回一个pair类型数据，刚好作为map的关键字，如果为真，说明
		//<x,y>对应的值是true，已经出现过了，不做处理
		if(ensure[make_pair(x,y)])continue;
		
		//差分数组维护
		b[x+1]--;
		b[y]++;
		
		//给处理完的关系打上标记
		ensure[make_pair(x,y)]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		//从前往后便利不会出错
		a[i]=a[i-1]+b[i];
		
		//a数组里面的数都是对于最高身高 h 的相对差值
		cout<<a[i]+h<<'\n';
	}
	return 0;
}