#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void extended_euclid(int sol[], int a, int b){
    if(b==0){
        sol[0]=a;
        sol[1]=1;
        sol[2]=0;
        return;
    }
    extended_euclid(sol, b, a%b);
    int temp[3];
    temp[0]=sol[0];
    temp[1]=sol[2];
    temp[2]=sol[1]-(a/b)*sol[2];
    sol[0]=temp[0];
    sol[1]=temp[1];
    sol[2]=temp[2];
}

int main(){
    int a, b;
    cin>>a>>b;
    int sol[3];
    extended_euclid(sol, a, b);
    cout<<sol[0]<<" "<<sol[1]<<" "<<sol[2]<<endl;
    return 0;
}
