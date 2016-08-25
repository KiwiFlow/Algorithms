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
            
            
class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        self.trie = Trie()
        for each in words:
            self.trie.insert(each)
        self.board = board
        self.res = {}
        for  i in xrange(len(self.board)):
            for j in xrange(len(self.board[0])):
                self.p = self.trie.root
                k = self.board[i][j]
                self.board[i][j] = '1'
                #print self.trie.startsWith(k)
                if k in self.p.children.keys():
                    self.p = self.p.children[k]
                    self.match(i,j,k)
                self.board[i][j] = k
        return sorted(self.res.keys())
                
                
                
    def match(self,i,j,prefix):
        if self.p.is_a_word:
            #print prefix
            if prefix not in self.res:
                self.res[prefix] = None
            
        M = len(self.board)
        N = len(self.board[0])
        
        if j+1<N and self.board[i][j+1]!='1' and self.board[i][j+1] in self.p.children.keys():
            k = self.board[i][j+1]
            u = self.p
            self.p = self.p.children[k]
            self.board[i][j+1] = '1' #used
            self.match(i,j+1,prefix+k)
            self.board[i][j+1]=k
            self.p = u
            
        if i+1<M and self.board[i+1][j]!='1' and self.board[i+1][j] in self.p.children.keys():
            k = self.board[i+1][j]
            u = self.p
            self.p = self.p.children[k]
            self.board[i+1][j] = '1' #used
            self.match(i+1,j,prefix+k)
            self.board[i+1][j]=k
            self.p = u
            
        if i-1>=0 and self.board[i-1][j]!='1' and self.board[i-1][j] in self.p.children.keys():
            k = self.board[i-1][j]
            u = self.p
            self.p = self.p.children[k]
            self.board[i-1][j] = '1' #used
            self.match(i-1,j,prefix+k)
            self.board[i-1][j]=k
            self.p = u
            
        if j-1>=0 and self.board[i][j-1]!='1' and self.board[i][j-1] in self.p.children.keys():
            k = self.board[i][j-1]
            u = self.p
            self.p = self.p.children[k]
            self.board[i][j-1] = '1' #used
            self.match(i,j-1,prefix+k)
            self.board[i][j-1]=k
            self.p = u
        return
        
