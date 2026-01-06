#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<double>>A(n+1,vector<double>(n+1,0));
    vector<vector<double>>L(n+1,vector<double>(n+1,0));
    vector<vector<double>>U(n+1,vector<double>(n+1,0));
    vector<double>x(n+1,0),y(n+1,0),b(n+1,0);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>A[i][j];
        }
        b[i]=A[i][n];
    }

    for(int i=0;i<n;i++){
        for(int k=i;k<n;k++){
            double sum=0;
            for(int j=0;j<i;j++){
                sum+=L[i][j]*U[j][k];
            }
            U[i][k]=A[i][k]-sum;
        }

        for(int k=i;k<n;k++){
            if(i==k){
                L[i][i]=1;
            }else{
                double sum=0;
                for(int j=0;j<i;j++){
                    sum+=L[k][j]*U[j][i];
                }
                L[k][i]=(A[k][i]-sum)/U[i][i];
            }
        }
    }
        
        for(int i=0;i<n;i++){
            double sum=0;
            for(int j=0;j<i;j++){
                sum+=L[i][j]*y[j];
            }
            y[i]=b[i]-sum;
        }

        for(int i=n-1;i>=0;i--){
            double sum=0;
            for(int j=i+1;j<n;j++){
                sum+=U[i][j]*x[j];
            }
            x[i]=y[i]-sum;
            x[i]/=U[i][i];
        }

        for(int i=0;i<n;i++) cout<<x[i]<<" ";
}