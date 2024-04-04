#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Defining a structure for example, which has different properties.
struct Structure
{
    std::string name;      // structure name
    double x, y;           // structure coordinates
    double area;           // area of structure
    double resistance;     // structures resistance value
    double currentDensity; // structures current density

    // Constructor to easily create the object as needed.
    Structure(const std::string &name, double x, double y, double area, double resistance, double currentDensity)
        : name(name), x(x), y(y), area(area), resistance(resistance), currentDensity(currentDensity) {}
};

int main()
{
    /*
    Initialize a vector named 'structures' to hold objects of the 'Structure' type.
    This vector acts as a dynamic array, allowing for efficient storage and manipulation
    of multiple 'Structure' instances.
    */
    std::vector<Structure> structures;

    /* Populate the vector with examples of 'Structure' objects, each representing a distinct
    entity with unique properties. 'emplace_back' is used here for direct construction
    of 'Structure' objects within the vector, avoiding unnecessary copies and enhancing
    efficiency. This demonstrates how to add objects with various attributes into a container.
    */
    structures.emplace_back("Structure1", 1.0, 2.0, 100.0, 0.5, 0.01);
    structures.emplace_back("Structure2", 2.0, 3.0, 150.0, 0.4, 0.02);
    structures.emplace_back("Structure3", 3.0, 4.0, 90.0, 0.3, 0.03);
    structures.emplace_back("Structure4", 3.0, 4.0, 101.0, 0.19, 0.01);
    structures.emplace_back("Structure1.1", 1.0, 2.0, 100.0, 0.5, 0.01);
    structures.emplace_back("Structure2.1", 2.0, 3.0, 150.0, 0.4, 0.02);

    // Counter for later use.
    int i = 0;

    /* 
    Iterate over the vector, outputting each structure's position (as denoted by 'i')
    and its name. This loop showcases how to access and work with elements stored within
    a 'std::vector', demonstrating both iteration and the retrieval of object properties.
    */
    for (const auto &structure : structures)
    {
        i++;
        std::cout << "Structure " << i << " : " << structure.name << std::endl;
    }
    std::cout << "The list now contains " << structures.size() << " structures." << std::endl
              << std::endl;

    /*
    Utilizing the erase-remove idiom to efficiently remove structures from the vector based on a
    specific condition. In this case, we target structures whose area exceeds 100 and whose
    current density is less than 0.02.

    The 'remove_if' algorithm reorders the elements in the vector so that the elements to be
    removed are moved to the end of the vector and returns an iterator to the new logical end
    of the vector. The 'erase' function then removes the elements between this new end and
    the actual end of the vector. This technique allows for efficient removal of elements
    without leaving gaps in the container or requiring manual reindexing.

    After removal, the new size of the vector is outputted to show the effect of the operation,
    illustrating how the vector's size decreases as elements are removed.
    */
    std::cout << "Conditional removal of structures from vector... " << std::endl;
    structures.erase(std::remove_if(structures.begin(), structures.end(), [](const Structure &s)
                                    {
                                        return s.area > 100 && s.currentDensity < 0.02; // Condition for removal
                                    }),
                     structures.end());

    std::cout << "The list now contains " << structures.size() << " structures after removal." << std::endl
              << std::endl;

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
    std::cout << "Removal of all items from vector until empy." << std::endl;
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
}