#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

ofstream ofile;

class Tree;

class TreeNode {
    friend class BinaryTree;
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode() { left = NULL; right = NULL; parent = NULL; data = NULL; }
    TreeNode(int val) { left = NULL; right = NULL; parent = NULL; data = val; }

};

class BinaryTree {
public:
    BinaryTree() { root = NULL; }

    void Inorder(TreeNode* current);
    void Preorder(TreeNode* current);
    void Postorder(TreeNode* current);
    void Levelorder();
    void Insert(int val);
    TreeNode* Delete(TreeNode* root, int val);
    TreeNode* FindMin(TreeNode* tmp); // find the minimum number of right subtree;
    bool Search(int val);
    TreeNode* GetRoot() { return root; }; // get private "root" value;
    void Print();
    void Print_del(int val);

private:
    TreeNode* root;
    bool del;
};

void BinaryTree::Insert(int val) { // Seek a proper position for the new_node
    TreeNode* new_node = new TreeNode(val); 
    TreeNode* explorer = NULL;
    TreeNode* follower = NULL;

    explorer = root;

    while (explorer != NULL) {
        follower = explorer;
        if (explorer->data > new_node->data) 
        {
            explorer = explorer->left;
        }
        else if(explorer->data < new_node->data)
        {
            explorer = explorer->right;
        }
        else
        {
            cout << "Error! Number " << new_node->data << " exists." << endl;
            ofile << "Error! Number " << new_node->data << " exists." << endl;
            return;
        }
    }

    new_node->parent = follower;

    if (follower == NULL) 
    {
        this->root = new_node;
    }
    else if (new_node->data > follower->data) 
    {
        follower->right = new_node;
    }
    else
    {
        follower->left = new_node;
    }
    cout << "Number " << new_node->data << " is inserted." << endl;
    ofile << "Number " << new_node->data << " is inserted." << endl;
}

TreeNode* BinaryTree::Delete(TreeNode* root, int val) {
 
    if (root == NULL) {
        del = false;
        return NULL;
    }
    else
    {
        del = true;
    }

    if (val > root->data) 
    {
        root->right = Delete(root->right, val);
    }
    else if (val < root->data) 
    {
        root->left = Delete(root->left, val);
    }
    else // Determine which case to implement.
    {
        if (root->left == NULL && root->right == NULL) // node with no child
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) // node with one right child
        {
            root = root->right;
        }
        else if (root->right == NULL) // node with one left child
        {
            root = root->left;
        }
        else // node with two children
        {
            TreeNode* tmp = new TreeNode();
            tmp = FindMin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    
    return root;
}

void BinaryTree::Print_del(int val) {
    if (this->del) {
    	cout << "Number " << val << " is deleted." << endl;
    	ofile << "Number " << val << " is deleted." << endl;
	}
    else {
    	cout << "Number " << val << " is not exist." << endl;
    	ofile << "Number " << val << " is not exist." << endl;
	}
}

TreeNode* BinaryTree::FindMin(TreeNode* tmp) {

    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

bool BinaryTree::Search(int val) {

    TreeNode* current = root;
    while (current != NULL) {
        if (current->data > val)
        {
            current = current->left;
        }
        else if (current->data < val)
        {
            current = current->right;
        }
        else if (current->data == val)
        {
            cout << "Bingo! " << val << " is found." << endl;
            ofile << "Bingo! " << val << " is found." << endl;
            return true;
        }
    }
    cout << "Sorry! " << val << " is not found." << endl;
    ofile << "Sorry! " << val << "is not found." << endl;
    return false;
}

void BinaryTree::Preorder(TreeNode* current) {

    if (current != NULL) 
    {
        cout << current->data << " ";
        ofile << current->data << " ";
        Preorder(current->left);
        Preorder(current->right);
    }
    
}

void BinaryTree::Inorder(TreeNode* current) {

    if (current != NULL)
    {
        Inorder(current->left);
        cout << current->data << " ";
        ofile << current->data << " ";
        Inorder(current->right);
    }
    
}


void BinaryTree::Postorder(TreeNode* current) {

    if (current != NULL)
    {
        Postorder(current->left);
        Postorder(current->right);
        cout << current->data << " ";
        ofile << current->data << " ";
    }
    
}

void BinaryTree::Levelorder() {

    if (this->GetRoot() == NULL) return;
    queue<TreeNode*> q;
    q.push(this->GetRoot());

    while (!q.empty()) {
        TreeNode* current = q.front();
        cout << current->data << " ";
        ofile << current->data << " ";
        q.pop();

        if (current->left != NULL) 
        {
            q.push(current->left);
        }
        if (current->right != NULL) 
        {
            q.push(current->right);
        }
    }

}


void BinaryTree::Print() {

    cout << "The Tree in prefix order: ";
    ofile << "The Tree in prefix order: ";
    Preorder(root);
    cout << endl;
    ofile << endl;
    cout << "The Tree in infix order: ";
    ofile << "The Tree in infix order: ";
    Inorder(root);
    cout << endl;
    ofile << endl;
    cout << "The Tree in post order: ";
    ofile << "The Tree in post order: ";
    Postorder(root);
    cout << endl;
    ofile << endl;
    cout << "The Tree in level order: ";
    ofile << "The Tree in level order: ";
    Levelorder();
    cout << endl;
    ofile << endl;
}

int main()
{
    // Variables
    BinaryTree bt;
    char op;
    int val;
    string fileName;    
    
    // Console output
    cout << "Enter file name: ";
    cin >> fileName;
	cout << endl;
	
    // Open file
    ifstream ifile;
    ifile.open(fileName.c_str(), ios::in); // "sample.txt"
    
    ofile.open("output.txt", ios::out);
    
    ofile << "Enter file name: ";
	ofile << fileName << endl << endl;

    while (!ifile.eof()) {

        cout << "(I)nsert a number." << endl;
        cout << "(D)elete a number." << endl;
        cout << "(S)earch a number." << endl;
        cout << "(P)rint 4 kinds of orders." << endl;
        cout << "(E)xit." << endl << endl;
        
        ofile << "(I)nsert a number." << endl;
        ofile << "(D)elete a number." << endl;
        ofile << "(S)earch a number." << endl;
        ofile << "(P)rint 4 kinds of orders." << endl;
        ofile << "(E)xit." << endl << endl;

        ifile >> op;

        if (op == 'i' || op == 'I') 
        {
            cout << "Insert:" << endl;
            ofile << "Insert:" << endl;
            
            while (ifile >> val) {
                if (val != -1)
                    bt.Insert(val);
                else break;
            }
        }
        else if (op == 'd' || op == 'D') 
        {
            cout << "Delete:" << endl;
            ofile << "Delete:" << endl;
            
            while (ifile >> val) {
                if (val != -1){
                	bt.Delete(bt.GetRoot(), val);
                	bt.Print_del(val);
				}
                else break;
            }
        }
        else if (op == 's' || op == 'S') 
        {
            cout << "Search:" << endl;
            ofile << "Search:" << endl;
            
            while (ifile >> val) {
                if (val != -1)
                    bt.Search(val);
                else break;
            }
        }
        else if(op == 'p' || op == 'P') 
        {
            cout << "Print:" << endl;
            ofile << "Print:" << endl;
            
            bt.Print();
        }
        else if(op == 'e' || op == 'E')
        {
            cout << "Exit" << endl;
            ofile << "Exit" << endl;
            
            ifile.close();
            return 0;
        }
        cout << endl;
        ofile << endl;
    }
    
    return 0;
}

