#pragma once
#include <cmath>

typedef float (*func)(float x);

namespace canpp
{
	template<int R, int C>
	class mat {
	public:
		mat()
		{
			for (size_t i = 0; i < R; i++)
			{
				for (size_t j = 0; j < C; j++)
				{
					m_data[i][j] = 0.0f;
				}
			}
		}
		mat(std::array<std::array<float, C>, R> data)
			:m_data(data)
		{
		}

		inline int rows() { return R; }
		inline int columns() { return R; }
		inline std::array<float, C> row(int r) { return m_data[r]; }
		inline std::array<float, R> column(int C) 
		{ 
			std::array<float, R> result;
			for (size_t i = 0; i < R; i++)
			{
				result[i] = m_data[i][c];
			}
			return result;
		}

	private:
		std::array<std::array<float, C>, R> m_data;
	};
}
class Matrix
{
public:
	Matrix(int r, int c);
	Matrix(int r, int c, float* d);
	Matrix(const Matrix& copy);
	~Matrix();

	Matrix& Randomize(float min, float max);
	static Matrix* MatrixMultiplication(const Matrix& left, const Matrix& right);
	static Matrix* MatrixMultiplication(Matrix* left, Matrix* right);
	Matrix& Transpose();
	static Matrix* Transpose(Matrix* matrix);
	Matrix* Activation(func f);
	static Matrix* Map(Matrix* matrix, func f);

	friend Matrix* operator+(float left, const Matrix& right);
	friend Matrix* operator+(const Matrix& left, float right);
	friend Matrix* operator+(const Matrix& left, const Matrix& right);
	Matrix* operator+=(float x);
	Matrix* operator+=(const Matrix& other);

	friend Matrix* operator-(float left, const Matrix& right);
	friend Matrix* operator-(const Matrix& left, float right);
	friend Matrix* operator-(const Matrix& left, const Matrix& right);
	Matrix* operator-=(float x);
	Matrix* operator-=(const Matrix& other);

	friend Matrix* operator*(float left, const Matrix& right);
	friend Matrix* operator*(const Matrix& left, float right);
	friend Matrix* operator*(const Matrix& left, const Matrix& right);
	Matrix* operator*=(float x);
	Matrix* operator*=(const Matrix& other);

	friend Matrix* operator/(float left, const Matrix& right);
	friend Matrix* operator/(const Matrix& left, float right);
	friend Matrix* operator/(const Matrix& left, const Matrix& right);
	Matrix* operator/=(float x);
	Matrix* operator/=(const Matrix& other);


	void Print() const;

public:
	inline int GetRows() const { return rows; }
	inline int GetColumns() const { return columns; }

	inline void SetRows(int r) { rows = r; }
	inline void SetColumns(int c) { columns = c; }
	inline void SetData(float* d) { data = d; }

private:
	int size;
	int rows;
	int columns;
public:
	float* data;
};