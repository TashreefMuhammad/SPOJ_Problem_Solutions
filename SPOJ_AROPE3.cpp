/**
  * Both solution using Rope and only String is given here
  * The rope part is uncommented and string part is commented
  * Start and end points for each solutions are marked using comments
  * comment/uncomment specific parts to see each type at work
**/


/// Solution using Rope Data Structure start here
#include <iostream>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, l, q, x, y, t;
    string s;
    rope <char> r_f, r_b, tmp_b, tmp_f;

    cin >> s;
    l = s.size();
    cin >> q;

    for(i = 0; i < l; i++)
        r_f.push_back(s[i]);
    for(i = l-1; i >= 0; i--)
        r_b.push_back(s[i]);


    while(q--)
    {
        cin >> t;

        if(t == 1 || t== 2)
        {
            cin >> x >> y;
            if(x > y)
                swap(x, y);

            if(x == 0 && y == l-1)
                continue;
            tmp_b = r_f.substr(x, y-x+1);
            r_f.erase(x, y-x+1);

            x = l - 1 - x;
            y = l - 1 - y;
            if(x < y)
                swap(x, y);
            tmp_f = r_b.substr(y, x-y+1);
            r_b.erase(y, x-y+1);

            if(t == 1)
            {
                r_f.insert(r_f.mutable_begin(), tmp_f);
                r_b.insert(r_b.mutable_end(), tmp_b);
            }
            else
            {
                r_f.insert(r_f.mutable_end(), tmp_f);
                r_b.insert(r_b.mutable_begin(), tmp_b);
            }
        }
        else
        {
            cin >> y;
            cout << r_f[y] << "\n";
        }
    }

    return 0;
}
/// Solution using Rope Data Structure end here

/// Solution using only STL string functions start here

/** Please note that only when chosen
  * Compiler: C++(g++ 4.3.2)
  * I got the solution of using only string accepted.
  * Rope is faster than string here, so though Rope can pass
  * using other C++ compilers of SPOJ judge, the string solution
  * does not get TLE only while using the given compiler when I tested
**/
/*
#include <iostream>
#include <cstring>
#include <algorithm>

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

    while(q--)
    {
        cin >> t;

        if(t == 1 || t== 2)
        {
            cin >> x >> y;
            if(x > y)
                swap(x, y);

            if(x == 0 && y == l-1)
                continue;

            tmp = s.substr(x, y-x+1);
            reverse(tmp.begin(), tmp.end());
            s.erase(x, y-x+1);

            if(t == 1)
                s = tmp + s;
            else
                s = s + tmp;
        }
        else
        {
            cin >> y;
            cout << s[y] << "\n";
        }
    }

    return 0;
}
*/
/// Solution using only STL string functions end here
