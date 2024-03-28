//https://eunchanee.tistory.com/91 
//밑의 풀이 말고 다른 풀이  -참고-


#include <bits/stdc++.h>
using namespace std;

bool ck(char c)
{
    if (c >= '1' && c <= '9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
struct fileName
{
    int index;
    string head;
    int number;
};
bool cmp(const fileName &f1, const fileName &f2)
{
    if (f1.head == f2.head)
    {
        if(f1.number==f2.number){
            return f1.index < f2.index;
        }
        return f1.number < f2.number;
    }
    return f1.head<f2.head;
}



vector<fileName> v;

vector<string> solution(vector<string> files)
{
    vector<string> answer;

    // head,number부분 구하기

    for (int i = 0; i < files.size(); i++)
    {
        vector<int> idx;
        for (int j = 0; j < files[i].size(); j++)
        {
            if (0 <= files[i][j] && files[i][j] <= '9')
            {
                idx.push_back(j);
            }
        }
        string head = "";
        for (int j = 0; j < idx[0]; j++)
        {
            head += tolower(files[i][j]);
        }
        string number = files[i].substr(idx[0], idx.size());

        fileName f;
        f.index = i;
        f.head = head;
        f.number = stoi(number);
        v.push_back(f);
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<v.size();i++){
        answer.push_back(files[v[i].index]);
    }

    return answer;
}

int main()
{
    // Example usage:
    vector<string> files = {"img12.png", "IMG10.png", "img2.png", "img1.png"};
    vector<string> result = solution(files);

    for (const auto &file : result)
    {
        cout << file << '\n';
    }

    return 0;
}