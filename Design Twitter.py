class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time = 0 # system time
        self.tweets = {}  # userID -> [(time,tweet)]
        self.follows = {} # userID -> [followees]

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        if userId in self.tweets:
            self.tweets[userId].append((self.time,tweetId))
        else:
            self.tweets[userId] = [(self.time,tweetId)]
        self.time+=1
            
        

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        #from heapq import *
        h = None
        if userId in self.tweets:
            h = self.tweets[userId]
        else:
            h = []
        if userId in self.follows:
            for each in self.follows[userId]:
                if each in self.tweets:
                    h = h + self.tweets[each]
        h.sort(reverse=True)
        if len(h)>=10:
            return [i[1] for i in h[:10]]
        else:
            return [i[1] for i in h]
        
        
        

    def follow(self, followerId, followeeId):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId==followeeId:
            return
        if followerId in self.follows:
            if followeeId not in self.follows[followerId]:
                self.follows[followerId].append(followeeId)
        else:
            self.follows[followerId] = [followeeId]
            
    def unfollow(self, followerId, followeeId):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId in self.follows and followeeId in self.follows[followerId]:
            self.follows[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
