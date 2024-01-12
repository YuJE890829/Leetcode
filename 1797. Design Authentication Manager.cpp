#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;
class AuthenticationManager {
    int timeToLive;
    unordered_map<string, int> hash;
public:
    AuthenticationManager(int timeToLive) {
        this -> timeToLive = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        hash[tokenId] = currentTime + timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if (hash.find(tokenId) != hash.end() && hash[tokenId] > currentTime)
            hash[tokenId] = currentTime + timeToLive;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int UnexpiredTokens = 0;
        for (auto i: hash)
            if (i.second > currentTime)
                UnexpiredTokens++;
        return UnexpiredTokens;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */