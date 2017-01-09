/*
Knapsack top down Approach
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<long int> w,v;
map<pair<long int, long int>, long int> mymap;
long int maxm(long int x, long int y)
{
    return x>y?x:y;
}
long int knapsack(long int n, long int weight){
    if(mymap[{n, weight}]!=0){
        //cout<<"this";
        return mymap[{n, weight}];
    }
    if(weight<=0||n<=0)
        return 0;
    else if(weight<w[n])
        return knapsack(n-1, weight);
    //cout<<weight<<" ";
    long int x= maxm(knapsack(n-1,weight), (v[n] + knapsack(n-1, weight- w[n])));
    mymap[{n,weight}]=x;
    return x;
}
int main()
{
    long int n, maxw;
    cin>>maxw>>n;
    v.push_back(0);
    w.push_back(0);
    for(long int i=0;i<n;i++)
    {
        long int x,y;
        cin>>x>>y;
        v.push_back(x);
        w.push_back(y);
    }
    cout<<knapsack(n, maxw);
    return 0;
}
