#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
const int MAX=100;
using namespace std;
struct INFO
{
    INFO()
    {
        nScore = nGet = nLost = 0;
    }

    string strName;
    int nScore;
    int nGet;
    int nLost;
    bool operator < (const INFO& one) const
    {
        if (nScore != one.nScore)
        {
            return nScore > one.nScore;
        }
        else if (nGet - nLost != one.nGet - one.nLost)//这里把one.nLost写成了one.nGet
        {
            return nGet - nLost > one.nGet - one.nLost;
        }
        else if (nGet != one.nGet)
        {
            return nGet > one.nGet;
        }
        else
        {
            return strName < one.strName;
        }
    }
};

int main()
{
    int nN;
    while (scanf("%d", &nN) == 1)
    {
        int nLast = nN * (nN - 1);
        char szOne[MAX];
        char szTwo[MAX];
        int nOne, nTwo;

        map<string, INFO> myMap;
        for (int i = 0; i < nLast; ++i)
        {
            scanf("%s %*s %s %d:%d", szOne, szTwo, &nOne, &nTwo);
            string strOne = szOne;
            myMap[strOne].strName = strOne;
            myMap[strOne].nGet += nOne;
            myMap[strOne].nLost += nTwo;
			string strTwo = szTwo;
            myMap[strTwo].strName = strTwo;
            myMap[strTwo].nGet += nTwo;
            myMap[strTwo].nLost += nOne;

            if (nOne > nTwo)
            {
                myMap[strOne].nScore += 3;
            }
            else if (nOne == nTwo)
            {
                myMap[strOne].nScore += 1;
                myMap[strTwo].nScore += 1;
            }
            else
            {
                myMap[strTwo].nScore += 3;
            }
        }

        map<string, INFO>::iterator it;
        vector<INFO> myVt;
        for (it = myMap.begin(); it != myMap.end(); it++)
        {
            myVt.push_back(it->second);
        }

        sort(myVt.begin(), myVt.end());
        for (int i = 0; i < myVt.size(); ++i)
        {
            printf("%s %d\n", myVt[i].strName.c_str(), myVt[i].nScore);
        }
        printf("\n");
    }

    return 0;
}
