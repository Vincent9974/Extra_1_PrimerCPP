#include <iostream>
#include "Wine.h"
#include "Wine1.h"
#include "QueueTp.h"
#include "Worker.h"
#include "Person.h"
#include "ctime"
#include "Company.h"


void _14_7_1()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};

    Wine more("Gushing Grape Red", YRS, y, b);
    more.show();

    cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;

    cout << "Bye\n";

}


void _14_7_2()
{
    std::cout << "Enter name of wine: ";
    char lab[50];
    std::cin.getline(lab, 50);

    std::cout << "Enter number of years: ";
    int yrs;
    std::cin >> yrs;

    Wine1 holding(lab, yrs);
    holding.GetBottles();
    holding.show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine1 more("Gushing Grape Red", YRS, y, b);

    more.show();
    std::cout << "Total bottles for " << more.Label() << ": " << more.sum() << "\n";

}

void _14_7_3()
{
    QueueTp<Worker*> workerQueue;

    Worker* w1 = new Worker("John", 25);
    Worker* w2 = new Worker("Alice", 30);

    workerQueue.enqueue(w1);
    workerQueue.enqueue(w2);

    Worker* removedWorker;
    while (workerQueue.dequeue(removedWorker)) 
    {
        std::cout << "Dequeued worker: " << removedWorker->getName() << "\n";
        delete removedWorker;
    }

}

void _14_7_4()
{
    // Gunslinger gunslinger("John", "Doe", 3.5, 10);
    // gunslinger.Show();

    std::srand(std::time(0));

    BadDude badDude("John", "Doe", 5.0, 3);

    badDude.Show();
    std::cout << "Gunslinger draw time: " << badDude.Gdraw() << std::endl;
    std::cout << "PokerPlayer draw: " << badDude.Cdraw() << std::endl;

}

void _14_7_5()
{
    employee em("Trip", "Harris", "Thumper");
    std::cout << em << std::endl;
    em.showAll();

    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << ma << std::endl;
    ma.showAll();

    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << fi << std::endl;
    fi.showAll();

    highfink hf(ma, "Curly Kew");
    std::cout << "Recruitment? ";
    hf.showAll();

    std::cout << "Press a key for next phase: \n";
    std::cin.get();

    highfink hf2;
    hf2.SetAll();

    std::cout << "Using an abstr_emp * pointer: \n";
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->showAll();
}

int main()
{

    //_14_7_1();

    //_14_7_2();

    //_14_7_3();

    //_14_7_4();

    _14_7_5();

    return 0;
}