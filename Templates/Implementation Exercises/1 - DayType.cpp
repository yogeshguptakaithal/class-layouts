enum class DaysOfWeek : short
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class Daytype 
{
private:
	DaysOfWeek curr_day;
	inline static const string Days[7] { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
public:
	Daytype(DaysOfWeek day = DaysOfWeek::Monday)
	{
		
	}

	DaysOfWeek getDay() const
	{
		
	}

	void setDay(DaysOfWeek dy)
	{
		
	}

	string getString() const
	{
		
	}

	Daytype nextDay()
	{
		
	}

	Daytype getprevious()
	{
		
	}

	Daytype dayAfterDays(int d) const
	{
		
	}
};