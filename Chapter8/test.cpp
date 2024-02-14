#include <iostream>

using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void ShowBox(const box &b)
{
    // a
    cout << b.maker << endl;
    cout << b.height << endl;
    cout << b.width << endl;
    cout << b.length << endl;
}

void ShowBox(box &b)
{
    b.volume = b.length * b.height * b.width;
}

template <typename T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
T maxVolumeBox (T a, T b) {
    return (a.volume > b.volume) ? a : b;
}

int main()
{
    int res = add(3, 4);
    cout << res << endl;

    int rats = 3;
    int &ra = rats;

    cout << ra++ << endl;
    cout << rats << endl;

    box b = {"brand", 1, 2, 3};
    //ShowBox(b);

     // 创建两个 box 对象
    box box1 = {"Box1", 2, 3, 4};
    box box2 = {"Box2", 3, 4, 5};

    // 调用模板函数比较体积
    box result = maxVolumeBox(box1, box2);
    ShowBox(result);

    int g(int x);
    float m = 5.5f;
    float &rm = m;

    decltype(m) v1 = m;
    decltype(rm) v2 = m;
    decltype((m)) v3 = m;
    decltype(g(100)) v4;
    decltype(2.0 * m) v5;

    return 0;
}