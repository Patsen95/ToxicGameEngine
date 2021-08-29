#include "Matrix.h"
#include "../System/Convert.h"
#include "../Math/Random.h"



template<class T>
inline toxic::Matrix<T>::Matrix()
{
	this->rows = 1;
	this->cols = 1;
	_mat.resize(this->rows);
	for(unsigned int i = 0; i < _mat.size(); i++)
		_mat[i].resize(this->cols, static_cast<T>(0));
}

template<class T>
inline toxic::Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
	if(rows < 1) rows = 1;
	if(cols < 1) cols = 1;

	this->rows = rows;
	this->cols = cols;
	_mat.resize(this->rows);
	for(unsigned int i = 0; i < _mat.size(); i++)
		_mat[i].resize(this->cols, static_cast<T>(0));
}

template<class T>
inline toxic::Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const T& initVal)
{
	if(rows < 1) rows = 1;
	if(cols < 1) cols = 1;

	this->rows = rows;
	this->cols = cols;
	_mat.resize(this->rows);
	for(unsigned int i = 0; i < _mat.size(); i++)
		_mat[i].resize(this->cols, initVal);
}

template<class T>
inline toxic::Matrix<T>::Matrix(const Matrix<T>& other)
{
	this->_mat = other._mat;
	this->rows = other.rows;
	this->cols = other.cols;
}

template<class T>
inline toxic::Matrix<T>::~Matrix()
{
	_mat.clear();
}

template<class T>
inline toxic::Matrix<T>& toxic::Matrix<T>::operator=(const Matrix<T>& other)
{
	if(&other == this)
		return (*this);
	unsigned int _rows = other.GetRows();
	unsigned int _cols = other.GetCols();
	_mat.resize(_rows);
	for(unsigned int i = 0; i < _mat.size(); i++)
		_mat[i].resize(_cols);

	for(unsigned int i = 0; i < _rows; i++)
	{
		for(unsigned int j = 0; j < _cols; j++)
			_mat[i][j] = other(i, j);
	}
	this->rows = _rows;
	this->cols = _cols;
	return (*this);
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator+(const Matrix<T>& other)
{
	Matrix<T> res(this->rows, this->cols);
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			res(i, j) = _mat[i][j] + other(i, j);
	}
	return res;
}

