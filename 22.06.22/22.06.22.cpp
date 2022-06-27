#include <iostream>
#include "BinaryTree.cpp"

int main()
{
	BinaryTree<float> tree(25);
	tree.add(23);
	tree.add(29);
	tree.add(27);
	tree.add(26);
	tree.add(28);
	tree.add(28.1);
	tree.add(28.4);
	tree.add(35);
	tree.add(32);

	tree.print();
	//std::cout << std::endl << tree.search(28);

	tree.del(29);
	std::cout << std::endl;
	tree.print();
}