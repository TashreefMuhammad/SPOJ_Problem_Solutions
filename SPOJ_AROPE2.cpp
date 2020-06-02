#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, l, q, x, y, t;
    string s, tmp;

    cin >> s;
    l = s.size();
    cin >> q;
    string queued[q+1];
    queued[0] = s;

    for(i = 1; i <= q; i++)
    {
        cin >> t;

        if(t == 1 || t== 2)
        {
            cin >> x >> y;

            if(x > y)
                swap(x, y);

            if(x == 0 && y == l)
               continue;
            tmp = s.substr(x, y-x+1);
            s.erase(x, y-x+1);
            if(t == 1)
                queued[i] = s = tmp + s;
            else
                queued[i] = s = s + tmp;
        }
        else if(t == 3)
        {
            cin >> y;
            cout << s[y] << "\n";
            queued[i] = queued[i-1];
        }
        else
        {
            cin >> x >> y;
            cout << queued[x][y] << "\n";
            queued[i] = queued[i-1];
        }
    }

    return 0;
}
