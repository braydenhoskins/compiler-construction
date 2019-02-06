#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//stores temporary string values for comparison
char ab_temp;
string aa_temp;
string abc_temp;
string aa0aa_temp;
string aab_temp;
//stores indexes of correct occurrences
vector <int> abc_vector;
vector <int> a_vector;
vector <int> ab_vector;
vector <int> aab_vector;
vector <int> aa0aa_vector;
//functions to detect correct indexes
int check_abc(char, int);
int check_a(char, int);
int check_ab(char, int);
int check_aab(char, int);
int check_aa0aa(char, int);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "too few arguments" << endl;
        return 0;
    }
    ifstream file(argv[1]);
    char c;
    int cnt=0;
    string temp;
    vector <int> :: iterator it;
    cout << "file: " << endl;
    while(file.get(c))
    {
    	cout << c;
        cnt++;
        check_abc(c, cnt);
        check_a(c, cnt);
        check_ab(c, cnt);
        check_aab(c, cnt);
        check_aa0aa(c, cnt);
    }
    // loop through vectors print index of occurrence to console
    cout << endl << "a: [";
    for(it = a_vector.begin(); it != a_vector.end(); ++it)
    {
        if(it == a_vector.end() - 1)
        	cout << *it;
        else
        	cout << *it << ",";
    }
    cout << "]" << endl << "ab: [";
    for(it = ab_vector.begin(); it != ab_vector.end(); ++it)
    {
        if(it == ab_vector.end() - 1)
        	cout << *it;
        else
        	cout << *it << ",";
    }
    cout << "]" << endl << "aab: [";
    for(it = aab_vector.begin(); it != aab_vector.end(); ++it)
    {
        if(it == aab_vector.end() - 1)
        	cout << *it;
        else
        	cout << *it << ",";
    }
    cout << "]" << endl << "abc: [";
    for(it = abc_vector.begin(); it != abc_vector.end(); ++it)
    {
        if(it == abc_vector.end() - 1)
        	cout << *it;
        else
        	cout << *it << ",";
    }
    cout << "]" << endl << "aa0aa: [";
    for(it = aa0aa_vector.begin(); it != aa0aa_vector.end(); ++it)
    {
        if(it == aa0aa_vector.end() - 1)
        	cout << *it;
        else
        	cout << *it << ",";
    }
    cout << "]" << endl;
    file.close();
    return 0;

}

int check_a(char c, int index)
{
    if(c == 'a')
    {
        a_vector.push_back(index);
        return 1;
    }
    return 0;
}

int check_ab(char c, int index)
{
    if(c == 'a')
    {
        ab_temp = c;
    }
    else if(c != 'b' && ab_temp == 'a')
    {
    	ab_temp = '\0';
    }
    else if(c == 'b' && ab_temp == 'a' )
    {
        ab_vector.push_back(index);
        return 1;
    }
    return 0;
}

int check_aab(char c, int index)
{

	if(c == 'a' && aab_temp.compare("") == 0)
	{
		aab_temp = c;
	}
	else if(c != 'a' && aab_temp.compare("a") == 0)
    {
    	aab_temp = "";
    }
    else if(c == 'a' && aab_temp.compare("a") == 0)
    {
        aab_temp += c;
    }
    else if(c != 'b' && aab_temp.compare("aa") == 0)
    {
    	aab_temp = "";
    }
    else if(c == 'b' && aab_temp.compare("aa") == 0)
    {
        aab_vector.push_back(index);
        return 1;
    }
    return 0;
}

int check_abc(char c, int index)
{
    if(c == 'a')
    {
        abc_temp = c;
    }
    else if(c == 'b' && abc_temp.compare("a") == 0)
    {
        abc_temp += c;
    }
    else if(c == 'c' && abc_temp.compare("ab") == 0)
    {
        abc_vector.push_back(index);
        return 1;
    }
    else
    {
    	abc_temp = "";
    }
    return 0;
}

int check_aa0aa(char c, int index)
{
    if(c == 'a' && aa0aa_temp.compare("") == 0)
    {
        aa0aa_temp = "a";
    }
    else if(aa0aa_temp.compare("a") == 0 && c != 'a')
    {
        aa0aa_temp = "";
    }
    else if(c == 'a' && aa0aa_temp.compare("a") == 0)
    {
        aa0aa_temp = "aa";
    }
    else if(c == 'a' && aa0aa_temp.compare("aa") == 0)
    {
        aa0aa_temp = "aaa";
    }
    else if(aa0aa_temp.compare("aaa") == 0 && c != 'a')
    {
        aa0aa_temp = "";
    }
    else if(c == 'a' && aa0aa_temp.compare("aaa") == 0)
    {
        aa0aa_temp = "aa";
        aa0aa_vector.push_back(index);
        return 1;
    }
    return 0;
}