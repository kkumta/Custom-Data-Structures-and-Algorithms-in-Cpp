#pragma once

template<typename T>
class Tree;

template<typename T>
class BinarySearchTree : public Tree<T>
{
private:
	struct Node
	{
		T key;
		unique_ptr<Node> left;
		unique_ptr<Node> right;

		explicit Node(const T& k)
			: key(k), left(nullptr), right(nullptr) { }
	};

	unique_ptr<Node> root;

public:
	bool Insert(const T& key)
	{
		if (root == nullptr)
		{
			root = make_unique<Node>(key);
			return true;
		}

		Node* curNode = root.get();
		while (true)
		{
			if (curNode->key == key)
				return false;
			else if (curNode->key < key)
			{
				if (curNode->right == nullptr)
				{
					curNode->right = make_unique<Node>(key);
					return true;
				}
				curNode = curNode->right.get();
			}
			else
			{
				if (curNode->left == nullptr)
				{
					curNode->left = make_unique<Node>(key);
					return true;
				}
				curNode = curNode->left.get();
			}
		}
	}

	bool Contains(const T& key) const
	{
		return false;
	}

	bool Remove(const T& key)
	{
		return false;
	}

	bool Empty() const
	{
		if (root == nullptr)
			return true;
		return false;
	}

	void Clear()
	{
	}

	void Inorder() const
	{
	}
};