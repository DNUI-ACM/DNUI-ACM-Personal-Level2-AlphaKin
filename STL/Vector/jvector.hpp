#ifndef _JVECTOR_H_
#define _JVECTOR_H_
#define DEFAULT_CAPACITY 4 //默认空间大小
#define DEFAULT_INCREASE 2 //默认扩增倍数
#include <cstddef>
#include <malloc.h>
#include <cstring>

namespace jj{
	template<class T>
	class jvector{
	public:
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using value_type = T;
		using pointer = value_type* ;
		using reference = value_type& ;

	protected:
		T * start;
		T * finish;
		T * end_of_storage;
	public:
		//迭代器类
		class iterator{
		private:
			T * ptr;
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
			T * ptr;
		public:
			reverse_iterator(T * ptrr = nullptr) : ptr(ptrr) {}
			bool operator!=(const reverse_iterator & it) const { return ptr != it.ptr; }
			bool operator==(const reverse_iterator & it) const { return ptr == it.ptr; }
			reference operator*(){ return *ptr; }
			reverse_iterator operator++(){ return --ptr; }
			reverse_iterator operator--(){ return ++ptr; }
			reverse_iterator operator+(const size_type & diff){ return ptr+diff; }
			reverse_iterator operator-(const size_type & diff){ return ptr-diff; }
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
			pointer new_start = new value_type[cap * DEFAULT_INCREASE];
			memmove(new_start, start, sizeof(T) * len);
			delete start;
			cap *= DEFAULT_INCREASE;
			end_of_storage = new_start + cap;
			return new_start;
		}
	public:
		//默认构造
		explicit jvector(const size_type c = DEFAULT_CAPACITY) : cap(c), len(0) {
			start = new value_type[cap];
			finish = start + len;
			end_of_storage = start + cap;
		}
		//拷贝构造
		jvector(const jvector & oth){
			start = new value_type[oth.capacity()];
			memmove(start, oth.begin(), oth.capacity() * sizeof(T));
			len = oth.size();
			cap = oth.capacity();
			finish = start + len;
			end_of_storage = start + cap;
		}
		//初始化n个对象
		jvector(size_type n, const T & value) : len(n), cap(n + 1){
			start = new value_type[n + 1];
			for(int i=0; i<n; ++i) *(start + i) = value;
			finish = start + len;
			end_of_storage = start + cap;
		}

		~jvector(){ delete [] start; }

		void setlen(const int l){ len = l; }
		void setcap(const int c){ cap = c; }

		pointer begin() const { return start; }
		
		pointer end() const { return finish; }

		pointer rbegin() const { return finish-1; }
		
		pointer rend() const { return start-1; }
		
		size_type size() const { return len; }
		
		size_type capacity() const { return cap; }
		
		bool empty() const { return len == 0; }
		
		reference front() const { return *start; }
		
		reference back() const { return *(finish - 1); }
		
		void clear(){ while(size()) pop_back(); }
		
		reference operator[](size_type position){
			if(position < len) return *(start + position);
		}

		pointer at(const size_type position){
			if(position < len) return start + position;
		}

		pointer push_back(const T & value){
			if(len == cap) start = increase(value);
			*(start + len++) = value;
			finish = start + len;
			return finish - 1;
		}
		
		void pop_back(){
			if(empty()) return;
			--len, --finish;
		}
		
		pointer erase(pointer position){
			if(position < start + len){
				pointer tmp = position;
				while(position != end()){
					*position = *(position + 1);
					++position;
				}
				--len, --finish;
				return tmp;
			}
			else return nullptr;
		}

		pointer erase(size_type position){
			if(position < len){
				T * tmp = start + position;
				while(position < len){
					*(start + position) = *(start + position + 1);
					++position;
				}
				--len, --finish;
				return tmp;
			}
			else return nullptr;
		}
		
		void swap(jvector & obj){
			pointer tmpit = obj.start; obj.start = start; start = tmpit;
			tmpit = obj.finish; obj.finish = finish; finish = tmpit;
			tmpit = obj.end_of_storage; obj.end_of_storage = end_of_storage; end_of_storage = end_of_storage;
			size_type tmp = len; len = obj.size(); obj.setlen(tmp);
			tmp = cap; cap = obj.capacity(); obj.setcap(tmp);
		}

		void resize(size_type new_size, const T & x){
			pointer new_space;
			if(new_size != cap){
				new_space = new value_type[new_size];
				memmove(new_space, start, sizeof(T) * new_size);
			} 
			delete start;
			start = new_space;
			pointer tmp = start + (len < new_size ? len : new_size);
			len = cap = new_size;
			end_of_storage = finish = start + len;
			while(tmp != finish){
				*tmp = x;
				++tmp;
			}
		}
	};
}

#endif
