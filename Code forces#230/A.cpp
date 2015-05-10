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
        //int c[130];
        char a[101];
        while(scanf("%s", a)!=EOF){
            int cn=0, ci=0, ct=0, ce=0;
            for(int i=0; i<strlen(a); i++){
                if(a[i]=='n')
                    cn++;
                else if(a[i]=='i')
                    ci++;
                else if(a[i]=='t')
                    ct++;
                else if(a[i]=='e')
                    ce++;
            }

            cn=cn/3;
            ce=ce/3;

            cout<<cn<<endl<<ci<<endl<<ct<<endl<<ce<<endl;

            int r=9999999;
            if(r>cn)
                r=cn;
            if(r>ci)
                r=ci;
            if(r>ct)
                r=ct;
            if(r>ce)
                r=ce;
            if(cn==0 &&ci==0 && ct==0 && ce==0)
                r=0;
            printf("%d\n", r);
        }
        return 0;
    }
