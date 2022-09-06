#include "BTNode.h"

template<typename T>
BTNode<T>::BTNode()
{
	left = right = nullptr;
}
template<typename T>
BTNode<T>::BTNode(T val) : info(val)
{
	left = right = nullptr;
}
