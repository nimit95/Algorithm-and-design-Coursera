#include<iostream>
#include<fstream>
#include <sstream>
#include<vector>
#include<stdlib.h>
#include<queue>
#include <algorithm>
#include<ctime>
using namespace std;
vector< vector< pair<int,int> > > graph(200);
priority_queue< pair<long int,int>, vector < pair<long int,int> > , greater< pair<long int,int> > > pq;
vector<long int> weight(200);
int main()
{
    ifstream fin;
    fin.open("dijkstraData.txt");
    int initial=1,vertice;
    char ch[300];
    string s;
    while(!fin.eof())
    {
        fin.getline(ch,300,'\n');
        stringstream stream(ch);
        while(1)
        {
            int n,z;
            char seperator;
            if (initial==1)
                stream>>n;
            else
                stream >> n>>seperator>>z;
            if(!stream){
                initial=1;
                break;
            }
            if(initial==1){
                    initial++;
                    vertice=n;
                    weight.at(vertice-1)=100000;
                   // pq.push(make_pair(100000,vertice-1));
                  // cout<<weight.at(vertice-1);
            }
            else{
                graph[vertice-1].push_back(make_pair(n,z));
                cout<<n<<","<<z<<" ";
            }
        }
        cout<<endl;
    }
    weight.at(0)=0;
    //cout<<weight.at(1);
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int ver=pq.top().second;
        //cout<<ver;
        int tempweight=pq.top().first;
        //cout<<tempweight;
        //int weight(ver-1)=pq.top().second;
        for(int i=0;i<graph[ver-1].size();i++)
        {   //cout<<graph[ver-1].at(i).second<<"   "<<weight.at(ver-1);
            int tempv=graph[ver-1].at(i).first;
            if(weight.at(tempv-1)>tempweight + graph[ver-1].at(i).second){
                   // cout<<i;
                pq.push(make_pair(tempweight + graph[ver-1].at(i).second,graph[ver-1].at(i).first));
                weight.at(tempv-1)=tempweight+ graph[ver-1].at(i).second;
               // cout<<tempv<<"-"<<weight.at(tempv-1)<<" ";
            }
        }

        pq.pop();
    }
    for(int i=1;i<weight.size();i++)
        if(i==7||i==37||i==59||i==82||i==99||i==115||i==133||i==165||i==188||i==197)
            cout<<weight.at(i-1)<<",";
}
