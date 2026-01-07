#include<bits/stdc++.h>
using namespace std;

void coff(vector<vector<double>>&mat,vector<vector<double>>&cf,int n,int p,int q){
    int i=0,j=0;

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(r==p || c==q) continue;
            cf[i][j++]=mat[r][c];
            if(j==n-1){
                j=0;
                i++;
            }
        }
    }
}

double det(vector<vector<double>>&mat,int n){
    if(n==1) return mat[0][0];

    double res=0;
    vector<vector<double>>cf(n-1,vector<double>(n-1,0));
    int sign=1;

    for(int i=0;i<n;i++){
        coff(mat,cf,n,0,i);
            res+=mat[0][i]*sign*det(cf,n-1);
            sign*=-1;
    }
    return res;
}

void adjcalc(vector<vector<double>>&mat,vector<vector<double>>&adj,int n){
    if(n==1){
        adj[0][0]=1;
        return;
    }

    vector<vector<double>>cf(n-1,vector<double>(n-1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            coff(mat,cf,n,i,j);
            int sign=(i+j) % 2==0 ? 1 : -1;
            adj[j][i]= sign*det(cf,n-1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<double>>A(n,vector<double>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>A[i][j];
    }

    double d=det(A,n);
    cout<<d<<endl;
    vector<vector<double>>adj(n,vector<double>(n,0));
    adjcalc(A,adj,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]/=d;
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }


}