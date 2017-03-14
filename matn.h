#pragma once

template <typename T, const int length>
class matn {
// constructors
public:
	matn();
	matn(const matn& m);

// operators
public:
	operator const T* () const;

	T* operator [] (int i);
	const T* operator [] (int i) const;

	matn& operator = (const matn& m);

	matn operator * (const matn& m) const;
	void operator *= (const matn& m);

// static functions
public:
	static matn identity();

// protected variables
protected:
	T data[length][length];
};	// matn

#include "matn.inl"
