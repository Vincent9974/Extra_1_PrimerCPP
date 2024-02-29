#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <list>
#include <memory>

bool isPalindrome(const std::string &str)
{
    auto begin = str.begin();
    auto end = str.end();

    while (begin < end)
    {
        if (tolower(*begin) != tolower(*end))
        {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

void _16_10_1()
{
    std::string input;
    std::cout << "Enter a string:";
    std::getline(std::cin, input);
    if (isPalindrome(input))
    {
        std::cout << "The string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The string is not a palindrome." << std::endl;
    }
}

bool isPalindrome1(const std::string &str)
{
    std::string cleanedStr;

    for (char ch : str)
    {
        if (std::isalnum(ch))
        {
            cleanedStr += std::tolower(ch);
        }
    }

    // 使用前后比较，检查是否是回文
    auto begin = cleanedStr.begin();
    auto end = cleanedStr.end() - 1;

    while (begin < end)
    {
        if (*begin != *end)
        {
            return false;
        }
        ++begin;
        --end;
    }

    return true;
}

void _16_10_2()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindrome1(input))
    {
        std::cout << "The string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The string is not a palindrome." << std::endl;
    }
}

void _16_10_3()
{
    std::ifstream inFile("word.txt");

    if (!inFile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
    }

    std::vector<std::string> words;
    std::string word;

    while (inFile >> word)
    {
        words.push_back(word);
    }

    std::cout << "Words from the file:" << std::endl;
    for (const auto &w : words)
    {
        std::cout << w << std::endl;
    }

    inFile.close();
}

int reduce(long ar[], int n)
{
    std::sort(ar, ar + n);

    auto end = std::unique(ar, ar + n);

    int reduceSize = end - ar;

    return reduceSize;
}

void _16_10_4()
{
    long ar[7] = {1, 1, 2, 2, 3, 4, 5};

    int n = reduce(ar, 7);

    std::cout << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << *ar + i << std::endl;
    }
}

template <class T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);
    auto endIt = std::unique(ar, ar + n);
    return std::distance(ar, endIt);
}

void _16_10_5()
{
    // Test with long array
    long longArray[] = {1, 2, 3, 4, 3, 2, 5, 6, 7, 8, 7};
    int longSize = sizeof(longArray) / sizeof(longArray[0]);

    std::cout << "Original Size of longArray: " << longSize << std::endl;

    int reducedLongSize = reduce(longArray, longSize);

    std::cout << "Reduced Size of longArray: " << reducedLongSize << std::endl;

    // Test with string array
    std::string stringArray[] = {"apple", "banana", "orange", "apple", "grape"};
    int stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original Size of stringArray: " << stringSize << std::endl;

    int reducedStringSize = reduce(stringArray, stringSize);

    std::cout << "Reduced Size of stringArray: " << reducedStringSize << std::endl;
}

