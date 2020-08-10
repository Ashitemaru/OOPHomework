#include "friday.h"
#include "day.h"
#include "plan.h"
#include <iostream>
#include <string>

Day* days[101];
int main()
{

    freopen("example_in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int m, k, a, b;
    std::string c;
    std::cin >> m;
    for(int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> c;
        if(c == "Friday")
            days[i] = new Friday(a, b, c);
        else
            days[i] = new Day(a, b, c);
    }
    std::cin >> k;
    while(k--)
    {
        std::cin >> a >> b >> c;
        Plan t(a, b, c);
        for(int i = 0; i < m; ++i)
            if(days[i]->insert(t))
                break;
    }
    for(int i = 0; i < m; ++i)
        days[i]->print();
    return 0;
}
