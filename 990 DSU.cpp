

class Solution
{
    map<int, int> disjointSetsLeader, disjointSetsRank;
    map<char, int> cti;
    int totalSets ;

public:
    bool equationsPossible(vector<string>& equations)
    {
        equations.push_back( equations[0]);

        int sz = equations.size();
        int currIndex = 1;
        totalSets = sz*2+5;

        createSets(totalSets);


        for(int i = 1; i<sz ; i++)
        {
            if(equations[i][1] == '!' || equations[i][0] == equations[i][3])
            {
                continue;
            }

            if(!cti[equations[i][0]]  )
            {
                cti[equations[i][0]] = currIndex ++;
            }

            if(!cti[equations[i][3]]  )
            {
                cti[equations[i][3]] = currIndex ++;
            }

            int x = cti[equations[i][0]], y = cti[equations[i][3]];

            unionCharacters(x,y);

        }

        printSets(sz);

        bool isPossible = true;

        for(int i = 1; i<sz ; i++)
        {

            if(equations[i][1] == '=' )
            {

                continue;
            }

            if(!cti[equations[i][0]]  )
            {
                cti[equations[i][0]] = currIndex ++;
            }

            if(!cti[equations[i][3]]  )
            {
                cti[equations[i][3]] = currIndex ++;
            }

            int x = cti[equations[i][0]], y = cti[equations[i][3]];
            int xpar = find(x) ;
            int ypar = find(y);
            if(xpar == ypar)
            {
                isPossible = false;
                break;
            }

        }

        return isPossible;
    }
    void printVec(vector<string>& eq)
    {
        int sz = eq.size();
        for(int i=0; i<sz; i++)
        {
            cout<<eq[i]<<" "
                ;
        }
        cout<<endl;
    }



    void createSets(int sz)
    {
        for (int i = 1; i <= sz; i++)
        {
            disjointSetsLeader[i] =  i;
            disjointSetsRank[i] = 1;
        }
    }

    void printSets(int sz)
    {
        for (int i = 1; i <= sz; i++)
        {
            cout<<disjointSetsLeader[i]<< " " <<disjointSetsRank[i]<<endl;
        }
    }

    void unionCharacters(int x, int y)
    {
        int leaderOfX = find(x);
        int leaderOfY = find(y);
        // cout<< x <<" leader " <<leaderOfX<<",, "<< y<<" leader "<<leaderOfY<<endl;
        if (leaderOfX == leaderOfY)
        {
            return;
        }

        if ( disjointSetsRank[leaderOfY] > disjointSetsRank[leaderOfX] )
        {
            swap(leaderOfY, leaderOfX);
            // swap leaderOfY and leaderOfX to avoid writing repetitive code
        }
        disjointSetsLeader[leaderOfY] =  leaderOfX;
        int updatedRankOfX = disjointSetsRank[leaderOfX] +
                             disjointSetsRank[leaderOfY];
        disjointSetsRank[leaderOfX]  =  updatedRankOfX;
        totalSets--;
    }

    int find(int x)
    {
        if (disjointSetsLeader[x] != x)
        {
            int rootLeader = find(disjointSetsLeader[x]);
            disjointSetsLeader[x] =  rootLeader;
            return rootLeader;
        }
        return x;
    }


};





