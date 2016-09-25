#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string operations= "*-+";
    
    vector<string> addOperators(string num, int target) {
        vector<string > expressions;
        int n =num.size();
        int index=0;
        vector<int> numbers (n, 0);
        for(int i=0; i < n; i++){
            numbers[i]=num[i] - '0';
        }
        string exp;
        return find_number(numbers, num, target, index, n, exp, expressions);
            
    }
    
    
    
    bool find_number(vector<int>& nums, string str_num, int target, int index, int n, string exp, vector<string > & expressions){
        if(index >= n) return false;
        
        if(index == n-1){
            if(nums[index] == target) {
                expressions.push_back(exp);
                return true;
            }
            else
                return false;
        }
        
        int e=nums[index];
        //expression.push_back(e);
        
        for(int count=0; count<3; count++){
            
            if(operations[count] == '*') {
                int e1 = nums[index+1];
                nums[index+1] = e * e1;
                exp.push_back(str_num[index]);
                exp.push_back('*');
                if(find_number(nums, str_num, target, index+1, n, exp, expressions) == true)
                {   
                    nums[index+1] = nums[index+1]/e;
                    return true;
                }
                nums[index+1] = nums[index+1]/e;
                exp.pop_back();
                exp.pop_back();
            }
            
            if(operations[count] == '-') {
                exp.push_back(str_num[index]);
                exp.push_back('-');
                int newtarget = e-target;
                if(find_number(nums, str_num, newtarget, index+1, n, exp, expressions) == true){
                    return true;
                }
                exp.pop_back();
                exp.pop_back();
            }
            
            if(operations[count] == '+') {
                exp.push_back(str_num[index]);
                exp.push_back('+');
                int newtarget = target - e;
                if(find_number(nums, str_num, newtarget, index+1, n, exp, expressions) == true){
                    return true;
                }
                exp.pop_back();
                exp.pop_back();
            }
            
        }
    }
};


int main(){
	Solution obj;
	obj.addOperators("123", 6);
	return 0;
}
