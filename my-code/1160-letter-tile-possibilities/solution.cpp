class Solution {
public:
    // so make all possible subsets of given and generate all possible permutations of each without having duplicates as subsets can have duplicate elements in them.
    string temp;
    string temp1;
    int ans=0;
    void genpermute(unordered_map<char,int>& m,int n)
    {
        if(temp1.size()==n)
        {
            ans++;
            return;
        }
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second>0)
            {
                temp1.push_back(it->first);
                it->second--;
                genpermute(m,n);
                temp1.pop_back();
                it->second++;
            }
        }
    }
    void permute(string& temp)
    {
        unordered_map<char,int> m;
        for(int i=0;i<temp.size();i++)
        {
            m[temp[i]]++;
        }
        genpermute(m,temp.size());
    }
    void subsets(string& tiles,int p) // generatin all possible subsets
    {
        if(p==tiles.size())
        {
            if(temp.size()>0)
            {
              permute(temp);
            }
            return;
        }
        temp.push_back(tiles[p]);
        subsets(tiles,p+1);
        while(p<tiles.size()-1 && tiles[p]==tiles[p+1])
        {
           p++;
        }
        temp.pop_back();
        subsets(tiles,p+1);
        return;
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        subsets(tiles,0);
        return ans;
    }
};
