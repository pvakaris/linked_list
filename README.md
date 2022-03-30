# AVL Binary Search Tree data structure

***

### Classes and their explanation

* Node represents a list element that can store data and point to the previous and next node.
* LinkedList is a data structure made of nodes.

### LinkedList supported methods:

* `push_front` Takes an item and pushes it onto the front of the list.
* `front()` Returns a reference to the data inside the head node.
* `push_back` Takes an item and pushes it onto the back of the list.
* `back()` Returns a reference to the data inside the tail node.
* `size()` Returns the count of how many elements are in the list.
* `begin()` Returns an iterator pointing to the head of the list.
* `end()` Returns an iterator pointing to nullptr (it doesn't point to the tail: it points off the end of the list -- and the Node after the tail is nullptr.
* `delete` Deletes every node in the list.
* `reverse()` Reverses the order of the nodes in the list.

----

## How to compile and run

Open the terminal and cd to the directory containing cloned files:

```
cd PATH_TO_THE_CLONED_DIRECTORY
```

Compile all test files using CMake:

```
make TestList

make TestListD

make TestNode
```

Compile all test files without CMake:

```
g++ -Wall -g -std=c++11 -o TestNode TestNode.cpp

g++ -Wall -g -std=c++11 -o TestList TestList.cpp

g++ -Wall -g -std=c++11 -o TestListD TestListD.cpp
```

Test the code by running all the tests:

```
./TestList

./TestNode

./TestListD
```
***

Vakaris Paulavičius

Version 1.0