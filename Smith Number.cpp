// One Of the Best Sum I Have Ever Solved..
//GFG
//Smith Number
typedef long long ll;
ll m=1e6+1;
vector<ll>primes(m,1);
class Solution {
  public:
    ll reverse(ll n){
        ll s=0;
        while(n!=0){
            s=s+(n%10);
            n=n/10;
        }
        return s;
    }
    void seive(){
        if(primes[4]==2) return;
        primes[0]=0;
        primes[1]=1;
        for(ll i=2;i<=m;i++){
            if(primes[i]==1){
                primes[i]=i;
                for(ll j=2*i;j<=m;j+=i) primes[j]=i;
            }
        }
    }
    int smithNum(int n) {
        seive();
        if(n<1e6+1 and primes[n]==n) return 0;
        vector<ll>list;
        for(int i=2;i<=sqrt(n);i++){
            ll a=(n/i);
            if(primes[i]==i and n%i==0){
                list.push_back(i);
            }
            if(a<1e6+1 and primes[a]==a and n%a==0){
                list.push_back(a);
            }
        }
        ll s=reverse(n);
        map<ll,ll>mpp;
        for(int i=0;i<list.size();i++){
            ll t=list[i];
            while(n%t==0){
                mpp[t]++;
                n=n/t;
            }
        }
        ll ans=0;
        for(auto it:mpp){
            int t=it.first;
            //cout<<it.first<<" "<<it.second<<"\n";
            t=reverse(t);
            ans=ans+(t*it.second);
        }
        return ans==s;
    }
};
