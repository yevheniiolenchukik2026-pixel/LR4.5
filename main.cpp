// Оленчук Є., ЛР 4.5, варіант 10. «Попадання» у плоску фігуру.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Мішень: сірі області варіанту 10 (межа належить області).
// R – радіус кола, a, b – півсторони прямокутника |x| <= a, |y| <= b.
bool hit(double x, double y, double R, double a, double b)
{
    bool inCircle = (x*x + y*y <= R*R);

    // III чверть: всередині кола і прямокутника
    bool part1 = (x <= 0 && y <= 0) && inCircle && (x >= -a && y >= -b);

    // I чверть: всередині прямокутника, але поза колом
    bool part2 = (x >= 0 && y >= 0) && !(x*x + y*y < R*R) && (x <= a && y <= b);

    return part1 || part2;
}

int main()
{
    double R, a, b, x, y, M;

    cout << "R = "; cin >> R;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    if (R <= 0 || a <= 0 || b <= 0)
    {
        cout << "R, a, b must be positive" << endl;
        return 1;
    }

    srand((unsigned) time(NULL));

    // 1 спосіб: десять пострілів із клавіатури
    cout << endl << "Manual shots" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if (hit(x, y, R, a, b))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    // 2 спосіб: десять випадкових пострілів, x, y з [-M; M], M = max(a, b, R)
    M = max(max(a, b), R);

    cout << endl << "Random shots" << endl << fixed;
    for (int i = 1; i <= 10; i++)
    {
        x = 2.*M*rand()/RAND_MAX - M;
        y = 2.*M*rand()/RAND_MAX - M;

        cout << setw(8) << setprecision(4) << x << "    "
             << setw(8) << setprecision(4) << y << "    ";
        if (hit(x, y, R, a, b))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
