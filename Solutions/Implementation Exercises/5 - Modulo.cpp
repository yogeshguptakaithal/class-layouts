// layout for modulo class
#define MOD 1000000007
class ModuloWrapper
{
private:
	long long int number;
	static const auto mod = MOD;

	static inline auto Modulo(long long n)
	{
		return ((n % MOD) + MOD) % MOD;
	}

public:
	ModuloWrapper(long long int num = 0) : number(Modulo(num))
	{

	}

	inline operator long long int() const
	{
		return number;
	}

	ModuloWrapper operator+(const long long& rhs)
	{
		return ModuloWrapper(this->number + rhs);
	}

	ModuloWrapper operator-(const long long& rhs)
	{
		return ModuloWrapper(this->number - rhs);
	}

	ModuloWrapper operator*(const long long& rhs)
	{
		return ModuloWrapper(this->number * rhs);
	}

	ModuloWrapper operator/(const long long& rhs)
	{
		return ModuloWrapper(this->number * binpow(rhs, mod - 2));
	}

	ModuloWrapper& operator +=(const long long& rhs)
	{
		this->number = ModuloWrapper(*this + rhs);
		return *this;
	}

	ModuloWrapper& operator -=(const long long& rhs)
	{
		this->number = ModuloWrapper(*this - rhs);
		return *this;
	}

	ModuloWrapper& operator *=(const long long& rhs)
	{
		this->number = ModuloWrapper(*this * rhs);
		return *this;
	}

	ModuloWrapper& operator /=(const long long& rhs)
	{
		this->number = ModuloWrapper(*this / rhs);
		return *this;
	}

	ModuloWrapper binpow(long long a, long long b)
	{
		ModuloWrapper val = a;

		ModuloWrapper res(1);
		while (b > 0) 
		{
			if (b & 1)
				res = res * val;
			val = val * val;
			b >>= 1;
		}
		return res;
	}
	
	// TODO: Add four more operator overloading methods to achieve the following: 
	// 1.	long long + MW
	// 2.	long long - MW
	// 3.	long long * MW
	// 4.	long long / MW
	// where MW is short form for ModuloWrapper.
	// Reference link: https://stackoverflow.com/questions/34292219/binary-operator-overloading-in-c-with-differing-data-types
};
