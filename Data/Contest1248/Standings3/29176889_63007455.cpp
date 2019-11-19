#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include <iostream>
#define LL long long
#define mod 1000000007LL
using namespace std;

int top=0;
char a[505];

int main(int argc, char const *argv[])
{
	int n; scanf("%d",&n);
	string s; cin>>s;
	int l=s.length();
	int Ans=0,L=1,R=1,A=0,B=0;
	for (int i=0; i<l; i++)
	{
		if (s[i]=='(') A++;
		else B++;
	}
 	if(A!=B)
	{
		printf("0\n1 1");
		return 0;
	}
	for (int i=0; i<l; i++)
		for (int j=i; j<l; j++)
		{
			swap(s[i],s[j]);

			top=0;
			int ans=0;

			for (int k=0; k<l; k++)
			{
				a[++top]=s[k];
				if (s[k]==')' && (a[top-1]==')' || top==1))
				{
					ans=0;
					continue;
				}
				bool flag=0;
				while (top && a[top]==')' && a[top-1]=='(')
				{
					top-=2;
					flag=1;
				}
				if ((a[top]==')' || !top)&&flag) ans++;
			}

			int tot=0;

			if (top) ans++;

				if (Ans<ans)
				{
					Ans=ans;
					L=i+1;
					R=j+1;
				}

			swap(s[j],s[i]);
		}
	cout<<Ans<<endl;
	cout<<L<<" "<<R;
	return 0;
}