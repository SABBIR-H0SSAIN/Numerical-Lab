#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    double a,b,h;

    
    vector<double>y(n+1),x(n+1);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    cin>>a>>b;
    h=(b-a)/n;

    double res=y[0]+y[n];

    for(int i=1;i<n;i++){
        res+=i%2==1 ? y[i]*4 : y[i]*2;
    }
    res*=h/3.0;
    cout<<res<<endl;

}