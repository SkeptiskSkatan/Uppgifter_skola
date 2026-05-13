#include <iostream>
#include <cassert>


class WaterTank {
    public:
        int maxTank;
        int water;
        int fill(int waterFill);
        int use(int waterUse);
        int getVolume();



        // Set when declared 
        WaterTank(int waterIn);
};

WaterTank::WaterTank(int waterIn) {

    maxTank = waterIn;
    water = 0;

}




int WaterTank::fill(int waterFill) {

    if (water + waterFill <= maxTank) {
        water += waterFill;
        return waterFill;
    }
    else {
        int svar = maxTank - water;
        water = maxTank;
        return svar;

    };
};

int WaterTank::use(int waterUse) {

    if (water - waterUse <= 0) {
        int svar = water;
        water = 0;
        return svar;

    }
    else {
        water -= waterUse;

        return waterUse;
    };
};

int WaterTank::getVolume() {

    return water;

};


void runTests() {
    // Fresh tank starts empty
    WaterTank t1(1500);
    assert(t1.getVolume() == 0);

    // Normal fill
    WaterTank t2(1500);
    assert(t2.fill(1000) == 1000);
    assert(t2.getVolume() == 1000);

    // Fill over capacity clamps to max
    WaterTank t3(1500);
    assert(t3.fill(1800) == 1500);
    assert(t3.getVolume() == 1500);

    // Normal use
    WaterTank t4(1500);
    t4.fill(1000);
    assert(t4.use(600) == 600);
    assert(t4.getVolume() == 400);

    // Use more than available clamps to 0
    WaterTank t5(1500);
    t5.fill(500);
    assert(t5.use(800) == 500);
    assert(t5.getVolume() == 0);

    // Fill exact capacity
    WaterTank t6(1500);
    assert(t6.fill(1500) == 1500);
    assert(t6.getVolume() == 1500);

    // Use exact amount
    WaterTank t7(1500);
    t7.fill(1000);
    assert(t7.use(1000) == 1000);
    assert(t7.getVolume() == 0);

    std::cout << "All tests passed!" << std::endl;
}


int main()
{

    runTests();

}

