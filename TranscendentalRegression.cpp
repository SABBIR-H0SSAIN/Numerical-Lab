#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<double>x(n+1,0),y(n+1,0);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];

    double xi=0,yi=0,xiyi=0,xi2=0;
    for(int i=0;i<n;i++){
        x[i]=log(x[i]);
        y[i]=log(y[i]);

        xi+=x[i];
        yi+=y[i];
        xiyi+=x[i]*y[i];
        xi2+=x[i]*x[i];
    }

    double b=(n*xiyi)-(xi*yi);
    b/=(n*xi2)-(xi*xi);
    double a=yi-(b*xi);
    a/=n;
    a=exp(a);

    cout<<"FInal equation: "<<"y="<<a<<"x^"<<b;
}