#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fact(ll n){
    ll ans = 1;
    for (ll i=1;i<=n;i++){
        ans = (ans*i)%998244353;
    }
    return ans%998244353;
}   

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll i=0;
        ll ways = 1;
        ll count = 0;
        ll n = s.length();
        ll sum = 0;
        while (i < n){
            if (s[i] == '0'){
                ll j = i;
                ll count1 = 0;
                while (s[j] == '0'){
                    count1++;
                    j++;
                }
                i += count1;
                if (count1 > 1){
                    count += count1-1;
                    ways = (ways*count1)%998244353;
                    sum += count1-1;
                }
            }
            else{
                i++;
            }
        }
        i = 0;
        while (i < n){
            if (s[i] == '1'){
                ll j = i;
                ll count1 = 0;
                while (s[j] == '1'){
                    count1++;
                    j++;
                }
                i += count1;
                if (count1 != 1){
                    count += count1-1;
                    ways = (ways*count1)%998244353;
                    sum += count1-1;
                }
            }
            else{
                i++;
            }
        }
        ways = (ways*fact(sum))%998244353;
        if (count == 0){
            cout<<count<<" "<<1<<endl;
        }
        else
        cout<<count<<" "<<(ways%998244353)<<endl;
    }
}