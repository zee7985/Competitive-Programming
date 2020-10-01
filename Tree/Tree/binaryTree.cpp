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

int maxDia = 0; //gives diameter

int diameter_03(Node *node)
{ //O(n)-Updating global max
    if (node == NULL)
        return -1;

    int lh = diameter_03(node->left);
    int rh = diameter_03(node->right);

    maxDia = max(maxDia, lh + rh + 2);
    return max(lh, rh) + 1; // return height
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

int nodeToNodeMaxSum(Node *node)
{
    if (node == NULL)
        return 0;

    int leftsum = nodeToNodeMaxSum(node->left);
    int rightsum = nodeToNodeMaxSum(node->right);

    int sideMax = max(leftsum, rightsum) + node->data;
    maxSum = max(max(maxSum, sideMax), max(leftsum + rightsum + node->data, node->data));

    return max(sideMax, node->data);
}

//Leetcode PAthsum 3
// int ans=0;
// void pathSumIII(Node* node, int tar, int prefixSum, map<int,int> mp) {
//         if (node == NULL)
//             return;

//         prefixSum += node->data;

//         if(mp.find(prefixSum - tar)!=mp.end())
//         {
//             ans+=mp[prefixSum - tar];
//         }
//         mp[prefixSum]++;

//         pathSumIII(node->left, tar, prefixSum, mp);
//         pathSumIII(node->right, tar, prefixSum, mp);

//         mp[prefixSum]--;
// }

// view Set.==================================

void lineWiseLevelOrder(Node *node)
{
    queue<Node *> que;
    que.push(node);

    int level = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        cout << "Level: " << level << " -> ";

        while (size-- > 0)
        {
            Node *currNode = que.front();
            que.pop();

            cout << currNode->data << ", ";

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
        }

        level++;
        cout << "\n";
    }
    cout << "\n";
}

void leftView(Node *node)
{
    queue<Node *> que;
    que.push(node);

    while (que.size() != 0)
    {
        int size = que.size();
        cout << que.front()->data << " ";

        while (size-- > 0)
        {
            Node *currNode = que.front();

            que.pop();

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
        }
    }
    cout << "\n";
}


void rightViewI(Node *node)
{
    queue<Node *> que;
    que.push(node);

    while (que.size() != 0)
    {
        int size = que.size();
        cout << que.back()->data << " ";

        while (size-- > 0)
        {
            Node *currNode = que.front();

            que.pop();

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
        }
    }
    cout << "\n";
}

void rightViewII(Node *node)   //Used to print vertical order
{
    queue<Node *> que;
    que.push(node);
    Node*prev=NULL;

    while (que.size() != 0)
    {
        int size = que.size();

        while (size-- > 0)
        {
            Node *currNode = que.front();
            que.pop();

            prev=currNode;

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
            
        }
        cout<<prev->data<<" ";
    }
    cout << "\n";
}

void topView(Node *node)   //Used to print vertical order
{
    queue<Node *> que;
    que.push(node);
    Node*prev=NULL;

    while (que.size() != 0)
    {
        int size = que.size();
        cout << que.front()->data << " ";
        int count=0;   // count to keep check that root node is not printed twice

        while (size-- > 0)
        {
            count++;
            Node *currNode = que.front();
            que.pop();

            prev=currNode;

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
            
        }
        if(count>1)
            cout<<prev->data<<" ";
    }
    cout << "\n";
}

void verticalView(Node* node)
{
    queue<Node*> queN;   // Node
    queue<int> queI;     // Order

    queN.push(node);
    queI.push(0);

    map<int,vector<int>> mp;   // to store all the node corresponding to the vertical order

    while(queN.size()!=0)
    {
        int size=queN.size();

        while(size-->0)
        {
            Node *currNode = queN.front();
            int verticalOrder=queI.front();
            queN.pop();
            queI.pop();


            // if(mp.find(verticalOrder)!=mp.end())
            // {
            //     mp[verticalOrder].push_back(currNode->data);
            // }
            mp[verticalOrder].push_back(currNode->data);

            if (currNode->left != NULL)
            {
                queN.push(currNode->left);
                queI.push(verticalOrder-1);

            }

            if (currNode->right != NULL)
            {
                queN.push(currNode->right);
                queI.push(verticalOrder+1);
            }
        }
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        for (auto a:it->second)
        {
            cout << a << " "; 
        }
        cout<<"\n";
    }
}
void width(Node* node, int level, vector<int> ans) {  // To find range of tree;
        if (node == NULL)
            return;

        ans[0] = min(ans[0], level);
        ans[1] = max(ans[1], level); 

        width(node->left, level - 1, ans);
        width(node->right, level + 1, ans);
}

