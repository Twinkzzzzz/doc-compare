#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double n;
int m,a[100],t[100];

bool isint(double f) //�ж�������or������ 
{
	int x=f;
	double temp=f-x;
	if (temp>-(1e-6) && temp<1e-6) return 1; //���ڸ�������������ȫ��ȷ�洢��ֻ�жϵ�С�����6λ 
	return 0;
}

void tranint(int n) //���������� 
{
	int f=0,k=31;
	if (n<0)
	{
		n=-n-1; //����
		f=1;
	}
	memset(a,0,sizeof(a));
	while(n>0) //����ת������ 
	{
		a[k]=(n%2);
		n/=2;
		k--;
	}
	if (f) for(int i=0;i<=31;++i) a[i]=1-a[i]; //�����Ĳ������ͬ 
	for(int i=0;i<=31;++i)
	{
		cout << a[i];
		if ((i+1)%8==0) cout << ' ';
	}
	cout << endl;
	return;
}

void trandouble(double n) //���������� 
{
	memset(a,0,sizeof(a));
	if (n<0)
	{
		a[0]=1;
		n=-n; 
	} 
	m=(int)(n);
	n-=m;
	int k=0,k1,i; //k����Ϊ�ƶ�С�����λ�� 
	while(m>0) //�������ֽ���ת�� 
	{
		t[k]=m%2;
		m/=2;
		k++;
	}
	k--;
	for(i=0;i<=(k-1)/2;++i) swap(t[i],t[k-i]);
	i=k+1;
	if (!i)
	{
		while(n*(2.0)<1)  //����Ҫʹ�������ֽ�����1��Ҫ�ƶ�С�������λ������Ϊ���� 
		{
			n*=(2.0);
			k--;
		}	
	}
	while(n>0 && i<=52) //С�����ֽ���ת��
	{
		n*=(2.0);
		t[i]=(int)(n);
		if (n>=(1.0)) n-=(1.0);
		i++;
	}
	k1=k;
	k+=1023; //ָ��λ������洢����˫����ʱ1023����0 
	if (!(k>=0) && k<=2047)
	{
		cout << "out of boundary!\n";
		return;
	}
	i=11;
	while(k>0 && i>0) //ָ��λת��Ϊ������ 
	{
		a[i]=k%2;
		k/=2;
		i--;
	}
	cout << "double: " << a[1] << " ";
	for(int i=1;i<=11;++i) cout << a[i];
	cout << " ";
	for(int i=1;i<=52;++i) cout << t[i];
	cout << endl;
	k=k1+127; //���Դ������ȴ洢����λ����ͬ�⣬������˫������ȫ��ͬ 
	if (k>=0 && k<=255)
	{
		i=8;
		while(k>0 && i>0)
		{
			a[i]=k%2;
			k/=2;
			i--;
		}
		cout << "float: " << a[1] << " ";
		for(int i=1;i<=8;++i) cout << a[i];
		cout << " ";
		for(int i=1;i<=23;++i) cout << t[i];
		cout << endl;
	}
	return;
}

int main() //���������� 
{
	cin >> n;
	if (isint(n)) tranint(n); else trandouble(n);
	return 0;
} 
