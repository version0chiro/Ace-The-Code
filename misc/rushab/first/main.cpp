#include <bits/stdc++.h>

using namespace std;

class Vector3D
{
public:
    int x, y, z;
    // Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector3D(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3D()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector3D cross(Vector3D v)
    {
        return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    }

    int dot(Vector3D v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    Vector3D operator+(Vector3D v)
    {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    Vector3D operator-(Vector3D v)
    {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    }
};
class Player
{

public:
    Vector3D Location;
    float Rotation;
    // in radians 0->parallel to x axis, pi/2->parallel to y axis
    float CollisionRadius;

    Player(int x, int y, int z, float r, float cr)
    {
        Vector3D temp(x, y, z);
        Location = temp;
        Rotation = r;
        CollisionRadius = cr;
    }
    Vector3D AimVector()
    {
        return Vector3D(cos(Rotation), sin(Rotation), 0);
    }

    bool IsBehindMe(Player Other)
    {
        Vector3D v = Other.Location - Location;

        return v.dot(AimVector()) < 0;
    }

    bool IsTargeting(Player Other)
    {
        Vector3D v = Other.Location - this->Location;
        return v.dot(AimVector()) > 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Player me = Player(0, 0, 0, 0, 0);
    Player other = Player(0, 0, 0, 0, 0);
    cin >> me.Location.x >> me.Location.y >> me.Location.z >> me.Rotation >> me.CollisionRadius;
    cin >> other.Location.x >> other.Location.y >> other.Location.z >> other.Rotation >> other.CollisionRadius;

    if (me.IsBehindMe(other))
    {
        cout << "YES, Other is behind me";
    }
    else if (me.IsTargeting(other))
    {
        cout << "YES, Player is targeting Other";
    }
    else
    {
        cout << "NO, Player is not targeting Other";
    }

    return 0;
}