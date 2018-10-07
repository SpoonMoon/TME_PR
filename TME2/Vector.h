#pragma once
#include <cstddef>
#include <iosfwd>

namespace pr{
	template <class T> class Vector{
		T* tab;
		size_t sz,cap;
	public:
		Vector(size_t c=10){
			tab = new T[c];
			sz = c;
			cap = c;
		}
		~Vector(){
			delete[] tab;
		}
		T& operator[](size_t index){
			return tab[index];
		}
		void push_back(const T& v){
			ensure_capacity(sz+1);
			tab[sz]=v;
			++sz;
		}
		void ensure_capacity(size_t n){
			if(n >= cap){
				cap *= 2;
				T* nz = new T[cap];
				for(size_t i=0;i<sz;i++)
					nz[i]=tab[i];
				delete[] tab;
				tab=nz;
			}
		}
		size_t size() const{
			return sz;
		}
		bool empty() const{
			return sz;
		}	
	
	typedef T* iterator;
	typedef const T* const_iterator;
		
	iterator begin(){
		return tab;
	}
	iterator end(){
		return tab+sz;
	}
		
	iterator begin() const{
		return tab;
	}
	iterator end() const{
		return tab+sz;
	}
	};
	
	template <class T> 
	std::ostream& operator<<(std::ostream& os, const Vector<T> &t){
		typename Vector<T>::const_iterator it = t.begin();
		while(it!=t.end()){
			os<<*it;
			++it;
		}
		return os;
	}
	
}
	
