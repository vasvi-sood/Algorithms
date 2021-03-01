
Given a stair case of  n steps we can take 1,2 or 3 steps at a time, calculate the number of ways for reaching from n to 0th level
eg n=4
possible paths 1,1,1,1... 2,2... 2,1,1... 1,1,2 , 3,1 etc
Here a recursive approach is changed to tabular approach by fir taking the base case and moving upwards. For eg here stair 0 has paths 1
Stair 1 has 1 path to reach 0, 2 has 2 paths...
