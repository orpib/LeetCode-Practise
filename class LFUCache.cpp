class LFUCache {
    private:
    map<int, int> hashTable , nxt , prev;
    int cap , currsize, curr ,lru;
public:
    LFUCache(int capacity) {
        cap = capacity;
        //counter =  1;
        curr = -1;
    }
    
    int get(int key) {

        if(hashTable.find(key) == hashTable.end()) {
            return -1;
        };
        //lru wont be -1 , as the value exist in the hash
        if(nxt[key] != -1) // nxt[key] will not be == nxt.end(); will contain this value, as hashtable also contains ,
        {
            prev[next[key]] = prev[key]; 

            if(lru == key){
                lru = nxt[key] ;
            }
        }
        
        // if(key == curr){
            // prev[key]  = (curr == key) ? prev[curr] : curr;
            // next[curr] = (curr == key) ? -1 : key  ;
            
        // }
        prev[key]  = (curr == key) ? prev[curr] : curr;
        next[curr] = (curr == key) ? -1 : key  ;

        return hashTable[key];   
    }
    
    void put(int key, int value) {
        // if(hashTable.find(key) != hashTable.end()){
        //     hashTable.erase(key);
        //     hashTable[key]= value;
        // }
        // else{
        //     //if(hashTable.size() > cap){
        //     //auto itr = hashTable.begin();
        //     //cout<<itr->first<<" Val"<<endl;
        //   ///  hashTable.erase(itr->first);            
        // //}

            
        // }

        if(cap == 0) return;
        
        if(hashTable.find(key) == hashTable.end()){
            currsize++;
        }

        hashTable[key] = value;

        if(counter > cap){
            if(lru != -1){
                hashTable.erase(lru);
                int temp = lru;
                if( next[lru] != -1 ){
                     temp  = next[lru];
                     prev[ next[lru] ]  = prev[lru];  
                }
                 prev[lru] = -1;
                 next[lru] = -1;
                 lru = temp;
                 counter--;
            }
        }

        if( nxt.find(key) != nxt.end() && next[key] != -1){
                prev[next[key]] = prev[key];
            }

            if(curr == -1){
                prev[key] = -1;
            }
            else {
                    prev[key]= (curr == key) ? prev[curr] : curr;
                    next[curr] = (curr == key) ? -1 : key  ;
            }

            if(prev[key] == -1){
                lru = key;
            }
            else if(prev[next[key]] == -1){
                lru= next[key];
            }

        }


        if(lru == -1) lru = key;

        
    }
};