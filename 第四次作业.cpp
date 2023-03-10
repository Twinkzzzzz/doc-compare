#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double n;
int m,a[100],t[100];

bool isint(double f) //判断整形数or浮点数 
{
	int x=f;
	double temp=f-x;
	if (temp>-(1e-6) && temp<1e-6) return 1; //由于浮点数并不是完全精确存储，只判断到小数点后6位 
	return 0;
}

void tranint(int n) //整形数处理 
{
	int f=0,k=31;
	if (n<0)
	{
		n=-n-1; //负数
		f=1;
	}
	memset(a,0,sizeof(a));
	while(n>0) //进制转换部分 
	{
		a[k]=(n%2);
		n/=2;
		k--;
	}
	if (f) for(int i=0;i<=31;++i) a[i]=1-a[i]; //负数的补码规则不同 
	for(int i=0;i<=31;++i)
	{
		cout << a[i];
		if ((i+1)%8==0) cout << ' ';
	}
	cout << endl;
	return;
}

void trandouble(double n) //浮点数处理 
{
	memset(a,0,sizeof(a));
	if (n<0)
	{
		a[0]=1;
		n=-n; 
	} 
	m=(int)(n);
	n-=m;
	int k=0,k1,i; //k最终为移动小数点的位数 
	while(m>0) //整数部分进制转换 
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
		while(n*(2.0)<1)  //计算要使整数部分仅保留1需要移动小数点多少位（左移为正） 
		{
			n*=(2.0);
			k--;
		}	
	}
	while(n>0 && i<=52) //小数部分进制转换
	{
		n*=(2.0);
		t[i]=(int)(n);
		if (n>=(1.0)) n-=(1.0);
		i++;
	}
	k1=k;
	k+=1023; //指数位的特殊存储规则，双精度时1023代表0 
	if (!(k>=0) && k<=2047)
	{
		cout << "out of boundary!\n";
		return;
	}
	i=11;
	while(k>0 && i>0) //指数位转换为二进制 
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
	k=k1+127; //尝试处理单精度存储，出位数不同外，规则与双精度完全相同 
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

int main() //主函数部分 
{
	cin >> n;
	if (isint(n)) tranint(n); else trandouble(n);
	return 0;
} 
