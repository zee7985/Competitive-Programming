#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data = 0;
    vector<Node*> childs;

    Node(int data)
    {
        this->data = data;
    }
};

int size(Node *root)
{
    int s = 0;

    for (Node *child : root->childs)
    {

        s += size(child);
    }
    return s + 1;
}

int height(Node *root)
{
    int h = -1;

    for (Node *child : root->childs)
    {

        h = max(h, height(child));
    }
    return h + 1;
}

bool findData(Node *root, int data)
{
    if (root->data == data)
    {
        return true;
    }

    bool res = false;
    for (Node *child : root->childs)
    {
        res = res || findData(child, data);
    }
    return res;
}

Node *createTree(vector<int> arr)
{
    stack<Node*> st;

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] = -1)
        {
            Node *node = st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
        else
        {
            st.push(new Node(arr[i]));
        }
    }
    return st.top();
}

void display(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data;

    for (Node *child : root->childs)
    {
        cout<<child->data<<",";
    }
    cout<<endl;

    for (Node *child : root->childs)
    {
        display(child);
    }
}

vector<Node *> nodeToRootPath(Node *node, int data)
{
    if (node == NULL)
        return {};

    if (node->data == data)
    {
        vector<Node *> base;
        base.push_back(node);
        return base;
    }

    for (Node *child : node->childs)
    {
        vector<Node *> child_ = nodeToRootPath(child, data);
        if (child_.size() != 0)
        {
            child_.push_back(node);
            return child_;
        }
    }
    return {};
}

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -140, 100, -1, -1, -1};
    Node *node = createTree(arr);
    display(node);
}