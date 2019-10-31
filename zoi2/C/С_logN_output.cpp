#include <bits/stdc++.h>
//rarabar
using namespace std;

const int maxn = 3e5 + 1, sigma = 26; // 26 english letters
int len[maxn], link[maxn], to[maxn][sigma];
// serial link, vertex differ
int slink[maxn], diff[maxn], series_ans[maxn];
int sz, last, n;
char s[maxn];

void init()
{
	s[n++] = -1;
	link[0] = 1;
	len[1] = -1;
	sz = 2;
}

int get_link(int v)
{
	while (s[n - len[v] - 2] != s[n - 1])	v = link[v];
	return v;
}

void add_letter(char c)
{
	s[n++] = c -= 'a';//cout << s << " " << c << "\n";
	last = get_link(last);  // get sufix that ...abcba is a palindrome; ..abcba. is not what we want
	//for ...abcbak max sufiax is "k", for ...abcbab max sufix is "bab"
	//if vertex is not filled
	if (!to[last][c])
	{
		len[sz] = len[last] + 2;
		link[sz] = to[get_link(link[last])][c];
		diff[sz] = len[sz] - len[link[sz]];
		if (diff[sz] == diff[link[sz]])
			slink[sz] = slink[link[sz]];
		else
			slink[sz] = link[sz];
		to[last][c] = sz++;
	}
	last = to[last][c];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	string s;
	cin >> s;
	int n = s.size();
	int ans[n + 1];
	memset(ans, 63, sizeof(ans));
	ans[0] = 0;
	int row = -1;
	vector<string> res;

	
	for (int i = 1; i <= n; i++)
	{
		add_letter(s[i - 1]);
		bool second = false;
		for (int v = last; len[v] > 0; v = slink[v])
		{
			series_ans[v] = ans[i - (len[slink[v]] + diff[v])];
			if (diff[v] == diff[link[v]])
			{
				series_ans[v] = min(series_ans[v], series_ans[link[v]]);//головна динаміка abab => aba & bab, abbab => abba & bab
			//	cout<<"_";
			}
			
		
			cout<<" min("<<ans[i]<<", "<<ans[i-len[v]] + 1<<")  |  ";
			ans[i] = min(ans[i], series_ans[v] + 1); 
			
			if(second)
			{
				cout<<"\n[";
				for(int i=0; i<res.size(); ++i)
				{
					cout<<res[i]<<"  "; //TODO "\n"
				}
				cout<<"]\n";
				//old: if (ans[i]<ans[i-len[v]] + 1)
				// TODO (#1#): 
				if (ans[i] < series_ans[v] + 1)
				{
				 	//cout<<" first"<<" "<<len[i+1];
				 	cout<<"ansi-ansprev: "<<ans[i]-ans[i-1]<<"*";
					 if ((ans[i]-ans[i-1])  == 0)
					{
				 		int row_size = res[row].size();	
						int difference = len[i+1]-row_size;					
						if (row_size<len[i+1]){
						
				 		
				 			int pr_sz = res[row-1].size(); // length of previous palindrom
				 			
				 			/*
				 			{"ee","rtr"} + 'e'
				 			{"e"+"e","rtr"} + 'e'
				 			{"e"+"e","rtr"} + 'e'
				 			{"e"+"e","e"+"rtr"} + 'e'
				 			{"e"+"e"-"e","e'rtr"} + 'e'
				 			{"e","ertr"+'e'}
				 			
							 */
				 			int start = pr_sz - int(difference/2);// diff is always even, "ee","rtr"+'e' ".e" is the position
				 			//cout<<"["<<start<<"]";
							string cut =res[row-1].substr(start,pr_sz); 
							 //cout<<"{"<<cut<<"}";
							 //"ee", "rtr" + 'e' => min({ee,rtr,e} or {"e","ertre"})  //  if ".e"=='e'
						 	res[row] = cut+res[row];
						 	
							 res[row-1] =  res[row-1].substr(0,start);
			/*from previous get difference char*/
						}
	//			 		res[row]  = // get last 4 digits from s
					}
					
					if (ans[i]-ans[i-1] == -1)
					{
						
						int row_size = res[row].size();	
						int difference = len[i+1]-row_size;					
						if (row_size<len[i+1]){
						
				 		
				 			int pr_sz = res[row-2].size(); // length of previous palindrom
				 			
				 			/*
				 			{"ee","rtr"} + 'e'
				 			{"e"+"e","rtr"} + 'e'
				 			{"e"+"e","rtr"} + 'e'
				 			{"e"+"e","e"+"rtr"} + 'e'
				 			{"e"+"e"-"e","e'rtr"} + 'e'
				 			{"e","ertr"+'e'}
				 			
							 */
				 			int start = pr_sz - int(difference/2);// diff is always even, "ee","rtr"+'e' ".e" is the position
				 			//cout<<"["<<start<<"]";
							string cut =res[row-2].substr(start,pr_sz); 
												
							 cout<<"{"<<cut<<"}";
							 //"ee", "rtr" + 'e' => min({ee,rtr,e} or {"e","ertre"})  //  if ".e"=='e'
						 	res[row] = cut+res[row];
						 	
							 res[row-1] =  res[row-1].substr(0,start);
			/*from previous get difference char*/
						}
	//			 		res[row]  = // get last 4 digits from s
					}
				}
			}
			second=true;	// first time it is null
		}
		cout <<"\t\t"<<ans[i]<<"\n";
		int d = ans[i]-ans[i-1];
		switch(d)
		{
			case 1:  // new palindrom
				++row;
				res.push_back("");
				res[row] = s[i-1];
				break;
			case 0: // add to the same row
				res[row] += s[i-1];
				break;
			case -1:
				--row;
				res[row] += res[row+1];
				res[row] += s[i-1];
				res.pop_back();
				break;
			default:
				cout<<"\n\nHow did you get here. It must not happen\n\n";	
		}

	}
	cout<<ans[n]<<endl;
	for(int i=0; i<res.size(); ++i)
	{
		cout<<res[i]<<"\n"; //TODO "\n"
	}	
	return 0;
}

