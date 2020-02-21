#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *left = NULL;
    Node *right = NULL;

    Node()
    {
    }

    Node(int data)
    {
        this->data = data;
    }

    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int idx = 0;

Node *createTree(vector<int> arr)
{
    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return NULL;
    }

    Node *node = new Node(arr[idx]);
    idx++;

    node->left = createTree(arr);
    node->right = createTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == NULL)
        return;
    string ans = "";
    ans += node->left != NULL ? to_string(node->left->data) : "->";
    ans += " -> " + to_string(node->data) + " <- ";
    ans += node->right != NULL ? to_string(node->right->data) : "->";
    cout << ans << endl;

    display(node->left);
    display(node->right);
}

bool findData(Node *node, int data)
{
    if (node == NULL)
        return false;
    if (node->data == data)
        return true;

    bool res = false;
    res = res || findData(node->left, data);
    res = res || findData(node->right, data);

    return res;

    // bool left = findData(node->left, data);
    // if (left == true)
    //     return left;

    // bool right = findData(node->right, data);
    // if (right == true)
    //     return right;

    // return false;
}

int size(Node *node)
{
    return node == NULL ? 0 : size(node->left) + size(node->right) + 1;
}
int height(Node *node)
{
    return node == NULL ? -1 : max(height(node->left), height(node->right)) + 1;
}

vector<Node*> nodeToRootPath(Node* node, int data)
{
    if (node == NULL)
        return {};

    if (node->data == data)
    {
        vector<Node*> base;
        base.push_back(node);
        return base;
    }

    vector<Node*> left = nodeToRootPath(node->left, data);
    if (left.size() != 0)
    {
        left.push_back(node);
        return left;
    }

    vector<Node*> right = nodeToRootPath(node->right, data);
    if (right.size() != 0)
    {
        right.push_back(node);
        return right;
    }

    return {};
}

Node *LCA_01(Node *node, int data1, int data2)
{
    vector<Node*> list1 = nodeToRootPath(node, data1);
    vector<Node*> list2 = nodeToRootPath(node, data2);

    if (list1.size() == 0 || list2.size == 0)
        return {};

    int i = list1.size() - 1;
    int j = list2.size() - 1;
    Node *prev = NULL;

    while (i >= 0 && j >= 0)
    {
        if (list1.get(i)->data != list2.get(j)->data)
            break;

        prev = list1.get(i);
        i--;
        j--;
    }

    return prev;
}

int main()
{
    vector<int> arr = {10, 20, 40, 60, -1, -1, 70, -1, -1, 50, 80, -1, -1, -1, 30, 90, -1, 110, 150, -1, -1, -1, 100,
                       120, -1, -1, -1};

    //Create Tree
    Node *node = createTree(arr);

    //display(node);

    //===================================
    //Find Data
    //cout<<findData(node,130)<<endl;

    //==================================
    //cout<<size(node)<<endl;

    //cout<<height(node)<<endl;

    //==================================
    // vector<Node*> path = nodeToRootPath(node, 80);
    // for(auto i: path){
    //     cout<<i->data<<" ";
    // }

    //=======================================

    // Node* ans=LCA_01(node,20,80);
    // cout<<ans->data;
    //===================================
}