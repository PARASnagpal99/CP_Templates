class BSTIterator{
private :
    stack<Node*>stk ;
    void push(Node* root){
         while(root){
             stk.push(root);
             root = root->left ;
         }
    }
public :
    BSTIterator(Node* root){
        push(root);
    }
  
    int next(){
        Node* curr = stk.top() ;
        stk.pop() ;
        push(curr->right);
        return curr->val ;
    }
  
    int hasNext(){
        return (stk.size() == 0 ? false : true) ;
    }
    
};
