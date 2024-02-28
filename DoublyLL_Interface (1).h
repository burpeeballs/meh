#pragma once

#include <cstdint>
class DoublyLL {
    protected:
        struct Node {
            int data;
            Node* next;
            Node* prev;
            Node() {
                data = 0;
                next = nullptr;
                prev = nullptr;
            }
            int get_data() const { return data; }
            Node* get_next() const { return next; }
            Node* get_prev() const { return prev; }

            void set_data(int newData) { data = newData; }
            void set_next(Node* newNode) { next = newNode; }
            void set_prev(Node* newNode) { prev = newNode; }
        };
    public:
        DoublyLL(); // Constructor
        virtual ~DoublyLL() = default; // Destructor
        // The following functions you are to declare in your
        // respective .h files then define in your .cc files.
        
        // front() is supposed to return the first (head) element in
        // the linked list. Should throw error on empty list.
        [[nodiscard]]virtual int front() const = 0;
        // back() is supposed to return the last (tail) element in
        // the linked list. Should throw error on empty list.
        [[nodiscard]]virtual int back() const = 0;
        // isEmpty() is supposed to check if the linked list is empty.
        // True if empty, false if > 0 elements inside.
        [[nodiscard]]virtual bool isEmpty() const = 0;
        // get_size() is supposed to return the current size of the linked
        // list. Throws error if it overflows or size < 0.
        [[nodiscard]]virtual unsigned long long get_size() const = 0;
        // clear() is supposed to clear all the elements in the linked lists.
        // Ensure size is set to 0.
        virtual void clear() = 0;
        // insert_at(pos, newData) is supposed to insert a new node with 
        // newData as the node's data and inserted at position pos.
        // Should throw error if pos is < 0.
        virtual void insert_at(unsigned long long pos, int newData) = 0;
        // contains(key) is suppsed to return true if key is inside the 
        // linked list and false if it doed not contain key. 
        [[nodiscard]]virtual bool contains(int key) const = 0;
        // erase(pos) is supposed to erase a node at position pos.
        // Should throw error if pos is < 0.
        virtual void erase(unsigned long long pos) = 0;
        // push_back(newData) is to insert at the tail of the linked list.
        virtual void push_back(int newData) = 0;
        // pop_back() is to delete from the tail of the linked list.
        // Should throw error if empty.
        virtual void pop_back() = 0;
        // push_front(newData) is to insert at the head of the linked list.
        virtual void push_front(int newData) = 0;
        // pop_front() is to delete from the head of the linked list.
        // Should throw error if empty.
        virtual void pop_front() = 0;
        // resize(newSize) will change the size of the linked list.
        // If newSize < size, then the link list will clear until newSize - 1.
        // If newSize > size, then the capacity of the linked list will only increase
        // leaving the rest of the linked list alone. Should throw error if 
        // newSize is < 0.
        virtual void resize(unsigned long long newSize) = 0;
        // swap() will take two nodes in the linked list at posOne and posTwo
        // then swap them thereby making NodeOne go to where NodeTwo was in the 
        // linked list. Should throw error if posOne < 0 and posTwo < 0. 
        virtual void swap(unsigned long long posOne, unsigned long long posTwo) = 0;
        // reverse() reverses a linked list.
        virtual void reverse() = 0;
        // make_unique() will remove all duplicates in a linked list.
        virtual void make_unique() = 0;
        // merge(other) will take the other linked list and put other's head
        // as the next of the lhs's tail.
        virtual void merge(DoublyLL &other) = 0;
        // splice(pos, other) will take the other linked list and take all elements
        // from other starting at pos and add them to lhs linked list, setting the 
        // next of lhs's tail to the other's elements starting at pos. 
        // Should throw errors if pos goes out of range of other's list.
        virtual void splice(unsigned long long pos, DoublyLL &other) = 0;
        // print() will print all elements in the linked list.
        virtual void print() const = 0;
};