void _16_10_6()
{
    std::queue<int> myQueue;

    for (int i = 0; i <= 5; ++i)
    {
        myQueue.push(i * 10);
    }

    while (!myQueue.empty())
    {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
}

std::vector<int> Lotto(int totalNumbers, int selectedNumbers)
{
    // Initialize a vector with all possible numbers
    std::vector<int> allNumbers(totalNumbers);
    for (int i = 0; i < totalNumbers; ++i)
    {
        allNumbers[i] = i + 1;
    }

    // Seed for randomness
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Shuffle the vector
    std::random_shuffle(allNumbers.begin(), allNumbers.end());

    // Create a vector to store selected numbers
    std::vector<int> selected;

    // Copy the first 'selectedNumbers' from the shuffled vector
    std::copy(allNumbers.begin(), allNumbers.begin() + selectedNumbers, std::back_inserter(selected));

    return selected;
}

void _16_10_7()
{
    std::vector<int> winners = Lotto(51, 6);

    // Print the randomly selected numbers
    for (int number : winners)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void _16_10_8()
{
    std::cout << "Mat,请输入朋友的姓名列表(以空格分隔,输入exit结束): " << std::endl;
    std::vector<std::string> matFriends;
    std::string matFriendName;
    while (std::cin >> matFriendName && matFriendName != "exit")
    {
        if (matFriendName == "exit")
        {
            break;
        }
        matFriends.push_back(matFriendName);
    }

    // 按排列后的顺序显示Mat的朋友列表
    std::sort(matFriends.begin(), matFriends.end());
    std::cout << "Mat的朋友列表(按排列后的顺序): ";
    for (const auto &name : matFriends)
    {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    std::cout << "Pat,请输入朋友的姓名列表(以空格分隔,输入exit结束): " << std::endl;
    std::vector<std::string> patFriends;
    std::string patFriendName;
    while (std::cin >> patFriendName && patFriendName != "exit")
    {
        if (patFriendName == "exit")
        {
            break;
        }
        patFriends.push_back(patFriendName);
    }

    // 按排列后的顺序显示Mat的朋友列表
    std::sort(patFriends.begin(), patFriends.end());
    std::cout << "Pat的朋友列表(按排列后的顺序): ";
    for (const auto &name : patFriends)
    {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    std::vector<std::string> totalName;
    std::merge(matFriends.begin(), matFriends.end(),
               patFriends.begin(), patFriends.end(), std::back_inserter(totalName));

    std::sort(totalName.begin(), totalName.end());
    auto uniqueEnd = std::unique(totalName.begin(), totalName.end());
    totalName.erase(uniqueEnd, totalName.end());

    // 显示合并后的朋友列表
    std::cout << "合并后的朋友列表（删除重复部分并按排列后的顺序）: ";
    for (const auto &name : totalName)
    {
        std::cout << name << " ";
    }
    std::cout << std::endl;
}

void _16_10_9()
{
    const int SIZE = 1000000; // 可以根据需要修改数组大小

    // 创建一个大型 vector 并使用 rand() 初始化
    std::vector<int> vi0(SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        vi0[i] = rand();
    }

    // 创建 vector 和 list，它们的长度与 vi0 相同
    std::vector<int> vi(vi0.begin(), vi0.end());
    std::list<int> li(vi0.begin(), vi0.end());

    // 测试 vector 的排序性能
    clock_t start = clock();
    std::sort(vi.begin(), vi.end());
    clock_t end = clock();
    std::cout << "Time taken for sorting vector: "
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";

    // 将 list 重置为排序后的 vi0 的内容，排序并将结果复制到 li 中
    start = clock();
    li.assign(vi0.begin(), vi0.end());
    li.sort();
    end = clock();
    std::cout << "Time taken for sorting list: "
              << (double)(end - start) / CLOCKS_PER_SEC << " seconds\n";
}

// 在结构Review中添加成员price
struct Review
{
    std::string title;
    int rating;
    double price; // 新添加的成员
};

void displayBooks(const std::vector<std::shared_ptr<Review>> &books)
{
    for (const auto &book : books)
    {
        std::cout << "Title: " << book->title << "\tRating: " << book->rating << "\tPrice: " << book->price << std::endl;
    }
}

bool compareTitles(const std::shared_ptr<Review> &a,
                   const std::shared_ptr<Review> &b)
{
    return a->title < b->title;
}

bool compareRatings(const std::shared_ptr<Review> &a,
                    const std::shared_ptr<Review> &b)
{
    return a->rating < b->rating;
}

bool comparePrices(const std::shared_ptr<Review> &a,
                   const std::shared_ptr<Review> &b)
{
    return a->price < b->price;
}

void _16_10_10()
{
    std::vector<Review> books = {
        {"Book1", 4, 25.0},
        {"Book3", 5, 30.0},
        {"Book2", 3, 20.0}
        // 可以根据实际情况添加更多书籍
    };


    std::vector<std::shared_ptr<Review>> bookPtrs;
    for (const auto &book : books)
    {
        // 使用new返回的指针来初始化shared_ptr
        auto ptr = std::make_shared<Review>(book);
        bookPtrs.push_back(ptr);
    }

    while (1)
    {
        // 提示用户选择如何显示书籍
        std::cout << "\nChoose how to display books:" << std::endl;
        std::cout << "1. Original Order\t2. Alphabetical Order\t3. Rating Ascending Order" << std::endl;
        std::cout << "4. Rating Descending Order\t5. Price Ascending Order\t6. Price Descending Order\t7. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        // 根据用户选择排序并显示书籍
        switch (choice)
        {
        case 1:
            // 按原始顺序显示
            displayBooks(bookPtrs);
            break;
        case 2:
            // 按字母表顺序显示
            std::sort(bookPtrs.begin(), bookPtrs.end());
            displayBooks(bookPtrs);
            break;
        case 3:
            // 按评级升序显示
            std::sort(bookPtrs.begin(), bookPtrs.end(),
                      [](const std::shared_ptr<Review> &a, const std::shared_ptr<Review> &b)
                      { return a->rating < b->rating; });
            displayBooks(bookPtrs);
            break;
        case 4:
            // 按评级降序显示
            std::sort(bookPtrs.rbegin(), bookPtrs.rend(),
                      [](const std::shared_ptr<Review> &a, const std::shared_ptr<Review> &b)
                      { return a->rating < b->rating; });
            displayBooks(bookPtrs);
            break;
        case 5:
            // 按价格升序显示
            std::sort(bookPtrs.begin(), bookPtrs.end(),
                      [](const std::shared_ptr<Review> &a, const std::shared_ptr<Review> &b)
                      { return a->price < b->price; });
            displayBooks(bookPtrs);
            break;
        case 6:
            // 按价格降序显示
            std::sort(bookPtrs.rbegin(), bookPtrs.rend(),
                      [](const std::shared_ptr<Review> &a, const std::shared_ptr<Review> &b)
                      { return a->price < b->price; });
            displayBooks(bookPtrs);
            break;
        case 7:
            // 退出
            std::cout << "Exiting..." << std::endl;
            return;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
}

int main()
{

    //_16_10_1();

    //_16_10_2();

    //_16_10_3();

    //_16_10_4();

    //_16_10_5();

    //_16_10_6();

    //_16_10_7();

    //_16_10_8();

    //_16_10_9();

    _16_10_10();

    return 0;
}