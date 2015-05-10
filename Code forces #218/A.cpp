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

    using namespace std;

    int main(){
        int n, k, a[100][100];
        while(scanf("%d %d", &n, &k)!=EOF){
            mem(a, 0);
            for(int z=1; z<=n/k; z++){
                for(int x=1; x<=k; x++){
                    scanf("%d", &a[z][x]);
                }
                //cout<<co<<" "<<ct<<endl;
            }

            int count=0;
            for(int z=1; z<=k; z++){
                int co=0, ct=0;
                for(int x=1; x<=n/k; x++){
                    //scanf("%d", &a[x][z]);
                    if(a[x][z]==1)
                        co++;
                    else if(a[x][z]==2)
                        ct++;
                }
                //cout<<co<<" "<<ct<<endl;

                if(co>=ct)
                    count+=ct;
                else
                    count+=co;
                //cout<<count<<endl;
            }
            printf("%d\n", count);

        }
        return 0;
    }
