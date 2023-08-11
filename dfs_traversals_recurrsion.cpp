#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *lchild, *rchild;

    Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

struct Node *root = NULL;

void create_tree(vector<int> vec){

    queue <Node*> q;
    struct Node *p, *t;
    root = new Node(vec[0]);
    q.push(root);
    int i = 1;

    while(!q.empty() && i < vec.size()) {
        p = q.front();
        q.pop();

        if(i < vec.size() && vec[i] != -1){
            t = new Node(vec[i]);
            q.push(t);
            p->lchild = t;
        }
        i++;

        if(i < vec.size() && vec[i] != -1){
            t = new Node(vec[i]);
            q.push(t);
            p->rchild = t;
        }
        i++;
    }
}

vector<int> preorder(struct Node * ptr) {
    vector<int> pre;

    if(ptr){
        pre.push_back(ptr->data);
        vector<int> leftSubtree = preorder(ptr->lchild);
        pre.insert(pre.end(), leftSubtree.begin(), leftSubtree.end());
        vector<int> rightSubtree = preorder(ptr->rchild);
        pre.insert(pre.end(), rightSubtree.begin(), rightSubtree.end());
    }
    return pre;
}

vector<int> inorder(struct Node * ptr) {
    vector<int> in;

    if(ptr) {
        vector<int> leftSubtree = inorder(ptr->lchild);
        in.insert(in.end(), leftSubtree.begin(), leftSubtree.end());
        in.push_back(ptr->data);
        vector<int> rightSubtree = inorder(ptr->rchild);
        in.insert(in.end(), rightSubtree.begin(), rightSubtree.end());
    }
    return in;
}

vector<int> postorder(struct Node * ptr) {
    vector<int> post;

    if(ptr) {
        vector<int> leftSubtree = postorder(ptr->lchild);
        post.insert(post.end(), leftSubtree.begin(), leftSubtree.end());
        vector<int> rightSubtree = postorder(ptr->rchild);
        post.insert(post.end(), rightSubtree.begin(), rightSubtree.end());
        post.push_back(ptr->data);
    }
    return post;
}

int main() {
    
    vector<int> vec = {10, 50, 100, 150, 200, 500};
    create_tree(vec);
    vector<int> ans = inorder(root);
//  vector<int> ans = preorder(root);
//  vector<int> ans = postorder(root);
    for(auto x : ans) {
        cout<<x<<" ";
    }

    return 0;
}