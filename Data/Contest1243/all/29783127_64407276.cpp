#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char s[100];
char t[100];

void swap(int i, int j, queue<pair<int, int> > &SW, int &m)
{
    SW.push(make_pair(i, j));
    ++m;
}

void Run()
{
    int N, i, j, k, m = 0;
    char c;
    bool success = false;
    queue<pair<int, int> > SW;
    scanf("%d", &N);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    
    for(k = 1; k <= N; ++k)
    {
        if(s[k] == t[k])
            continue;
        
        success = false;
        for(j = k + 1; j <= N; ++j)
        {
            if(t[j] == t[k])
            {
                swap(k, j, SW, m);
                c = t[j];
                t[j] = s[k];
                s[k] = c;
                success = true;
                break;
            }
        }
        if(success)
            continue;
        
        for(j = k + 1; j <= N; ++j)
        {
            if(s[j] == t[k])
            {
                swap(j, j, SW, m);
                c = t[j];
                t[j] = s[j];
                s[j] = c;
                swap(k, j, SW, m);
                c = t[j];
                t[j] = s[k];
                s[k] = t[j];
                success = true;
                break;
            }
        }
        if(!success)
        {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    printf("%d\n", m);
    while(!SW.empty())
    {
        printf("%d %d\n", SW.front().first, SW.front().second);
        SW.pop();
    }
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
