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
        int n, m;
        while(scanf("%d %d", &n, &m)!=EOF){
            char s[1001][1001];
            mem(s, 0);
            vector<int>v;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cin>>s[i][j];
                }
            }

            int flag=1;

            for(int i=0; i<n; i++){
                    int gs, ss;
                for(int j=0; j<m; j++){
                    if(s[i][j]=='S'){
                        ss=j;
                    }
                    else if(s[i][j]=='G'){
                        gs=j;
                    }
                }

                if(gs>ss){
                    flag=0;
                    break;
                }

                else{
                    int temp=ss-gs;
                    //cout<<temp<<endl;
                    int f=1;
                    for(int k=0; k<v.size(); k++){
                        if(temp==v[k]){
                            f=0;
                            break;
                        }
                    }

                    if(f==1)
                        v.pb(temp);
                }
            }

            if(flag==1)
                cout<<v.size()<<endl;
            else
                cout<<"-1"<<endl;
                v.clear();
        }
        return 0;
    }
