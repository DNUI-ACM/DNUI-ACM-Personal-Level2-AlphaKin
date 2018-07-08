#ifndef _JVECTOR_H_
#define _JVECTOR_H_
#define DEFAULT_CAPACITY 4 //默认空间大小
#define DEFAULT_INCREASE 2 //默认扩增倍数
#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <cstdio>

namespace jj{
	template<class T>
	class jvector{
	public:
		using size_type 		= size_t;
		using difference_type 	= ptrdiff_t;
		using value_type 		= T;
		using pointer 			= value_type* ;
		using reference 		= value_type& ;

	private:
		pointer base;
		pointer end_of_storage;
	public:
		//迭代器类
		class iterator{
		private:
			pointer ptr;
		public:
			iterator(T * ptrr = nullptr) : ptr(ptrr) {}
			bool operator!=(const iterator & it) const { return ptr != it.ptr; }
			bool operator==(const iterator & it) const { return ptr == it.ptr; }
			reference operator*(){ return *ptr; }
			iterator operator++(){ return ++ptr; }
			iterator operator+(const size_type & diff){ return ptr+diff; }
			iterator operator-(const size_type & diff){ return ptr-diff; }
			iterator operator--(){ return --ptr; }
			void operator++(int){
				T * tmp = ptr;
				++ptr;
				return tmp;
			}
			void operator--(int){
				T * tmp = ptr;
				--ptr;
				return tmp;
			}
		};
		//反向迭代器类
		class reverse_iterator{
		private:
			pointer ptr;
		public:
			reverse_iterator(T * ptrr = nullptr) : ptr(ptrr) {}
			bool operator!=(const reverse_iterator & it) const { return ptr != it.ptr; }
			bool operator==(const reverse_iterator & it) const { return ptr == it.ptr; }
			reference operator*(){ return *ptr; }
			reverse_iterator operator++(){ return --ptr; }
			reverse_iterator operator--(){ return ++ptr; }
			reverse_iterator operator+(const size_type & diff){ return ptr-diff; }
			reverse_iterator operator-(const size_type & diff){ return ptr+diff; }
			void operator++(int){
				T * tmp = ptr;
				--ptr;
				return tmp;
			}
			void operator--(int){
				T * tmp = ptr;
				++ptr;
				return tmp;
			}
		};

	private:
		size_type len;
		size_type cap;
		pointer increase(const value_type & value){
			pointer new_base = new value_type[cap * DEFAULT_INCREASE];
			memmove(new_base, base, sizeof(T) * len);
			delete [] base;
			cap *= DEFAULT_INCREASE;
			end_of_storage = new_base + cap;
			return new_base;
		}
	public:
		//默认构造
		explicit jvector(const size_type c = DEFAULT_CAPACITY) : cap(c), len(0) {
			base = new value_type[cap];
			end_of_storage = base + cap;
		}
		//拷贝构造
		jvector(const jvector & oth){
			base = new value_type[oth.capacity()];
			iterator oth_base = oth.begin();
			for(int i=0, aim=oth.size(); i<aim; ++i)
				*(base + i) = *(oth_base + i);
			len = oth.size();
			cap = oth.capacity();
			end_of_storage = base + cap;
		}
		//初始化n个对象
		jvector(size_type n, const T & value) : len(n), cap(n + 1){
			base = new value_type[n + 1];
			for(int i=0; i<n; ++i) *(base + i) = value;
			end_of_storage = base + cap;
		}

		~jvector(){ delete [] base; }

		void setlen(const int l){ len = l; }
		void setcap(const int c){ cap = c; }

		iterator begin() const { return iterator(base); }
		
		iterator end() const { return iterator(base + len); }

		reverse_iterator rbegin() const { return reverse_iterator(base + len - 1); }
		
		reverse_iterator rend() const { return reverse_iterator(base - 1); }
		
		size_type size() const { return len; }
		
		size_type capacity() const { return cap; }
		
		bool empty() const { return len == 0; }
		         
		reference front() const { return *base; }
		
		reference back() const { return *(base + len - 1); }
		
		void clear(){ while(size()) pop_back(); }
		
		reference operator[](const size_type position){
			if(position < len) return *(base + position);
		}

		reference at(const size_type position){
			if(position < len) return *(base + position);
		}

		void push_back(const T & value){
			if(len == cap) base = increase(value);
			*(base + len++) = value;

		}
		
		void pop_back(){
			if(empty()) return;
			--len;
		}
		
		iterator erase(pointer position){
			if(position < base + len){
				pointer tmp = position;
				while(position != end()){
					*position = *(position + 1);
					++position;
				}
				--len;
				return iterator(tmp);
			}
			else return iterator(nullptr);
		}

		iterator erase(size_type spos, size_type epos){
			if(spos < 0 || epos >= len) return iterator(base + spos);
			for(int i=0, p=epos, q=spos, aim = len-epos; i<aim; ++i)
				*(base + q++) = *(base + p++);
			len -= epos - spos;
			return iterator(base + spos);
		}

		iterator erase(size_type position){
			if(position < len){
				T * tmp = base + position;
				while(position < len){
					*(base + position) = *(base + position + 1);
					++position;
				}
				--len;
				return iterator(tmp);
			}
			else return iterator(nullptr);
		}
		
		// void swap(jvector & obj){
		// 	pointer tmpit = obj.base; obj.base = base; base = tmpit;
		// 	tmpit = obj.finish; obj.finish = finish; finish = tmpit;
		// 	tmpit = obj.end_of_storage; obj.end_of_storage = end_of_storage; end_of_storage = end_of_storage;
		// 	size_type tmp = len; len = obj.size(); obj.setlen(tmp);
		// 	tmp = cap; cap = obj.capacity(); obj.setcap(tmp);
		// }

		iterator insert(iterator pos, const T& value){
			pointer new_base = new value_type[cap+1];
			for(int i=0, k=0; i<len; ++i){
				if(pos == base + i) *(new_base + k++) = value;
				*(new_base + k++) = *(base + i);
			}
			base = new_base;
			++cap, ++len;
			end_of_storage = base + cap;
		}

		void shrink_to_fit(){
			pointer new_space = new value_type[len];
			memmove(new_space, base, sizeof(T) * len);
			delete [] base;
			base = new_space;
			cap = len;
			end_of_storage = base + cap;
		}

		void reserve(size_type length){
			if(length <= len) return;
			pointer new_space = new value_type[length];
			memmove(new_space, base, sizeof(T) * length);
			delete [] base;
			base = new_space;
			cap = length;
			end_of_storage = base + length;
		}

		void resize(size_type new_size, const T & x){
			pointer new_space;
			if(new_size != cap){
				new_space = new value_type[new_size];
				memmove(new_space, base, sizeof(T) * new_size);
			} 
			delete [] base;
			base = new_space;
			pointer tmp = base + (len < new_size ? len : new_size);
			len = cap = new_size;
			end_of_storage = base + len;
			while(tmp != base + len){
				*tmp = x;
				++tmp;
			}
		}
	};
}

#endif
