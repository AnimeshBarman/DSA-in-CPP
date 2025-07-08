#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Practice Question1: Function to calculate the sum of all nodes..
Node *buildTree(vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *curr = q.front();
        q.pop();
        if (i < arr.size())
        {
            curr->left = new Node(arr[i++]);
            q.push(curr->left);
            curr->right = new Node(arr[i++]);
            q.push(curr->right);
        }
    }
    return root;
}

int sumOfNodes(Node *root)
{
    if (!root)
        return 0;

    int total = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        total += curr->data;
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return total;
}


// Print the left view of a tree
int max_level_visited = 0;
void print_left_view(Node *node, int curr_level) { 
    if (node == NULL) return; 
    if(max_level_visited < curr_level) { 
        cout << node->data << " "; 
        max_level_visited = curr_level; 
    } 
    print_left_view(node->left, curr_level+1); 
    print_left_view(node->right, curr_level+1); 
} 
void helper_left_view(Node *root){ 
    print_left_view(root, 1); 
} 


// Practice Question2: Print the Right View of a tree..

int maxLevelVisited = 0;
void printRightView(Node* node, int currLevel){
    if(node == NULL) return;
    
    if(maxLevelVisited < currLevel){
        cout<<node->data<<" ";
        maxLevelVisited = currLevel;
    }
    printRightView(node->right, currLevel+1);
    printRightView(node->left, currLevel+1);

}

void helperRightView(Node* root){
    printRightView(root, 1);
}


// LCA-Lowest Common Ancestor

Node* lca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = lca(root->left, n1, n2);
    Node* rightLCA = lca(root->right, n1, n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;

}



int main() { 
    /*
    Node *root=new Node(20); 
    root->left=new Node(70); 
    root->right=new Node(90); 
    root->left->left=new Node(30); 
    root->left->right=new Node(40); 
    root->right->right=new Node(70); 
    helper_left_view(root); 
    */

    /*

    Node *root=new Node(20); 
    root->left=new Node(70); 
    root->right=new Node(90); 
    root->left->left=new Node(30); 
    root->left->right=new Node(40); 
    root->right->right=new Node(70); 
    helperRightView(root);

    */


    /*
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    Node* root = buildTree(arr);
    cout<<sumOfNodes(root)<<endl;
    */


    Node *root=new Node(20); 
    root->left=new Node(70); 
    root->right=new Node(90); 
    root->left->left=new Node(30); 
    root->left->right=new Node(40); 
    root->right->right=new Node(70); 

    Node* ans = lca(root, 30, 40);

    if(ans)
        cout<<"The LCA is: "<<ans->data<<endl;
     else 
        cout<<"LCA not found!.."<<endl;

    return 0;
}


