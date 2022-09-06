#ifndef B_T_NODE_H
#define B_T_NODE_H
template <typename T>
class BTNode
{
public:
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode();
	BTNode(T val);
};

#endif // !B_T_NODE_H


