class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        long n = a.size(), m = b.size();
        vector<int> arr(n + m);
        // int i=0,j=0;
        // for(int k=0;k<n+m;k++)
        // {
        //     if(i>=n)
        //     {
        //        arr[k]=b[j];
        //         j++;
        //     }
        //     else
        //         if(j>=m)
        //         {
        //             arr[k]=a[i];
        //             i++;
        //         }
        //     else
        //         if(a[i]<=b[j])
        //         {
        //               arr[k]=a[i];
        //             i++;
        //         }
        //     else
        //     {
        //         arr[k]=b[j];
        //         j++;
        //     }
        // }
        merge(a.begin(), a.end(), b.begin(), b.end(), arr.begin());
        /*Returns a merged sorted list of any two given lists(even non sorted)*/
        long num1 = arr[(m + n) / 2];
        if ((m + n) % 2 == 1)
            return (double)num1;
        long num2 = arr[((m + n) / 2) - 1];
        return ((double)num1 + num2) / 2;
    }
};