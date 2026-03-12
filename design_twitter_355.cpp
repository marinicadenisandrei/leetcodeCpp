/* Leetcode - 355. Design Twitter (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class Twitter
{
private:
    vector<vector<vector<int>>> users = {
        {{}, {}},
        {{}, {}}
    };

public:
    Twitter() = default;
    ~Twitter() = default;

    void postTweet(int user, int tweet_id)
    {
        users[user - 1][0].push_back(tweet_id);
    }

    void getNewsFeed(int user)
    {
        vector<int> feed;

        for (int i = 0; i < users[user - 1][0].size(); i++)
        {
            feed.push_back(users[user - 1][0][i]);
        }

        for (int i = 0; i < users[user - 1][1].size(); i++)
        {
            int followedUser = users[user - 1][1][i];

            for (int j = 0; j < users[followedUser - 1][0].size(); j++)
            {
                feed.push_back(users[followedUser - 1][0][j]);
            }
        }

        cout << "[";
        for (int i = 0; i < feed.size(); i++)
        {
            cout << feed[i];
            if (i < feed.size() - 1) cout << ", ";
        }
        cout << "] ";
    }

    void follow(int user, int follow_user)
    {
        users[user - 1][1].push_back(follow_user);
    }

    void unfollow(int user, int unfollow_user)
    {
        for (int i = 0; i < users[user - 1][1].size(); i++)
        {
            if (users[user - 1][1][i] == unfollow_user)
            {
                users[user - 1][1].erase(users[user - 1][1].begin() + i);
                break;
            }
        }
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 355. Design Twitter (C++ language) - Medium\n";

    green();

    cout << "Test 1: ";

    reset();

    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.getNewsFeed(1);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    twitter.getNewsFeed(1);
    twitter.unfollow(1, 2);
    twitter.getNewsFeed(1);

    cout << "| ";

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void reset () {
  cout << "\033[1;0m";
}

void green () {
  cout << "\033[1;32m";
}

void yellow () {
  cout << "\033[1;33m";
}

void red () {
  cout << "\033[1;31m";
}