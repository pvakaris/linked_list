#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <initializer_list>
using std::initializer_list;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

/**
 * A doubly linked list class.
 * @tparam T Type of elements in the list.
 *
 * @author Vakaris Paulavičius (K20062023)
 * @version 1.5
 */
template<typename T>
class LinkedList {

private:
    Node<T> * head;
    Node<T> * tail;
    int numberOfElements;

public:
    /**
     * Constructor for an empty LinkedList.
     */
    LinkedList()
            : head(nullptr), tail(nullptr), numberOfElements(0) {
    }

    /**
     * Constructor for a LinkedList.
     * @param initList A list of objects to add to the the list at its creation.
     */
    LinkedList(initializer_list<T> initList)
            : head(nullptr), tail(nullptr), numberOfElements(0){
        if(initList.size() > 0) {
            auto * itr = initList.begin();
            const auto * itrEnd = initList.end();
            auto * node = new Node<T>(*itr);
            itr++;
            numberOfElements = 1;
            head = node;
            tail = node;
            while(itr != itrEnd) {
                push_back(*itr);
                itr ++;
            }
        }
    }

    /**
     * Return data stored in the head node.
     * @return Head node data.
     */
    T front() {
        return head->data;
    }

    /**
     * Return data stored in the tail node.
     * @return Tail node data.
     */
    T back() {
        return tail->data;
    }

    /**
     * Insert a value at the beginning of the list.
     * @param value A value to insert.
     */
    void push_front(const T value){
        auto * node = new Node<T>(value);
        if(numberOfElements == 0) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->previous = node;
            head = node;
        }
        numberOfElements += 1;
    }

    /**
     * Insert a value at the end of the list.
     * @param value A value to insert.
     */
    void push_back(const T value){
        auto * node = new Node<T>(value);

        if(numberOfElements == 0) {
            head = node;
            tail = node;
        }
        else {
            node->previous = tail;
            tail->next = node;
            tail = node;
        }
        numberOfElements += 1;
    }

    /**
     * Get NodeIterator that points to the head Node.
     * @return NodeIterator with pointer to the head.
     */
    NodeIterator<T> begin() {
        return NodeIterator<T>(head);
    }

    /**
     * Get ConstNodeIterator that points to the head Node.
     * @return ConstNodeIterator with pointer to the head.
     */
    ConstNodeIterator<T> begin() const{
        return ConstNodeIterator<T>(head);
    }

    /**
     * Get NodeIterator that points to the tail Node.
     * @return NodeIterator with pointer to the tail.
     */
    NodeIterator<T> end() {
        return NodeIterator<T>(tail->next);
    }

    /**
     * Get ConstNodeIterator that points to the tail Node.
     * @return ConstNodeIterator with pointer to the tail.
     */
    ConstNodeIterator<T> end() const{
        return ConstNodeIterator<T>(tail->next);
    }

    /**
     * Reverse the order of LinkedList elements.
     */
    void reverse() {

        Node<T> * current = head;
        Node<T> * placeholder = nullptr;
        tail = head;

        while(current != nullptr) {
            placeholder = current->previous;
            current->previous = current->next;
            current->next = placeholder;
            current = current->previous;
        }

        if(placeholder != nullptr) {
            head = placeholder->previous;
        }
    }

    /**
     * Insert value into the list at the given position.
     * @param whereToInsert NodeIterator pointing to where to insert the new value.
     * @param value A value to insert.
     * @return The NodeIterator to the new element.
     */
    NodeIterator<T> insert(NodeIterator<T> whereToInsert, const T value) {
        if(numberOfElements == 0) return NodeIterator<T>(nullptr);
        auto * node = new Node<T>(value);
        Node<T> * current = whereToInsert.getNode();
        if(numberOfElements == 1) {
            node->next = current;
            current->previous = node;
            head = node;
        }
        else {
            Node<T> * prev = current->previous;
            prev->next = node;
            node->previous = prev;
            node->next = current;
            current->previous = node;
        }
        numberOfElements += 1;

        return NodeIterator<T>(node);
    }

    /**
     * Erase value from from the given position in the list.
     * @param whichToRemove NodeIterator pointing to the element that has to be erased from the list.
     * @return The NodeIterator of the element that is now in that position.
     */
    NodeIterator<T> erase(NodeIterator<T> whichToRemove) {
        if(numberOfElements == 0) return NodeIterator<T>(nullptr);
        Node<T> * node = whichToRemove.getNode();
        Node<T> * prev = node->previous;
        Node<T> * next = node->next;
        if(numberOfElements == 1 && head == node) {
            head = nullptr;
            tail = nullptr;
        }
        else if(head == node) {
            next->previous = nullptr;
            head = next;
            next = node->next;
        }
        else if(tail == node) {
            prev->next = nullptr;
            tail = prev;
            next = nullptr;
        }
        else {
            prev->next = next;
            next->previous = prev;
            next = node->next;
        }
        delete node;
        numberOfElements -= 1;

        return NodeIterator<T>(next);
    }

    /**
     * Return the amount of items stored in the LinkedList.
     * @return LinkedList size.
     */
    int size() const {
        return numberOfElements;
    }

    /**
     * Delete LinkedList object.
     */
    ~ LinkedList() {

        Node<T> * current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        numberOfElements = 0;
        head = nullptr;
        tail = nullptr;
    }
};
// do not edit below this line

#endif
