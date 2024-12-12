#include <iostream>
using namespace std;
 
string largestCharacter(string str)
{
    bool lower(26, false);
    bool upper(26, false);
 
    for (auto ch : str) {
        if (islower(ch)) {
            lower[ch - 'a'] = true;
        }
        else if (isupper(ch)) {
            upper[ch - 'A'] = true;
        }
    }
 
    for (int i = 25; i >= 0; i--) {
        if (lower[i] == true && upper[i] == true) {
            string str = "";
            str += char(i + 'A');
            return str;
        }
    }
 
    return "-1";
}
 
int main()
{
 
    string str = "admeDCAB";
    cout << largestCharacter(str);
    return 0;
}