// Question 1 Install g tests and add to cmakes lists X
#include <gtest/gtest.h>
#include <iostream>
#include <map>
#include <thread>
#include <cmath> 
#include <mutex>
#include <utility>
#include <assert.h>

const int values[] = { 1,2,3,4,5 };
const int NVALS = sizeof (values) / sizeof (int);
void function(char**);
void fn(int**);

template <typename T>
struct ptr_holder {
  static_assert(!std::is_same<T, std::remove_pointer<T>>::value);
  T ptr;
};

int total = 0;

class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
    }
};

class Foo {
public:
    Foo(int a, Wallet* b = NULL);
};

struct person {
   int age;
   float weight;
};

TEST(WalletTest, ThreadTest) {
    for (int k = 0; k < 1000; k++) {
        Wallet walletObject;
        std::vector<std::thread> threads;
        for(int i = 0; i < 5; ++i){
                threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
        }
        for(int i = 0; i < threads.size() ; i++)
        {
            threads.at(i).join();
        }
        EXPECT_TRUE(walletObject.getMoney()==5000) << "Error at count = "<< k <<" Money in Wallet = "<< walletObject.getMoney() << std::endl;
    }
}

int Main()
{
    // Question 2 X
    int x{10};
    int y{15};
    std::cout << x << " " << y << std::endl;

    // Question 3 Get the function to run X
    char *arr[] = { "ant", "bat", "cat", "dog", "egg", "fly" };
	function(arr);

    // Question 4 Insert in map
    typedef std::map<int, double> valmap;

    valmap m;

    for (int i = 0; i < NVALS; i++) {
        m.insert(std::make_pair(values[i], std::pow(values[i], .5)));
    }
    valmap::iterator it;              
    valmap::iterator it2;              
    m.insert(std::make_pair(1,2));
    
    // Question 5 X
    int i = 1, j = 1;
    if ( (i != 3) && (j==1))
    {
        std::cout << "inside if statement\n";
    }

    // Question 6 Store a char * pointer in template
    ptr_holder<char *> p;

    // Question 7 Fix the compiler errors and race conditions
    // Convert the testerFunction() into a google test
    

    // Question 8 X
    int n = 1;
    int *nn = &n;
    fn(&nn);

    // Question 9 X
    struct person *ptr;
    ptr = (struct person*)malloc(sizeof(struct person));
    ptr->age = 10;
    ptr->weight = 55.5;

    // Question 10 Initialise foo X
    Foo foo(0);

    // Question 11 X
    char c;
    while((c = getchar()) == EOF)
    {
        putchar(c);
    }
    return 0;                         
}

// Do not change anything besides the ptr variable
void function(char **ptr)
{
	char *ptr1;
	ptr1 = (ptr += sizeof(int))[-2];
	printf("%s\n", ptr1);
}

void fn(int** pp)
{
    printf("%p : %p : %d", pp, *pp, **pp);
}
