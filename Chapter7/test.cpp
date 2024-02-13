#include <iostream>

using namespace std;

struct boss
{
};

void ofcourse(struct boss b);

void setArr(int arr[], int arrLen, int num)
{
    for (int i = 0; i < arrLen; i++)
    {
        arr[i] = num;
    }
}

void setArrP(int *begin, int *end, int number)
{
    for (int *current = begin; current != end; ++current)
    {
        *current = number;
    }
}

double findMax(const double arr[], int arrLength)
{
    double max = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int replace(char *str, char c1, char c2);

struct applicant
{
    char name[30];
    int credit_ratings[3];
};

void showApplicant(const struct applicant app)
{
    cout << app.name << endl;
    for(int i=0;i<3;++i)
    {
        cout << app.credit_ratings[i] <<endl;
    }
}

void showApplicantP(const struct applicant* app)
{
    cout << app->name << endl;
    for(int i=0;i<3;++i)
    {
        cout << app->credit_ratings[i] <<endl;
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    for (auto a : arr)
    {
        cout << a << endl;
    }

    // setArr(arr,sizeof(arr), 1);
    // for(auto a:arr)
    // {
    //     cout << a << endl;
    // }

    setArrP(arr, arr + sizeof(arr), 1);
    for (auto a : arr)
    {
        cout << a << endl;
    }

    const double arrf[3] = {1.0, 2.0, 3.9};
    double x = findMax(arrf, 3);
    cout << x << endl;

    char str[] = "hello world!";
    int count = replace(str, 'h', 'c');
    cout << count << endl;

    int intArr[3] ={1,3,3};
    applicant a = {"name", {1,2,3}};
    showApplicant(a);
    showApplicantP(&a);

    return 0;
}

int replace(char *str, char c1, char c2)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
            count++;
        }
    }
    return count;
}