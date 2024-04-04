#ifndef STRUCTURE_LIST_H
#define STRUCTURE_LIST_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Defines a structure to represent a complex object with multiple properties.
// This struct serves as an example of how structured data can be efficiently
// managed and manipulated in C++.
struct Structure
{
    std::string name;      // The name of the structure.
    double x, y;           // Coordinates of the structure, representing its position.
    double area;           // The area covered by the structure.
    double resistance;     // Electrical resistance property of the structure.
    double currentDensity; // Measure of current density flowing through the structure.

    // Constructor initializes the structure with specified properties.
    // Enables easy creation and setup of structure instances.
    Structure(const std::string &name, double x, double y, double area, double resistance, double currentDensity) : name(name), x(x), y(y), area(area), resistance(resistance), currentDensity(currentDensity) {}
};

// Encapsulates utility functions for managing a collection of Structure objects.
// This namespace provides a set of operations that can be performed on a vector of Structures,
// such as adding a new Structure, printing all Structures, and conditionally removing Structures.
namespace StructureUtils
{

    // Adds a given Structure object to a vector of Structures.
    // This function demonstrates how objects can be dynamically added to a collection.
    inline void addStructure(std::vector<Structure> &structures, const Structure &structure)
    {
        structures.push_back(structure);
    }

    // Iterates over and prints details of each Structure in a vector.
    // Useful for displaying the state of the collection at any point in time.
    inline void printStructures(const std::vector<Structure> &structures)
    {
        int i = 0;
        for (const auto &structure : structures)
        {
            std::cout << "Structure " << ++i << " : " << structure.name << std::endl;
        }
    }

    // Removes Structures from the vector based on a specified condition (predicate).
    // Demonstrates the use of the erase-remove idiom for efficient element removal.
    // The Predicate parameter allows for flexible removal criteria.
    template <typename Predicate>
    inline void removeStructuresIf(std::vector<Structure> &structures, Predicate pred)
    {
        structures.erase(std::remove_if(structures.begin(), structures.end(), pred), structures.end());
    }

}

#endif // STRUCTURE_LIST_H