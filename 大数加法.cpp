/*给出2个大整数A,B，计算A+B的结果。
Input
第1行：大数A
第2行：大数B
(A,B的长度 <= 10000 需注意：A B有可能为负数）
Output
输出A + B
Input示例
68932147586
468711654886
Output示例
537643802472*/

#include<iostream>
#include<string>

using namespace std;


string addTwoString(string s,string num){
    int max_len=max(s.length(), num.length()), min_len=min(s.length(), num.length());
    string res(max_len+1, '0');
    int carry = 0;
    string::reverse_iterator a_iter=num.rbegin();
    string::reverse_iterator b_iter=s.rbegin();
    int i = res.size()-1;
    for (;a_iter != num.rend() && b_iter != s.rend() ;a_iter++, b_iter++, i--) {
        res[i] = *a_iter - '0' + *b_iter - '0' + carry;
        carry = res[i]/10;
        res[i] = res[i] % 10 + '0';
    }
    for (;a_iter != num.rend();a_iter++, i--) {
        res[i] = *a_iter - '0'  + carry;
        carry = res[i]/10;
        res[i] = res[i] % 10 + '0';
    }

    for (;b_iter != s.rend() ;b_iter++, i--) {
        res[i] = *b_iter - '0' + carry;
        carry = res[i]/10;
        res[i] = res[i] % 10 + '0';
    }

    res[i] = carry+'0';

    return res;
}

string subTwoString(string a,string b){
    int max_len=max(a.length(), b.length()), min_len=min(a.length(), b.length());
    string res(max_len, '0');
    int  recede = 0;
    string::reverse_iterator a_iter=a.rbegin();
    string::reverse_iterator b_iter=b.rbegin();
    int i = res.size()-1;
    for (;a_iter != a.rend() && b_iter != b.rend() ;a_iter++, b_iter++, i--) {
        res[i] = *a_iter - *b_iter - recede;
        if (res[i] < 0) {
            recede = 1;
            res[i] = res[i] + 10 + '0';
        } else {
            recede = 0;
            res[i] = res[i] + '0';
        }
    }
    for (;a_iter != a.rend();a_iter++, i--) {
        res[i] = *a_iter - '0' - recede;
        if (res[i] < 0) {
            recede = 1;
            res[i] = res[i] + 10 + '0';
        } else {
            recede = 0;
            res[i] = res[i] + '0';
        }
    }

    for (;b_iter != b.rend() ;b_iter++, i--) {
        res[i] = *b_iter - '0' - recede;
        if (res[i] < 0) {
            recede = 1;
            res[i] = res[i] + 10 + '0';
        } else {
            recede = 0;
            res[i] = res[i] + '0';
        }
    }
    return res;
}

int main(){
    string a,b;
    cin>>a;
    cin>>b;
    
    if(a[0]=='-' && b[0]=='-'){
        string c = addTwoString(a.substr(1),b.substr(1));
        string::size_type begin_idx = c.find_first_not_of("0");
        if (begin_idx == string::npos) {
            cout << "0" << endl;
        }
        else{
            cout << "-" << c.substr(begin_idx) <<endl;
        }
    }

    if(a[0]!='-' && b[0]!='-'){
        string c = addTwoString(a,b);
        string::size_type begin_idx = c.find_first_not_of("0");
        if (begin_idx == string::npos) {
            cout << "0" << endl;
        }
        else{
            cout << c.substr(begin_idx) <<endl;
        }
    }

    if(a[0]!='-' && b[0]=='-'){
        if(a.size() > b.substr(1).size() || a.size() == b.substr(1).size() && a > b.substr(1)){
            string c = subTwoString(a,b.substr(1));
            string::size_type begin_idx = c.find_first_not_of("0");
            if (begin_idx == string::npos) {
                cout << "0" << endl;
            }
            else{
                cout << c.substr(begin_idx) <<endl;
            }

        }else{
            string c = subTwoString(b.substr(1),a);
            string::size_type begin_idx = c.find_first_not_of("0");
            if (begin_idx == string::npos) {
                cout << "0" << endl;
            }
            else{
                cout << "-" << c.substr(begin_idx) <<endl;
            }
        }
    }

    if(a[0]=='-' && b[0]!='-'){
        if(b.size() > a.substr(1).size() || b.size() == a.substr(1).size() && b > a.substr(1)){
            string c = subTwoString(b,a.substr(1));
            string::size_type begin_idx = c.find_first_not_of("0");
            if (begin_idx == string::npos) {
                cout << "0" << endl;
            }
            else{
                cout << c.substr(begin_idx) <<endl;
            }
            
        }else{
            string c = subTwoString(a.substr(1),b);
            string::size_type begin_idx = c.find_first_not_of("0");
            if (begin_idx == string::npos) {
                cout << "0" << endl;
            }
            else{
                cout<< "-" << c.substr(begin_idx) <<endl;
            }
        }
    }

    return 0;
}
