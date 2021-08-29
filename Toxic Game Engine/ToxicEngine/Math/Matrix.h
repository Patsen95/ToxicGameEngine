#pragma once

#include "../Config.h"
//#include "../System/IPrintable.h"

#include <vector>



namespace toxic
{
	template<class T>
	class Matrix //: public IPrintable
	{
	public:
		Matrix();
		Matrix(unsigned int rows, unsigned int cols);
		Matrix(unsigned int rows, unsigned int cols, const T& initVal);
		explicit Matrix(const Matrix<T>& other);
		~Matrix();

		Matrix<T>& operator=(const Matrix<T>& other);
		Matrix<T> operator+(const Matrix<T>& other);
		Matrix<T>& operator+=(const Matrix<T>& other);
		Matrix<T> operator-(const Matrix<T>& other);
		Matrix<T>& operator-=(const Matrix<T>& other);
		Matrix<T> operator*(const Matrix<T>& other);
		Matrix<T>& operator*=(const Matrix<T>& other);

		Matrix<T> operator+(const T& val);
		Matrix<T> operator-(const T& val);
		Matrix<T> operator*(const T& val);
		Matrix<T> operator/(const T& val);

		T& operator()(const unsigned int& row, const unsigned int& col);
		const T& operator()(const unsigned int& row, const unsigned int& col) const;

		void Randomize();
		void SetIdentity();
		void SetZero();
		void Negate();
		void Transpose();
		//void Invert();

		std::vector<T> GetDiagonal() const;

		T Determinant(); // TODO: add definition
		bool IsDiagonal() const;
		bool IsZero() const;
		bool IsSquare() const;
		unsigned int GetRows() const;
		unsigned int GetCols() const;
		unsigned int Size() const;
		T* GetRawMatrix() const;

	private:
		std::vector<std::vector<T>> _mat;
		unsigned int rows;
		unsigned int cols;

//		virtual String ToString() const;
	};
	typedef Matrix<long> Matrix_i;
	typedef Matrix<float> Matrix_f;
	typedef Matrix<double> Matrix_d;
}
#include "Matrix.inl"
