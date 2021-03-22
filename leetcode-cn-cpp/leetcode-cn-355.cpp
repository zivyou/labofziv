#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Twitter {
private:
    vector<int> userList;
    vector<vector<int> > news;
    map<int, vector<int> > followList; // a follow b
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        news.push_back(vector<int>({userId, tweetId}));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> followee = followList[userId];
        vector<int> re;
        
        for (int i=news.size()-1; i>=0; i--){
            vector<int> v = news[i];
            if (v[0] == userId){
                re.push_back(v[1]);

                if (re.size() == 10)
                    break;
                else
                    continue;
            }

            for (auto user : followee){
                if (user == v[0]){
                    re.push_back(v[1]);
                    break;
                }
            }
            if (re.size() == 10)
                break;
        }

        return re;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followList.find(followerId) == followList.end()){
            followList[followerId] = vector<int>(followeeId);
        }else{
            followList[followeeId].push_back(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followList.find(followerId) == followList.end())
            return;
        int i=0;
        for (auto user : followList[followerId]){
            if (user == followeeId)
                break;
            i++;
        }

        if ((followList[followerId].begin()+i) != followList[followerId].end()){
            followList[followerId].erase(followList[followerId].begin()+i);
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

int main(){
    Twitter tw;

    return 0;
}