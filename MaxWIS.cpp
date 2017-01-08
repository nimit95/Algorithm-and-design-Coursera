//Maximum Weight independent Set
#include<iostream>
#include<vector>
using namespace std;
vector<long int> w,a;
long int maxi(long int x, long int y)
{
    return x>y?x:y;
}
void reconstruction(vector<long int> a)
{
    int i = a.size();
    while(i>=1)
    {
        if(a[i-1]>a[i-2] + w[i])
            i--;
        else{
            if(i==1 || i==2 || i==3 || i==4 || i==17 || i== 117 ||i== 517 || i== 997)
                cout<<i<<" ";
            i= i - 2;
        }
    }
}
int main()
{
    w.push_back(0);
    long int vert;
    cin>>vert;
    while(vert--){
        long int weight;
        cin>>weight;
        w.push_back(weight);
    }
    a.push_back(0);
    a.push_back(w[1]);
    for(int i=2;i<w.size();i++){
        a.push_back( maxi(a[i-1],a[i-2] + w[i]));
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<endl;
    reconstruction(a);
    return 0;
}
