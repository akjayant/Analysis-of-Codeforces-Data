#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char s[10010];
char t[10010];

void Run()
{
    int N, i, j, k, noDiff;
    scanf("%d", &N);
    scanf("%s", s);
    scanf("%s", t);
    noDiff = 0;
    for(i = 0; i < N; ++i)
        if(s[i] != t[i])
            ++noDiff;
    if(noDiff != 2)
    {
        printf("No\n");
        return;
    }
    
    i = 0;
    while(i < N)
    {
        if(s[i] != t[i])
            break;
        ++i;
    }
    j = N - 1;
    while(j >= 0)
    {
        if(s[j] != t[j])
            break;
        --j;
    }
    
    //printf("i = %d, j = %d\n", i, j);
    if(s[i] == s[j] && t[i] == t[j])
        printf("Yes\n");
    else
        printf("No\n");
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
        Run();
    return 0;
}
