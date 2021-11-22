#include <vector>
#include <stdio.h>


int main(void)
{
    std::vector<std::vector<int>> test;

    int numbers[] = {0,1,2,3,4,5};
    for(int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); ++i)
    {
        std::vector<int> temp;
        for(int j=0; j<=i; ++j)
        {
            temp.push_back(numbers[j]);
        }
        test.push_back(temp);
    }

    for(auto row : test)
    {
        for(auto num : row)
        {
            printf("%d - ",num);
        }
        printf("\n");
    }

    test.erase(test.begin() + 1);
    test.erase(test.begin() + 1);
    test.erase(test.begin() + 1);
    test.erase(test.begin() + 1);
    test.erase(test.begin() + 1);
    test.clear();

    for(auto row : test)
    {
        for(auto num : row)
        {
            printf("%d - ",num);
        }
        printf("\n");
    }


    return 0;
}