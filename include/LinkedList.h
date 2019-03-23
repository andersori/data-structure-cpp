#ifndef LinkedList_h
#define LinkedList_h

#include <memory>
#include "LinkedNode.h"

using std::shared_ptr;
using std::make_shared;

template<class T>
class LinkedList
{
	private:
		int size;
		shared_ptr<LinkedNode<T> > root;
		shared_ptr<LinkedNode<T> > last;

		shared_ptr<LinkedNode<T> > getNode(int);

	public:
		LinkedList();
		~LinkedList();

		int getSize();
		T get(int);
		T remove(int);
		void push(T);
};

template<class T>
LinkedList<T>::LinkedList()
{
	this->size = 0;
	this->root = nullptr;
	this->last = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
	shared_ptr<LinkedNode<T> > temp;
	while(root != nullptr)
	{
		temp = root;
		root = root->next;
		temp = nullptr;
	}

	this->last = nullptr;
	this->size = 0;
}

template<class T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<class T>
T LinkedList<T>::get(int pos)
{
	shared_ptr<LinkedNode<T> > result = this->getNode(pos);
	if(result != nullptr)
	{
		return result->data;
	}
	else
	{
		throw;
	}
}

template<class T>
T LinkedList<T>::remove(int pos)
{

    if(pos == 0)
    {
        T data = this->root->data;
        this->root = this->root->next;

        this->size--;
        return data;
    }
    else
    {
        shared_ptr<LinkedNode<T> > previous = this->getNode(pos-1);
        shared_ptr<LinkedNode<T> > removed = previous->next;

        if(previous != nullptr)
        {
            T data = removed->data;
            previous->next = removed->next;

            this->size--;
            return data;
        }
        else
        {
            throw;
        }
    }
}

template<class T>
void LinkedList<T>::push(T data)
{
	shared_ptr<LinkedNode<T> > newNode = make_shared<LinkedNode<T> >();
	newNode->data = data;

	if(this->root == nullptr)
	{
		root = newNode;

		last = root;
	}
	else
	{
		last->next = newNode;
		last = newNode;
	}

	this->size++;
}

template<class T>
shared_ptr<LinkedNode<T> > LinkedList<T>::getNode(int pos)
{
	shared_ptr<LinkedNode<T> > temp = this->root;

	for(int i = 0; i < this->getSize(); i++)
	{
		if(i == pos)
		{
			return temp;
		}
		temp = temp->next;
	}

	return nullptr;
}

#endif
