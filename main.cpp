#include "StructureList.h"
#include <iostream>

int main()
{
    // Creating a vector to hold structure objects.
    std::vector<Structure> structures;

    // Populating the vector with Structure objects. Each object represents
    // a unique entity characterized by multiple properties. By using the
    // addStructure utility function, objects are directly emplaced into
    // the vector, demonstrating an efficient method to populate a container
    // with complex objects without the overhead of copying.
    StructureUtils::addStructure(structures, {"Structure1", 1.0, 2.0, 100.0, 0.5, 0.01});
    StructureUtils::addStructure(structures, {"Structure2", 2.0, 3.0, 150.0, 0.4, 0.02});
    StructureUtils::addStructure(structures, {"Structure3", 3.0, 4.0, 90.0, 0.3, 0.03});
    StructureUtils::addStructure(structures, {"Structure4", 3.0, 4.0, 101.0, 0.19, 0.01});
    StructureUtils::addStructure(structures, {"Structure1.1", 1.0, 2.0, 100.0, 0.5, 0.01});
    StructureUtils::addStructure(structures, {"Structure2.1", 2.0, 3.0, 150.0, 0.4, 0.02});

    // Utilizing the printStructures utility to iterate over the collection
    // and output each Structure's details. This showcases how elements within
    // a container can be accessed and their properties retrieved, facilitating
    // an easy review of the container's contents at any point in the program's execution.
    StructureUtils::printStructures(structures);

    std::cout << "\nThe list contains " << structures.size() << " structures.\n"
              << std::endl;

    // Demonstrating conditional removal of structures from the vector. Structures
    // that meet specified criteria (area > 100 and currentDensity < 0.02) are targeted
    // for removal. This employs the removeStructuresIf utility which leverages the
    // erase-remove idiom for efficient element deletion based on a predicate,
    // showcasing how dynamic container manipulation can be achieved in C++.
    std::cout << "Conditional removal of structures from vector based on area > 100 and current density < 0.02 ... " << std::endl;
    StructureUtils::removeStructuresIf(structures, [](const Structure &s)
                                       {
                                           return s.area > 100 && s.currentDensity < 0.02; // Criteria for removal
                                       });

    std::cout << "The list now contains " << structures.size() << " structures after removal.\n"
              << std::endl;

    std::cout << "Removal of all items from vector until empty." << std::endl;

    /*
    This loop demonstrates safely removing elements from 'structures' while iterating through it.
    Normally, erasing elements from a container during iteration requires careful handling to avoid
    invalidating iterators and to ensure the loop processes each element correctly. Here, we call
    'erase' on the current element, which not only removes the element but also returns an iterator
    to the next valid element in the vector. This makes it safe to continue the iteration without
    skipping any elements or causing undefined behavior. After each removal, we display the current
    size of the vector to observe how it decreases with each operation. This pattern is useful for
    selectively removing elements based on complex conditions or when the removal process involves
    additional operations on the remaining elements.
    */
    for (auto it = structures.begin(); it != structures.end(); /* no increment here */)
    {
        it = structures.erase(it); // 'erase' returns an iterator to the next valid element.
        std::cout << "The list contains " << structures.size() << " structures." << std::endl;
    }

    /*
    The 'structures' vector is automatically cleaned up when it goes out of scope,
    demonstrating RAII (Resource Acquisition Is Initialization) where resources are
    automatically managed and released by objects in C++.
    */
    return 0;
}