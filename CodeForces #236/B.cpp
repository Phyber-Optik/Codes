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
        int k, a, v, b;
        while(scanf("%d %d %d %d", &k, &a, &b, &v)!=EOF){
            int c, d, box=0;
            while(b){
                if(b+1>k){
                    c=k;
                    b=b-(k-1);
                }

                else{
                    c=b+1;
                    b=0;
                }

                //cout<<"c="<<c<<endl;

                d=c*v;
                a=a-d;
                box++;
                if(a<v){
                    break;
                }
            }
            //cout<<a<<endl;
            if(a<1){
                cout<<box<<endl;
            }

            else{
                double x=ceil((double)a/(double)v);
                //cout<<x<<endl;
                box+=(int)x;
                cout<<box<<endl;
            }
        }
        return 0;
    }
