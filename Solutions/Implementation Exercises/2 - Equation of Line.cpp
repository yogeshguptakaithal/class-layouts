class Linetype
{
private:
	double a;
	double b;
	double c;

	static constexpr auto inf = std::numeric_limits<double>::infinity();

public:
	Linetype(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c)
	{
		assert(a != 0 || b != 0);
	}

	inline bool IsVertical() const
	{
		return this->b == 0;
	}

	inline bool IsHorizontal() const
	{
		return this->a == 0;
	}

	inline double Slope() const
	{
		if (IsVertical())
			return inf;
		return -this->a / this->b;
	}

	bool areEqual(const Linetype &lhs, const Linetype& rhs) const
	{
		int a = (lhs.a == 0 ? 1 : 0) | (lhs.b == 0 ? 2 : 0) | (lhs.c == 0 ? 4 : 0);
		int b = (rhs.a == 0 ? 1 : 0) | (rhs.b == 0 ? 2 : 0) | (rhs.c == 0 ? 4 : 0);

		if (a ^ b)	// Not Same Type
			return false;

		double temp[3]
		{
			(a & 1) ? lhs.a / rhs.a : inf,
			(a & 2) ? lhs.b / rhs.b : inf,
			(a & 4) ? lhs.c / rhs.c : inf
		};

		for (auto d1 : temp)
			for (auto d2 : temp)
				if (d1 != inf && d2 != inf && d1 != d2)
					return false;

		return true;
	}

	inline bool areParallel(const Linetype& lhs, const Linetype& rhs) const
	{
		return lhs.Slope() == rhs.Slope();
	}

	inline bool arePrependicular(const Linetype& lhs, const Linetype& rhs) const
	{
		auto sl1 = lhs.Slope();
		auto sl2 = rhs.Slope();
		
		if (sl1 == inf)
			return sl2 == 0;
		if (sl2 == inf)
			return sl1 == 0;

		return sl1 * sl2 == -1;
	}

	/// <summary>
	/// Returns true if unique point of intersectionexists
	/// </summary>
	/// <param name="rhs">Line with which we want of find point of intersection</param>
	/// <param name="x">x coordinate of intersection. Infinity if unique solution doesn't exist</param>
	/// <param name="y">y coordinate of intersection. Infinity if unique solution doesn't exist</param>
	bool IntersectWith(const Linetype& rhs, double &x, double &y) const
	{
		x = y = inf;

		auto denom = this->a * rhs.b - rhs.a * this->b;
		if (denom == 0)
		{
			cerr << "No unique point of intersection exists" << endl;
			return false;
		}

		x = (this->b * rhs.c - rhs.b * this->c) / denom;
		y = (this->c * rhs.a - rhs.c * this->a) / denom;
		return true;
	}
};