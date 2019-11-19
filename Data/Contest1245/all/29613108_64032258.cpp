#include<iostream>
#include<cstring>

using namespace std;

long long memo[50][2][2][2][2];

long long l, r;
long long calcState(int index, bool isSmallerA, bool isSmallerB, bool isBiggerA, bool isBiggerB)
{
    if(index==-1) return 1;
    if(memo[index][isSmallerA][isSmallerB][isBiggerA][isBiggerB]!=-1) return memo[index][isSmallerA][isSmallerB][isBiggerA][isBiggerB];

    long long answer = 0;
    for(int d1 = 0;d1<2;d1++)
    {
        for(int d2 = 0;d2<2;d2++)
        {
            if((d1+d2)==(d1^d2))
            {
                if(d1<=((r>>index)&1) || isSmallerA==true)
                {
                    if(d2<=((r>>index)&1) || isSmallerB==true)
                    {
                        if(d1>=((l>>index)&1) || isBiggerA==true)
                        {
                            if(d2>=((l>>index)&1) || isBiggerB==true)
                            {
                                bool smallerA = (d1<((r>>index)&1));
                                bool smallerB = (d2<((r>>index)&1));

                                bool biggerA = (d1>((l>>index)&1));
                                bool biggerB = (d2>((l>>index)&1));

                                answer += calcState(index-1, max(isSmallerA, smallerA), max(isSmallerB, smallerB), max(isBiggerA, biggerA), max(isBiggerB, biggerB));
                            }
                        }

                        //cout << index << "-> " << d1 << " " << d2 << '\n';
                    }
                }
            }
        }
    }

    memo[index][isSmallerA][isSmallerB][isBiggerA][isBiggerB] = answer;
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        cin >> l >> r;

        memset(memo, -1, sizeof(memo));
        cout << calcState(45, false, false, false, false) << '\n';
    }
}
