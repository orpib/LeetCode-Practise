class LFUCache {
    private:
    unordered_map<int, int> hashTable , nxt , prev;
    int cap , currsize, curr ,lru,counter;
public:
    LFUCache(int capacity) {
        cap = capacity;
        currsize =  0;
        curr = -1;
        lru = -1;
        counter = 0;
    }
    void printQueue(){
        
        int temp = lru;
        cout<<" printing on "<< counter << " -- ";
        while( nxt.find(temp) != nxt.end() || temp != -1){
            cout<<temp<<" ";
            temp = nxt[temp];
        }
        cout<<endl;
    }
    int get(int key) {
        counter++;
        cout<<" GET "<<" key "<< key << " ";

        
        if(hashTable.find(key) == hashTable.end()) {
            printQueue();
            cout<<endl;
            return -1;
        };
        //lru wont be -1 , as the value exist in the hash
        if(nxt[key] != -1) // nxt[key] will not be == nxt.end(); will contain this value, as hashtable also contains ,
        {
            prev[nxt[key]] = prev[key]; 

            if(lru == key){
                lru = nxt[key] ;
            }
        }
        
        // if(key == curr){
            // prev[key]  = (curr == key) ? prev[curr] : curr;
            // nxt[curr] = (curr == key) ? -1 : key  ;
            
        // }
        prev[key]  = (curr == key) ? prev[curr] : curr;
        nxt[key] = -1;
        nxt[curr] = (curr == key) ? -1 : key  ;
        curr = key;
                cout<<key <<" lru "<<lru<< " Next "<<nxt[lru]<< endl;
        printQueue();
        return hashTable[key];   
    }
    
    void put(int key, int value) {
        counter++;
        cout<<" PUT "<<key<<endl;
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
        
        if(hashTable.find(key) == hashTable.end()){ // need to decide if to assign first or letter
            currsize++;
        }

        hashTable[key] = value;

        if(currsize > cap){
            //if(lru != -1){
                hashTable.erase(lru);
                int tempHead = lru;
                 tempHead  = nxt[lru];
                 cout<<lru<<" temphead "<<tempHead<<endl;
                if( tempHead != -1 ){
                     prev[ tempHead ]  = -1;  
                }
                prev.erase(lru);
                nxt.erase(lru);
                //  prev[lru] = -1;
                //  nxt[lru] = -1;
                 cout<<" pop "<<tempHead <<" nxt "<< nxt[lru]<<endl;
                 lru = tempHead;
                 
                 currsize--;
           // }
        }

        if( nxt.find(key) != nxt.end() && nxt[key] != -1)
        {
                prev[nxt[key]] = prev[key];
                // cout<< " one-  prev "<<prev[key]<< " -- dash "; 
                
        }
        cout<<" LRU "<<lru<<" key "<<key<<" - ";
            if(lru == -1){ // first link initialize
            cout<< " FIRST "<<endl;
                prev[key] = -1;
                nxt[key] = -1;
                 //cout<< " two - prev "<<prev[key]<< " -- dash "; 
            }
            else {
                    prev[key] = (curr == key) ? prev[curr] : curr;
                    nxt[key] = -1;
                    nxt[curr] = (curr == key) ? -1 : key  ;
                     //cout<< " three prev "<<prev[key]<< " -- dash "; 
            }

            
            cout<<" LRU "<<lru<<" key "<<key<< " -- ";
            if(prev[key] == -1){ // if it is the first element;
                //cout<< " prev "<<prev[key]<< " -- dash "; 
                lru = key;
            }
           else if(lru == key){
                lru = nxt[lru];
            }
             
            cout<<" LRU "<<lru<<" key "<<key<< " --- ";
            if(lru == -1) lru = key;
            curr = key;
            printQueue();

            cout<<" LRU "<<lru<<" key "<<key << " next ---- " <<nxt[lru]<<endl;

        }


        

        
    
};