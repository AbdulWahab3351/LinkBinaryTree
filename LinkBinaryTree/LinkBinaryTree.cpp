#include "LinkBinaryTree.h"
#include <string>
#include <iostream>
using namespace std;

template<typename T>
LinkBinaryTree<T>::LinkBinaryTree()
{
	root = nullptr;
}
template<typename T>
void LinkBinaryTree<T>:: setRoot(T val)
{
	if (root)
		root->info = val;
	else
		root = new BTNode<T>(val);
}
template<typename T>
T LinkBinaryTree<T>::getRoot()
{
	return root->info;
}
template<typename T>
void LinkBinaryTree<T>::setLeftchild(T parent, T child)
{
	BTNode<T>* p = search(root, parent);
	if (!p)
		return;
	if (p->left)
		p->left->info = child;
	else
		p->left = new BTNode<T>(child);
}
template<typename T>
void LinkBinaryTree<T>::setRightchild(T parent, T child)
{
	BTNode<T>* p = search(root, parent);
	if (!p)
		return;
	if (p->right)
		p->right->info = child;
	else
		p->right = new BTNode<T>(child);
}
template<typename T>
T LinkBinaryTree<T>:: getParent(T node)
{
	if (!root)
		throw string("Tree is empty\n");
	BTNode<T>* ptr = searchParent(root, node);
	if (!ptr)
		throw string("Root has no parent\n");
	return ptr->info;
}
template<typename T>
BTNode<T>* LinkBinaryTree<T>:: searchParent(BTNode<T>* p, T key)
{
	if (!p || p->info == key)
		return nullptr;
	BTNode<T>* status = nullptr;
	if (!status && p->left)
	{
		if (p->left->info == key)
			status = p;
		else
			status = searchParent(p->left, key);
	}
	if (!status && p->right)
	{
		if (p->right->info == key)
			status = p;
		else
			status = searchParent(p->right, key);
	}
	return status;
}
template<typename T>
BTNode<T>* LinkBinaryTree<T>:: search(BTNode<T>* ptr, T key)
{
	BTNode<T>* status = nullptr;
	if (ptr->info == key)
		status = ptr;
	if (!status && ptr->left)
		status = search(ptr->left, key);
	if (!status && ptr->right)
		status = search(ptr->right, key);
	return status;
}
template<typename T>
void LinkBinaryTree<T>:: removeDescendants(BTNode<T>* ptr,T key)
{
	if (ptr->left)
	{
		if (ptr->left->info == key)
		{
			removeFull(ptr->left);
			ptr->left = nullptr;
			return;
		}
		else
			removeDescendants(ptr->left, key);
	}
	if (ptr->right)
	{
		if (ptr->right->info == key)
		{
			removeFull(ptr->right);
			ptr->right = nullptr;
			return;
		}
		else
			removeDescendants(ptr->right, key);
	}
	
}
template<typename T>
LinkBinaryTree<T>::~LinkBinaryTree()
{
	if (!root)
		return;
	removeFull(root);
	root = nullptr;
}
template<typename T>
void LinkBinaryTree<T>:: remove(T node)
{
	if (!root)
		return;
	if (root->info == node)
	{
		this->~LinkBinaryTree();
		return;
	}
	removeDescendants(root, node);
}
template<typename T>
void LinkBinaryTree<T>:: removeFull(BTNode<T>* ptr)
{
	BTNode<T>* temp1 = ptr->left;
	BTNode<T>* temp2 = ptr->right;
	delete ptr;
	if (temp1)
		removeFull(temp1);
	if (temp2)
		removeFull(temp2);
}
template <typename T>
void LinkBinaryTree<T>:: descendantsDisplay(BTNode<T>* ptr)
{
	cout << ptr->info << ' ';
	if (ptr->left)
		descendantsDisplay(ptr->left);
	if (ptr->right)
		descendantsDisplay(ptr->right);
}
template <typename T>
void LinkBinaryTree<T>:: displayDescendants(T node)
{
	if (!root)
		return;
	BTNode<T>* ptr = search(root,node);
	if (!ptr)
		return;
	if (ptr->left)
		descendantsDisplay(ptr->left);
	if (ptr->right)
		descendantsDisplay(ptr->right);
}
template <typename T>
bool LinkBinaryTree<T>:: ancestorsDisplay(BTNode<T>* ptr, T key)
{
	if (ptr->info == key)
		return true;
	bool status = false;
	if (!status && ptr->left)
		status = ancestorsDisplay(ptr->left, key);
	if (!status && ptr->right)
		status = ancestorsDisplay(ptr->right, key);
	if (status)
		cout << ptr->info << ' ';
	return status;
}
template <typename T>
void LinkBinaryTree<T>:: displayAncestors(T node)
{
	if (!root)
		return;
	if (root->info == node)
		throw string("Root has no ancestors\n");
	ancestorsDisplay(root, node);
}
template<typename T>
void LinkBinaryTree<T>:: levelOrder()
{
	if (!root)
		return;
	Queue<T> q;
	Queue<BTNode<T>*> addressQ;
	q.enQueue(root->info);
	addressQ.enQueue(root);
	levelOrderTraversing(q, addressQ);
}
template <typename T>
void LinkBinaryTree<T>:: levelOrderTraversing(Queue<T>& q, Queue<BTNode<T>*>& addressQ)
{
	BTNode<T>* ptr;
	while (!q.isEmpty())
	{
		cout << q.deQueue() << ' ';
		ptr = addressQ.deQueue();
		if (ptr->left)
		{
			q.enQueue(ptr->left->info);
			addressQ.enQueue(ptr->left);
		}
		if (ptr->right)
		{
			q.enQueue(ptr->right->info);
			addressQ.enQueue(ptr->right);
		}
	}
}
template <typename T>
void LinkBinaryTree<T>:: preOrder()
{
	if (!root)
		return;
	cout << root->info << ' ';
	if(root->left)
		descendantsDisplay(root->left);
	if (root->right)
		descendantsDisplay(root->right);
}
template <typename T>
void LinkBinaryTree<T>:: postOrder()
{
	if (!root)
		return;
	postOrderTraversing(root);
}
template <typename T>
void LinkBinaryTree<T>:: inOrder()
{
	if (!root)
		return;
	inOrderTraversing(root);
}
template <typename T>
void LinkBinaryTree<T>::postOrderTraversing(BTNode<T>* ptr)
{
	if (ptr->left)
		postOrderTraversing(ptr->left);
	if (ptr->right)
		postOrderTraversing(ptr->right);
	cout << ptr->info << ' ';
}
template <typename T>
void LinkBinaryTree<T>::inOrderTraversing(BTNode<T>* ptr)
{
	if (ptr->left)
		inOrderTraversing(ptr->left);
	cout << ptr->info << ' ';
	if (ptr->right)
		inOrderTraversing(ptr->right);
}
template <typename T>
int LinkBinaryTree<T> :: heightOfTree()
{
	if (!root)
		return 0;
	return getHeight(root);
}
template <typename T>
int LinkBinaryTree<T>::getHeight(BTNode<T>* ptr)
{
	int left = 0;
	int right = 0;
	if (ptr->left)
		left = getHeight(ptr->left);
	if (ptr->right)
		right = getHeight(ptr->right);
	return left > right ? 1 + left : 1 + right;
}
template <typename T>
void LinkBinaryTree<T>:: displayParenthesizedView()
{
	if (!root)
		return;
	paranthesizedView(root);
}
template <typename T>
void LinkBinaryTree<T>:: paranthesizedView(BTNode<T>* ptr)
{
	cout << ptr->info;
	if (ptr->left || ptr->right)
		cout << '(';
	else
		return;
	if (ptr->left)
		paranthesizedView(ptr->left);
	cout << ',';
	if (ptr->right)
		paranthesizedView(ptr->right);
	cout << ')';
}
template <typename T>
void LinkBinaryTree<T>:: displayExplorerView()
{
	if (!root)
		return;
	explorerView(root, 0);
}
template <typename T>
void LinkBinaryTree<T>:: explorerView(BTNode<T>* ptr, int level)
{
	for (int i = 0; i < level; i++)
		cout << '\t';
	cout << ptr->info << '\n';
	if (ptr->left)
		explorerView(ptr->left, level + 1);
	if (ptr->right)
		explorerView(ptr->right, level + 1);
}
template <typename T>
int LinkBinaryTree<T>::findLevelOfNode(T node)
{
	if (!root)
		return -1;
	return levelOfNode(root, node, 0);
}
template <typename T>
int LinkBinaryTree<T>::levelOfNode(BTNode<T>* ptr, T key, int count)
{
	if (ptr->info == key)
		return count;
	int val = -1;
	if (ptr->left)
		val = levelOfNode(ptr->left, key, count + 1);
	if (val == -1 && ptr->right)
		val = levelOfNode(ptr->right, key, count + 1);
	return val;
}
template <typename T>
void LinkBinaryTree<T>:: displayLevel(int levelNo)
{
	if (!root)
		return;
	Queue<T> q;
	Queue<BTNode<T>*> qAddress;
	Queue<int> levelQ;
	q.enQueue(root->info);
	qAddress.enQueue(root);
	levelQ.enQueue(0);
	displayParticularLevel(levelNo,q,qAddress,levelQ);
}
template <typename T>
void LinkBinaryTree<T>::displayParticularLevel(int levelToDisplay,
	Queue<T>& q, Queue<BTNode<T>*>& addressQ, Queue<int>& levelQ)
{
	T temp;
	BTNode<T>* ptr;
	int levelNo;
	while (!q.isEmpty())
	{
		temp = q.deQueue();
		ptr = addressQ.deQueue();
		levelNo = levelQ.deQueue();
		if (levelNo == levelToDisplay)
			cout << temp << ' ';
		else
		{
			if (ptr->left)
			{
				q.enQueue(ptr->left->info);
				addressQ.enQueue(ptr->left);
				levelQ.enQueue(levelNo + 1);
			}
			if (ptr->right)
			{
				q.enQueue(ptr->right->info);
				addressQ.enQueue(ptr->right);
				levelQ.enQueue(levelNo + 1);
			}
		}
	}
}