#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 510;
char ss[maxn];
int n;

void swap(int i,int j)
{
	char tmp = ss[i];
	ss[i] = ss[j];
	ss[j] = tmp;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",ss);
//	printf("%s",ss);
	int l,r,res = 0;
	int a = 0,b = 0;
	for(int  i = 0;i<n;i++)
	{
		if(ss[i]=='(') a++;
		else b++;
	}
	if(a!=b)
	{
		printf("0\n1 1");
		return 0;
	}
	
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			swap(ss[i],ss[j]);
//			printf("~%s\n",ss);
			stack<char> st;
			int num = 0;
			for(int k = 0;k<n;k++)
			{
				if(ss[k]==')'&&!st.empty()&&st.top()=='(')
				{
					st.pop();
				}
				else
					st.push(ss[k]);
			}
			num = st.size()/2;
//			printf("~%d??\n",num);
			int tmp = 0;
			for(int k = 0;k<n;k++)
			{
				if(ss[k]=='(')
					num++;
				else
					num--;
				if(num == 0)
					tmp++;
			}
			if(res<tmp)
			{
				res = tmp;
				l = i;
				r = j;
			}
			swap(ss[i],ss[j]);
			
		}
	}
	printf("%d\n%d %d",res,l+1,r+1);







	return 0;
}
