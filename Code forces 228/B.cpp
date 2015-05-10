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
        //read(in);
        int n;
        while(scanf("%d", &n)!=EOF){
            string a[100];
            for(int i=0; i<n; i++){
                cin>>a[i];
            }
            int z, x, flag=1;
            for(z=0; z<n; z++){
                for(x=0; x<n; x++){
                    if(a[z][x]=='#'){
                        if(a[z+1][x-1]!='#' || a[z+1][x]!='#' || a[z+1][x+1]!='#' || a[z+2][x]!='#' || x-1<0 || x+1>=n || z+1>=n || z+1>=n){
                            flag=0;
                            break;
                        }

                        else{
                            a[z][x]='.';
                            a[z+1][x-1]='.';
                            a[z+1][x]='.';
                            a[z+1][x+1]='.';
                            a[z+2][x]='.';
                        }
                    }
                }
                if(flag==0){
                    break;
                }
            }

            if(flag==1){
                flag=1;
                for(z=0; z<n; z++){
                    for(x=0; x<n; x++){
                        if(a[z][x]=='#'){
                            flag=0;
                            break;
                        }
                    }
                    if(flag==0){
                        break;
                    }
                }

                if(flag){
                    printf("YES\n");
                }

                else{
                    puts("NO");
                }
            }

            else
                puts("NO");
            for(int i=0; i<n; i++){
                a[i].clear();
            }
        }
        return 0;
    }
