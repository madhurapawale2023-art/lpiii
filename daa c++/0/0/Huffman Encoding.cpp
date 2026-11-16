#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int f;
    Node *l, *r;
    Node(char c,int x) {
        ch=c; f=x; l=r=NULL;
    }
};

int main() {
    int n;
    char c;
    int f;
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> q;

    cout<<"Enter number of characters: ";
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>c>>f;
        q.push({f,new Node(c,f)});
    }

    while(q.size()>1) {
        Node *a=q.top().second; q.pop();
        Node *b=q.top().second; q.pop();
        Node *p=new Node('$',a->f+b->f);
        p->l=a; p->r=b;
        q.push({p->f,p});
    }

    cout<<"Huffman Tree Created Successfully!";
}
//ouput-
//Enter number of characters: 4
//A 5
//B 9
//C 12
//D 13