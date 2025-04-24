#include<bits/stdc++.h>
#include<utility>
using namespace std;
const int N=1e5+10;
pair<string,int>a[N];
int n,m;

//用参数的第bit位进行n次运算
int jud(int bit,int now)
{
	for(int i=1;i<=n;i++)
	{
		int x=(a[i].second>>bit)&1;
		if(a[i].first=="AND") now&=x;
		if(a[i].first=="OR")now=now|x;
		if(a[i].first=="XOR")now=now^x;
	}
	return now;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	
	//记录输入值
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	
	//tempval_judge表示可能取的1~m中的值
	//final_ans表示取tempval_judge值时最终结果
	//对于（0,1）情况来说tempval_judge和final_ans是一样的，二进制下每一位上tempval_judge取1则final_ans也取1
	//tempval_judge取0则final_ans也取0，但是对于其他情况来说，二进制下每一位tempval_judge取0,final_ans都取1
	int tempval_judge=0,final_ans=0;
	
	//位数从高到低验证，使结果值最大，最终结果一定不超过m<2^30，最终位数一定小于30位
	for(int bit=29;bit>=0;bit--)
	{
		int res0=jud(bit,0);
		int res1=jud(bit,1);
		
		//情况；(0,0),(0,1),(1,0),(1,1)只有(0,1)才满足条件
		//下面也可以写成res0==0 and res1==1 and tempval_judge+(1<<bit)) <= m
		if(res0<res1 and (tempval_judge+(1<<bit)) <= m)
		{
			tempval_judge+=1<<bit;//1<<bit表示1左移bit位，2^bit
			final_ans+=1<<bit;
		}
		
		//下面条件的话，res0可能是0，也可能是1
		else 
		{
			//此时tempval_judge值此位数上取值0，对tempval_judge值没有影响，final_ans值取1
			final_ans+=res0<<bit;
		}
	}
	cout<<final_ans;
}