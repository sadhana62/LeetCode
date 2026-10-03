class Twitter {
public:
    vector<pair<int,int>> posts;
    unordered_map<int,set<int>> followers;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> output;
       for (auto p = posts.rbegin(); p!= posts.rend();p++) {
         if (output.size() == 10) break;
         auto user = followers[userId];
         if (user.find(p->first) != user.end() || p->first == userId) {
            output.push_back(p->second);
         }
       }
       return output;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
