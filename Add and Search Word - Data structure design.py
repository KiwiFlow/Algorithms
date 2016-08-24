class TrieNode():
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = {}
        self.is_a_word = False
        
class Trie():

    def __init__(self):
        self.root = TrieNode()
        
    def getRoot(self):
        return self.root

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
            
    def searchX(self,p,word):
        if word=="":
            if p.is_a_word:
                return True
            else:
                return False
        if len(word)==1:
            if word=='.':
            	for each in p.children.keys():
            		if p.children[each].is_a_word:
            			return True
                return False
            elif word in p.children.keys() and p.children[word].is_a_word:
                return True
            else:
                return False
        elif word[0]!='.':
        	if word[0] in p.children.keys():
        		return self.searchX(p.children[word[0]],word[1:])
        	else:
        		return False
        else:
            for each in p.children.keys():
                if self.searchX(p.children[each],word[1:]):
                    return True
            return False
        
        
            
            
class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.Trie = Trie()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        self.Trie.insert(word)
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        root = self.Trie.getRoot()
        return self.Trie.searchX(root,word)
        

# Your WordDictionary object will be instantiated and called as such:
wordDictionary = WordDictionary()
wordDictionary.addWord("word")
wordDictionary.addWord("bad")
wordDictionary.addWord("dad")
wordDictionary.addWord("mad")
wordDictionary.addWord("")
#print wordDictionary.search("")
#print wordDictionary.search("pa")
#print wordDictionary.search("bad")
#print wordDictionary.search("b..")
wordDictionary.addWord("x")
#print wordDictionary.search(".")
#print wordDictionary.search("...........")
wordDictionary.addWord("wordwordwordword")
print wordDictionary.search("word....word....")







