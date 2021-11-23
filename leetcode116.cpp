/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL)
            return NULL;
        
        Node* ans = new Node();
        
        queue<Node*> q;
        q.push(root);
        
        auto it = ans;
        while(!q.empty()){
            
            int size =q.size();
            auto it = q.front();
            for(int i=0;i<size;i++){//每一層

                Node* node = q.front();
                q.pop();

                
                if(node->left!=NULL){
                    q.push(node->left);
                    q.push(node->right);
                }
                
                //cout << node->val << endl;
                
                if(it==root){
                    //cout << it->val << endl;
                    it->next = NULL;
                }
                else{
                    //cout << it->val << endl;
                    if(i==size-1)
                        it->next = NULL;
                    else{
                        it->next = q.front();
                        it = it->next;
                    }
                    
                }
                
            }
           
        }
        
        
        return root;
    }
};
