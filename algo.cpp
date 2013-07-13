#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "stack"
using namespace std;


class TreeNode{
private:
    int v;
    TreeNode* _left, *_right;
public:
    TreeNode(int v): v(v){}
    TreeNode* inorder();
    TreeNode*& left(){
        return _left;
    }
    TreeNode*& right()
    {
        return _right;
    }
    
    int value(){ return v;}
};

TreeNode* TreeNode::inorder(){
	TreeNode* p = this;
    stack<TreeNode*> s;
    while(!s.empty() || p)
    {
        while(p){
            s.push(p);
            p = p->left();            
        }
        p = s.top();
        s.pop();
        cout << p->value() << " ";
        p = p->right();
    }
}


int main()
{
    TreeNode* head = new TreeNode(1);
    head->left() = new TreeNode(2);
    head->right() = new TreeNode(3);
    head->left() ->left() = new TreeNode(4);
    head->right() -> right() = new TreeNode(5);
    head->left() -> right() = new TreeNode(6);
    head->right() -> left() = new TreeNode(7);
    head->left() ->right() -> left() = new TreeNode(8);
    head->right() -> left() -> left() = new TreeNode(9);
    head->right() -> left() -> left() -> left() = new TreeNode(10);
    head->right() -> left() -> left() -> left() -> right() = new TreeNode(11);
    head->inorder();
    return 0;
}
