#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll min = 0;
    for (int i=0;i<n;i++){
        ll c;
        cin>>c;
        if (i == 0){
            min = c+1;
            if (c > 1){
                min = 1;
            }
        }
        else{
            if (min+1 < c || min+1 > c){
                min = min+1;
            }
            else{
                min = c+1;
            }
        }
    }
    cout<<min<<endl;
    }
}