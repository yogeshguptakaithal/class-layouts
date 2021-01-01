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
		for (int i = 0; i < DIMENSIONS; ++i)
		{
			for (int j = 0; j < DIMENSIONS; ++j)
				cout << (
					board[i][j] == 1
					? "X"
					: board[i][j] == -1
					? "0"
					: "-");
			cout << endl;
		}
	}

	bool IsValidMove(int row, int column) const
	{
		if (row < 0 || row >= DIMENSIONS || column < 0 || column >= DIMENSIONS || Winner() != 0)
			return false;

		return board[row][column] == 0;
	}

	void Move(int row, int column)
	{
		assert(IsValidMove(row, column));
		board[row][column] = player;
		player *= -1;
	}

	/// <summary>
	/// Checks if we have a winner
	/// </summary>
	/// <returns>player ID if some player won the game, otherwise 0</returns>
	int Winner() const
	{
		// Vertical
		for (int j = 0; j < DIMENSIONS; ++j)
		{
			if (board[0][j] == 0)
				continue;

			bool win = true;
			for (int i = 0; i < DIMENSIONS; ++i)
				if (board[i][j] != board[0][j])
				{
					win = false; 
					break;
				}

			if (win)
				return board[0][j];
		}

		// Horizontal

		for (int i = 0; i < DIMENSIONS; ++i)
		{
			if (board[i][0] == 0)
				continue;

			bool win = true;
			for (int j = 0; j < DIMENSIONS; ++j)
				if (board[i][j] != board[i][0])
				{
					win = false;
					break;
				}

			if (win)
				return board[i][0];
		}

		// Diagonal '\'
		bool win = true;
		for (int i = 0; i < DIMENSIONS; ++i)
		{
			if (board[i][i] != board[0][0])
			{
				win = false;
				break;
			}
		}

		if (win)
			return board[0][0];

		// Diagonal '/'
		win = true;
		for (int i = 0; i < DIMENSIONS; ++i)
		{
			if (board[i][DIMENSIONS - i - 1] != board[0][DIMENSIONS - 1])
			{
				win = false;
				break;
			}
		}

		if (win)
			return board[0][DIMENSIONS - 1];

		return 0;
	}
};