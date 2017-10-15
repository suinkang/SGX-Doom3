#pragma once

template<typename T>
class SGX_V
{
private:
	T m_DebugValue;
public:
	void operator =(T Value);
	void operator +=(T Value);
	void operator -=(T Value);
	void operator /=(T Value);
	void operator *=(T Value);
	void operator %=(T Value);
	void operator <<=(T Value);
	void operator >>=(T Value);
	void operator &=(T Value);
	void operator |=(T value);
	void operator ^=(T Value);

	void operator =(SGX_V<T>& Src);

	//일단 비교연산자를 만들긴 했는데 정말 필요한지는 다시 생각해 봐야 할 것 같다.
	bool operator <(T Value);
	bool operator >(T Value);
	bool operator <=(T Value);
	bool operator >=(T Value);
	bool operator ==(T Value);
	bool operator !=(T Value);

	//&, |, ^ 등의 논리 연산은 그냥 사용 가능

	//++, --같은 경우는 어떻게 만들어야되는지 생각해볼 것
	operator T();
};

template<typename T>
void SGX_V<T> :: operator =(T Value)
{
	int ReturnValue;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&Value, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator +=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue += Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator -=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue -= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator /=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue /= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator *=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue *= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator %=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue %= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator <<=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue <<= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator >>=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue >>= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator &=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue &= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator |=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue |= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator ^=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	TempValue ^= Value;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
}

template<typename T>
void SGX_V<T> :: operator =(SGX_V<T>& Src)
{
	T Value = Src;
	int ReturnValue;
	SGX_SetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&Value, sizeof(T));
}

template<typename T>
bool SGX_V<T> :: operator <(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue < Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator >(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue > Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator <=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue <= Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator >=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue >= Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator ==(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue == Value)
		return true;
	else
		return false;
}

template<typename T>
bool SGX_V<T> :: operator !=(T Value)
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	if (TempValue != Value)
		return true;
	else
		return false;
}

template<typename T>
SGX_V<T> :: operator T()
{
	T TempValue;
	int ReturnValue;

	SGX_GetData(global_eid, &ReturnValue, (int)this, (unsigned char*)&TempValue, sizeof(T));
	return TempValue;
}
