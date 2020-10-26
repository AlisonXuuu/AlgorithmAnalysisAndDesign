#include<iostream>
#include<stdlib.h>
using namespace std;

void Swap(int &x,int &y)//交换
{
	int t;
	t=x;
	x=y;
	y=t;
}

void sort(int w[],int t[],int n)//排序，由小到大
{
	for(int m=0;m<n;m++) //为每个物品编序号
	{
		t[m]=m;
	}
	int i,j;
	int lastExchangeIndex;
	i=n-1;
	while(i>0)
	{
		lastExchangeIndex=0;
		for(j=0;j<i;j++)
		{
			if(w[j+1]<w[j])
			{
				Swap(w[j+1],w[j]); //物品重量交换
				lastExchangeIndex=j;
				Swap(t[j],t[j+1]); //物品序号交换
			}
		}
		i=lastExchangeIndex; //当不存在交换的时候，lastExchangeIndex = 0，循环结束
	}
}

void Loading(int x[],int w[],int c,int n,int *t) //传址
{
	sort(w,t,n);
	for(int i=0;i<n;i++)x[i]=0;
	for(int i=0;i<n && w[t[i]]<=c ; i++)
	{
		x[t[i]]=1;//装入
		c-=w[t[i]];
	}
}

int main()
{
	int n,c;
	cout<<"请输入物品个数："<<endl;
	cin>>n;
	cout<<"请输入最大容量："<<endl;
	cin>>c;
	int *t=new int[n]; //存储物品编号
	int *w=new int[n]; //存储每个物品重量
	
	cout<<"请输入每个物品重量："<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	int *x=new int[n]; //物品是否装入
	for(int j=0;j<n;j++) //初始化 所有物品均为不装入
	{
		x[j]=0;
	}
	Loading(x,w,c,n,t);

	cout<<"装入物品编号为："<<endl;
	for(int k=0;k<n;k++)
	{
		if(x[k]==1)
			cout<<t[k]+1<<"　";
	}
	
	return 0;
}
