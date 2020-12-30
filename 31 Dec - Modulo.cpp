// layout for modulo class
#define MOD 1000000007

class ModuloWrapper
{
private:
	long long int number;
	static const auto mod = MOD;

public:
	ModuloWrapper(long long int num = 0)
	{

	}

	// implicitly convert to long long int
	inline operator long long int() const
	{
	
	}

	ModuloWrapper operator+(const long long& rhs) const
	{
	
	}

	ModuloWrapper operator-(const long long& rhs) const
	{
	
	}

	ModuloWrapper operator*(const long long& rhs) const
	{
	
	}

	ModuloWrapper operator/(const long long& rhs) const
	{
	
	}

	ModuloWrapper& operator +=(const long long& rhs)
	{
	
	}

	ModuloWrapper& operator -=(const long long& rhs)
	{
	
	}

	ModuloWrapper& operator *=(const long long& rhs)
	{
	
	}

	ModuloWrapper& operator /=(const long long& rhs)
	{
	
	}
	
	// TODO: Add four more operator overloading methods to achieve the following: 
	// 1.	long long + MW
	// 2.	long long - MW
	// 3.	long long * MW
	// 4.	long long / MW
	// where MW is short form for ModuloWrapper.
	// Reference link: https://stackoverflow.com/questions/34292219/binary-operator-overloading-in-c-with-differing-data-types
};
