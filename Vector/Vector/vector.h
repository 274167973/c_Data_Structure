#include<assert.h>

namespace cd
{
	template<class T>
	class vector {
		
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		/*vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();

			for (size_t i = 0; i < v.size(); ++i)
			{
				*_finish = v[i];
				++_finish;
			}
		}*/

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		//v1=v3
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		void swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				
				T* tmp = new T[n];
				if (_start)
				{
					
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage =tmp+ n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/
			insert(_finish, x);
		}

		void pop_back()
		{
			assert(_start < _finish);
			--_finish;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}
			for (iterator end = _finish - 1; end >= pos; --end)
			{
				*(end + 1) = *end;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			for (iterator it = pos; it < _finish - 1; ++it)
			{
				*it = *(it + 1);
			}
			--_finish;
			return ++pos;
		}

		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}

		const T& operator[](size_t n) const
		{
			assert(n < size());
			return _start[n];
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test01()
	{
		vector<int> vt;

		vt.push_back(1);
		cout << "size=" << vt.size() << endl;
		cout << "capacity=" << vt.capacity() << endl;

		vt.push_back(2);
		cout << "size=" << vt.size() << endl;
		cout << "capacity=" << vt.capacity() << endl;

		vt.push_back(3);
		cout << "size=" << vt.size() << endl;
		cout << "capacity=" << vt.capacity() << endl;
		
		vt.push_back(4);
		cout << "size=" << vt.size() << endl;
		cout << "capacity=" << vt.capacity() << endl;

		vt.push_back(5);
		cout << "size=" << vt.size() << endl;
		cout << "capacity=" << vt.capacity() << endl;

		vector<int>::iterator it = vt.begin();
		while (it != vt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		for (auto e : vt)
		{
			cout << e<<" ";
		}
		cout << endl;
		vt.pop_back();
		vt.insert(vt.begin(), 0);
		for (int i = 0; i < vt.size(); ++i)
		{
			cout << vt[i] << " ";
		}
		cout << endl;
	}

	void test02()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		vector<int>::iterator it = v.begin();
		it = v.erase(v.begin());

		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);


		v.resize(20, 10);

		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		v.resize(5, 3);
		vector<int> v1(v);
		for (int i = 0; i < v1.size(); ++i)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		vector<int> v2 = v1;
		for (int i = 0; i < v2.size(); ++i)
		{
			cout << v2[i] << " ";
		}
		cout << endl;

	}

}

