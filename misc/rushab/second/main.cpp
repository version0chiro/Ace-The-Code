#include <bits/stdc++.h>

using namespace std;

class BigBoomer : public Item
{
private:
    const float fAttackPeriod;
    float fTimeUntilNextAttack = 0.9f;
    void Fire()
    {
        // deal magical damage in a 40 unit radius
    }

public:
    void Tick(float fDeltaSeconds)
    {
        // Fire Big Boomer every "fAttackPeriod" seconds
        fTimeUntilNextAttack -= fDeltaSeconds;
        if (fTimeUntilNextAttack <= 0.0f)
        {
            Fire();
            fTimeUntilNextAttack = fAttackPeriod;
        }
    }
}

int
main()
{
    // fAttackPeriod = 0.9 and Frame time = 1.0 seconds
    BigBoomer boomer;
    // boomer.fTimeUntilNextAttack = 0.9f;

    boomer.Tick(1.0f);

    return 0;
}