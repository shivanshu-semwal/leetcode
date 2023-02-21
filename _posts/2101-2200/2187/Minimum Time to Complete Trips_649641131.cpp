class Solution {
public:
   
    long long minimumTime(vector<int>& time, long long t) {
        long long n = time.size();
        long long ul=0, ll=0;
        
        double temp=0;
        for(long long i=0;i<n;i++){
            temp += 1.0/time[i];
        }
        
        long long m = -1;
        for (long long i = 0; i < n; i++) {
            m = max((long long) time[i], m);
        }
        
        ll = t/temp;
        ul = t * m;
        
        while(1){
            if(ll == ul) return ll;
            long long mid = ll + (ul - ll)/2;
            long long c = 0;
            for(long long j=0;j<n;j++){
                c += mid/(long long)time[j];
            }
            //if(c==t) return mid;
            if(c>=t){
                ul = mid;
            } else if(c<t){
                ll = mid + 1;
            }
        }

        return 0;
    }
};
