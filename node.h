#ifndef NODE_H
#define NODE_H

/**
 * Class object represents a node that stores data and pointers to the previous and next node.
 * @tparam T Type of data.
 *
 * @author Vakaris Paulavičius (K20062023)
 * @version 1.3
 */
template<typename T>
class Node {

public:

    T data;
    Node<T> * next;
    Node<T> * previous;

    /**
     * Node constructor.
     * @param data Data to be stored in the Node.
     */
    explicit Node(T data)
            : data(data), next(nullptr), previous(nullptr) {
    }

    /**
     * Delete this Node object.
     */
    ~ Node() {
        next = nullptr;
        previous = nullptr;
    }

};

// ====================================================================================================================

/**
 * NodeIterator used to iterate over Node objects.
 * @tparam T Data type stored in the current Node.
 *
 * @author Vakaris Paulavičius (K20062023)
 * @version 1.5
 */
template<typename T>
class NodeIterator {

private:

    Node<T> * current;

public:

    /**
     * NodeIterator constructor.
     * @param currentIn Pointer to the current Node.
     */
    explicit NodeIterator(Node<T>* currentIn)
            : current(currentIn) {
    }

    /**
     * Return current pointer data.
     * @return data that is stored in the current Node.
     */
    T & operator*() {
        return current->data;
    }

    /**
     * Change the current pointer value to the next object with ++iteratorObject.
     */
    void operator++() {
        Node<T> temp = (*current);
        current = temp.next;
    }

    /**
     * Change the current pointer value to the next object with iteratorObject++.
     * @return NodeIterator object.
     */
    NodeIterator<T> operator++(int)
    {
        NodeIterator<T> temp = *this;
        current = current->next;
        return temp;
    }

    /**
     * Check whether this and the provided NodeIterator are the same.
     * They are the same if they point to the same Node.
     * @param other Another NodeIterator to compare to.
     * @return true if they are the same, false otherwise.
     */
    bool operator ==(const NodeIterator other) const{
        return current == other.current;
    }

    /**
     * Check whether this and the provided NodeIterator are different.
     * They are different if they point to different Nodes.
     * @param other Another NodeIterator to compare to.
     * @return true if they are different, false otherwise.
     */
    bool operator !=(const NodeIterator other) const{
        return current != other.current;
    }

    /**
     * Get a pointer to the Node that this Iterator is pointing to.
     * @return current Node.
     */
    Node<T> * getNode() {
        return current;
    }

};

// ====================================================================================================================

/**
 * ConstNodeIterator used to iterate over Node objects without the ability to make amendments to them.
 * @tparam T Data type stored in the current Node.
 *
 * @author Vakaris Paulavičius (K20062023)
 * @version 1.0
 */
template<typename T>
class ConstNodeIterator {

private:

    Node<T> * current;

public:

    /**
     * ConstNodeIterator constructor.
     * @param currentIn Pointer to the current Node.
     */
    explicit ConstNodeIterator(Node<T>* currentIn)
            : current(currentIn) {
    }

    /**
     * Return current pointer data.
     * @return const data that is stored in the current Node.
     */
    const T & operator*() {
        return current->data;
    }

    /**
     * Change the current pointer value to the next object with ++iteratorObject.
     */
    void operator++() {
        Node<T> temp = (*current);
        current = temp.next;
    }

    /**
     * Change the current pointer value to the next object with iteratorObject++.
     * @return ConstNodeIterator object.
     */
    ConstNodeIterator<T> operator++(int)
    {
        ConstNodeIterator<T> temp = *this;
        current = current->next;
        return temp;
    }

    /**
     * Check whether this and the provided NodeIterator are the same.
     * They are the same if they point to the same Node.
     * @param other Another ConstNodeIterator to compare to.
     * @return true if they are the same, false otherwise.
     */
    bool operator ==(const ConstNodeIterator other) const{
        return current == other.current;
    }

    /**
     * Check whether this and the provided NodeIterator are different.
     * They are different if they point to different Nodes.
     * @param other Another ConstNodeIterator to compare to.
     * @return true if they are different, false otherwise.
     */
    bool operator !=(const ConstNodeIterator other) const{
        return current != other.current;
    }

    /**
     * Get a pointer to the Node that this Iterator is pointing to.
     * @return const current Node.
     */
    const Node<T> * getNode() {
        return current;
    }

};

// do not edit below this line

#endif
