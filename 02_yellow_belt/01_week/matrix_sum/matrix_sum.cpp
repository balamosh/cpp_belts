#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

class Matrix
{
	public:
		Matrix()
		{
			rows = 0;
			cols = 0;
			matrix = {};
		}

		Matrix(int num_rows, int num_cols)
		{
			Reset(num_rows, num_cols);
		}

		int	GetNumRows() const
		{
			return (rows);
		}

		int	GetNumColumns() const
		{
			return (cols);
		}

		void	Reset(int new_rows, int new_cols)
		{
			if (new_rows < 0 || new_cols < 0)
				throw out_of_range("Wrong matrix size");
			if (new_rows != 0 && new_cols != 0)
			{
				rows = new_rows;
				cols = new_cols;
			}
			else
			{
				rows = 0;
				cols = 0;
			}
			matrix = vector<vector<int>>(rows, vector<int>(cols, 0));
		}

		int	At(int row, int col) const
		{
			if (row < rows && row >= 0 && col < cols && col >= 0)
				return (matrix[row][col]);
			else
				throw out_of_range("At(" 
						+ to_string(row) + ", "
						+ to_string(col) +
						+ ") from matrix("
						+ to_string(rows) + ", "
						+ to_string(cols) + ")");
		}
		
		int&	At(int row, int col)
		{
			if (row < rows && row >= 0 && col < cols && col >= 0)
				return (matrix[row][col]);
			else
				throw out_of_range("At(" 
						+ to_string(row) + ", "
						+ to_string(col) +
						+ ") from matrix("
						+ to_string(rows) + ", "
						+ to_string(cols) + ")");
		}

	private:
		int			rows;
		int			cols;
		vector<vector<int>>	matrix;
};

ostream&	operator<<(ostream& stream, const Matrix& matrix)
{
	int	rows = matrix.GetNumRows();
	int	cols = matrix.GetNumColumns();
	stream << rows << ' ' << cols << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			stream << matrix.At(i, j);
			stream << ' ';
		}
		stream << matrix.At(i, cols - 1) << endl;
	}
	return (stream);
}

istream&	operator>>(istream& stream, Matrix& matrix)
{
	int	rows, cols;
	stream >> rows >> cols;
	matrix = Matrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			stream >> matrix.At(i, j);
		}
	}
	return (stream);
}

bool		operator==(const Matrix& lhs, const Matrix& rhs)
{
	int	rows = lhs.GetNumRows();
	int	cols = lhs.GetNumColumns();
	if (rows != rhs.GetNumRows() || cols != rhs.GetNumColumns())
		return (false);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (lhs.At(i, j) != rhs.At(i, j))
				return (false);
		}
	}
	return (true);
}

Matrix		operator+(const Matrix& lhs, const Matrix& rhs)
{
	int	rows = lhs.GetNumRows();
	int	cols = lhs.GetNumColumns();
	if (rows != rhs.GetNumRows() || cols != rhs.GetNumColumns())
		throw invalid_argument("Matrix size conflict");
	Matrix	new_matrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			new_matrix.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
		}
	}
	return (new_matrix);
}
