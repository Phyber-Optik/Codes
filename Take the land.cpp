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
    #define INF 1LL<<50
    using namespace std;

    long long kadane(long long* arr, int* start, int* finish, int n){
        long long sum=0, maxSum=-1*INF;
        int i;
        *finish=-1;
        int local_start=0;

        for(i=0; i<n; i++){
            sum+=arr[i];
            //cout<<sum<<endl;
            if(sum<0){
                sum=0;
                local_start=i+1;
            }

            else if(sum>maxSum){
                maxSum=sum;
                *start=local_start;
                *finish=i;
            }
        }
        maxSum=max(0LL, maxSum);
        if(*finish!=-1)
            return maxSum;

        maxSum=arr[0];
        *start=*finish=0;
        for(i=1; i<n; i++){
            if(arr[i]>maxSum){
                maxSum=arr[i];
                *start=*finish=i;
            }
        }
        maxSum=max(0LL , maxSum);
        return maxSum;
    }

    int main(){
        int row, col;
        long long a[110][110];
        while(scanf("%d %d", &row, &col) && (row||col)){
            mem(a, 0);
            int c;
            for(int z=0; z<row; z++){
                for(int x=0; x<col; x++){
                    scanf("%d", &c);
                    if(c==1){
                        a[z][x]=-1*INF;
                    }

                    else
                        a[z][x]=1;
                }
            }

            long long maxSum=-1*INF;

            int left, right, i;
            long long temp[row], sum=-1*INF;
            int start, finish;

            for(left=0; left<col; ++left){
                mem(temp, 0);
                for(right=left; right<col; ++right){
                    for(i=0; i<row; ++i){
                        temp[i]+=a[i][right];
                    }
                    sum=kadane(temp, &start, &finish, row);
                    //cout<<sum<<endl;
                    if (sum > maxSum){
                        maxSum = sum;
                    }
                }
            }
            maxSum=max(0LL, maxSum);
            printf("%lld\n", maxSum);
        }
        return 0;
    }
