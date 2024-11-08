#pragma once

#include "Tree.h"
#include "BinarySearchTree.h"

template<typename T>
class Set
{
public:
    enum class TreeType { BinarySearchTree, RedBlackTree };

    explicit Set(TreeType type = TreeType::BinarySearchTree)
    {
        if (type == TreeType::BinarySearchTree)
            _tree = std::make_unique<BinarySearchTree<T>>();
        // else
        //     _tree = std::make_unique<RedBlackTree<T>>();
    }

    bool Insert(const T& key) { return _tree->Insert(key); }
    bool Contains(const T& key) const { return _tree->Contains(key); }
    bool Remove(const T& key) { return _tree->Remove(key); }
    bool Empty() const { return _tree->Empty(); }
    void Clear() { _tree->Clear(); }
    void Inorder() const { _tree->Inorder(); }

private:
    unique_ptr<Tree<T>> _tree;
};