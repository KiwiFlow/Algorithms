class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = {}
        self.is_a_word = False
        

class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        p = self.root
        for each in word:
            if each not in p.children.keys():
                p.children[each] = TrieNode()
            p = p.children[each]
        p.is_a_word = True
        
    def longestCommonPrefix(self):
        ans = ''
        p = self.root
        while p and p.children and not p.is_a_word:
            if len(p.children.keys())==1:
                for k,v in p.children.iteritems():
                    ans += k
                    p = v
            else:
                break
        return ans
        
        
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        trie = Trie()
        for each in strs:
            trie.insert(each)
        return trie.longestCommonPrefix()
        
        
        
        
