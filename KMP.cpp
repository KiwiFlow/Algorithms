#include<iostream>
#include<string>
#include<vector>
using namespace std;



void getNext(vector<int> &n,string &P){
	n[0] = -1;
	for(int i=1;i<n.size();i++){
		int k = n[i-1];
		while(true){
			if(k==-1){
				n[i] = 0;
				break;
			}else{
				if(P[i-1] == P[k]){
					n[i] = k+1;
					break;
				}else{
					k = n[k];
				}
			}
		}
	}
}

void kmp(string &P,string &T){
	vector<int> n(P.size(),0);
	getNext(n,P);
	int j = 0;
	for(int i=0;i<T.size();){
		if(j==-1 || P[j]==T[i]){
			j++;
			i++;
			if(j==P.size()){
				cout<<T.substr(i-P.size(),P.size())<<endl;
				j=0;
			}
		}else{
			j = n[j];
		}
	}
}



int main() {
	string P = "ababc";
	string T = "aaabbaaaababccccccdegaegagreoijjababcopierjfwerqweqwe";
	kmp(P,T);
	string P1 = "jkfqpehq";
	string T1 = "jkfqpehaasdfasgasgagajkfqpehhhhhhqwdasfgwetqeraafafd";
	kmp(P1,T1);
	string P2 = "Apache";
	string T2 = "The ASF provides an established framework for intellectual property and financial contributions that simultaneously limits potential legal exposure for our project committers. Through the ASF's meritocratic process known as The Apache Way, more than 500 individual Members and 4,500 Committers successfully collaborate to develop freely available enterprise-grade software, benefiting millions of users worldwide: thousands of software solutions are distributed under the Apache License; and the community actively participates in ASF mailing lists, mentoring initiatives, and ApacheCon, the Foundation's official user conference, trainings, and expo.";
	kmp(P2,T2);
    return 0;
}
