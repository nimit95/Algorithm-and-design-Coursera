#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
priority_queue< tuple<double,int,int> > pq;
int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int w,l;
        cin >> w >>l ;
        pq.push(make_tuple(w- l ,w,l));    //push in pq
    }
    long long int ctime = 0;
    long double wsum = 0  ;
    while(!pq.empty())
    {
        cout<<get<0>(pq.top())<<get<1>(pq.top())<<endl;
        ctime = ctime + get<2>(pq.top());         
        wsum = wsum + ctime * get<1>(pq.top());
        pq.pop();
    }
    cout<<(long long int)wsum ;
    return 0;
}
