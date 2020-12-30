class CPM
{
private:
	vector<vector<pair<int, double>>> arr;
	vector<double> Forward;
	vector<double> Backward;
	
public:

	CPM(int n)
	{
		
	}

	void AddDirectedEdge(int source, int destination, double weight = 0)
	{
		
	}
	
	void Iterate()
	{
		
	}

	void Print()
	{
		
	}
};

/*
-----Constraints-----
1 <= xi, yi <= n
wi: weight in double
1 <= i <= t

-----Input Format-----
n t
x1 y1 w1
...
xt yt wt

-----Sample Input-----
7 9
1 2 8
1 3 2
2 4 2
2 5 3
3 5 2
4 6 7
5 6 3
6 7 6
5 4 0

-----Sample Output-----
1 0 0
2 3 3
3 2 4
4 6 6
5 6 6
6 13 13
7 19 19
*/
