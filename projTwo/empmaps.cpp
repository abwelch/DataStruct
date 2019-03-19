/*
Andrew Welch
abw28@zips.uakron.edu
2700340

Program that populates a vector of employee objects, creates ordered and
unordered maps, and prints results.
*/

#include "empmaps.h"
#include <fstream>
#include <sstream>

// Prompts the user for an input file name and opens the file if correctly
// entered. Loops through the file line by line to generate employee objects and
// add to vector.
std::vector<Employee> employees()
{
    std::ifstream inputFile;
    std::string inputtedFileName;
    std::vector<Employee> employeeVector;
    std::cout << "Enter a graph filename to process (include "
                 "extension): ";
    getline(std::cin, inputtedFileName);
    inputFile.open(inputtedFileName.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "ERROR: inputted file does not exist!\n";
        std::exit(0);
    }
    std::cout << inputtedFileName << " successfully opened!\n";
    std::string fileLine;
    // Variables to store employee info on each line
    int id, salary;
    std::string lastName;

    // Beginning of loop for reading from file and creating employees
    while (getline(inputFile, fileLine))
    {
        std::istringstream lineStream(fileLine);
        lineStream >> id;
        lineStream >> lastName;
        lineStream >> salary;
        Employee newEmp(id, lastName, salary);
        employeeVector.push_back(newEmp);
    }
    std::cout << "Number of employees are: " << employeeVector.size()
              << std::endl;
    inputFile.close();
    return employeeVector;
}

// Creates an ordered map with keys derived from the first 4 sig digits
// of the employee ID
std::map<int, std::vector<Employee>> mapEmpDept(std::vector<Employee> &emp)
{
    std::map<int, std::vector<Employee>> orderedDepMap;
    std::vector<Employee>::iterator iter = emp.begin();
    int key;
    while (iter != emp.end())
    {
        // Creates an id with the first 4 sig digits and pushes back the employee
        key = iter->id() / 100;
        orderedDepMap[key].push_back(*iter);
        ++iter;
    }
    std::cout << "ORDERED Map number of departments: " << orderedDepMap.size()
              << std::endl;
    return orderedDepMap;
}

// Creates an ordered map with keys derived from salary
std::map<int, std::vector<Employee>> mapSalRange(std::vector<Employee> &emp)
{
    std::map<int, std::vector<Employee>> orderedSalMap;
    std::vector<Employee>::iterator iter = emp.begin();
    int key;
    while (iter != emp.end())
    {
        // This truncates the salary's hundreds, tens, and ones values
        key = (iter->sal() / 10000) * 10000;
        orderedSalMap[key].push_back(*iter);
        ++iter;
    }
    std::cout << "ORDERED Map number of salary ranges: " << orderedSalMap.size()
              << std::endl;
    return orderedSalMap;
}

// Traverse the ordered map and print total employees at each key.
// Document key with greatest number of employees and display at end.
void printSalRange(std::map<int, std::vector<Employee>> &salRange)
{
    int mostEmp = 0, mostEmpSalRange = 0;
    int currentEmpAmount = 0, currentEmpSalRange = 0;
    for (std::map<int, std::vector<Employee>>::iterator i = salRange.begin();
         i != salRange.end(); ++i)
    {
        // Assigns the key
        currentEmpSalRange = i->first;
        // Assigns total elements in vector at this key
        currentEmpAmount = i->second.size();
        std::cout << "ORDERED Map Salary range " << currentEmpSalRange
                  << " contains " << currentEmpAmount << std::endl;
        // Assigns new most values if current map element has a larger employee
        // vector
        if (currentEmpAmount > mostEmp)
        {
            mostEmp = currentEmpAmount;
            mostEmpSalRange = currentEmpSalRange;
        }
    }
    std::cout << "ORDERED Map Salary Range with most employees: "
              << mostEmpSalRange << " containing " << mostEmp << " employees.\n";
}

// Creates an unordered map with keys derived from the first 4 sig digits
// of the employee ID
std::unordered_map<int, std::vector<Employee>>
umapEmpDept(std::vector<Employee> &emp)
{
    std::unordered_map<int, std::vector<Employee>> unorderedDepMap;
    std::vector<Employee>::iterator iter = emp.begin();
    int key;
    while (iter != emp.end())
    {
        // Creates an id with the first 4 sig digits and pushes back the employee
        key = iter->id() / 100;
        unorderedDepMap[key].push_back(*iter);
        ++iter;
    }
    std::cout << "UNORDERED Map number of departments: " << unorderedDepMap.size()
              << std::endl;
    return unorderedDepMap;
}

// Creates an unordered map with keys derived from salary
std::unordered_map<int, std::vector<Employee>>
umapSalRange(std::vector<Employee> &emp)
{
    std::unordered_map<int, std::vector<Employee>> unorderedSalMap;
    std::vector<Employee>::iterator iter = emp.begin();
    int key;
    while (iter != emp.end())
    {
        // This truncates the salary's hundreds, tens, and ones values
        key = (iter->sal() / 10000) * 10000;
        unorderedSalMap[key].push_back(*iter);
        ++iter;
    }
    std::cout << "UNORDERED Map number of salary ranges: "
              << unorderedSalMap.size() << std::endl;
    return unorderedSalMap;
}

// Traverse the unordered map and print total employees at each key.
// Document key with greatest number of employees and display at end.
void uprintSalRange(std::unordered_map<int, std::vector<Employee>> &salRange)
{
    int mostEmp = 0, mostEmpSalRange = 0;
    int currentEmpAmount = 0, currentEmpSalRange = 0;
    for (std::unordered_map<int, std::vector<Employee>>::iterator i =
             salRange.begin();
         i != salRange.end(); ++i)
    {
        // Assigns the key
        currentEmpSalRange = i->first;
        // Assigns total elements in vector at this key
        currentEmpAmount = i->second.size();
        std::cout << "UNORDERED Map Salary range " << currentEmpSalRange
                  << " contains " << currentEmpAmount << std::endl;
        // Assigns new most values if current map element has a larger employee
        // vector
        if (currentEmpAmount > mostEmp)
        {
            mostEmp = currentEmpAmount;
            mostEmpSalRange = currentEmpSalRange;
        }
    }
    std::cout << "UNORDERED Map Salary Range with most employees: "
              << mostEmpSalRange << " containing " << mostEmp << " employees.\n";
}