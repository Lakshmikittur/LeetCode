class Solution {
public:
    bool buddyStrings(string A, string B) {
        
        int m = A.length();
        int n = B.length();
        
        if(m==0 || n==0 || m!=n)
            return false;
        
        int mismatch_count=0;
        char a1,b1,a2,b2;
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<m;i++)
        {
            if(A[i]!=B[i])
            {
                if(mismatch_count==0)
                {
                    a1=A[i];
                    b1= B[i];
                    mismatch_count++;
                }
                else if(mismatch_count==1)
                {
                    a2=A[i];
                    b2=B[i];
                    mismatch_count++;
                }
                else if(mismatch_count==2)
                {
                    return false;
                }              
        
            }
            
            mp[A[i]]++;
            
            if(mismatch_count>2)
                return false;
        }
        
        if(mismatch_count==2)
        {
            if(a2==b1 && a1==b2)
                return true;
            return false;
        }
            
        
        else if(mismatch_count==0)
        {
            if(A.compare(B)==0) //Eg:ababa shoudl return true but abcd false..so checking such things
            {
                for(auto i = mp.begin();i!=mp.end();i++)
                {
                    if(i->second>=2)
                        return true;
                }
                return false;
            }
            for(int i=1;i<m;i++) //Eg: aaaaa true
            {
                if(A[0]!=B[i])
                    return false;
            }
            
            return true;
            
        }
        return false;
        
    }
};
