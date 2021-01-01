
class TicTacToe
{
private:
	int **board;
	int player;
	static constexpr auto DIMENSIONS = 3;

public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="StartPlayer">Either 1 or -1</param>
	TicTacToe(int StartPlayer = 1) : player(StartPlayer)
	{
		assert(StartPlayer * StartPlayer == 1);
		board = new int*[DIMENSIONS];

		for (int i = 0; i < DIMENSIONS; ++i)
		{
			board[i] = new int[DIMENSIONS];
			for (int j = 0; j < DIMENSIONS; ++j)
				board[i][j] = 0;
		}
	}

	void PrintBoard() const
	{
		
	}

	bool IsValidMove(int row, int column) const
	{
		
	}

	void Move(int row, int column)
	{
		
	}

	/// <summary>
	/// Checks if we have a winner
	/// </summary>
	/// <returns>player ID if some player won the game, otherwise 0</returns>
	int Winner() const
	{
		
	}
};