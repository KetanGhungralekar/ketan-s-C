#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        vector <ll> a(n);
        vector <ll> b(n);
        for (ll i=0;i<n;i++){
            cin>>a[i];
        }
        for (ll i=0;i<n;i++){
            cin>>b[i];
        }
        ll total = 0;
        ll min1 = *min_element(a.begin(),a.end());
        ll min2 = *min_element(b.begin(),b.end());
        ll sum = 0;
        ll sum2 = 0;
        for (auto i:a){
            sum += i;
        }
        for (auto i:b){
            sum2 += i;
        }
        cout<<min(n*min1 + sum2,n*min2 + sum2)<<endl;
    }
}