#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400100;
char s[MAXN];
char t[MAXN];
int Block[MAXN];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch-'0'<0||ch-'0'>9){if(ch=='-') f=-1;ch=getchar();}
    while(ch-'0'>=0&&ch-'0'<=9){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int st,n,k;
void pre()
{
	st = n;
	for(int i = 1; i < n; i++)
		if(s[i] == s[i + 1]){
			st = i;
			break;
		}
}
bool check()
{
    return (s[1] != s[n]) && (st == n);
}
void solve()
{
	int Last = s[st], flag = 0, b; int ed = st + n - 1;
	for(int i = st + 1; i <= ed + 2; i++)
    {
		if(s[i] == s[i - 1])
        {
			t[i] = t[i - 1] = s[i];
			if(flag)
            {
				if(Last == s[i])
                {
					int l = b;
					int r = i - 2;
					int mi = min(k, (r - l + 2) >> 1);
					for(int j = 0; j < mi; j++)  t[l + j] = t[r - j] = Last;
					for(int j = l + mi; j <= r - mi; j++)
						if(t[j - 1] == 'W') t[j] = 'B';
						else                t[j] = 'W';
				} 
                else{
					int l = b;
					int r = i - 2;
					int mi = min(k, (r - l + 1) >> 1);
					for(int j = 0; j < mi; j++)  t[l + j] = Last, t[r - j] = s[i];
					for(int j = l + mi; j <= r - mi; j++)
						if(t[j - 1] == 'W') t[j] = 'B';
						else                t[j] = 'W';
				}
			}
            flag=0;
			Last=s[i];
		}
        else{
			if(s[i] != s[i + 1])
            {
				if(!flag) {
					flag = 1;
					b = i;
				}
			}
		}
	}
	for(int i = st; i <= ed; i++)   if(i>n) t[i-n]=t[i];
	t[n+1]=0;
    for(int i=1;i<=n;i++)  putchar(t[i]);
    puts("");
}
int main()
{
	n=read(),k=read();
    scanf("%s",s+1);
    pre();
	for(int i = 1; i <= n; i++)
    {
        s[i + n] = s[i];
        s[n * 2 + 2] = s[2];
        s[n * 2 + 1] = s[1];
    }
	if(check())
    {
		if(k & 1)
        {
			for(int i = 1; i <= n; i++)
            {
				if(s[i] == 'B') s[i] = 'W';
				else            s[i] = 'B';
			}            
        }
        for(int i=1;i<=n;i++)  putchar(s[i]);
        puts("");
		return 0;
	}
    solve();
	return 0;
}