void verticalView_02(Node* node)
{
    queue<Node*> queN;   // Node
    queue<int> queI;     // Order

    queN.push(node);
    queI.push(0);

    map<int,vector<int>> mp;   // to store all the node corresponding to the vertical order

    while(queN.size()!=0)
    {
        int size=queN.size();

        while(size-->0)
        {
            Node *currNode = queN.front();
            int verticalOrder=queI.front();
            queN.pop();
            queI.pop();


            // if(mp.find(verticalOrder)!=mp.end())
            // {
            //     mp[verticalOrder].push_back(currNode->data);
            // }
            mp[verticalOrder].push_back(currNode->data);

            if (currNode->left != NULL)
            {
                queN.push(currNode->left);
                queI.push(verticalOrder-1);

            }

            if (currNode->right != NULL)
            {
                queN.push(currNode->right);
                queI.push(verticalOrder+1);
            }
        }
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        for (auto a:it->second)
        {
            cout << a << " "; 
        }
        cout<<"\n";
    }
}

void TreeToDoublyLL(Node* curr, Node* &head,Node* &prev)
{
    
    if (curr == NULL)
        return;

  
    TreeToDoublyLL(curr->left, head,prev);

    
    if (prev != NULL)
    {
        // set current node's left child to prev
        curr->left=prev;

        // make prev's right child as curr
        prev->right = curr;
    }
     // if prev is null, then update head of DLL as this is first node in inorder
    else
    {
        head = curr;
     }

    // after current node is visited, update previous pointer to current node
    prev = curr;

    TreeToDoublyLL(curr->right, head,prev);
}


class ItrPair
{
    public:
    Node* node=NULL;
    bool sd=false;
    bool ld=false;
    bool rd=false;

    ItrPair(Node* node)
    {
        this->node=node;
    }
};


void iterorders(Node* node)
{
    stack<ItrPair> s;
    s.push(ItrPair(node));


    while(s.size()!=0)
    {
        //ItrPair pair = s.top();

        if(s.top().sd==false)
        {
            s.top().sd=true;
            cout << s.top().node->data<<" ";
            
        }
        else if(s.top().ld==false)
        {
            s.top().ld=true;
            if(s.top().node->left!=NULL) 
            {
                s.push(ItrPair(s.top().node->left));
            }
        }
        else if(s.top().rd==false)
        {
            s.top().rd=true;
            if(s.top().node->right!=NULL) 
            {
                s.push(ItrPair(s.top().node->right));
            }
        }
        else{
            s.pop();
        }
    }
}


int main()
{
    vector<int> arr = {10, 20, 40, 60, -1, -1, 70, -1, -1, 50, 80, -1, -1, -1, 30, 90, -1, 110, 150, -1, -1, -1, 100, 120, -1, -1, -1};

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

    // nodeToNodeMaxSum(node);
    // cout<<maxSum;

    //=========================================
    //PathSum3

    //     vector<int> arr = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
    //     Node *node = createTree(arr);
    //     map<int, int> mp;
    //     mp[0]++;

    //     pathSumIII(node, 8, 0, mp);
    //     cout << ans << "\n";
    // }

    //=============================================
    //View Set

    //Level Order
    //lineWiseLevelOrder(node);

    //Left View

    //leftView(node);

    //Right View

    //rightViewI(node);
    //rightViewII(node);


    //Top View

    //topView(node);

    //verticalOrder
    //verticalView(node);

     //Tree to Doubly LL
    //  Node* prev=NULL;
    // TreeToDoublyLL(node,node,prev);
    // Node* curr = node;
    // while (curr != NULL)
    // {
    //     cout << curr->data << " ";
    //     curr = curr->right;
    // }

    //display(node);
   iterorders(node);



     

    return 0;
}
