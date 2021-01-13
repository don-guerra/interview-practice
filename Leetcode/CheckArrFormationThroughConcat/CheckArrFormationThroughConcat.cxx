#include <iostream>
#include <vector>
#include <map>

bool canFormArray(std::vector<int> &arr, std::vector<std::vector<int>> &pieces);

int main()
{
    std::vector<int> arr{85};
    std::vector<std::vector<int>> pieces{{85}};
    std::cout << "First test\t" << canFormArray(arr, pieces) << std::endl;

    arr = {15, 88};
    pieces = {{88}, {15}};
    std::cout << "Second test\t" << canFormArray(arr, pieces) << std::endl;

    arr = {49, 18, 16};
    pieces = {{16, 18, 49}};
    std::cout << "Third test\t" << canFormArray(arr, pieces) << std::endl;

    arr = {91, 4, 64, 78};
    pieces = {{78}, {4, 64}, {91}};
    std::cout << "Fourth test\t" << canFormArray(arr, pieces) << std::endl;
    return 0;
}

bool canFormArray(std::vector<int> &arr, std::vector<std::vector<int>> &pieces)
{
    std::map<int, std::vector<int>> piecesMap;
    for (int i = 0; i < pieces.size(); i++)
    {
        piecesMap.insert(std::pair<int, std::vector<int>>(pieces[i][0], pieces[i]));
    }

    int arrIndex = 0;
    while (arrIndex < arr.size())
    {
        int arrKey = arr[arrIndex];
        std::map<int, std::vector<int>>::iterator it = piecesMap.find(arrKey);

        if (it == piecesMap.end())
        {
            return false;
        }

        int piecesIndex = 0;
        std::vector<int> piecesAtKey = piecesMap.at(arrKey);
        while (arrIndex < arr.size() && piecesIndex < piecesAtKey.size())
        {
            if (arr[arrIndex++] != piecesAtKey[piecesIndex++])
            {
                return false;
            }
        }

        piecesMap.erase(it);
    }

    if (piecesMap.size() > 0)
    {
        return false;
    }

    return true;
}