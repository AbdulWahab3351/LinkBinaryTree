#ifndef LINK_BINARY_TREE_H
#define LINK_BINARY_TREE_H
#include"BTNode.h"
#include "Queue.h"

template <typename T>
class LinkBinaryTree
{
	BTNode<T>* root;

	BTNode<T>* search(BTNode<T>* ptr, T key);
	BTNode<T>* searchParent(BTNode<T>* p, T key);
	void removeDescendants(BTNode<T>* ptr, T key);
	void removeFull(BTNode<T>* ptr);
	void descendantsDisplay(BTNode<T>* ptr);
	bool ancestorsDisplay(BTNode<T>* ptr, T key);
	void levelOrderTraversing(Queue<T>& q, Queue<BTNode<T>*>& qIndex);
	void postOrderTraversing(BTNode<T>* ptr);
	void inOrderTraversing(BTNode<T>* ptr);
	int getHeight(BTNode<T>* ptr);
	void paranthesizedView(BTNode<T>* ptr);
	void explorerView(BTNode<T>* ptr, int level);
	int levelOfNode(BTNode<T>* ptr,T key, int count);
	void displayParticularLevel(int levelToDisplay, Queue<T>& q,
		Queue<BTNode<T>*>& qAddress, Queue<int>& level);
public:
	LinkBinaryTree();
	void setRoot(T val);
	T getRoot();
	void setLeftchild(T parent, T child);
	void setRightchild(T parent, T child);
	T getParent(T node);
	void remove(T node);
	void displayDescendants(T node);
	void displayAncestors(T node);
	void displayLevel(int levelNo);
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrder();
	int heightOfTree();
	void displayParenthesizedView();
	void displayExplorerView();
	int findLevelOfNode(T node);
	~LinkBinaryTree();
};

#endif // !LINK_BINARY_TREE



