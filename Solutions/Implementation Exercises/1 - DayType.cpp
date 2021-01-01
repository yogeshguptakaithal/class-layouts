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
	Daytype(DaysOfWeek day = DaysOfWeek::Monday) : curr_day(day)
	{

	}

	DaysOfWeek getDay() const
	{
		return curr_day; 
	}

	void setDay(DaysOfWeek dy)
	{
		curr_day = dy;
	}

	string getString() const
	{
		return Days[(int)curr_day];
	}

	Daytype nextDay()
	{
		return dayAfterDays(1);
	}

	Daytype getprevious()
	{
		return dayAfterDays(-1);
	}

	Daytype dayAfterDays(int d) const
	{
		d += (int)this->curr_day;
		return Daytype(static_cast<DaysOfWeek>(d % 7));
	}
};
