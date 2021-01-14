//A+B in Hogwarts
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;
struct currency {
    int Galleon;
    int Sickle;
    int Knut;
};

int main() {
    currency a, b, c;
    scanf("%d.%d.%d %d.%d.%d", &a.Galleon, &a.Sickle, &a.Knut, &b.Galleon, &b.Sickle, &b.Knut);
    c.Galleon = a.Galleon + b.Galleon;
    c.Sickle = a.Sickle + b.Sickle;
    c.Knut = a.Knut + b.Knut;
    if (c.Knut >= 29) {
        c.Knut -= 29;
        c.Sickle++;
    }
    if (c.Sickle >= 17) {
        c.Sickle -= 17;
        c.Galleon++;
    }
    printf("%d.%d.%d", c.Galleon, c.Sickle, c.Knut);
    system("pause");
    return 0;
}