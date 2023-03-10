#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
using namespace std;

map<string,int>num1,num2;
string word1[100001],word2[10001];
int tot1,tot2,sum1,sum2;
int vector1[10001],vector2[10001];

void get1()  //单词分离 
{
	string t;
	char c;
	while((c=cin.get())!=EOF)
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			if (c>='A' && c<='Z') c=c+32;
			t+=c;
		}
		else
		{
			if(!(t==""))
			{
				sum1++;
				if(num1[t]>=1)
				{
					num1[t]++;
				}
				else
				{
					num1[t]=1;
					tot1++;
					word1[tot1]=t;
				}
				t="";
			}
		}
	}
	if(!(t==""))
	{
		sum1++;
		if(num1[t]>=1)
		{
			num1[t]++;
		}
		else
		{
			num1[t]=1;
			tot1++;
			word1[tot1]=t;
		}
		t="";
	}
}

void get2()
{
	string t;
	char c;
	while((c=cin.get())!=EOF)
	{
		if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			if (c>='A' && c<='Z') c=c+32;
			t+=c;
		}
		else
		{
			if(!(t==""))
			{
				sum2++;
				if(num2[t]>=1)
				{
					num2[t]++;
				}
				else
				{
					num2[t]=1;
					tot2++;
					word2[tot2]=t;
				}
				t="";
			}
		}
	}
	if(!(t==""))
	{
		sum2++;
		if(num2[t]>=1)
		{
			num2[t]++;
		}
		else
		{
			num2[t]=1;
			tot2++;
			word2[tot2]=t;
		}
		t="";
	}
}

int main()
{
	cout << "Choose the files to be compared(doc/docx/docm)\n";  //选择文件 
	system("transform.vbs txt1.in");
	system("transform.vbs txt2.in");
	tot1=0;
	tot2=0;
	freopen("txt1.in","r",stdin);  //读取转换过后的txt文件 
	get1();
	fclose(stdin);
	cin.clear();
	freopen("txt2.in","r",stdin);
	get2();
	fclose(stdin);
	memset(vector1,0,sizeof(vector1));
	memset(vector2,0,sizeof(vector2));
	string tmp;
	int tot=0;
	for(int i=1;i<=tot1;++i)  //整理各单词出现次数 
	{
		tmp=word1[i];
		tot++;
		vector1[tot]=num1[tmp];
		if (num2[tmp]>0) vector2[tot]=num2[tmp];
	}
	for(int i=1;i<=tot2;++i)
	{
		tmp=word2[i];
		if(!(num1[tmp]>0))
		{
			tot++;
			vector2[tot]=num2[tmp];
		}
	}
	double ans=0,len1=0,len2=0;
	for(int i=1;i<=tot;++i)  //计算余弦值 
	{
		ans+=vector1[i]*vector2[i];
		len1+=vector1[i]*vector1[i];
		len2+=vector2[i]*vector2[i];
	}
	len1=sqrt(len1);
	len2=sqrt(len2);
	ans/=(len1*len2);
	cout << "Similarity=" << ans << endl;
} 
