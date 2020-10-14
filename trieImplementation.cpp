class Trie {
    
    struct TrieNode{
      bool isEndOfWord;
      struct TrieNode*children[26];  
    };
    
    struct TrieNode*root;
    
    struct TrieNode* getNode(void)
    {
        struct TrieNode*pNode=new TrieNode;
        pNode->isEndOfWord=false;
        for(int i=0;i<26;i++)
        {
            pNode->children[i]=NULL;
        }
        return pNode;
    }
    
    public:
    Trie() {
        root=getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode*pCrawl=root;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(pCrawl->children[index]==NULL)
                pCrawl->children[index]=getNode();
            pCrawl=pCrawl->children[index];
        }
        pCrawl->isEndOfWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode*pCrawl=root;
        for(int i=0;i<word.length();i++)
        {
            int index=word[i]-'a';
            if(pCrawl->children[index]==NULL)
                return false;
            pCrawl=pCrawl->children[index];
        }
        if(pCrawl->isEndOfWord==true)
            return 1;
        else
            return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
       TrieNode*pCrawl=root;
        for(int i=0;i<prefix.length();i++)
        {
            int index=prefix[i]-'a';
            if(pCrawl->children[index]==NULL)
                return false;
            pCrawl=pCrawl->children[index];
        }
       return 1;
    }
};
