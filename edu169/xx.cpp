class Solution {
public:
    string largestPalindrome(int n, int k) {
        if (k == 1 || k == 3 || k == 9) return string(n, '9');
        
        if (n == 1) return string(1, '0' + min(k, 9));
        
        string result(n, '9');
        
        switch(k) {
            case 2:
            case 5:
                result[0] = result[n-1] = '0' + k;
                break;
            case 4:
            case 8:
                if (n <= (k == 4 ? 3 : 5)) return string(n, '8');
                result[0] = result[1] = result[n-2] = result[n-1] = '8';
                if (k == 8 && n > 5) result[2] = result[n-3] = '8';
                break;
            case 6:
                result[0] = result[n-1] = '8';
                if (n % 2) result[n/2] = '8';
                else result[n/2] = result[n/2 - 1] = '7';
                break;
            case 7:
                return calc(n);
            default:
                return "";
        }
        
        return result;
    }

class Solution {
public:
    int dp[100005][11];
    int up[100005];
    int solve(int i, int n, int t, int mod, int k, vector<vector<int>>& kmod){
        if(i == n) return mod == 0;
        if(dp[i][mod] != -1) return dp[i][mod];
        int oi = t - i - 1;
        int no = 0;
        for(int dig=9; dig>=0; dig--){
            int val = solve(i+1, n, t, (mod + kmod[i][dig] + ((oi != i) ? kmod[oi][dig] : 0)) % k, k, kmod);
            if(val){
                up[i] = dig;
                break;
            }
        }
        return dp[i][mod] = (up[i] != -1);
    }
    string largestPalindrome(int n, int k) {
        vector<vector<int>> kmod(n, vector<int>(10));
        int num = 1;
        for(int i=0; i<n; i++){
            for(int j=1; j<10; j++){
                kmod[i][j] = (num * j) % k;
            }
            num = (num * 10) % k;
        }
        memset(dp, -1, sizeof dp);
        memset(up, -1, sizeof up);
        string ans(n, '0');
        solve(0, (n+1)/2, n, 0, k, kmod);
        for(int i=0; i<(n+1)/2; i++){
            ans[i] = '0' + up[i];
            ans[n-i-1] = ans[i];
        }
        return ans;
    }
};