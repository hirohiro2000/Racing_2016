#ifndef _VECTOR_TEMPLATE_H_
#define _VECTOR_TEMPLATE_H_

template<typename T, size_t Max, size_t Num>
class VectorBase
{
public:
	void mul(T& val) { /*Vector<T, I>::mul(val); */};
	template<typename First , typename... Vals>
	VectorBase(First& first, Vals&... val){};
	VectorBase(){};
};

template<typename T, size_t Max>
class Vector :public VectorBase<T, Max,1>
{
public:
	Vector(){};
	#define Vector_Assign \
	for (size_t i = 0; i < Max && i < DifMax; i++)\
	{\
		(&x)[-i] = (&v.x)[-i];\
	}
	template<typename DifType,size_t DifMax>
	inline Vector& operator = (const Vector<DifType, DifMax>& v)
	{
		Vector_Assign
		return *this;
	}
	template<typename DifType, size_t DifMax>
	inline Vector (Vector<DifType, DifMax>& v)
	{
		Vector_Assign
	}
	template< typename... Vals>
	inline Vector(Vals... val) :VectorBase<T, Max, 1>(val...){};
	inline Vector& operator *= (T val)
	{
		for (size_t i = 0; i < Max; i++)
		{
			(&x)[-i] *= val;
		}
		return *this;
	}

	inline Vector operator * (T val)
	{
		Vector tmp(*this);
		for (size_t i = 0; i < Max; i++)
		{
			(&tmp.x)[-i] *= val;
		}
		return tmp;
	}
	inline Vector& operator /= (T val)
	{
		for (size_t i = 0; i < Max; i++)
		{
			(&x)[-i] /= val;
		}
		return *this;
	}

	inline Vector operator / (T val)
	{
		Vector tmp(*this);
		for (size_t i = 0; i < Max; i++)
		{
			(&tmp.x)[-i] /= val;
		}
		return tmp;
	}
	template<typename DifType, size_t DifMax>
	inline Vector operator + (const Vector<DifType, DifMax>& v)
	{
		Vector tmp(*this);
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&tmp.x)[-i] += (T)(&v.x)[-i];
		}
		return tmp;
	}

	template<typename DifType, size_t DifMax>
	inline Vector& operator += (const Vector<DifType, DifMax>& v)
	{
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&x)[-i] += (T)(&v.x)[-i];
		}
		return *this;
	}

	template<typename DifType, size_t DifMax>
	inline Vector operator - (const Vector<DifType, DifMax>& v)
	{
		Vector tmp(*this);
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&tmp.x)[-i] -= (T)(&v.x)[-i];
		}
		return tmp;
	}

	template<typename DifType, size_t DifMax>
	inline Vector& operator -= (const Vector<DifType, DifMax>& v)
	{
		for (size_t i = 0; i < Max && i < DifMax; i++)
		{
			(&x)[-i] -= (T)(&v.x)[-i];
		}
		return *this;
	}

	inline float Lengthf()
	{
		float tmp = .0f;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (float)(&x)[-i] * (float)(&x)[-i];
		}
		return sqrtf(tmp);
	}

	inline double Lengthd()
	{
		double tmp = 0.0;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (double)(&x)[-i] * (double)(&x)[-i];
		}
		return sqrt(tmp);
	}

	inline T LengthSq()
	{
		T tmp = ( T)0;
		for (size_t i = 0; i < Max; i++)
		{
			tmp += (&x)[-i] * (&x)[-i];
		}
		return tmp;
	}
	
	void Normalize()
	{
		T l = Lengthf();
		if (l != 0)
			for (size_t i = 0; i < Max; i++)
			{
				(&x)[-i] /= l;
			}
	}
	Vector Normalized()
	{
		Vector tmp(*this);
		T l = Length<T>();
		if (l != 0)
			for (size_t i = 0; i < Max; i++)
			{
				(&tmp.x)[-i] /= l;
			}
		return tmp;
	}

	bool operator ==(const Vector<T,Max>& v)
	{
		for (size_t i = 0; i < Max ; i++)
		{
			if ((&x)[-i] != (&v.x)[-i])
				return false;
		}
		return true;
	}


	bool operator !=(const Vector<T, Max>& v)
	{
		for (size_t i = 0; i < Max; i++)
		{
			if ((&x)[-i] != (&v.x)[-i])
				return true;
		}
		return false;
	}

};

#define makeVectorClass(num,ValName) template<typename T,size_t Max>\
class VectorBase<T,Max, num> :public VectorBase<T,Max, num + 1>\
{\
public:\
	T ValName;\
	VectorBase<T,Max, num>():ValName((T)0){};\
	template<typename First,typename... Vals>\
	inline VectorBase<T,Max, num>(First& first, Vals&... val):VectorBase<T,Max, num + 1>(val...),ValName((T)first){};\
};

#define makeStopperVectorClass(num) template<typename T>\
class VectorBase<T, num, num + 1>\
{\
public:\
	VectorBase<T, num, num + 1>(){};\
};
makeStopperVectorClass(1)
makeStopperVectorClass(2)
makeStopperVectorClass(3)
makeStopperVectorClass(4)

makeVectorClass(4, w)
makeVectorClass(3, z)
makeVectorClass(2, y)
makeVectorClass(1, x)

typedef Vector<int, 1> Vector1i;
typedef Vector<int, 2> Vector2i;
typedef Vector<int, 3> Vector3i;
typedef Vector<int, 4> Vector4i;
typedef Vector<float, 1> Vector1f;
typedef Vector<float, 2> Vector2f;
typedef Vector<float, 3> Vector3f;
typedef Vector<float, 4> Vector4f;
typedef Vector<double, 1> Vector1d;
typedef Vector<double, 2> Vector2d;
typedef Vector<double, 3> Vector3d;
typedef Vector<double, 4> Vector4d;

#endif