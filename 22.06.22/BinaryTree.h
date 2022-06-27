#pragma once

template <typename T>
struct Node
{
	T data;
	Node* left = nullptr;
	Node* right = nullptr;
	Node* parent = nullptr;
	int id;
	bool operator < (const Node& other)
	{
		return data < other.data;
	}
	bool operator > (const Node& other)
	{
		return data > other.data;
	}
	friend std::ostream& operator << (std::ostream& out, const Node& other)
	{
		out << other.data;
		return out;
	}
};

template <typename T>
class BinaryTree
{
private:
	int counter = 0;
	Node<T>* root = nullptr;
public:
	BinaryTree(){}
	BinaryTree(T object)
	{
		Node<T>* node = new Node<T>{ object };
		root = node;
		node->id = counter;
		counter++;
	}
	void add(T object)
	{
		Node<T>* node  = new Node<T>{ object };
		if (root == nullptr)
		{
			root = node;
		}
		else
		{
			Node<T>* buf = root;
			while (true)
			{
				if (*node < *buf)
				{
					if (buf->left == nullptr)
					{
						node->parent = buf;
						buf->left = node;
						break;
					}
					buf = buf->left;
				}
				else if (*node > *buf)
				{
					if (buf->right == nullptr)
					{
						node->parent = buf;
						buf->right = node;
						break;
					}
					buf = buf->right;
				}
				else break;
			}
		}
		node->id = counter;
		counter++;
	}
	void print(Node<T>* buf = nullptr)
	{
		if (buf == nullptr) buf = root;
		std::cout << *buf << " ";
		if (buf->left != nullptr) print(buf->left);
		if (buf->right != nullptr) print(buf->right);
	}

	Node<T>* search(T object)
	{
		Node<T>* buf = root;
		while (true)
		{
			if (buf->left == nullptr && buf->right == nullptr && object != buf->data) return nullptr;
			else if (object < buf->data) buf = buf->left;
			else if (object > buf->data) buf = buf->right;
			else return buf;
		}
	}

	void del(T object) //неполное удаление - дописать
	{
		Node<T>* buf = search(object);
		Node<T>* buf2 = buf->left;
		if (buf)
		{
			if (buf->right != nullptr && buf->right != nullptr)
			{
				while (buf2->right != nullptr)
				{
					buf2 = buf2->right;
				}
				buf->data = buf2->data;
				if (buf2->parent->left == buf2) buf2->parent = buf2->left; //точно?
				else buf2->parent->right = buf2->right;
				buf = buf2;
			}
			delete buf;
			counter--;
		}
	}
};



