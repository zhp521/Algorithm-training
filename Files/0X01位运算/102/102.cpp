#include<iostream>
#include<math.h>
#include<utility>
#include<algorithm>//练习头文件书写
using namespace std;
const int N=1e5+10;
//sum数组是b数组的前缀和数组
int a[N];//牛的数目肯定是整数
double b[N],sum[N];//减去平均值之后就不一定是整数了
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int f;cin>>f;
	
	//初始化a数组,fanweimax表示最终答案的取值范围,即a[i]最大值，最大平均数不可能超过这个数
	int fanweimax=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fanweimax=max(fanweimax,a[i]);
	}

	//二分答案：
	double l=0;
	double r=fanweimax;
	
	//由于是double类型，只要两数字差值小于1e-6就表明两数字相等
	double chazhi=1e-8;
	while(r-l>chazhi)
	{
		double mid=(l+r)/2.0;
		for(int i=1;i<=n;i++)
		{
			//为什么不直接在a数组上直接减呢？因为a数组下次循环也要用的，不能更改a数组
			//导致影响下一次循环
			b[i]=a[i]-mid;
			sum[i]=sum[i-1]+b[i];
		}
		
		//记录此平均值下长度大于f的b数组的最大和,这里记住要是-1e10,不是1e-10
		//因为res可能取值就是负数，很大的负数
		double res=-1e10;
		//来记录min(sum[j]),0=<j<=i-f
		double min_val=1e10;
		for(int i=f;i<=n;i++)
		{
			min_val=min(min_val,sum[i-f]);
			res=max(res,sum[i]-min_val);
		}
		
		//res>=0说明此时的平均值还可以更大
		if(res>=0)l=mid;
		else r=mid;
	}
	cout<<int(r*1000);
	return 0;
}