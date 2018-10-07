#pragma once
#include <cstddef>
#include <iosfwd>


namespace pr{
	template <class T> class List{
		class Chainon{
		public:
			T data;
			Chainon *next;
			Chainon(const T& dat, Chainon *n):data(dat),next(n){}
		};
		Chainon * tete;
	public:
		List():tete(nullptr){}
		virtual ~List(){
			for(Chainon * c(tete);c;){
				Chainon* tmp(c->next);
				delete c;
				c=tmp;
			}
		}
		void push_front(const T& t){
			tete = new Chainon(t,tete);
		}
		void push_back(const T& t){
			if (tete==nullptr)
				push_front(t);
			Chainon * u1 = tete;
			while(u1->next)
				u1 = u1->next;
			u1->next = new Chainon(t,nullptr);
		}
		size_t size(){
			size_t sz = 0;
			for(Chainon * c(tete);c;c=c->next)
				sz++;
			return sz;
		}
			
		class ListIt{
			Chainon * cur;
		public:
			ListIt(Chainon *c=nullptr):cur(c){}
			T& operator*(){
				return cur->data;
			}
			ListIt& operator++(){
				cur = cur->next;
				return *this;
			}
			T* operator->(){
				return &(cur->data);
			}
			bool operator!=(ListIt& it2){
				return cur != it2.cur;
			}
		};
    typedef ListIt iterator;
	
	iterator begin(){
		return iterator(tete);
	}
	iterator end(){
		return iterator();
	}
	
	iterator begin() const{
		return iterator(tete);
	}
	iterator end() const{
		return iterator();
	}

	};


	
	template <class T> 
	std::ostream& operator<<(std::ostream& os, List<T> &t){
		typename List<T>::iterator it = t.begin();
		typename List<T>::iterator it_end = t.end();
		while(it!=it_end){
			os<<*it;
			++it;
		}
		return os;
	}

}
