// zoi2 C Palindrom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>


//rarabar
using namespace std;

const int maxn = 3e5 + 1, sigma = 26; // 26 english letters
int len[maxn], link[maxn], to[maxn][sigma];
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
	while (s[n - len[v] - 2] != s[n - 1]) v = link[v];
	return v;
}

void add_letter(char c)
{
	s[n++] = c -= 'a';
	cout << s << " " << c << "\n";
	last = get_link(last);
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
	int* ans = new int[n + 1];
	memset(ans, 63, sizeof(ans));
	ans[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		add_letter(s[i - 1]);
		for (int v = last; len[v] > 0; v = slink[v])
		{
			series_ans[v] = ans[i - (len[slink[v]] + diff[v])];
			if (diff[v] == diff[link[v]]) {
				series_ans[v] = min(series_ans[v], series_ans[link[v]]);
				//cout<<"cond";

			}
			else //cout<<"else";
				ans[i] = min(ans[i], series_ans[v] + 1);
		}
		cout << ans[i] << "\n";
	}
	for (int i = 0; i < n + 50; ++i)
	{
		//  cout<<link[i]<<" ";
		for (int j = 0; j < sigma; ++j)
		{
			//              cout<<to[i][j]<<" ";
		}
		//   cout<<endl;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
