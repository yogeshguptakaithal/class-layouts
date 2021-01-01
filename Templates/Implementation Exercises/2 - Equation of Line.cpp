class Linetype
{
private:
	double a;
	double b;
	double c;

	static constexpr auto inf = std::numeric_limits<double>::infinity();

public:
	Linetype(double a = 0, double b = 0, double c = 0) 
	{
		assert(a != 0 || b != 0);
		this->a = a;
		this->b = b;
		this->c = c;
	}

	inline bool IsVertical() const
	{

	}

	inline bool IsHorizontal() const
	{

	}

	inline double Slope() const
	{

	}

	bool areEqual(const Linetype &lhs, const Linetype& rhs) const
	{

	}

	inline bool areParallel(const Linetype& lhs, const Linetype& rhs) const
	{

	}

	inline bool arePrependicular(const Linetype& lhs, const Linetype& rhs) const
	{

	}

	/// <summary>
	/// Returns true if unique point of intersectionexists
	/// </summary>
	/// <param name="rhs">Line with which we want of find point of intersection</param>
	/// <param name="x">x coordinate of intersection. Infinity if unique solution doesn't exist</param>
	/// <param name="y">y coordinate of intersection. Infinity if unique solution doesn't exist</param>
	bool IntersectWith(const Linetype& rhs, double &x, double &y) const
	{

	}
};