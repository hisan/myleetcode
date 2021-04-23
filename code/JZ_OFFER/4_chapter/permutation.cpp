#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

class Solution {
public:
	void dfs(const string &str,vector<string> &res,string &cur_str,map<int,int> &numvisited)
	{
		if (cur_str.size() == str.size())
		{
			res.push_back(cur_str);
			return;
		}
		
		bool visited[128] = {0};
		for (size_t i = 0 ; i < str.size();++i)
		{
			if (numvisited[i] == 1)
			{
				continue;
			}
			
			if (visited[(int)str[i]] == 1)
			{
				continue;
			}
			
			visited[(int)str[i]] = 1;
			numvisited[i] = 1;
			
			cur_str.push_back(str[i]);
			
			dfs(str,res,cur_str,numvisited);
			
			cur_str.pop_back();
			numvisited[i] = 0;
		}
	}
	
    vector<string> permutation(string s) {
		vector<string> res;
		string cur_str;
		map<int,int> numvisited;
		dfs(s,res,cur_str,numvisited);
		return res;
    }
};


int main()
{
	Solution sol;
	string str;
	cin>>str;
	vector <string> res = sol.permutation(str);
	
	for (auto vecs:res)
	{
		cout<<vecs<<endl;
	}
	
	cout<<res.size()<<endl;
	
	return 0;
}



