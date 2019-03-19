/*
Andrew Welch
abw28@zips.uakron.edu
2700340

Driver program
*/
#include "empmaps.h"
#include <ctime>

int main()
{
    std::vector<Employee> employeeVector = employees();
    clock_t start, stop;
    // Call to ordered map with department keys
    start = clock();
    mapEmpDept(employeeVector);
    stop = clock();
    std::cout << "ORDERED Map creation with department as key clock ticks: "
              << double(stop - start) << std::endl;
    // Call to ordered map with salary keys
    start = clock();
    std::map<int, std::vector<Employee>> orderedSalMap =
        mapSalRange(employeeVector);
    stop = clock();
    std::cout << "ORDERED Map creation with salary as key clock ticks: "
              << double(stop - start) << std::endl;
    // Call to ordered map print with salary keys
    printSalRange(orderedSalMap);
    std::cout << std::endl;
    // Call to unordered map with department keys
    start = clock();
    umapEmpDept(employeeVector);
    stop = clock();
    std::cout << "UNORDERED Map creation with department as key clock ticks: "
              << double(stop - start) << std::endl;
    // Call to unordered map with salary keys
    start = clock();
    std::unordered_map<int, std::vector<Employee>> unorderedSalMap =
        umapSalRange(employeeVector);
    stop = clock();
    std::cout << "UNORDERED Map creation with salary as key clock ticks: "
              << double(stop - start) << std::endl;
    // Call to unordered map print with salary keys
    uprintSalRange(unorderedSalMap);
    return 0;
}
