#pragma once

template<typename T>
class Tree
{
public:
	virtual ~Tree() = default;

	virtual bool Insert(const T& key) = 0;
	virtual bool Contains(const T& key) const = 0;
	virtual bool Remove(const T& key) = 0;
	virtual bool Empty() const = 0;
	virtual void Clear() = 0;
	virtual void Inorder() const = 0;
};