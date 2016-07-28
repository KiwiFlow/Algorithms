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
                
            
            
        

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        p = self.root
        i = 0
        while p and i<len(word):
            if word[i] not in p.children.keys():
                p = None
            else:
                p = p.children[word[i]]
            i+=1
        if i == len(word) and p and p.is_a_word==True:
            return True
        else:
            return False
            
        

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        p = self.root
        i = 0
        while p and i<len(prefix):
            if prefix[i] not in p.children.keys():
                p = None
            else:
                p = p.children[prefix[i]]
            i+=1
        if p!=None:
            return True
        else:
            return False
        

# Your Trie object will be instantiated and called as such:

#trie = Trie()
#print trie.insert("somestring")
#print trie.insert("what")
#print trie.insert("nearlyeverthingisreallyinterestingifyougodeepontoit")
#print trie.search("what")
#print trie.search("key")
#print trie.startsWith("some")
#print trie.startsWith("somestring")
#print trie.search("wha")
#print trie.search("nearlyeverthingisreallyinterestingifyougodeepontoit")
#print trie.startsWith("nearlyeverthingisreallyinterestingifyougodeepon")
#print trie.search("nobodyever")

#print trie.insert("abc")
#print trie.search("abc")
#print trie.search("ab")
#print trie.insert("ab")
#print trie.search("ab")
#print trie.insert("ab")
#print trie.search("ab")