template<class T>
inline toxic::Matrix<T>& toxic::Matrix<T>::operator+=(const Matrix<T>& other)
{
	unsigned int _rows = other.GetRows();
	unsigned int _cols = other.GetCols();
	for(unsigned int i = 0; i < _rows; i++)
	{
		for(unsigned int j = 0; j < _cols; j++)
			_mat[i][j] += other[i][j];
	}
	return (*this);
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator-(const Matrix<T>& other)
{
	unsigned int _rows = other.GetRows();
	unsigned int _cols = other.GetCols();
	Matrix<T> res(_rows, _cols);
	for(unsigned int i = 0; i < _rows; i++)
	{
		for(unsigned int j = 0; j < _cols; j++)
			res(i, j) = _mat[i][j] - other(i, j);
	}
	return res;
}

template<class T>
inline toxic::Matrix<T>& toxic::Matrix<T>::operator-=(const Matrix<T>& other)
{
	unsigned int _rows = other.GetRows();
	unsigned int _cols = other.GetCols();
	for(unsigned int i = 0; i < _rows; i++)
	{
		for(unsigned int j = 0; j < _cols; j++)
			_mat[i][j] -= other[i][j];
	}
	return (*this);
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator*(const Matrix<T>& other)
{
	unsigned int _rows = other.GetRows();
	unsigned int _cols = other.GetCols();
	Matrix<T> res(_rows, _cols);

	for(uint i = 0; i < _rows; i++)
	{
		for(uint j = 0; j < _cols; j++)
		{
			for(unsigned int k = 0; k < rows; k++)
				res(i, j) += _mat[i][k] * other(k, j);
		}
	}
	return res;
}

template<class T>
inline toxic::Matrix<T>& toxic::Matrix<T>::operator*=(const Matrix<T>& other)
{
	Matrix<T> res = (*this) * other;
	(*this) = res;
	return (*this);
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator+(const T& val)
{
	Matrix<T> res(this->rows, this->cols);
	for(unsigned int i = 0; i < rows; i++)
	{
		for(unsigned int j = 0; j < cols; j++)
			res(i, j) = _mat[i][j] + val;
	}
	return res;
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator-(const T& val)
{
	Matrix<T> res(this->rows, this->cols);
	for(unsigned int i = 0; i < rows; i++)
	{
		for(unsigned int j = 0; j < cols; j++)
			res(i, j) = _mat[i][j] - val;
	}
	return res;
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator*(const T& val)
{
	Matrix<T> res(this->rows, this->cols);
	for(unsigned int i = 0; i < rows; i++)
	{
		for(unsigned int j = 0; j < cols; j++)
			res(i, j) = _mat[i][j] * val;
	}
	return res;
}

template<class T>
inline toxic::Matrix<T> toxic::Matrix<T>::operator/(const T& val)
{
	Matrix<T> res(this->rows, this->cols);
	for(unsigned int i = 0; i < rows; i++)
	{
		for(unsigned int j = 0; j < cols; j++)
			res(i, j) = _mat[i][j] / val;
	}
	return res;
}

template<class T>
inline T& toxic::Matrix<T>::operator()(const unsigned int& row, const unsigned int& col)
{
	return this->_mat[row][col];
}

template<class T>
inline const T& toxic::Matrix<T>::operator()(const unsigned int& row, const unsigned int& col) const
{
	return this->_mat[row][col];
}

template<class T>
inline void toxic::Matrix<T>::Randomize()
{
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			_mat[i][j] = static_cast<T>(Random::NextFloat(100.0));
	}
}

template<class T>
inline void toxic::Matrix<T>::SetIdentity()
{
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			_mat[i][j] = (i == j ? 1 : 0);
	}
}

template<class T>
inline void toxic::Matrix<T>::SetZero()
{
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			_mat[i][j] = 0;
	}
}

template<class T>
inline void toxic::Matrix<T>::Negate()
{
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			_mat[i][j] = -_mat[i][j];
	}
}

template<class T>
inline void toxic::Matrix<T>::Transpose()
{
	unsigned int newRows = this->cols;
	unsigned int newCols = this->rows;
	std::vector<std::vector<T>> tmp(newRows);

	for(unsigned int i = 0; i < tmp.size(); i++)
		tmp[i].resize(newCols);

	for(unsigned int i = 0; i < newRows; i++)
	{
		for(unsigned int j = 0; j < newCols; j++)
			tmp[i][j] = _mat[j][i];
	}
	
	_mat.resize(newRows);
	for(unsigned int i = 0; i < _mat.size(); i++)
			_mat[i].resize(newCols);

	for(unsigned int i = 0; i < newRows; i++)
	{
		for(unsigned int j = 0; j < newCols; j++)
			_mat[i][j] = tmp[i][j];
	}
	this->rows = newRows;
	this->cols = newCols;
}

template<class T>
inline std::vector<T> toxic::Matrix<T>::GetDiagonal() const
{
	unsigned int _size = (this->rows < this->cols ? this->rows : this->cols);
	std::vector<T> diag(_size);
	for(unsigned i = 0; i < _size; i++)
		diag[i] = _mat[i][i];
	return diag;
}

//template<class T>
//inline T toxic::Matrix<T>::Determinant()
//{
//	if(IsSquare())
//	{
//		unsigned int sz = this->rows;
//		
//		T det;
//		for(unsigned int i = 0; i < sz; i++)
//		{
//			
//		}
//	}
//	return T();
//}

template<class T>
inline bool toxic::Matrix<T>::IsZero() const
{
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
		{
			if(_mat[i][j] == 0)
				return true;
			else return false;
		}
	}
}

template<class T>
inline bool toxic::Matrix<T>::IsSquare() const
{
	return (this->rows == this->cols);
}

template<class T>
inline unsigned int toxic::Matrix<T>::GetRows() const
{
	return this->rows;
}

template<class T>
inline unsigned int toxic::Matrix<T>::GetCols() const
{
	return this->cols;
}

template<class T>
inline unsigned int toxic::Matrix<T>::Size() const
{
	return (this->rows * this->cols);
}

template<class T>
inline T* toxic::Matrix<T>::GetRawMatrix() const
{
	std::vector<T> vec;
	for(unsigned int i = 0; i < this->rows; i++)
	{
		for(unsigned int j = 0; j < this->cols; j++)
			vec.push_back(_mat[i][j]);
	}
	return vec.data();
}
///////////////////////////////////////////////////
//template<class T>
//inline toxic::String toxic::Matrix<T>::ToString() const
//{
//	String str = "Matrix<";
//	str.Append(typeid(T).name()).Append(">");
//	str.Append("(").Append(Convert::ToString(this->rows)).Append("x").Append(Convert::ToString(this->cols)).Append("):\n");
//
//	for(unsigned i = 0; i < this->rows; i++)
//	{
//		str.Append("\t");
//		for(unsigned j = 0; j < this->cols; j++)
//		{
//			str.Append(Convert::ToString(_mat[i][j]));
//			if(j != (this->cols - 1))
//				str.Append(" ");
//		}
//		str.Append("\n");
//	}
//	return str;
//}
