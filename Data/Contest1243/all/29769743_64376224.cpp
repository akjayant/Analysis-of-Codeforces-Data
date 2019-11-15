#include <bits/stdc++.h>

#define input   std::cin
#define output  std::cout

int main()
{
    std::ios_base::sync_with_stdio(false);

    int K;  input >> K;
    while (K--) {
        int N;  input >> N;
        std::string s, t;
        input >> s >> t;

        std::vector <int> V;
        for (int i=0; i<N; ++i) {
            if (s[i] != t[i]) {
                V.push_back(i);
                if (V.size() == 3) i = N+5;
            }
        }

        if (V.size() == 2 && t[V[0]] == t[V[1]] && s[V[0]] == s[V[1]]) output << "Yes\n";
        else output << "No\n";
    }

    return 0;
}
