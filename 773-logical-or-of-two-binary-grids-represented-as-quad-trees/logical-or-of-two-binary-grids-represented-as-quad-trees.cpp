/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
// Node* f(vector<vector<int>>& grid,int n,int i,int j){
//     if(n==1) return new Node(grid[i][j],true);
//     Node* root=new Node();
//     int s=n/2;
//     Node* tl=f(grid,s,i,j);
//     Node* tr=f(grid,s,i,j+s);
//     Node* dl=f(grid,s,i+s,j);
//     Node* dr=f(grid,s,i+s,j+s);
//     if(tl->isLeaf &&  tr->isLeaf &&  dl->isLeaf &&  dr->isLeaf && tl->val==tr->val && dl->val==tr->val && dr->val==tl->val){
//         root->val=tl->val;
//         root->isLeaf=true;
//     }
//     else{
//        root->topLeft=tl;
//        root->topRight=tr; 
//        root->bottomLeft=dl;
//        root->bottomRight=dr;
//     }
//     return root;

// }

    Node* intersect(Node* q1, Node* q2) {
        if(q1->isLeaf && q2->isLeaf){
            if(q1->val==q2->val) return q1;
            else return new Node(1,1);
        }
        if(q1->isLeaf || q2->isLeaf){
            if(q1->isLeaf){
                if(q1->val==1) return q1;
                else return q2;
            }
            if(q2->isLeaf){
                if(q2->val==1) return q2;
                else return q1;
            }
        }
        Node* root=new Node();
        Node* tl=intersect(q1->topLeft,q2->topLeft);
        Node* tr=intersect(q1->topRight,q2->topRight);
        Node* dl=intersect(q1->bottomLeft,q2->bottomLeft);
        Node* dr=intersect(q1->bottomRight,q2->bottomRight);
        if(tl->isLeaf &&  tr->isLeaf &&  dl->isLeaf &&  dr->isLeaf && tl->val==tr->val && dl->val==tr->val && dr->val==tl->val){
            root->val=tl->val;
            root->isLeaf=true;
        }
        else{
        root->topLeft=tl;
        root->topRight=tr; 
        root->bottomLeft=dl;
        root->bottomRight=dr;
        }
        return root;
    }
};