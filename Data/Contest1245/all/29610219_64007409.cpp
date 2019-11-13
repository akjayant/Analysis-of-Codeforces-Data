#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int TC, N, A, B, C;
string SS, T;

int main()
{
    int i, j;

    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d%d%d%d", &N, &A, &B, &C);
        cin>>SS; T.clear(); T.resize(N, '!');
        int R=0, P=0, S=0;
        for(i=0; i<N; i++)
        {
            if(SS[i]=='R') P++;
            if(SS[i]=='P') S++;
            if(SS[i]=='S') R++;
        }

        int x=min(R, A)+min(P, B)+min(S, C);
        if(x<(N+1)/2) printf("NO\n");
        else
        {
            for(i=0; i<N; i++)
            {
                if(SS[i]=='R')
                {
                    if(B) T[i]='P', B--;
                }
                if(SS[i]=='P')
                {
                    if(C) T[i]='S', C--;
                }
                if(SS[i]=='S')
                {
                    if(A) T[i]='R', A--;
                }
            }
            string left;
            while(A--) left.push_back('R');
            while(B--) left.push_back('P');
            while(C--) left.push_back('S');
            for(i=0; i<N; i++) if(T[i]=='!') T[i]=left.back(), left.pop_back();
            cout<<"YES\n"<<T<<"\n";
        }
    }
}
