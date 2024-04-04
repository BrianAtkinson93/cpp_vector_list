# C++ Structure Vector List

---

### Overview

The C++ Structure Vector List project offers a structured approach to managing collections of objects in C++. It provides a concrete example of handling a `std::vector` of structures, demonstrating addition, removal, and retrieval operations akin to those found in Python's list, but within the statically typed environment of C++.

### Features

- **Structured Data Management**: Focuses on handling structured data, allowing for the efficient storage and manipulation of objects with multiple attributes.
- **Vector Operations**: Showcases common vector operations such as addition, iteration, conditional removal, and clearing.
- **C++11 Compatibility**: Utilizes C++11 features, making it accessible to a wide range of development environments without the need for the latest compiler versions.

### Getting Started

#### Prerequisites

Ensure you have a C++11-compatible compiler. This project uses features introduced in C++11, such as range-based for loops and lambda expressions.

#### Compilation

To compile the project, you can do one of the following:

1. Use the Makefile to build and run:
> ```bash
> make
> ```
2. use the following command:

> ```bash
> g++ -std=c++11 main.cpp -o vector_list
> ```
>
> This command compiles the `main.cpp` file, ensuring C++11 standard support, and outputs the executable named `vector_list`.
>
> #### Running the Program
>
>After compilation, you can run the program using:
>``` bash
>./vector_list
>```

## Example Usage

Below is a brief example showcasing how to work with the `Structure` vector within your code:

```cpp
// main.cpp
#include "StructureList.h"

int main() {
    std::vector<Structure> myList

    // Example of adding structures
    StructureUtils::addStructure(myList, {"Structure1", 1.0, 2.0, 100.0, 0.5, 0.01});

    // Example of iterating and printing structure names
    StructureUtils::printStructures(myList);

    return 0;
}

```

## Implementation Details

This project demonstrates handling a vector (`std::vector<Structure>`) of structured objects where each `Structure` contains multiple fields like name, coordinates, and physical properties. It provides insight into managing such collections in C++, focusing on operations like adding elements, conditional removal based on attributes, and iterating through the collection to access or modify elements.


## License

This project is licensed under the MIT License - see the LICENSE file for details.
