#include <iostream>
#include <cmath>

using namespace std;

struct Diet
{
    int weight;
    int threshold;
    int period;
    int diet_intake;
    int basic_meta;
    int activity_meta;
    int final_meta;
};

int unchangedMeta(Diet d)
{
    int weight = d.weight;
    for (int i = 0; i < d.period; i++)
    {
        int consume = d.basic_meta + d.activity_meta;
        weight += d.diet_intake - consume;

        if (weight <= 0)
            return -1;
    }

    return weight;
}

int changedMeta(Diet &d)
{
    int weight = d.weight;
    d.final_meta = d.basic_meta;

    for (int i = 0; i < d.period; i++)
    {
        int consume = d.final_meta + d.activity_meta;
        int delta = d.diet_intake - consume;

        weight += delta;

        if (weight <= 0)
            return -1;

        if (abs(delta) > d.threshold)
            d.final_meta += floor(delta / 2.0);

        if (d.final_meta <= 0)
            return -1;
    }

    return weight;
}

void printResult(Diet &d)
{
    int unchanged = unchangedMeta(d);
    int changed = changedMeta(d);

    if (unchanged == -1)
        cout << "Danger Diet\n";
    else
        cout << unchanged << " " << d.basic_meta << "\n";

    if (changed == -1)
    {
        cout << "Danger Diet\n";
        return;
    }
    cout << changed << " " << d.final_meta << " ";

    if (d.basic_meta - d.final_meta > 0)
        cout << "YOYO\n";
    else
        cout << "NO\n";
}

int main()
{
    Diet d;

    cin >> d.weight >> d.basic_meta >> d.threshold;
    cin >> d.period >> d.diet_intake >> d.activity_meta;

    printResult(d);

    return 0;
}