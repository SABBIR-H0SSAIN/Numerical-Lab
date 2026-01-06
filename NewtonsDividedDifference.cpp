#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<double>x(n+1),y(n+1);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    vector<vector<double>>diff(n+1,vector<double>(n+1,0));

    for(int i=0;i<n;i++) diff[i][0]=y[i];

    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            diff[i][j]=(diff[i+1][j-1]-diff[i][j-1])/(x[i+j]-x[i]);
        }
    }

    double res=diff[0][0],term=1,xn;
    cin>>xn;

    for(int i=1;i<n;i++){
        term*=xn-x[i-1];
        res+=term*diff[0][i];

    }

    cout<<res<<endl;

}