#include <iostream>
#include <vector>

using namespace std;

//이진 트리
struct TreeNode {
    int label; //저장할 자료
    //TreeNode* parent;

    TreeNode* rightChildren; //오른쪽 자식
    TreeNode* leftChildren; // 왼쪽 자식
};

void printLabels(TreeNode* root);
void traversal();
TreeNode* findTree(vector<int> preOrder, vector<int> inOrder);

int main(){
    int numOfTest;
    
    //cout << "Enter num of test : ";
    cin >> numOfTest;
    
    for(int i=0; i<numOfTest; i++){
        traversal();
    }
    
    return 0;
}

// 주어진 트리의 각 노드에 저장된 값을 모두 출력하는 함수.
void printLabels(TreeNode* root){
    //루트에 저장된 값을 출력한다.
    if(root->leftChildren != NULL)
        printLabels(root->leftChildren);
    if(root->rightChildren != NULL)
        printLabels(root->rightChildren);
    cout << root->label << " ";
}


void traversal(){
    int numOfNode;
    vector<int> preOrder;
    vector<int> inOrder;
    TreeNode* Tree;
    
    cout << "Enter num of Node : ";
    cin >> numOfNode;
    
    for(int i=0; i<numOfNode; i++){
        int pre_order_num;
        cin >> pre_order_num;
        preOrder.push_back(pre_order_num);
    }
    
    for(int i=0; i<numOfNode; i++){
        int in_order_num;
        cin >> in_order_num;
        inOrder.push_back(in_order_num);
    }
    
    Tree = findTree(preOrder, inOrder);
    
    //cout << "후위 순회 결과 : " << endl;
    printLabels(Tree);
    cout << endl;
    
    free(Tree);
}


TreeNode* findTree(vector<int> preOrder, vector<int> inOrder){
    TreeNode* root;
    
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->leftChildren = NULL;
    root->rightChildren = NULL;
    
    int index;
    
    for(index=0; index < inOrder.size(); index++){
        if(preOrder[0] == inOrder[index]){
            
            vector<int> left_preorder, right_preorder;
            vector<int> left_inorder, right_inorder;
            
            for(int i=1; i<=index; i++){
                left_preorder.push_back(preOrder[i]);
            }
            
            for(int i=index+1; i<preOrder.size(); i++){
                right_preorder.push_back(preOrder[i]);
            }
            
            for(int j=0; j<index; j++){
                left_inorder.push_back(inOrder[j]);
            }
            
            for(int i=index+1; i<inOrder.size(); i++){
                right_inorder.push_back(inOrder[i]);
            }
            
            root->label = preOrder[0];
            if(left_preorder.size()==0 || left_inorder.size()==0)
                root->leftChildren = NULL;
            else
                root->leftChildren = findTree(left_preorder, left_inorder);
            
            if(right_preorder.size()==0 || right_inorder.size()==0)
                root->rightChildren = NULL;
            else
                root->rightChildren = findTree(right_preorder, right_inorder);
            
        }
    }
        
    return root;
}
