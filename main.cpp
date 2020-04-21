#include <iostream>
#include <string>

int* getD1(std::string str)
{
    int *d1 = new int[str.size()];

    int left = 0, right = -1, tmp;

    for (int i = 0; i < str.size(); i++)
    {
        tmp = (i > right ? 1 : std::min(d1[left + right - i], right - i + 1));

        while (i + tmp < str.size() && i - tmp >= 0 && str[i + tmp] == str[i - tmp])
            tmp++;

        d1[i] = tmp;

        if (i + tmp - 1> right)
        {
            left = i - tmp + 1;
            right = i + tmp - 1;
        }
    }

    return d1;
}


int main()
{
    std::string input;
    std::cin >> input;

    int *d1 = getD1(input);

    for (int i = 0; i < input.size(); i++)
    {
        std::cout << d1[i] * 2 - 1 << " ";
    }

    return 0;
}