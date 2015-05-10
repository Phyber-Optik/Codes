#include <stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	// your code goes here
	int n,i;
    long long int arr[100],temp=0,sum1=0,sum2=0,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    if(n==1)printf("%lld",arr[0]);
    else{
    sort(arr,arr+n);
    sum1=arr[n-1];
    sum2=arr[n-2];
    for(i=n-1;i>=2;i--){
        temp=arr[i-2];
        if(sum1>=sum2)sum2=sum2+temp;
        else sum1=sum1+temp;
    }
    ans=abs(sum1-sum2);
    printf("%lld\n",ans);
    }
	return 0;
}
