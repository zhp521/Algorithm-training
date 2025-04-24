////第一种方法：快速幂
//#include<bits/stdc++.h>
//using namespace std;
//using gg=long long;
//int main()
//{
//	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	cout<<log10(ULLONG_MAX);
////	gg a,b,p;cin>>a>>b>>p;
////	gg ans=ans%p;
////	while(b)
////	{
////		if(b&1)ans=(ans+a)%p;
////		a=a*2%p;
////		b=b>>1;
////	}
////	cout<<ans;
//}

#include<bits/stdc++.h>
using namespace std;
class Stu
{
private:
	//学号
	string id;
	//成绩
	double grade;
public:
	Stu()
	{
		id="kong";
		grade=0;
	}
	void init(string id_,double grade_)
	{
		id=id_;
		grade=grade_;
	}
	
	friend string maxStu(Stu *p,int n);
};

string maxStu(Stu *p,int n)
{
	double max_grade=p[0].grade;
	int max_index=0;
	
	for(int i=1;i<n;i++)
	{
		if(p[i].grade > max_grade)
		{
			max_grade=p[i].grade;
			max_index=i;
		}
	}
	return p[max_index].id;
}

int main()
{
	cout<<"请输入学生的个数：";
	int n;cin>>n;
	cout<<"请初始化学生信息：(学号，成绩)"<<'\n';
	Stu *p=new Stu[n];
	for(int i=0;i<n;i++)
	{
		cout<<"第"<<i+1<<"个学生学号：";
		string s;cin>>s;
		
		cout<<"成绩";
		double g;cin>>g;
		(p+i)->init(s,g);
	}
	
	cout<<"成绩最好的学生的学号是:";
	cout<<maxStu(p,n);
	
	delete []p;
}