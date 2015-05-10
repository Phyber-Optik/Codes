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
    #define MAX 32001

    using namespace std;
    long long prime[200];
    bool status[MAX];

    int c, e, n, k, t, d, q, p, power[100];


    void gcd (int a, int b)
    {
        int bx;

        if (!b)
        {
            d=1; q=0;
            return;
        }

        gcd(b, a % b);

        bx = d; d = q;
        q = bx - (a / b) * q;
    }

    int main()
    {
        int i, j;

        scanf("%d", &k);
        for ( ; k--; )
        {
            scanf("%d %d %d", &e, &n, &c);
            for (i = 2; i <= n; i++)
            if (n % i == 0)
                p = i, i = n;
                q = n / p;

            t = (p - 1) * (q - 1);
            gcd(e, t);
            if (d < 0)
                d += t;

            t = power[0] = c;
            for (i = q = 1; i * 2 <= d; i *= 2, q++)
                t = (t * t) % n, power[q] = t;

            for (j = i, q--; q >= 0; q--, i /= 2)
                if (j + i <= d)
                    t = (t * power[q]) % n, j += i;
            printf("%d\n", t);
        }

        return 0;
}
