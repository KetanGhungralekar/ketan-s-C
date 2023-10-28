#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        ll w;
        ll e1;
        ll maxe = LONG_MIN;
        for (ll i=0;i<n;i++){
            ll st;
            ll e;
            cin>>st>>e;
            if (i == 0){
                w = st;
                e1 = e;
            }
            else{
                if (st >= w){
                    if (maxe < e){
                        maxe = e;
                    }
                }
            }
        }
        if (maxe < e1){
            cout<<w<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}