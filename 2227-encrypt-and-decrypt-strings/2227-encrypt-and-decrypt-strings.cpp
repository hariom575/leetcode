class Encrypter {
public:
    map<string,int>dict;
    map<char,string>key;
    map<string,vector<char>>value;
    map<string,int>mp;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        dict.clear();
        key.clear();
        value.clear();
        for(auto &a:dictionary) dict[a]++;
        for(int i=0;i<keys.size();i++){
            key[keys[i]]=values[i];
            value[values[i]].push_back(keys[i]);
        }
        for(auto &a:dictionary){
            string ans="";
            bool h=false;
            for(int i=0;i<a.size();i++){
                if(key.count(a[i])) ans+=key[a[i]];
                else h=true;
            }
            if(h) continue;
            mp[ans]++;
        }
    }
    
    string encrypt(string word1) {
        string ans="";
        for(int i=0;i<word1.size();i++){
            if(key.count(word1[i])) ans+=key[word1[i]];
        }
        return ans;
    }
    int decrypt(string word2) {
        if(!mp.count(word2)) return 0;
        return mp[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */