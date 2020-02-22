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

    vector<Node *> left = nodeToRootPath(node->left, data);
    if (left.size() != 0)
    {
        left.push_back(node);
        return left;
    }

    vector<Node *> right = nodeToRootPath(node->right, data);
    if (right.size() != 0)
    {
        right.push_back(node);
        return right;
    }

    return {};
}

Node *LCA_01(Node *node, int data1, int data2)
{
    vector<Node *> list1 = nodeToRootPath(node, data1);
    vector<Node *> list2 = nodeToRootPath(node, data2);

    if (list1.size() == 0 || list2.size() == 0)
        return {};

    int i = list1.size() - 1;
    int j = list2.size() - 1;
    Node *prev = NULL;

    while (i >= 0 && j >= 0)
    {
        if (list1[i]->data != list2[j]->data) // starting from parent -if data in the lists do not match
            break;                            // then break the loop because we cant find the common node after this

        prev = list1[i]; //Update prev every time data in both the list match until unmatched data comes
        i--;
        j--;
    }

    return prev;
}

int diameter_01(Node *node)
{
    //O(n ^ 2)
    if (node == NULL)
        return 0;

    int ld = diameter_01(node->left);
    int rd = diameter_01(node->right);

    int lh = height(node->left);
    int rh = height(node->right);

    return max(max(ld, rd), lh + rh + 2);
}

vector<int> diameter_02(Node *node)
{ //O(n)
    if (node == NULL)
    {
        vector<int> base{0, -1}; // 0-Diameter and 1 -height
        return base;
    }

    vector<int> ld = diameter_02(node->left);
    vector<int> rd = diameter_02(node->right);

    vector<int> ans(2);

    ans[0] = max(max(ld[0], rd[0]), ld[1] + rd[1] + 2);
    ans[1] = max(ld[1], rd[1]) + 1;

    return ans;
}

int maxDia = 0;  //gives diameter

int diameter_03(Node *node)
{ //O(n)-Updating global max
    if (node == NULL)
        return -1;

    int lh = diameter_03(node->left);
    int rh = diameter_03(node->right);

    maxDia = max(maxDia, lh + rh + 2);
    return max(lh, rh) + 1;    // return height
}

int maxSum = (int)-1e7;

int leafToLeafMaxSum(Node *node)
{
    if (node == NULL)
        return (int)-1e7;

    if (node->left == NULL && node->right == NULL)
        return node->data;

    int leftsum = leafToLeafMaxSum(node->left);
    int rightsum = leafToLeafMaxSum(node->right);
    if (node->left != NULL && node->right != NULL)
        maxSum = max(maxSum, leftsum + rightsum + node->data);

    return (node->left == NULL ? rightsum : node->right == NULL ? leftsum : max(leftsum, rightsum)) + node->data;
}

int maxSum=0;
 int nodeToNodeMaxSum(Node* node) {
        if (node == NULL)
            return 0;

        int leftsum = nodeToNodeMaxSum(node->left);
        int rightsum = nodeToNodeMaxSum(node->right);
        
        int sideMax = max(leftsum, rightsum) + node->data;
        maxSum = max(max(maxSum, sideMax), max(leftsum + rightsum + node->data, node->data));

        return max(sideMax, node->data);
    }

int main()
{
    vector<int> arr = {10, 20, 40, 60, -1, -1, 70, -1, -1, 50, 80, -1, -1, -1, 30, 90, -1, 110, 150, -1, -1, -1, 100,120, -1, -1, -1};

    //vector<int> arr = {-15,5,-8,2,-1,-1,6,-1,-1,1,-1,-1,6,3,-1,-1,9,-1,0,4,-1,-1,-1,10,-1,-1,-1};
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

    // cout<<diameter_01(node)<<endl;

    // vector<int> ans=diameter_02(node);
    // cout<<ans[0];     //0th index for diameter,1st index for height

    // diameter_03(node);    //returns height
    // cout<<maxDia;          // cout maxDia to get diameter

    //======================================

    // leafToLeafMaxSum(node);
    // cout<<maxSum;                        // gives laf to leafSum

    //=======================================


}
