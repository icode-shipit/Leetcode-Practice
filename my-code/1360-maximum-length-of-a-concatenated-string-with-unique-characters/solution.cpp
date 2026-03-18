class Solution {
public:
    string s;
    int ans=0;
    unordered_map<char,int> m;
    int curr_size=0;
    bool check(string& s1)
    {
        for(int i=0;i<s1.size();i++)
        {
            if(m[s1[i]]>0)
            {
                return false;
            }
        } // confirmed unique
        for(int i=0;i<s1.size();i++) //adding s1 chars to map m
        {
            m[s1[i]]++;
        }
        return true;
    }
    void remove_ch(string& s1)
    {
        for(int i=0;i<s1.size();i++)
        {
            m[s1[i]]--;
        }
        return;
    }
    void backtracking(vector<string>& arr,int p)
    {
        if(p==arr.size())
        {
            return;
        }
        for(int i=p;i<arr.size();i++)
        {
            if(check(arr[i])) // check if unique
            {
                int prev_size=s.size();
                int n=arr[i].size();
                s+=arr[i];
                curr_size+=n;
                ans=max(ans,curr_size);
                backtracking(arr,i+1);
                s.erase(prev_size,n);
                remove_ch(arr[i]);
                curr_size-=n;
            }
        }
        return;
    }
    bool has_duplicate(string& s1)
    {
        unordered_set<char> s2;
        for(int i=0;i<s1.size();i++)
        {
            if(s2.contains(s1[i]))
            {
                return true;
            }
            s2.insert(s1[i]);
        }
        return false;
    }
    int maxLength(vector<string>& arr) {
        for(int i=0;i<arr.size();i++) // remove all duplicate char containing substring in arr
        {
           if(has_duplicate(arr[i]))
           {
            arr.erase(arr.begin()+i);
            i--;
           }
        }
        backtracking(arr,0);
        return ans;
    }
};
