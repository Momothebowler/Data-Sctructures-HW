#include <vector>
#include <iostream>
#include <list>
#include "timer.h"
#include <string>
#include <iomanip>

int main()
{
    Timer<> clock;
    const int runs = 100;
    clock.tick();
    std::list<double> arr;
    for (int i = 0; i <= 1000000; i++)
        arr.push_back(i);

    for (int i = 0; i < runs; i++)
    {
        double sum = 0;
        for (double item : arr)
            sum += item;

        // std::cout << "Sum is: " << std::setprecision(15) << sum << "\n";
        sum = 0;
    }
    clock.tock();

    const double secs = clock.duration().count() / 1000.0 / runs;
    std::cout << "Took:" << secs << " seconds\n";

    clock.tick();
    std::vector<int> a(1000001);

    for (int i = 0; i <= 1000000; ++i)
        a[i] = i;

    for (int i = 0; i < runs; i++)
    {
        double sum = 0;
        for (double item : a)
            sum += item;

        // std::cout << "Sum is: " << std::setprecision(15) << sum << "\n";
        sum = 0;
    }
    clock.tock();
    const double secs2 = clock.duration().count() / 1000.0 / runs;
    std::cout << "Took:" << secs2 << " seconds\n";
    // std::cout << "List uses: " << sizeof(arr.back()) << " bytes\n";
    //  lists uses 8 bytes per item
    // std::cout << "Vector uses: " << sizeof(a[1000000 - 1]) << " bytes\n";
    //  Vectors use 4 bytes per item
    std::cout << "List uses: " << arr.size() * sizeof(arr.back()) << " bytes\n";
    std::cout << "Vector uses: " << a.size() * sizeof(a[1000000]) << " bytes\n";
    return 0;
}
