class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children = {}
        self.is_a_word = (False,None)
        self.index = []
        
class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word,index):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        p = self.root
        p.index.append(index)
        for each in word:
            if each not in p.children:
                p.children[each] = TrieNode()
            p = p.children[each]
            p.index.append(index)
        p.is_a_word = (True,index)
        
class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        trie = Trie()
        self.cache = {}
        for i in xrange(len(words)):
            trie.insert(words[i][::-1],i)
            
        res = []
        for i in xrange(len(words)):
        	if words[i]=='':
        		for x in xrange(len(words)):
        			if x!=i and self.isPalindrome(words[x]):
        				res.append([i,x])
        	else:
	            p = trie.root
	            if p.is_a_word[0] and i!=p.is_a_word[1] and self.isPalindrome(words[i]): #处理空串
	                res.append([i,p.is_a_word[1]])
	                
	            for j in xrange(len(words[i])):
	                if p.children and words[i][j] in p.children:
	                    p=p.children[words[i][j]]
	                    if j==len(words[i])-1:
	                        for each in p.index:
	                            if each!=i and self.isPalindrome(words[each][:-j-1]):
	                                res.append([i,each])
	                    elif p.is_a_word[0] and self.isPalindrome(words[i][j+1:]):
	                        res.append([i,p.is_a_word[1]])
	                else:
	                	break
        return res
                        
                       
    def isPalindrome(self,x):
    	if x in self.cache:
    		return self.cache[x]
        left = 0
        right = len(x)-1
        while left<right:
            if x[left]!=x[right]:
            	self.cache[x]=False
                return False
            else:
            	if x[left+1:right] in self.cache:
            		self.cache[x] = self.cache[x[left+1:right]]
            left+=1
            right-=1
        self.cache[x]=True
        print self.cache
        return True
        
