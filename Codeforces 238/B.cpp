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
        int n;
        while(scanf("%d", &n)!=EOF){
            string s;
            cin>>s;
            int first=0, pos=0, flag=0;
            for(int i=0; i<n; i++){
                //cout<<s[i]<<endl;
                if(s[i]=='.'){
                    first++;
                }

                else{
                    flag=1;
                    pos=i;
                    break;
                }
            }

            if(flag=0){
                cout<<first<<endl;
                //cout<<"poop"<<endl;
                continue;
            }

           // cout<<first<<" "<<pos<<endl;
            char las=s[pos], cur;
            if(s[pos]=='L'){
                //las='R';
                int total=0, p;
                for(int i=pos+1; ;i++){
                    if(s[i]=='.'){
                        total++;
                    }

                    else{
                        p=i;
                        break;
                    }
                }

                //cout<<total<<endl;

                int z=0;
                char l;
                for(int j=n-1; ;j--){
                    if(s[j]=='.'){
                        z++;
                    }

                    else{
                        l=s[j];
                        break;
                    }
                }
                //cout<<total<<endl;
                int f=n-z;
                if(l=='L')
                    total+=z;

                int d=0;
                for(int i=p+1; i<f; i++){
                    cout<<total<<endl;
                    if(las=='R'){
                        //cout<<i<<endl;
                        if(s[i]=='.'){
                            d++;
                        }

                        else{
                            las='L';
                            if(d%2==1){
                                total++;
                                d=0;
                                continue;
                            }
                            else{
                                d=0;
                                continue;
                            }
                        }
                    }

                    else{
                        //cout<<"shurur d="<<d<<endl;
                        if(s[i]=='.'){
                            d++;
                        }

                        else{
                            las='R';
                            //cout<<"I="<<i<<"D="<<d<<endl;
                            total+=d;
                            d=0;
                            continue;
                        }
                    }
                }

                cout<<total<<endl;
            }

            if(s[pos]=='R'){
                //las='R';
                int q=0;
                char l;
                for(int j=n-1; ; j--){
                    if(s[j]=='.'){
                        q++;
                    }

                    else{
                        l=s[j];
                        if(s[j]=='R'){
                            q++;
                        }

                        break;
                    }
                }
                if(l=='R')
                    n=n-q;

                int total=first, p;

                int z=0;
                for(int j=n-1; ;j--){
                    if(s[j]=='.'){
                        z++;
                    }

                    else{
                        break;
                    }
                }

                int f=n-z;
                total+=z;

                las='R';
                int d=0;
                for(int i=0; i<f; i++){
                    if(las=='R'){
                        if(s[i]=='.'){
                            d++;
                        }

                        else{
                            las='L';
                            if(d%2==1){
                                total++;
                                d=0;
                                continue;
                            }

                            else{
                                d=0;
                                continue;
                            }
                        }
                    }

                    else{
                        if(s[i]=='.'){
                            d++;
                        }

                        else{
                            total+=d;
                            d=0;
                            las='R';
                            continue;
                        }
                    }
                }

                cout<<total<<endl;
            }
        }
        return 0;
    }
