#include<bits/stdc++.h>
using namespace std;
double f(vector<double>&cf,double x){
    double res=0;
    int n=cf.size();
    for(int i=0;i<n;i++){
        res+=pow(x,n-i-1)*cf[i];
    }
    return res;
}

double fp(vector<double>&cf,double x){
    double res=0;
    int n=cf.size();
    for(int i=0;i<n-1;i++){
        res+=(n-i-1)*pow(x,n-i-2)*cf[i];
    }
    return res;
}

double xmax(vector<double>&cf){
    int n=cf.size();
    double xm=0;
    for(int i=1;i<n;i++){
        xm=max(xm,abs(cf[i]/cf[0]));
    }
    return 1+xm;
}

int main(){
    int d;
    cin>>d;
    vector<double>cf(d+1,0);
    for(int i=0;i<=d;i++){
        cin>>cf[i];
    }

    double X=xmax(cf);
    vector<pair<double,double>>ranges;

    for(double i=-X;i<=X;i+=.45){
        if(f(cf,i)*f(cf,i+.45) < 0){
            ranges.push_back({i,i+.45});
        }
    }
   

    for(auto r : ranges){
         double x0=r.first;
         double xn=0;

         do{
            xn=x0-(f(cf,x0)/fp(cf,x0));
            if(abs(x0-xn)<0.0001)break;
            x0=xn;
            

         }while(true);
         cout<<x0<<endl;
    }
    
}