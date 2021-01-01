class CPM
{
private:
	vector<vector<pair<int, double>>> arr;
	vector<double> Forward;
	vector<double> Backward;

	void dfs(const int v, vector<bool>& visited, vector<int>& ans) const
	{
		visited[v] = true;
		for (const auto& u : arr[v]) {
			if (!visited[u.first])
				dfs(u.first, visited, ans);
		}
		ans.push_back(v);
	}

	void topological_sort(const int n, vector<bool>& visited, vector<int>& ans) const
	{
		visited.assign(n, false);
		ans.clear();
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
				dfs(i, visited, ans);
		}
		reverse(ans.begin(), ans.end());
	}

public:

	CPM(int n) :
		arr(vector(n, vector<pair<int, double>>())),
		Forward(vector<double>(n, -1)),
		Backward(vector<double>(n, INT_MAX))
	{

	}

	void AddDirectedEdge(int source, int destination, double weight = 0)
	{
		arr[source - 1].push_back({ destination - 1, weight });
	}

	void Iterate()
	{
		int n = arr.size();
		vector<bool> visited = vector<bool>(n, false);
		vector<int> ans = vector<int>(n, -1);
		topological_sort(n, visited, ans);


		Forward[0] = 0;
		for (int source : ans)
			for (const auto &dest : arr[source])	// dest.first -> destination node index, dest.second -> weight to go from source to dest
				Forward[dest.first] = max(Forward[dest.first], Forward[source] + dest.second);

		Backward[n - 1] = Forward[n - 1];

		for (int i = n - 1; i > -1; --i)
		{
			auto source = ans[i];
			for (const auto &dest : arr[source])	// dest.first -> destination node index, dest.second -> weight to go from source to dest
				Backward[source] = min(Backward[source], Backward[dest.first] - dest.second);
		}
	}

	void Print()
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			cout << i + 1 << "\t" << Forward[i] << "\t" << Backward[i] << endl;
		}
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
