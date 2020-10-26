#include<iostream>
#include<stdlib.h>
using namespace std;

void Swap(int &x,int &y)//����
{
	int t;
	t=x;
	x=y;
	y=t;
}

void sort(int w[],int t[],int n)//������С����
{
	for(int m=0;m<n;m++) //Ϊÿ����Ʒ�����
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
				Swap(w[j+1],w[j]); //��Ʒ��������
				lastExchangeIndex=j;
				Swap(t[j],t[j+1]); //��Ʒ��Ž���
			}
		}
		i=lastExchangeIndex; //�������ڽ�����ʱ��lastExchangeIndex = 0��ѭ������
	}
}

void Loading(int x[],int w[],int c,int n,int *t) //��ַ
{
	sort(w,t,n);
	for(int i=0;i<n;i++)x[i]=0;
	for(int i=0;i<n && w[t[i]]<=c ; i++)
	{
		x[t[i]]=1;//װ��
		c-=w[t[i]];
	}
}

int main()
{
	int n,c;
	cout<<"��������Ʒ������"<<endl;
	cin>>n;
	cout<<"���������������"<<endl;
	cin>>c;
	int *t=new int[n]; //�洢��Ʒ���
	int *w=new int[n]; //�洢ÿ����Ʒ����
	
	cout<<"������ÿ����Ʒ������"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	int *x=new int[n]; //��Ʒ�Ƿ�װ��
	for(int j=0;j<n;j++) //��ʼ�� ������Ʒ��Ϊ��װ��
	{
		x[j]=0;
	}
	Loading(x,w,c,n,t);

	cout<<"װ����Ʒ���Ϊ��"<<endl;
	for(int k=0;k<n;k++)
	{
		if(x[k]==1)
			cout<<t[k]+1<<"��";
	}
	
	return 0;
}
