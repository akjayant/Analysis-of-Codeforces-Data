#include <cstdio>
#include <algorithm>
using namespace std;
int K,N;
int data[1005];
int main()
{
    scanf("%d",&K);
    for(int ii=0;ii<K;ii++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d",&data[i]);

        sort(data,data+N);
        int maxi=1;
        for(int i=0;i<N;i++)
        {
            maxi = max(maxi, min(data[i],N-i));
        }
        printf("%d\n",maxi);
    }
    return 0;
}
