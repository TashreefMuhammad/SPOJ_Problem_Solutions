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
    int i, l, q, x, y, t;
    string s;
    rope <char> r, tmp;

    cin >> s;
    l = s.size();
    cin >> q;

    for(i = 0; i < l; i++)
        r.push_back(s[i]);

    while(q--)
    {
        cin >> t;

        if(t == 1 || t== 2)
        {
            cin >> x >> y;

            if(x > y)
                swap(x, y);

            if(x == 0 && y == l)
               continue;
            tmp = r.substr(x, y-x+1);
            r.erase(x, y-x+1);
            if(t == 1)
                r.insert(r.mutable_begin(), tmp);
            else
                r.insert(r.mutable_end(), tmp);
        }
        else
        {
            cin >> y;
            cout << r[y] << "\n";
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

            if(x == 0 && y == l)
               continue;
            tmp = s.substr(x, y-x+1);
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
