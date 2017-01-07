#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> Rank,leader;
void make_set(int x)
{
    leader.push_back(x);
    Rank.push_back(0);
}
int Find(int x){
    int temp;
    while(leader[x]!=x)
        x = leader[x];
    return x;
}
void Union(int x, int y)
{
    int s1=Find(x),s2=Find(y);
    if(Rank[s1]>Rank[s2])
        leader[s2] = s1;
    else if(Rank[s1]<Rank[s2])
        leader[s1] = s2;
    else
    {
        leader[s1] =s2;
        Rank[s2] += 1;
    }
}
int main(){
    int nsize,k;
    long int dist=0;
    Rank.push_back(0);
    leader.push_back(0);
    cin>>nsize;
    k = nsize;
    priority_queue<pair<int,pair<int, int>>, vector< pair<int,pair<int, int>> >, greater< pair<int,pair<int, int>> > > pq;
    for(long int i=1;i<=nsize;i++)
        make_set(i);
    for(long int i=0;i<nsize*(nsize-1)/2 ; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        pq.push({z,{x,y}});
    }
    while(k!=3)
    {
        if(Find(pq.top().second.first) != Find(pq.top().second.second))
        {
            k--;
            if(k==3)
                dist = pq.top().first;
            Union(pq.top().second.first, pq.top().second.second);
        }
        pq.pop();
    }
    cout<<dist;
    return 0;
}
