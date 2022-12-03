Class:
	TreeNode -> To construct a node structure. I have a right pointer and a left pointer
		     to point to right and left child, data to store integer value, parent 
		     pointer to point to two child nodes parent.
	BinaryTree -> Some functions and root pointer. Boolean value del just use to check 
		       if the node exists or not. 

Functions in BinaryTree:
	Inorder -> Print nodes in infix way.
	Preorder -> Print nodes in prefix way.
	Postorder -> Print nodes in postfix way.
	Levelorder -> Print nodes in level order way.
	Insert -> Insert nodes into tree.
	Delete -> Delete specific node. If the node doesn't exist, print some message.
	FindMin -> Use in Delete function. To find minimum value in right subtree, and replace
		    the node you want to delete with it.
	Search -> Search specific node. If the node doesn't exist, print some message.
	GetRoot -> Because my root is private, I use this to get root value.
	Print -> Use function Inorder, Preorder, Postorder, Inorder to print value.
	Print_del -> Some message for Delete function.

Detail in some function:
	Insert -> variable new_node is to store the data for the node wanting to insert. And 
		   explorer is to find proper position for new_node, and follower just follow
		   it like a parent. So if the number is exist, the explorer will find. Finally,
		   just let the follower be new_node's parent and determine the node is right 
		   child or left child. Then, print some message.

	Delete -> First, check if the is empty or not, then set del's value. Second, if the 
		   node value is bigger than root, search right subtree, otherwise, search left
		   subtree. Here I uae recursive way to find the node. After finding the node, 
		   check which case we encounter. If there's no child for the node, delete the 
		   node directly. With one child just let the node's parent left or right pointer
		   point to the node's child. The worst case is that the node have two children. 
		   The way I use is to find right subtree's minimum value, and replace the node's
		   value with it. After that, I use the same way (recursion) to delete the duplicate
		   node. Delete completed.

	Search -> Compare node's value with root's or parent's value until reach leaf node.

In main function:
	Variable:
		bt is use to implement function in class Binarytree.
		op is to store type of operation.
		val is to store the value of node.
		fileName is to store specific file name.