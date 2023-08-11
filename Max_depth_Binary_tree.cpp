#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * lchild;
    struct Node * rchild;

    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

struct Node * root = NULL;
void create_tree(queue <Node*> &q, vector <int> vec) {
    struct Node *p, *t;
    root = new Node(vec[0]);
    q.push(root);
    int i = 1;

    while(!q.empty() && i < vec.size()){

        // Popping out the last node to assign it's left and right child!
        p = q.front();
        q.pop();

        // lchild:
        if(i < vec.size() && vec[i] != -1){
            t = new Node(vec[i]);
            p->lchild = t;
            q.push(t);
        }
        i++;
        // rchild:
        if(i < vec.size() && vec[i] != -1){
            t = new Node(vec[i]);
            p->rchild = t;
            q.push(t);
        }
        i++;
    }
}


vector<int> preorder(struct Node * ptr) {
    vector<int> vec;
    if(ptr) {
       vec.push_back(ptr->data);
       vector<int> leftSubtree = preorder(ptr->lchild);
       vec.insert(vec.end(), leftSubtree.begin(), leftSubtree.end());
       vector<int> rightSubtree = preorder(ptr->rchild);
       vec.insert(vec.end(), rightSubtree.begin(), rightSubtree.end());
    }
    return vec;
}


//Function to find the maximum height of the binary tree: 
 
int depth(struct Node* ptr) {
    if(ptr == NULL){
        return 0;
    }
    int lh = depth(ptr->lchild);
    int rh = depth(ptr->rchild);

    return 1 + max(lh, rh);
}

int main() {
    
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,-1,13,14,-1};
    queue <Node *> q;
    create_tree(q,vec);
    vector<int> pre = preorder(root);

    for(auto x : pre){
        cout<<x<<" ";
    }
    cout<<endl;
    int ans = depth(root);
    cout<<"The height of this binary tree is: "<<ans;
    return 0;
}