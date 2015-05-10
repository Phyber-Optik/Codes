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

    bool clap_number(int num) {
        if (num % 7 == 0)
            return true;

        while (num) {
            int r = num % 10;
            num /= 10;

            if (r == 7)
                return true;
        }

        return false;
    }

    int main(){
        int n, m, k;
        while(scanf("%d %d %d", &n, &m, &k) && (n||m||k)){
            int cur=0;
            int step=1;
            int p=1;

            while(1){
                cur++;
                if(p==m && clap_number(cur)){
                    k--;
                    if(k==0){
                        printf("%d\n", cur);
                        break;
                    }
                }

                p+=step;
                if(p>n){
                    p=n-1;
                    step=-1;
                }

                if(p==0){
                    p=2;
                    step=1;
                }
            }
        }
        return 0;
    }
