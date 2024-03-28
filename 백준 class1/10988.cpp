#include <bits/stdc++.h>
using namespace std;

void is_palindrome(string word)
{

    string rev_word;

    for (int i = word.length() - 1; i >= 0; i--)
    {
        rev_word += word[i];
    }

    if (word == rev_word)
    {
        cout << "yes" << '\n';
    }

    else
    {
        cout << "no" << '\n';
    }
}

int main(void)
{
    string word;
    while (1)
    {
        
        cin >> word;
        if(word == "0"){
            break;
        }
        is_palindrome(word);
        
    }

    return 0;
}