//Kapsack Problem using bottom up approach
#include<iostream>
#include<queue>
using namespace std;
int main(){
    long int n,m,maxw=0;
    cin>>maxw>>n;
    vector<long int> v(n+1), w(n+1);
    vector<vector<long int>> c(n+1, vector<long int>(maxw+1));
    long int i;
    for(i =0;i<n;i++)
       {
        cin>>v[i];
             cin>>w[i];
    }
    cout<<"hello";
    for(long int i=0;i<=maxw;i++)
        c[0][i]=0;
      for(long int i=0;i<=n;i++)
        c[i][0]=0;
    for(long int i=1;i<=n;i++)
    {
        for(long int j= 1;j<=maxw;j++)
        {
            if(w[i-1]>j)
                c[i][j]=c[i-1][j];
            else{
                if(v[i-1]+c[i-1][j-w[i-1]]>c[i-1][j])
                    c[i][j]=v[i-1]+c[i-1][j-w[i-1]];
                else
                    c[i][j]=c[i-1][j];
            }
                cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"Answer is"<<c[n][maxw];
}
