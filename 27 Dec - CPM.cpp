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

int main() 
{
	int n, t;
	cin >> n >> t;

	CPM cpm = CPM(n);

	cout << "N : " << n << endl << "T : " << t << endl;

	while (t--)
	{
		int x, y;
		double w;
		cin >> x >> y >> w;
		cout << "Edge added : " << x << " -> " << y << " with weight " << w << endl;
		cpm.AddDirectedEdge(x, y, w);
	}

	cpm.Iterate();
	cpm.Print();

	return 0;
}
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

-----Sample Output of Print method of CPM class-----
1 0 0
2 3 3
3 2 4
4 6 6
5 6 6
6 13 13
7 19 19
*/
