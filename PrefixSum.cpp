#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    cout << "Enter the number of input required.." << endl;
    int n;
    cin >> n;
    vector<int> v(n);

    // Taking inputs...
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Displaying the prefix sum outputs...
    vector<int> pre(n + 1, 0); // Initialize prefix sum array with 0s
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    pre[n] = pre[n - 1]; // Since pre[n] will be the total sum

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        // Calculate sum from l to r (inclusive)
        cout << pre[r] - ((l == 0) ? 0 : pre[l - 1]) << " ";
    }
    cout << endl; // To ensure the output ends with a newline
}

int main()
{
    solve(); // Call the solve function to execute the logic
    return 0;
}
/*
//Leetcode question..
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int> pre(n+1,0);
        pre[0]=nums[0];
        for(int i=1;i<=n-1;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        pre[n]=pre[n-1];

        vector<int> post(n+1,0);
        post[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            post[j]=post[j+1]+nums[j];
        }
        post[n] = post[n-1];

        //now we have 2 arrays ..one pre and second one is post..
        vector<int> ans(n,0);
        for(int k=0;k<n;k++){
            ans[k]+=abs(pre[k]-post[k]);
        }

        return ans;
    }
};*/