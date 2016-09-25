#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

void check_minheap(){
	vector<int> v(3,1);
	v[0]=1;v[1]=2;v[2]=3;
	priority_queue<int, std::vector<int>, std::greater<int> > q(v.begin(),v.end());
	
	q.push(100);
	q.push(10);
	q.push(15);
	q.push(30);
	int t=2;
	while (--t){
		cout << q.top() << " ";
		q.pop();
	}
	
	q.push(5);
	q.push(105);
	while (!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	q.size();
}

//this is the max heap implementation
void check_heap(){
	vector<int> v(3,1);
	v[0]=1;v[1]=2;v[2]=3;
	
	priority_queue<int> q(v.begin(),v.end());
	q.push(100);
	q.push(10);
	q.push(15);
	q.push(30);
	int t=2;
	while (--t){
		cout << q.top() << " ";
		q.pop();
	}
	
	q.push(5);
	q.push(105);
	while (!q.empty()){
		cout << q.top() << " ";
		q.pop();
	}
	q.size();
}

void general_function(){
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	string s="173";
	int test=stoi(s);
	int no=174;
	string num=to_string(no);
	cout << num << no << test;
}

void check_stack(){
	stack<int> st;
	st.push(1);
	st.pop();
	st.top();
	st.empty();
}

void check_map(){
	map<string, int> mp;
	mp["a"]=1;
	mp["an"]=2;
	mp["ank"]=3;
	mp.find("ankit"); //mp.find()!=mp.end()
}

void vector_double(){
	vector<int> v(4,1);
	vector<vector<int> > vv(4, vector<int> (3, -1));
	v.erase(v.begin()); //iterator position
}

void check_set(){
	vector<int> v (5,1);
	v[0]=2;
	v[1]=3;
	set<int> s(v.begin(), v.end());
	for (set<int>::iterator it=s.begin(); it!=s.end();it++)
		cout << *it;
	s.insert(4);
	s.erase(3);
	s.empty();
	s.clear();
	s.find(3); 	//s.find()!=s.end() if found else s.end()
	
}
void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}


void check_string(){
	
	string s1="not to be ";
	string s="ankit";
	s=s + "_verma";
	s.find("it");//returns the index of starting string // s.find("it")!=string::npos
	s.empty();
	reverse(s.begin(), s.end());
	sort(s.begin(), s.end());
	cout << s;
	s.substr(1, 3); //first is the index and then the length
	s.substr(4); //get the 4 till the end of string
	s.size();
	s.insert(3, s1, 0, 4);	
	s.push_back('c');
	s.pop_back(); //erase the character but does not return anything
	s.length();
	s.compare(1,4,"apple"); //second argument is always length
	s.erase(1, 4); //begin index, second is length
	s.front() = 'T'; //changes the value of front
	
	
	string newstr="try, to tokenize, me, ";
	vector<string> token;
	Tokenize(newstr, token);
	for(vector<string>::iterator it=token.begin();it!=token.end();it++){
		cout << *it;
	}
	
	//char *cc =strtok(newstr, " ");
}

void check_queue(){
	queue<int> q;
	q.push(3);
	q.push(2);
	q.push(1);
	q.pop();  	//this pops out the first element from the queue
	q.front()=-1;
	q.size();
	q.back();
	while (!q.empty()){
		cout<<q.front();
		q.pop();
	}
	
}
int main(){
	
	//check_string();
	//general_function();
	//check_set();
	//check_minheap();
	//vector_double();
	check_queue();
	
}
