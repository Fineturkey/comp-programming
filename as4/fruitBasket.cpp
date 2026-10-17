/*********************
 * This has to do with permuations, a fruit can either be included or left out
 * for any one fruit the remaining fruit can be included or left out
 * 2^(n - 1) then add 1 each time to figure out when the fruits are under 200
 * need to compute all groups meaning we compute the groups of 3, then 2, then 1
 * we only need to go up to 3 since each fruit weighs at least 50 grams
 ********************/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long oneFruitBaskets(const vector<int> &fruits)
{
    long long total = 0;

    for (int i = 0; i < fruits.size(); i++)
    {
        if (fruits[i] < 200)
        {
            total += fruits[i];
        }
    }

    return total;
}

long long twoFruitBaskets(const vector<int> &fruits)
{
    long long total = 0;

    for (int i = 0; i < fruits.size(); i++)
    {
        for (int j = i + 1; j < fruits.size(); j++)
        {
            int weight = fruits[i] + fruits[j];

            if (weight < 200)
            {
                total += weight;
            }
        }
    }

    return total;
}

long long threeFruitBaskets(const vector<int> &fruits)
{
    long long total = 0;

    for (int i = 0; i < fruits.size(); i++)
    {
        for (int j = i + 1; j < fruits.size(); j++)
        {
            for (int k = j + 1; k < fruits.size(); k++)
            {
                int weight = fruits[i] + fruits[j] + fruits[k];

                if (weight < 200)
                {
                    total += weight;
                }
            }
        }
    }

    return total;
}

long long basketsLess(const vector<int> &fruits)
{
    return oneFruitBaskets(fruits) + twoFruitBaskets(fruits) + threeFruitBaskets(fruits);
}

int main()
{

    int n;
    cin >> n;
    vector<int> fruits(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }
    long long sum = 0;
    for (int fruit : fruits)
    {
        sum += fruit;
    }

    long long answer = sum;
    for (int i = 1; i < n; i++)
    {
        answer *= 2;
    }
    int y = basketsLess(fruits);
    cout << answer - y;
    return 0;
}