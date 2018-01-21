
#include "stdafx.h"
#include "sortRoyalName.h"

using namespace std;

vector<string> RoyalName::sortRoyalName(vector<string> names) 
{
	sort(names.begin(), names.end(), &RoyalName::compareNames);
	return names;
}

//return true if n1 < n2
bool RoyalName::compareNames(string name1, string name2) 
{
	//istringstream iss(name1);
	//vector<string> n1{ istream_iterator<string>{iss},istream_iterator <string> {} };
	//iss.str(name2);
	//vector<string> n2{ istream_iterator<string>{iss},istream_iterator <string> {} };

	regex ws_re("\\s+");
	vector<std::string> n1{
		sregex_token_iterator(name1.begin(), name1.end(), ws_re, -1),{}
	};
	vector<std::string> n2{
		sregex_token_iterator(name2.begin(), name2.end(), ws_re, -1),{}
	};

	if (n1.at(0).compare(n2.at(0)) < 0) return true;
	else if (n1.at(0).compare(n2.at(0)) > 0) return false;
	else {
		return RomanToInt(n1.at(1)) < RomanToInt(n2.at(1));
	}
}


int RoyalName::RomanToInt(string numeral) 
{
	if (numeral.empty()) return 0;

	unordered_map<char, int> hasht({ { 'I', 1 },{ 'V', 5 },{ 'X', 10 },{ 'L',50 } });
	int number = 0;
	for (int i = 0; i < numeral.size(); ++i) {
		number += hasht[numeral[i]];

		if (i > 0 && hasht[numeral[i]] > hasht[numeral[i - 1]]) {
			number -= 2 * hasht[numeral[i - 1]];
		}
	}
	return number;
}

void RoyalName::printResult(vector<string> result) 
{
	vector<string>::iterator it = result.begin();
	for (; it != result.end(); ++it) {
		cout << *it << "\n";
	}
}