#include <bits/stdc++.h>
using namespace std;
int main(void){
	
	string S;
	S="abbab";
	// Every single char is palindrome so L[i][0] = 1;
	vector<vector<int> > L(S.length(), vector<int>(1,1));
	
	for (int i = 0; i < S.length(); i++) {
	 for (int j = 2; j < S.length(); j++) {
	   if (i - j + 1 >= 0 && S[i] == S[i-j + 1]) {
	     // See if there was a palindrome of length j - 2 ending at S[i-1]
	     bool inner_palindrome = false;
	     if (j ==2) {
	      inner_palindrome = true;
	     } else {
	       int k = (L[i-1]).size();
	       if (L[i-1][k-1] == j-2 || (k >= 2 && L[i-1][k-2] == j-2)) {
	         inner_palindrome = true;
	       }
	     }
	     if (inner_palindrome) {
	       L[i].push_back(j);
	     }
	   } 
	 }
	} 
	for (int i=0; i<L.size(); ++i) 
    {
    	for (int j=0; j<L[i].size(); ++j) 
	    {
	    	
	    	cout<<L[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

