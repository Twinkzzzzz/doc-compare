#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n;
int a[33];

int main()
{
	int f=0,k=31;
	cin >> n;
	if (n<0)
	{
		n=-n-1;
		f=1;
	}
	memset(a,0,sizeof(a));
	while(n>0)
	{
		a[k]=(n%2);
		n/=2;
		k--;
	}
	if (f) for(int i=0;i<=31;++i) a[i]=1-a[i];
	for(int i=0;i<=31;++i)
	{
		cout << a[i];
		if ((i+1)%8==0) cout << ' ';
	}
	cout << endl;
	return 0;
} 
