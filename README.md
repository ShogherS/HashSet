# HashSet
User defined hash set implementation

This is a C++ implementation of a hash set, also known as a set, that allows you to store a collection of unique strings. It provides functions for adding, removing, searching for elements, and visiting elements in the set. The hash set automatically manages resizing to ensure efficient storage.

Features

Efficient storage and retrieval of unique string elements.
Automatic resizing (rehashing) when the set is getting full.
Support for adding, removing, and searching for elements.
A function to visit each element in the set with a user-defined action.
Built-in error handling for element not found and element already exists scenarios.
Usage

To use this HashSet in your C++ program:

1. Include the HashSet header file in your source code:

	#include "HashSet.h"

2. Create an instance of the HashSet class:

	HashSet mySet;

3. Use the provided functions to add, remove, search for elements, and visit elements in the set:

	mySet.add("apple");
  mySet.add("banana");
  bool found = mySet.search("apple");
  mySet.remove("banana");
  mySet.visit([](const std::string& str) {
    std::cout << "Visited: " << str << std::endl;
  });


Customization

This HashSet is designed to store unique string elements. You can easily customize it to store other data types or change the hashing function if needed.

Contributing

Feel free to contribute to this project by submitting bug reports, feature requests, or pull requests.
