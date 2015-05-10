    #include<stdio.h>
    #include<memory.h>
    #include<cstdio>
    #include<iostream>
    #include<cstring>
    #include<cmath>
    #include<cstdlib>
    #include<cctype>
    #include<vector>
    #include<queue>
    #include<fstream>
    #include<sstream>
    #include<set>
    #include<climits>
    #include<map>
    #include<algorithm>

    typedef long long ll;

    #define pb push_back
    #define mem(a, x) memset(a, x, sizeof a)
    #define PI acos(-1)
    #define MAX 10000
    #define read(in) freopen("in.txt", "r", stdin)

    using namespace std;
    int tab[1000001];

    int main()
    {
        int i, j, k, q;

        memset(tab, 0, sizeof(tab));
        for (i = 2; i <= 1000000; i++) {
            if (tab[i] != 0)
                continue;

            for (k = i; ; ) {
                for (j = k; j <= 1000000; j += k)
                    tab[j]++;

                if (i > 1000)
                    break;
                if ((k *= i) >= 1000000)
                    break;
            }
        }

        for (i = 2, k = 0; i <= 1000000; i++) {
            k += tab[i];
            tab[i] = k;
        }

        while (scanf("%d", &q)!=EOF)
            printf("%d\n", tab[q]);

        return 0;
    }
