#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;

#define alphabets 26

struct TrieNode{
    TrieNode* links[alphabets];//used to store links to the nodes
    bool flag; //Flag to know the end of the word
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    //this function returns a specific character from the trie
    TrieNode* getSpecificChar(char ch){
        return links[ch-'a'];
    }

    //this function adds a children for a specific character
    void putSpecificChar(char ch,TrieNode* node){
        links[ch-'a']=node;
        return;
    }
    //this function returns the end of the word
    bool isEnd(){
        return flag;
    }
    //this function marks the current node as end of the word
    void setEnd(){
        flag=true;
        return;
    }
    //this function unmarks the current node as end of the word
    void makeFalse(){
        flag=false;
        return;
    }
};
class Solution{
        TrieNode* root;
    public:
        Solution(){
            root=new TrieNode();
        }

     // This function will insert the word in the trie.
    void insert(string word){
            TrieNode* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->putSpecificChar(word[i],new TrieNode());
                }
                node=node->getSpecificChar(word[i]);
            }
            node->setEnd();
    }

    // This function Searches whether a given word can be formed by using two or more words from the given list.
    bool search(string s,int i,TrieNode* temp){
        if(i==s.length()){
        return temp->isEnd();
        }
        if(temp->isEnd()){
            if(search(s,i,root))
                return true;
        }
        if(temp->containsKey(s[i])){
            return search(s,i+1,temp->getSpecificChar(s[i]));
        }
        else{
            return false;
        }
    }

    // This function is used to set the flag of the word as false.
    void st(string s,int i,TrieNode* temp){
            if(i==s.length()){
                temp->makeFalse();
                return;
            }
            st(s,i+1,temp->getSpecificChar(s[i]));
            return;
        }

    static bool cmp(string a,string b){  // Comparator function used for sorting 
        if(a.length()==b.length())
        return a<b;
        return a.length()>b.length();
    }

    void longestWord(vector<string>& words) {
        vector<string> ans; 
        for(int i=0;i<words.size();i++){
            ans.push_back(words[i]);
            insert(words[i]);
        }
        sort(ans.begin(),ans.end(),cmp);  // Sorting is done to find the longest word
        string ans1="",ans2="";
        for(int i=0;i<ans.size();i++){
            st(ans[i],0,root); // Used to unmark the flag of the word because if we didn't unmark the flag then it will always give the longest word as the answer because the flag of the word is true

            if(search(ans[i],0,root)){ 
                if(ans1.length()==0)
                ans1=ans[i];
                else{
                    // ans2=ans1;
                    ans2=ans[i];
                    break;
                }
            }
            insert(ans[i]);  // Used to mark the flag of the word as true
        }
        cout<<"Longest Compounded word: "<<ans1<<endl;
        cout<<"Second Longest Compounded word: "<<ans2<<endl;
        return;
    }
};

int main(){
    Solution st;
    ifstream infile;
    string filename;
  vector<string> filenames = {"Input_01.txt", "Input_02.txt", /* Add more filenames as needed */};
  
    vector<string> ans;  // This vector is used to store all the words from input file.
    for (const string &filename : filenames) {
    infile.open(filename);
    
    if(infile.fail()){
        cout<<"You are not able to open this file.";
    }
    else{
        string s;
        while(infile>>s){
            ans.push_back(s);
        }
        infile.close();
        auto start = high_resolution_clock::now();//start time for compiling longest concatenated words
        st.longestWord(ans);
        auto stop = high_resolution_clock::now();//end time for compiling longest concatenated words
        auto duration = duration_cast<milliseconds>(stop - start);
        cout<<"Time taken to process "<<filename<<" :"<<duration.count()<<" milliseconds"<<endl;
    }
    }
    return 0;
}