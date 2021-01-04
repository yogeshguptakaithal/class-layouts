enum class FromExpressionType
{
	PREFIX,
	INFIX,
	POSTFIX
};

enum class ToExpressionType
{
	PREFIX,
	POSTFIX
};

class ExpressionSolver
{
private:
	string expression;
	ToExpressionType Type;

protected:
	static string PrefixToInfix(const string& input)
	{

	}

	static string PostfixToInfix(const string& input)
	{

	}

	static string InfixToPrefix(const string& input)
	{

	}

	static string InfixToPostfix(const string& input)
	{

	}

	double SolvePrefix() const
	{

	}

	double SolvePostfix() const
	{

	}

public:
	ExpressionSolver(
		string& exp,
		FromExpressionType from = FromExpressionType::INFIX,
		ToExpressionType to = ToExpressionType::PREFIX) : Type(to)
	{
		if (from == FromExpressionType::POSTFIX && to == ToExpressionType::POSTFIX ||
			from == FromExpressionType::PREFIX && to == ToExpressionType::PREFIX)
		{
			this->expression = exp;
			return;
		}

		string* final_infix;

		// If the following switch body can have possible errors related to pointers, fix them
		switch (from)
		{
		case FromExpressionType::PREFIX:
			assert(IsValidPrefix(exp));
			final_infix = &PrefixToInfix(exp);
			break;

		case FromExpressionType::INFIX:
			assert(IsValidInfix(exp));
			final_infix = &exp;
			break;

		case FromExpressionType::POSTFIX:
			assert(IsValidPostfix(exp));
			final_infix = &PostfixToInfix(exp);
			break;

		default:
			assert(false);
			break;
		}

		switch (Type)
		{
		case ToExpressionType::PREFIX:
			this->expression = InfixToPrefix(*final_infix);
			break;

		case ToExpressionType::POSTFIX:
			this->expression = InfixToPostfix(*final_infix);
			break;

		default:
			assert(false);
		}
	}

	double Solve()
	{
		switch (Type)
		{
		case ToExpressionType::PREFIX:
			return SolvePrefix();
		case ToExpressionType::POSTFIX:
			return SolvePostfix();
		}

		assert(false);
	}

	static bool IsValidInfix(const string& input)
	{

	}

	static bool IsValidPrefix(const string& input)
	{

	}

	static bool IsValidPostfix(const string& input)
	{

	}
};
