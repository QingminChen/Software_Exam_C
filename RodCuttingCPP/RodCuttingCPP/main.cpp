
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int price[11] = { 0,1,5,8,9,10,17,17,20,24,30 };
    int n;
    cin >> n;
    vector<int> table(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        int max = -1;
        for (int j = 1; j <= i; j++)
        {
            if (price[j] + table[i - j] >= max)
            {
                max = price[j] + table[i - j];
            }
        }
        table[i] = max;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i<<" "<<table[i] << endl;
 
    }
    system("pause");
}
