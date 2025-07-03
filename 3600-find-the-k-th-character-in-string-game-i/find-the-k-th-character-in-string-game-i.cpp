class Solution {
public:

   string generate(string s)
   {
    string ans;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==122)
        {
            ans.push_back(char(97));
        }
        else
        {
            ans.push_back(char(s[i]+1));
        }
        
    }

    return ans;
   }
    char kthCharacter(int k) {

        string word="a";

        while(word.size()<k)
{
        string append=generate(word);

        word=word+append;


}
return word[k-1];
        

        
    }
};