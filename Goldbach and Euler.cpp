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
    #define si 100001000

    int prime[10000000];
    bool status[si];
    int pos=1;

    void sieve(){
        int i, j;
        for(i=0; i<si; i++){
            status[i]=false;
        }

        int sq=sqrt(si);

        for(i=4; i<=si; i+=2){
            status[i]=true;
        }

        for(i=3; i<=sq; i+=2){
            if(status[i]==false){
                for(j=2*i; j<=si; j+=i){
                    status[j]=true;
                }
            }
        }

        status[1]=false;

        for(int z=1; z<=si; z++){
            if(status[z]==false){
                prime[pos]=z;
                pos++;
            }
        }

        pos--;
    }

    int bin_s(int n){
        int high=pos, low=1;

        int mid=(high+low)/2;
        while(low<=high && prime[mid]!=n){
            if(n<prime[mid]){
                high=mid;
            }

            else
                low=mid+1;
            mid=(high+low)/2;
        }

        if(prime[mid]==n){
            return mid;
        }

        else
            return -1;
    }

    int main(){
        read(in);
        sieve();
        int n;
        while(scanf("%d", &n)!=EOF){
                if(n%2==1){
                    if(status[n-2]==false){
                        printf("%d is the sum of 2 and %d.\n", n, n-2);
                    }

                    else
                        printf("%d is not the sum of two primes!\n", n);
                }

                else{
                    int d=n/2;
                    int flag=0;

                    int k, p;
                    for(k=d; ; k--){
                        if(status[k]==false){
                            //cout<<k<<endl;
                            p=k;
                            break;
                        }
                    }

                    int i=bin_s(p);
                    if(i==-1){
                        flag=0;
                    }
                    else
                    for( ; prime[i]>=1; i--){
                        int temp=prime[i];
                        if(status[n-temp]==false){
                            if(temp!=n-temp){
                                flag=1;
                                printf("%d is the sum of %d and %d.\n", n, temp, n-temp);
                                break;
                            }
                        }
                    }

                    if(flag==0){
                        printf("%d is not the sum of two primes!\n");
                    }
                }
        }
        return 0;
    }
