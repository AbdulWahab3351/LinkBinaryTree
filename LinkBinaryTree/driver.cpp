#include <iostream>
using namespace std;
#include"LinkBinaryTree.h"
int main()
{
	LinkBinaryTree<char> l;
	l.setRoot('A');
	l.setLeftchild('A', 'B');
	l.setRightchild('A', 'C');
	l.setRightchild('C', 'F');
	l.setLeftchild('B', 'D');
	l.setRightchild('D', 'H');
	l.setRightchild('B', 'E');
	l.setLeftchild('E', 'I');
	l.setRightchild('E', 'J');
	l.setLeftchild('I', 'K');
	l.displayDescendants('A');
	cout << endl;
	l.preOrder();
	cout << endl;
	l.postOrder();
	cout << endl;
	l.inOrder();
	cout << endl;
	l.displayParenthesizedView();
	cout << endl;
	l.displayExplorerView();
	cout << '\n';
	l.displayLevel(0);
	cout << '\n';
	l.displayLevel(1);
	cout << '\n';
	l.displayLevel(2);
	cout << '\n';
	l.displayLevel(3);
	cout << '\n';
	l.displayLevel(4);
	//l.displayLevel(1);

	return 0;
}