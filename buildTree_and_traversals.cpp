#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node (int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};
Node* buildtree()
{ 
    int data;
    cout<<"Enter data : ";
    cin>>data;
    cout<<endl;
    if(data==-1)
    return NULL;

    Node* root = new Node (data);

    cout<<"Enter data for left part of "<<data<<" node"<<endl;
    root->left=buildtree();

    cout<<"Enter data for right part of "<<data<<" node ";
    root->right=buildtree();

    return root;


}

void levelorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" , ";
        if(temp->left)
        {q.push(temp->left);}
        if(temp->right)
        {q.push(temp->right);}
    }
}
void preordertraversal(Node* root)
{
    if(root==NULL)
    return ;
    else 
    {
    cout<<root->data<<" , ";
    preordertraversal(root->left);
    preordertraversal(root->right);
    }
}
void inordertraversal(Node* root)
{
    if(root==NULL)
    return  ;
    else 
    {
    inordertraversal(root->left);
    cout<<root->data<<" , ";
    inordertraversal(root->right);
    }
}
void postordertraversal(Node* root)
{
    if(root==NULL)
    return ;
    else 
    {
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" , ";
    }
}
int main()
{
    Node* root =NULL;
    cout<<"Enter Data for node and -1 for NULL :-"<<endl;
    root=buildtree();
    cout<<"Tree created"<<endl;
    cout<<"Levelorder traversal :";
    levelorder(root);
    cout<<endl;
    cout<<"Preorder traversal : ";
    preordertraversal(root);
    cout<<endl;
    cout<<"Inorder traversal : ";
    inordertraversal(root);
     cout<<endl;
     cout<<"Postorder traversal : "; 
    postordertraversal(root);
     cout<<endl;

    return 0;
}