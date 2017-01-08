//Finding minimum length of symbol in huffman tree
#include<iostream>
#include<queue>
#include<algorithm>
struct TreeNode{                      //Node of a tree
    long int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):data(x),left(NULL),right(NULL) {}
}*temp = NULL;
using namespace std;
vector<long int> lengh;
int maxlength(TreeNode *temp, int x)
{
    if(temp->right == NULL && temp->left==NULL ){
        lengh.push_back(x);
        return x;
    }
    x++;
    maxlength(temp->left,x);
    maxlength(temp->right,x);
}
int main()
{
    long int ssize,input;
    cin>>ssize;
    priority_queue<pair<long int, TreeNode*>, vector<pair<long int, TreeNode*>>, greater<pair<long int, TreeNode*>>> pq;
    while(ssize--){
        cin>>input;
        pq.push({input,new TreeNode(input)});    // inserting into priority queue
    }
    while(pq.size()!=1)
    {
        int tdata = pq.top().first;
        temp = new TreeNode(tdata);
        temp->left = pq.top().second;
        pq.pop();
        temp -> data = temp-> data + pq.top().first ;
        temp -> right = pq.top().second ;
        //cout<< temp->data<<" ";
        pq.pop();
        pq.push({temp->data, temp});
    }
    cout<<temp->data;
    maxlength(temp,0);
    cout<<endl<<*min_element(lengh.begin(), lengh.end());    //min length
    return 0;
}
