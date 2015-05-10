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

    int main(){
        int a[5001];
        mem(a, 0);

        a[1]=1;
        for(int z=2; z<=5000; z++){
            stringstream st;
            st << z;
            string s = st.str();

            sort(s.begin(), s.end());
            bool f = true;
            for(string::iterator it=s.begin()+1; it!=s.end() && f; ++it){
                if(*it == *(it-1))
                    f = false;
            }

            if(f==true){
                a[z]=a[z-1]+1;
            }

            else{
                a[z]=a[z-1];
            }
        }

        int p, q;
        while(scanf("%d %d", &p, &q)!=EOF){
                printf("%d\n", a[q]-a[p-1]);
        }

        return 0;
    }
