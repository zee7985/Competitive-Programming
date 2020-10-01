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

Node* ConstructBST(vector<int> arr, int s, int e) {
        if (s > e)
            return NULL;

        int mid = (s + e) >> 1;
        Node* node = new Node(arr[mid]);

        node->left = ConstructBST(arr, s, mid - 1);
        node->right = ConstructBST(arr, mid + 1, e);

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

bool findInBST(Node* node, int data) {
        while (node != NULL) {
            if (node->data == data) {
                return true;
            } else if (data < node->data) {
                node = node->left;
            } else
                node = node->right;
        }

    return false;
}

class myPair 
{
    int size = 0;
    int height = 0;
    bool find = false;

    int ceil = INT_MAX;
    int floor = INT_MIN;

    Node* pred = NULL;
    Node* succ = NULL;
    Node* prev = NULL;

};

void allSolution(Node* node, int level, int data, myPair &p) 
    {
        if (node == NULL)
            return;

        p.height = max(p.height, level);
        p.size++;
        p.find = p.find || node->data == data;

        if (node->data < data) {
            p.floor = max(p.floor, node->data);
        }

        if (data < node->data)
            p.ceil = min(p.ceil, node->data);

        if (node->data == data && p.pred == NULL) {
            p.pred = p.prev;
        }

        if (p.prev != NULL && prev->data == data && p.succ == NULL) {
            p.succ = node;
        }

        p.prev = node;

        allSolution(node->left, level + 1, data, p);
        allSolution(node->right, level + 1, data, p);
    }


int main()
{
    vector<int>arr{2,6,10,25,36,37,39,40,52,68,72};

    Node* node=ConstructBST(arr,0,arr.size()-1);
    //display(node);

    // cout<<findInBST(node,36);

    myPair p;
    

    return 0;
}