#include <vector>
#include <iostream>
#include <list>
#include "timer.h"
// #include <iomanip>

int main()
{
    Timer<> clock;
    const int runs = 100;
    std::list<double> arr;
    double secs = 0;
    double secs2 = 0;
    for (int i = 0; i <= 1000000; i++)
        arr.push_back(i);

    for (int i = 0; i < runs; i++)
    {
        clock.tick();
        double sum = 0;
        for (double item : arr)
            sum += item;

        // std::cout << "Sum is: " << std::setprecision(15) << sum << "\n";
        sum = 0;
        clock.tock();
        secs += clock.duration().count() / 1000.0;
    }

    secs = secs / runs;
    std::cout << "Took:" << secs << " seconds\n";

    std::vector<int> a(1000001);

    for (int i = 0; i <= 1000000; ++i)
        a[i] = i;

    for (int i = 0; i < runs; i++)
    {
        clock.tick();
        double sum = 0;
        for (double item : a)
            sum += item;

        // std::cout << "Sum is: " << std::setprecision(15) << sum << "\n";
        sum = 0;
        clock.tock();
        secs2 += clock.duration().count() / 1000.0;
    }

    secs2 = secs2 / runs;
    std::cout << "Took:" << secs2 << " seconds\n";
    //  lists uses 8 bytes per item
    //  Vectors use 4 bytes per item
    std::cout << "List uses: " << arr.size() * sizeof(arr.back()) << " bytes\n";
    std::cout << "Vector uses: " << a.size() * sizeof(a[1000000]) << " bytes\n";
    return 0;
}
