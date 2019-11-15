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

        std::map <char, int> miss;
        for (int i=0; i<N; ++i)
            if (s[i] != t[i])
                miss[s[i]] ++, miss[t[i]] ++;
        bool bAns = true;
        for (auto &it:miss)
            if (it.second % 2 == 1)
                bAns = false;

        if (!bAns) {
            output << "No\n";
        }
        else {
            output << "Yes\n";
            std::vector <std::pair <int, int>> sol;

            for (int i=0; i<N; ++i) if (s[i] != t[i]) {
                bool bFound = false;
                for (int j=i+1; j<N && !bFound; ++j) if (s[j] != t[j]) {
                    if (t[i] == t[j])
                        std::swap(s[i], t[j]), bFound = true, sol.push_back({i+1, j+1});
                }

                if (!bFound)
                    for (int j=i+1; j<N && !bFound; ++j) if (s[j] != t[j]) {
                        if (t[i] == s[j])
                            std::swap(s[j], t[j]), std::swap(s[i], t[j]), bFound = true, sol.push_back({j+1, j+1}), sol.push_back({i+1, j+1});
                    }
            }

            output << sol.size() << '\n';
            for (auto &it:sol)
                output << it.first << ' ' << it.second << '\n';
        }
    }

    return 0;
}
