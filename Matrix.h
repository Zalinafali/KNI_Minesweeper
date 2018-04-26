#pragma once

#include <cassert>

template<typename T>
class Matrix {
	int width_;
	int height_;
	std::vector<T> data_;

public:
	Matrix() : width_(0), height_(0) {}
	Matrix(int _width, int _height) : width_(_width), height_(_height) {
		for (int i = 0; i < width_ * height_; i++)
			data_.push_back(area());
	}

	int width() { return width_; }
	int height() { return height_; }

	T& operator()(int row, int col) {
		assert(col < width_);
		assert(row < height_);
		return data_[row * width_ + col];
	}
};