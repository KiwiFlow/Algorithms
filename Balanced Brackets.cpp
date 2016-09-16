#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void isBalanced(string &s){
    if(!s.size()){
        cout<<"NO"<<endl;
        return;
    }
    stack<char> match;
    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            match.push(s[i]);
        }else{
            if(!match.empty() && ((s[i]=='}'&&match.top()=='{') ||
                  (s[i]==']'&&match.top()=='[') || (s[i]==')'&&match.top()=='('))){
                match.pop();
            }else{
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    if(match.empty()){
        cout<<"YES"<<endl;
        return;
    }else{
        cout<<"NO"<<endl;
        return;
    }
}

/*bool isValid(string &s) {
		if(s.empty())	return false;
        stack<char> matchStack;
		for(int i=0;i!=s.size();i++)
		{
			if(!matchStack.empty())
			{
				char frontChar=matchStack.top();
				if(frontChar=='(' && s[i]==')'
				  || frontChar=='[' && s[i]==']'
				  || frontChar=='{' && s[i]=='}')
				{
					matchStack.pop();
				}
				else
				{
					matchStack.push(s[i]);
				}
			}
			else
			{
				matchStack.push(s[i]);
			}
		}
		return matchStack.empty();
    }*/

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        isBalanced(s);
        /*if(isValid(s)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }*/
    }
    return 0;
}
