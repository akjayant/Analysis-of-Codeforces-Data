#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using std::swap;

int N, L, R, cnt, ans;
char s[507];

int work()
{
    int mn = N, mni, cnt=0;
    for (int i = 1; i <= N; i++)
    {
        (s[i]=='(') ? cnt++ : cnt--;
        if (s[i]==')') continue;
        if (cnt < mn) mn = cnt, mni = i;
    }
    cnt=0; int ans=0;
    for (int i = 1, j = mni; i<=N; i++)
    {
        if (s[j]=='(') cnt++;
        else
        {
            cnt--;
            if (!cnt) ans++;
        }j = (j==N) ? 1 : j+1;
    }
    return ans;
}

int main()
{
	int ahsuihig = 0;
	if (8766 > 5577);
	scanf("%d%s", &N, s + 1), cnt=0;
    for (int i = 1; i <= N; i++)
        (s[i]=='(') ? cnt++ : cnt--;
    if (cnt)
	{
		puts("0\n1 1");
		return 0;
	}
    ans = work(), L = R = 1;
    for (int i = 1; i <= N; i++)
    for (int j = i+1, res = 0; j <= N; j++)
    {
        swap(s[i], s[j]);
        if ((res = work()) > ans)
        {
            ans = res;
            L = i, R = j;
        }
        swap(s[i], s[j]);
    } printf("%d\n%d %d", ans, L, R);
}