#include<bits/stdc++.h>
using namespace std;
using gg=long long;
gg power(gg a,gg b,gg p)
{
	//这里一定要%p，不能省略，a=123,b=0,p=1时
	//正确答案是0,但是如果这里不%p,最后答案会是1，因为没有进入循环
	gg ans=1%p;
	while(b)
	{
		//b&1来判断二进制表示下b的最后一位数字是0是1
		//如果是1，加入最后答案
		if(b&1)ans=ans*a%p;
		
		//a不受b&1的影响，每一次都平方；
		a=a*a%p;
		
		//这里也不收b&1的影响，每一次都右移一位，相当于便利了
		//二进制b下的每一位
		b=b>>1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	gg a,b,p;cin>>a>>b>>p;
	cout<<power(a,b,p);
}
