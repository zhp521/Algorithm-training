////方法1：时间复杂度O(1)
//#include<bits/stdc++.h>
//using namespace std;
//using ull=unsigned long long; 
//ull mul(ull a,ull b,ull p)
//{
//	//求出整数商，比如结果是3......,这一步取值就是3，特殊情况：如果a*b恰好整除p,但是
//	//由于long double 精确位只有17位可能导致c比实际值小1，后面会考虑
//	ull c=(long double)a*b/p;
//
////这样写也可以，实际上暗含的是x值，y值溢出，相当于对2^64取模
////	ull x=a*b;
////	ull y=c*p;
////	ull res=x-y;
//	
//	ull res=a*b-c*p;
//	
//	//考虑上面说的特殊情况，如果a*b恰好整除p,但是
//	//由于long double 精确位只有17位可能导致c比实际值小1，所以res本来应该等于0，现在
//	//等于p,将res取模p就OK
//	
//	return res%p;
//}
//int main()
//{
//	ull a,b,p;
//	cin>>a>>b>>p;
//	cout<<mul(a,b,p);
//}


//方法2：时间复杂度O(logb)
#include<bits/stdc++.h>
using namespace std;
using gg=long long;
gg mul(gg a,gg b,gg p)
{
	gg res=0;
	while(b)
	{
		if(b&1)res=(res+a)%p;
		a=a*2%p;
		b=b>>1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	gg a,b,p;cin>>a>>b>>p;
	cout<<mul(a,b,p);
}