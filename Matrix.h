#pragma once

#include <cassert>

template<typename T>
class Matrix {
	size_t width_;
	size_t height_;
	std::vector<T> data_;

public:
	Matrix() : width_(0), height_(0) {}
	Matrix(int _width, int _height) : width_(_width), height_(_height) {
		for (int i = 0; i < width_ * height_; i++)
			data_.push_back(area());
	}

	size_t width() { return width_; }
	size_t height() { return height_; }

	T& operator()(size_t row, size_t col) {
		assert(col < width_);
		assert(row < height_);
		return data_[row * width_ + col];
	}

	/*T const& operator()(size_t row, size_t col) {
	return const_cast<Matrix&>(*this)(row, col);
	}*/
};