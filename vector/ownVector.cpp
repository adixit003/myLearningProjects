#include<iostream>
#include<vector>
using namespace std;
template<typename T>

class myItretor
{
private:
	T *m_addr;
public:
	myItretor():m_addr(nullptr) {}
	myItretor(T *ptr):m_addr(ptr) {}

	myItretor<T>& operator++()
	{
		++m_addr;
		return *this;
	}

	T& operator*()
	{
		return *m_addr;
	}

	bool operator != (const myItretor<T>& ref)
	{
		return (m_addr != ref.m_addr);
	}

	bool operator == (const myItretor<T>& ref)
	{
		return (m_addr == ref.m_addr);
	}
};

template<typename T>
class myVector
{
private:
	T* m_arr;
	int m_size;
	int m_capacity;
public:
	myVector(int capacity) :m_size(0), m_capacity(capacity)
	{
		m_arr = new T[capacity];
	}

	~myVector()
	{
		if (m_capacity)
			delete[] m_arr;
	}

	void push_back(const T& val)
	{
		m_arr[m_size] = val;
		++m_size;
	}

	T pop_back()
	{
		T val = m_arr[m_size - 1];
		m_size--;
		return val;
	}

	int size() const
	{
		return m_size;
	}

	int capacity() const
	{
		return m_capacity;
	}

	T& at(int index)
	{
		return m_arr[index];
	}

	T& operator[](int index)
	{
		return m_arr[index];
	}

	void clear()
	{
		m_size = 0;
	}

	T* data()
	{
		return m_arr;
	}

	T* front()
	{
		return m_arr[0];
	}

	T* back()
	{
		return m_arr[m_size - 1];
	}

	myItretor<T> begin()
	{
		return myItretor<T>(&m_arr[0]);
	}

	myItretor<T> end()
	{
		return myItretor<T>(m_arr + m_size);
	}
};

// Fixes for myItretor class and main function

int main()
{
    myVector<int> myVec(10);

    myVec.push_back(10);
    myVec.push_back(20);
    myVec.push_back(30);
    myVec.push_back(40);
    myVec.push_back(50);


    myItretor<int> it;
    for (it = myVec.begin(); it != myVec.end(); ++it)
        cout << *it << " ";

    cout << endl;
    return 0;
}