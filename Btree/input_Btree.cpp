# include<iostream>
# include<vector>
# include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};
vector<int> creatVector(){
    cout << "input Vector elements" << endl;
    vector<int> input;
    char c;
    int temp;
    cin >> temp;
    input.push_back(temp);
    while((c = getchar()) != '\n'){
        cin >> temp;
        input.push_back(temp);
    }
    return input;
}
TreeNode* creatBTree(){
    vector<int> data = creatVector();
    int n = 0;
    TreeNode* root = new TreeNode(data[n++]);
    while(n != data.size()){
        TreeNode* currentTree = root;
        TreeNode* backTree = currentTree;
        int tempValue = data[n++];
        while(currentTree){
            backTree = currentTree;
            if(currentTree -> val > tempValue){
                currentTree = currentTree -> left;
            }
            else{
                currentTree = currentTree -> right;
            }
        }
        if(backTree -> val > tempValue){
            backTree -> left = new TreeNode(tempValue);
        }
        else{
            backTree -> right = new TreeNode(tempValue);
        }
    }
    return root;
}
TreeNode* creatOrderBTree(){
	TreeNode* root = new TreeNode();
	vector<int> input = creatVector();
	queue<TreeNode*> tempQueue;
	int n = 0;
	int val = input[n++];
	if (val == -1) {
		return nullptr;
	}
	else {
		root->val = val;
		tempQueue.push(root);
	}
	while (!tempQueue.empty()) {
		TreeNode* temp = tempQueue.front();
		tempQueue.pop();
		val = input[n++];
		if (val == -1) {
			temp->left == nullptr;
		}
		else {
			temp->left = new TreeNode(val);
			tempQueue.push(temp->left);
		}
		val = input[n++];
		if (val == -1) {
			temp->right == nullptr;
		}
		else {
			temp->right = new TreeNode(val);
			tempQueue.push(temp->right);
		}
	}
	return root;
}
void preOrder(TreeNode* root){
    if (root == nullptr){
        return;
    }
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right); 
}

void inOrder(TreeNode* root){
    if (root == nullptr){
        return;
    }
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right); 
}

void postOrder(TreeNode* root){
    if (root == nullptr){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right); 
    cout << root -> val << " ";
}
void showOrderBTree(TreeNode* root){
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* temp = Q.front();
        Q.pop();
        cout << temp -> val << " ";
        if (temp -> left){
            Q.push(temp -> left);
        }
        if (temp -> right){
            Q.push(temp -> right);
        }
    }
}

void showBTree(TreeNode *root){
    cout << "preOrder result: " << endl;
    preOrder(root);
    cout << endl;
    cout << "inOrder result: " << endl;
    inOrder(root);
    cout << endl;
    cout << "postOrder result: " << endl;
    postOrder(root);
    cout << endl;
    cout << "Order result: " << endl;
    showOrderBTree(root);
    cout << endl;
    cout << "------------------------------------------------------------------" << endl;
}
int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
}
int main(){
    // TreeNode* root1 = creatOrderBTree();
    // cout << "Tree1 maxDepth: " << maxDepth(root1) << endl;
    // showBTree(root1);
    TreeNode* root2 = creatBTree();
    cout << "Tree2 maxDepth: " << maxDepth(root2) << endl;
    showBTree(root2);
}