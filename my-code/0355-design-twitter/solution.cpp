class d_t
{
    public:
        int followeeId;
        int index;
        int tweetId;
        int count;

        d_t(int ct,int t_id,int f_id,int idx)
        {
            followeeId=f_id;
            index=idx;
            tweetId=t_id;
            count=ct;
        }
};

class Twitter {
public:
    int t_count;
    unordered_map<int,unordered_map<int,int>> followee;// following people
    unordered_map<int,vector<pair<int,int>>> tweets;  //first->count,second->tweetId
    Twitter() {
        t_count=0;
    }

    struct compare
    {
        bool operator()(const d_t *a,const d_t *b)
        {
            return a->count<b->count;
        }
    };

    void postTweet(int userId, int tweetId) {
        t_count++;
        tweets[userId].push_back({t_count,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        //lets add user_id to followee_id
        followee[userId].insert({userId,1});
        priority_queue<d_t*,vector<d_t*>,compare> pq;// first is count,second is tweetId
        unordered_map<int,int> &temp=followee[userId]; //followeeId's of userId
        for(auto it=temp.begin();it!=temp.end();it++)
        {
            if(tweets.contains(it->first))
            {
            int index=tweets[it->first].size()-1; // index of last element in tweetId's vector
            vector<pair<int,int>> &v=tweets[it->first]; // vector of tweetId's of each followeeId
            pair<int,int> &temp1=v[index]; // last pair of count,tweetId for followeeId
            d_t* ptr= new d_t(temp1.first,temp1.second,it->first,index-1);
            pq.push(ptr);
            }
        }
        while(ans.size()<10 && !pq.empty())
        {
                d_t* tempa=pq.top();
                ans.push_back(tempa->tweetId);
                pq.pop();
                int newindx=tempa->index;
                if(newindx>=0)
                {
                int followeeId= tempa->followeeId;
                pair<int,int> &newpair= tweets[followeeId][newindx];
                int newcount =newpair.first;
                int newtweetId=newpair.second;
                d_t* newele=new d_t(newcount,newtweetId,followeeId,newindx-1);
                pq.push(newele);
                }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followee[followerId].insert({followeeId,1});
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        {
           followee[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
