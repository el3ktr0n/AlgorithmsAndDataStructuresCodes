#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int euler_totient(int num){
    int ans=1;
    for(int i=2;i*i<=num;++i){
        int c=0;
        int p=1;
        while(num%i==0){
            p*=i;
            num/=i;
            c++;
        }
        if(c>0)
            ans=ans*(p-p/i);
    }
    if(num>0){
        ans=ans*(num-num/num);
    }
    return ans;
}

int main(){
    int num;
    cin>>num;
    cout<<euler_totient(num)<<endl;
    return 0;
}
