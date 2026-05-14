#include <iostream>
#include <cmath>
#include <cassert>




bool isInsideUnitDisk(double x, double y) {
    return x * x + y * y <= 1.0;
}

void runTests() {
    // Clearly inside
    assert(isInsideUnitDisk(0.5, 0.25) == true);

    // Clearly outside
    assert(isInsideUnitDisk(0.74, 0.85) == false);

    // Origin
    assert(isInsideUnitDisk(0.0, 0.0) == true);

    // Exactly on the circle - counts as inside
    assert(isInsideUnitDisk(1.0, 0.0) == true);
    assert(isInsideUnitDisk(0.0, 1.0) == true);
    assert(isInsideUnitDisk(-1.0, 0.0) == true);

    // Just inside
    assert(isInsideUnitDisk(0.99, 0.0) == true);

    // Just outside
    assert(isInsideUnitDisk(1.01, 0.0) == false);

    // Negative coordinates inside
    assert(isInsideUnitDisk(-0.5, -0.5) == true);

    // Negative coordinates outside
    assert(isInsideUnitDisk(-0.9, -0.9) == false);

    std::cout << "All tests passed!" << std::endl;
}


int main()
{

    float x = 0.5;
    float y = 0.5;

    float hyp = std::sqrt((x * x) + (y * y));

    if (hyp <= 1) {

        std::cout << "Inside the unit disk ";

    }
    else {

        std::cout << "Outside the unit disk ";

    };

    runTests();



};