s = Solution()
test = ["bbaabaaaabbbbaaaabaaaabaabbabbbaaabbabbbabbaaababbaabbaaaabbbaabbaabaaaabaaabbaabab","babbbbbaabbbaaaaaabbbbbbbaabbabbabbbbbaababaabbabbbabbbbbbabba","bbbbaabbbababbabbbbabaababaabbaabbabaaaaabababbabbabbbbbabbbbaaaabbabbabbbabababbbaaa","ababbbbbbbaaaabbaaababbbabababbaabbaababbbabbbabaabbaabaababbbabababaaabbbbabbaa","abbbaababaaaaabababaabaaaaaabbbbbbbababaaaabaabbbaaabbaaaabbbabbbbabbaaaaaaaaaaabbaaaababbabbbabbabaaaaabbaababbabbabababaaaaabbabbababbaaaabbbababaaabbaaabbabbaaba","aabbaaaaaaabaaabbbababbbbabababaaabbbabaabbababbaabbbbbaabbbbaabaa","abbabaabbaaaaaababbbabbabababbababbbbaaaaabbbaaabbaababbababbbabbaaaabbabbbabbabaaaaaaabbabbbaababaaaabbaabaabababbaaaababbabbbabaabbabbbbaaaabbabbaabbaaaababbbbbbaaaaaababba","abbabaabbabbabbbabaabbbbbabaabbbbaabaaabaabaaabbaaaaaaababbababb","bbabbbbaaabbbbaaababbabaabbbbababaaaabbaaabbbaabbbaaabaababababaaaaabbbbaaaabbbababbabbbbaabbbbaaaaaaaaaabbabaaabaabaaa","aabaabbabbabbaaabbbbbaabbaababbabbaabbabaaaaaababaabaabbaaaabbabbbaababaaabaabbbbbaabbbbabbbbaaaaabbbbabbbbabaabaabbaabbbabaabababaabbaaaaabbabaaabbaabbbabaaaababbabbbababaaabbaa","bbbaaaaaaaabaababbabbabbbb","aabbaababbbbbbbabbbababaaaababbabaaabbaaaaabbbaaababbaaabbaaaaaaabbaabbaababbbbaabbaababbabbbbbbaaabaaaabbaabaababaabaab","aabbaabaabbabaabbbababbbaababbaaaababaaaaabaaaababbabbabababaaaabbabbbabbbbbbaababaaabbbababaabaaaabbbabaaa","aabbbbbbaabbabababbbbabbbbbaabbabaabbaaabbbb","ababbabaaabaaa","babbaaaaabbaaabaaaabaabaabaaabaaaaaaabaaabba","bababaabbaaaaababbabaaabbbabababbbbbabbbbababb","aaababbbbaabaabaaaabaabbabbababaaaaab","baabbbbbaabbaaaaababbabaabbabaaaabbabbbaabbabababababbaabaaabbbaabaabbbabbaaabbbbabababaabaabaabaabbbaaabaaabbbaaabaaaabbaaabbaaaababbbbabbaabbababbaabbbbbbababaaaabbbababa","baabbabaabaababbbaababbbbbabbbabbaaaaaaaabbbaabbaabaabbbabaabaabaabbaaabaaaabaaabaababaa","bbabbbabaababaabaaabbbbaaaaaabbbaaaaaaabababababbbbababbaaaaabbaabbabababbaaaabababbababbabbababbabbaa","aabbaabaabbaaabaaaaaabaaabbabababaaaabbabaabaaabbbabababbaabaaabbabbbbabbaabbababbbabbaaaabaaababbabbbbbbaaabbaababbabaabaaabaaabbbabaababaa","babaaababaabbabbabbbbbabaaabbaaabbabaabbabbabbbaabbbaaaaaabaabbaababbbbaaababbababbabbbabaababaabbabababbbabaabbbbaabaababbaa","bbabbababaaababababaabaaaaaaaabaababaababbabbabb","bbabbbbabbaaaabaabbbbbbabbbaaaaaaabbbbabbaaabbabaabbabaabbbbbbaabbbabaaabbabaaabbaba","baabbbbbbaaaaabbaabbbbabaaabbaaaabbbaaabbabaaababaababbbbbbabbaabaaabaaabbabbabaaaba","bbbaabaabbabababbaaabbaaaababaabbbbaabaaaaaaaaabbbbaabbbbabbbabababbabbbbababbaabbba","aabbbaabaababaaaabbbbabaabaabaaabababbaabbaabbaaabaababaaabbbabaaababaabbaababbbbaababaabaabbaababbababbbbbababababaabbabbaabaaaaaabaabbaabaabaaabaabba","abbabaababbbbbbaaaaaababbaabaabbaabbaaaababaababaabbbbbaaaabbbabbbbbaabbbbbbaaababbbaabaabababb","bbbaabaabaaaaabaabaabbbbaaaabaabbbbbaabbaaabbbbbababbbbabbaaaaabbaababababababbbbbbbaaabaabbbaaaaababbbaabbabaabababbbbaaabaabbababbbaabbaabbbbaaaabababbabaabbaaaaaababaaaaabaababaabbabaabbabababab","babaabaabaabbbabaaaabaabbbaaaaaaabaababbabbbaabbbabaababbabbaabbaaabaaaabaababbabbaababbabababbbabaabbbababbbbbbbaaababbaaaabaabaabbababbaaabbaabbbaaabaabaaaabaa","abbbababaaabbaabbbbabababbaabbaaaabaabaabbbbbbbbaabbbbaaaaabbbbabaaaaabbbaaaaabbbbaaaaaababbbbbaabbabaaaaabbaabaaabaababbabaabaaabbab","babaabaababababbbbabababbbaabbaaabbbaabbaaaabaaabbbbbaaaab","aaaabbaabababbbaa","bbbbabbaabaabbbbaaaaaaaabbaababaaabaaabaaabbbbaababbbaabaabbbbaaabbabaabbbbbabbbbaaabababaabbaaababbabababbbabbabaabaaaabbab","aababaabaaaaaabbabababaaaaababbbbaabaa","bbababaaaaaaaaabaabbaaaabaaaaaaaaabbbabaabbbbbabaabaaabbbabbbabbbaaaaaabaaabbbbbbaa","abbaabaaaaabbaaaaaabbbbabaabbabbaabbbabbababaabaabaaabbababbaaabaababbbbbabbbabbabbaaaabbaababbaababbbabbbbbbaaabbbbbbb","baabababbbbbaabbbabaababaababaababbbabbbbbababbaababbaaaabaaabbbbaaaababbabbbabaabaabbababaaa","abbaabbbaabbabbabbbbbbbabbbabbaaabbaaababbaabbaababab","bbabbabbbbbbabababbbabaabbbaaaabababbaabbbabbbbaababbaabaaabbbbabaaaabbbabbaaabaabbaabbbaaababbaaaabaabbabbbabbbaaabaaabbbbabbaabbaabaa","aaaabbbabbaabbababbabbabaababbababaabbaaabaaaababbbabbaaaabbbbabaaabbbaaabababbbabbaabaaabbaabbbaabbbbaaabbbaabbbbababaaaaababbbabaabbbbbbabbabbbbbabaaabaaaaaabbaa","babaaabaabbaababaaabbaaababbbbbbbaabbbbbbbbabbaabbbbbbaaaaabbaabababaabbbabaaaaaaabbaabababaaabbabbabbaababbaaabbbaaaababbbbbabbbaabbbaaaabbabbaabbbaababbaaaabbaaaababbbbbb","abaababbaaabbbaaaaababaabbab","aabbaaaababbbabbbaaabaabababbabbbaabaaaabaabaaaabbabaabbaaabbbaaabbaabbabbbbaaabbbababbaabbaaaabbbabaabbbabbbbbbbaab","aabbbabbabaaaaabbabbababbbabbbbbbbbaabbbbabbbaabaabbaaababbbaaaaabbaaabbab","baaaabababaaababbaabbbabaaabbbbabbbbaaaabbabbbbbbbbababbaaaaabaabaaabbaabbbbbabababaabbbbaabbbbbabbaabaaabaababbbabbbabaababbaaaabbaaaaaabaababbbabaabbbaaabbbabbbaabbbbbbaabbabbbbabaabbbbaba","bbbaababaabaabbabbaabbabbaabbbbabaabbabbbbbbbabbaaaaababaaabbbaba","baaaaababaabaabaabbbbabbbbbaabbaabbaaababaabaababaabbaaabbabbbabbbaababababbaaaab","baabaaababbabbbaaaabbaabbaababbaababbbaabaabaaaaaabbbbababaaabaaabaababbaabbabbaababbbbbabbabbaabbaabbbabbbaabb","bbaaaaabbbaaabbbaaaaaaaaaabaaaaa","bbbbbbabaaaaabbbbaaabbabaababaabababbabbabaabababababbaabbabbbabbbababa","bbaabbbaabbabababaaaaaabbaabbababbbbabaabbbaabbabaabbbabbbabbaaabbabbababaaabbbababbabbbbbbbbaaaaabbaa","abaabbbaabbbbaabbabaabaaabaabaaaabbabbbabbaaabbbbababaabaaabaaaaaaaabaaaababbababaabbbbbaababaabbbbabbaaabbbabbabbbbabbbbaabaaa","bababbabbaaabbabaababbbbaabaabbbbbbababaabbbbaababababbaabbaabaaaababbabbabab","baaabbabbaaababbbbbbbaabaaabbabbaaabbabababbaaaabaabbbbaaaabbabbbbbbabaaaaabaabaaaaabababbbaabbaabbabbbbbabaababababbbbbbaabbbabbbaaabaabababaabaabbbbbbbbabaaaaabbaababab","ababababababbbabbabbbbbabbabbbbabbaaabbbbbbbbbbabbaabaabbbababbabbbaaaababbaabbbaab","baaaabbababbabaabbabbaabbbbabbbabbabbbbbabaaaabaabbbabbaababbabababaaaaabaaaababbbabbbaaaaabbbabbbaaaabbbbbaaaba","baababbbaaaabbbaaababbabaababbbbbaaabaabaaabababbbbaabbaaabaaabaaaaaabbbbbaabaaaababbbaabb","aaabaabbabaaaaaaaaaabbb","abbbaabaabbbbbabbaababbaaaaababbaaaaabbabbbb","ababaabababbbabbbbaaabbabbbaaaaaaabbabbbaba","baababbaabbbaabbbbbbaaabbbbaaaabbbbabaabbaaabaaababbbaaabbaabaabaabaaabbbbbaabaaaaab","babbabababaabbbaabababaaaaaaaaaabbbbabbababbbaaaabbaabababbbbbbbababaaaababbaaaabaabaaabaabaaaaababbbbababbaabbaaabbabaaababbbbbabbbaaabaababbaabbabbbbaaaabababaaa","abbbbbaaaaabbaabbbabaabbabaabbbaaabbaaabaabbb","abbababb","aababaaabbbabbbbaaaabaababbababbbaaaaabbababbbbaaaaaababababaabaaaabbbabbaababbbabbabaabbababbbbabbabbbabaaabababaababbbbbaaabaabaaaabbabbaaababbabaaaaa","abbbaaaaabaabbbabbbabbaaabbaababababbbaabbababaababaabbaaababbabbb","aaabaaabaabaababbabbbbaaaaaaaaabbbabbaabbababbaabababbbbbabbabababbabaaaabbbbabbbbbbbabbabaabababbaaabbaaaaaabbababbbbbbbaabbabbaaaababbabaaabbaabaaababaabaaaabaaba","baabbabbaabbbabbbbabbbaabbabaababaaaabaaaabbaaabaaababbabbbbbabaabbbaababaaababaababbaabaabaabababaaabbbbaabbbabbbbbba","abaababaaabaabbaabaaababbaabbbababbbaaaaaabbbabaaababbaabbbbaaabaabbaaabaaaababbabbbbbababbbaabbaaababaaaaaaababbbbbba","aaaabbaaaaaabbbaaaaabbaabbaabaabbababbbbbabababbababbabbaaaaabbaaabbabbaaabbbbbbaaabbbbbabbbbbabbabbaaaaaabbbbbaaaaaabbabbbbbbabbbaabbbaababbbbbabbaaabaa","ababbaaaababababbabaaabaaaaaabbbbababaababbababaabaabababaaaabbaaabaaaaaaabbbbababbabbbbabbbbbbabbbabaabbbabbbbbabbbbbababbbbaabbbaabbbababaaaabbbbaaabbab","bbabaababbabbbbbbaabbaaaabbaaabbabbaaabbabbaabaaabbbabbbababaabbbaaba","bbaaabbbaabaababbbababaaabbbbababbbbbaabaaabbbaabbbaaaaabbaabbaabaaabbabaababaaabbaababaabbbbbbaaabbabaabababaabbbaaaaabbbaaaabaabbababaaababaabbaabaaaaabaaaababbabaabababababaabaaaabaaabbaaabbbbababa","abbaaabbbaabbabb","abbbabbaaaabaabaaababaaaaabababbbaabbbbaabbbaaa","babaaabbbbbb","baaabaaabbbabaabbbaabaabbaaaabbbabbabbbbbaabbabbbabaabababaabbbbabaabaabbaaabbbabaaaaaaaaaabbbbaaabbaaaaaabaababbaabbabaabbbabaaabbbbaabbaababba","babababbbbabbaaaaaabbbbbaba","babba","abbbabaabbabbbbbbbbababaaaaaab","bbabbabbbabaaabbbaaababbbbaaaaaaabab","bbabbaabbbabaaaaaababaabbbabaaabaaababaabaaaaaaaaaaabbaababaababbababbabbababbbaaabbaaaabbaabbbbaaabbabbbabaabbbbbabababbaabaabbbabaabaaabaaababbbabbabbaababaabbbbaabaabbabbbbabbabbaababbbbba","bbaaabaaababaaaabbaabbabbbaabbaaabaababbaaababbbaaabaabaabbabababaaaabbbbbaaaabbbbbbababbbbabbbababbaababaababbbabaaabbabaaaabababaaabababaaabbbbbaaaaababaabbbbaabaaabba","ababaaaaaabbabbabba","aaabababaabaaabaaaaabaaabaababbbbbababbbabbbbbbaabbaaaaaba","baabbbab","abbaaaaababbbaaaabbbaaabbaaababbababababaabbabaabaaabaabaaabbaaabbababbaabaaaabaabababbbbbbabaabaaabaaaababbaababbaabbbbbaabbbbbbabaa","ababaaabbababbabbbaabbbaabaaaaaaaabbabaabaaaaaabaa","abbabbabbaaaaaababa"]
print s.palindromePairs(test)
