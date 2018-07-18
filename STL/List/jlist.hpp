#ifndef _JLIST_H_
#define _JLIST_H_
#include <cstdio>
#include <cstddef>
namespace jj{
	//node class:--------------------------------------------------------------------------------------------------------------------------------------
	template<class T>
	class list_node{
	private:
		list_node* prev;
		list_node* next;
		T data;

	public:
		list_node(list_node* q = nullptr, list_node* h = nullptr, const T & value = 0) :
			prev(q), next(h), data(value) {}

		list_node* getPrev(){
			return prev;
		}
		list_node* getNext(){
			return next;
		}
		T& getData(){
			return data;
		}
		void setPrev(list_node* p){
			prev = p;
		}
		void setNext(list_node* n){
			next = n;
		}
		void setValue(const T & v){
			data = v;
		}

	};
	//node class:--------------------------------------------------------------------------------------------------------------------------------------


	//iterator class::---------------------------------------------------------------------------------------------------------------------------------
	//迭代器
	template <class T>
	class list_iterator{
	public:
		using pointer 				= T* ;
		using reference				= T& ;
		using PNODE 				= list_node<T>* ;
		using size_type				= size_t ;
		using difference_type		= ptrdiff_t ;

	private:
		PNODE ptr;

	public:
		list_iterator(PNODE p = nullptr) : ptr(p) {}
		list_iterator(const list_iterator & p) : ptr(p.ptr) {}
		~list_iterator() {}

		bool operator==(const list_iterator & it) const {
			return ptr == it.ptr;
		}

		bool operator!=(const list_iterator & it) const {
			return ptr != it.ptr;
		}

		reference operator*() const {
			return ptr->getData();
		}

		list_iterator operator++(){
			ptr = ptr -> getNext();
			return list_iterator(ptr);
		}

		list_iterator operator++(int){
			list_iterator tmp = list_iterator(ptr);
			ptr = ptr -> getNext();
			return tmp;
		}

		list_iterator operator--(){
			ptr = ptr -> getPrev();
			return list_iterator(ptr);
		}

		list_iterator operator--(int){
			list_iterator tmp = list_iterator(ptr);
			ptr = ptr -> getPrev();
			return tmp;
		}

		list_iterator operator+(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getNext();
			}
			return list_iterator(tmp);
		}

		list_iterator operator-(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getPrev();
			}
			return list_iterator(tmp);
		}

		PNODE getPtr(){
			return ptr;
		}
	};

	//常迭代器
	template <class T>
	class const_list_iterator{
	public:
		using pointer 				= T* ;
		using reference				= T& ;
		using PNODE 				= list_node<T>* ;
		using size_type				= size_t ;
		using difference_type		= ptrdiff_t ;

	private:
		const PNODE ptr;

	public:
		const_list_iterator(PNODE p = nullptr) : ptr(p) {}
		const_list_iterator(const const_list_iterator & p) : ptr(p.ptr) {}
		~const_list_iterator() {}

		bool operator==(const const_list_iterator & it) const {
			return ptr == it.ptr;
		}

		bool operator!=(const const_list_iterator & it) const {
			return ptr != it.ptr;
		}

		reference operator*() const {
			return ptr->getData();
		}

		const_list_iterator operator++(){
			ptr = ptr -> getNext();
			return const_list_iterator(ptr);
		}

		const_list_iterator operator++(int){
			const_list_iterator tmp = const_list_iterator(ptr);
			ptr = ptr -> getNext();
			return tmp;
		}

		const_list_iterator operator--(){
			ptr = ptr -> getPrev();
			return const_list_iterator(ptr);
		}

		const_list_iterator operator--(int){
			const_list_iterator tmp = const_list_iterator(ptr);
			ptr = ptr -> getPrev();
			return tmp;
		}

		const_list_iterator operator+(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getNext();
			}
			return const_list_iterator(tmp);
		}

		const_list_iterator operator-(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getPrev();
			}
			return const_list_iterator(tmp);
		}

		PNODE getPtr(){
			return ptr;
		}
	};

	//反向迭代器
	template <class T>
	class reverse_list_iterator{
	public:
		using pointer 				= T* ;
		using reference				= T& ;
		using PNODE 				= list_node<T>* ;
		using size_type				= size_t;
		using difference_type		= ptrdiff_t;

	private:
		PNODE ptr;

	public:
		reverse_list_iterator(PNODE p = nullptr) : ptr(p) {}
		reverse_list_iterator(const reverse_list_iterator & p) : ptr(p.ptr) {}
		~reverse_list_iterator() {}

		bool operator==(const reverse_list_iterator & it) const {
			return ptr == it.ptr;
		}

		bool operator!=(const reverse_list_iterator & it) const {
			return ptr != it.ptr;
		}

		reference operator*() const {
			return ptr->getData();
		}

		reverse_list_iterator operator--(){
			ptr = ptr -> getNext();
			return reverse_list_iterator(ptr);
		}

		reverse_list_iterator operator--(int){
			reverse_list_iterator tmp = reverse_list_iterator(ptr);
			ptr = ptr -> getNext();
			return tmp;
		}

		reverse_list_iterator operator++(){
			ptr = ptr -> getPrev();
			return reverse_list_iterator(ptr);
		}

		reverse_list_iterator operator++(int){
			reverse_list_iterator tmp = reverse_list_iterator(ptr);
			ptr = ptr -> getPrev();
			return tmp;
		}
		
		reverse_list_iterator operator-(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getNext();
			}
			return reverse_list_iterator(tmp);
		}

		reverse_list_iterator operator+(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getPrev();
			}
			return reverse_list_iterator(tmp);
		}

		PNODE getPtr(){
			return ptr;
		}
	};

	//常反向迭代器
	template <class T>
	class const_reverse_list_iterator{
	public:
		using pointer 				= T* ;
		using reference				= T& ;
		using PNODE 				= list_node<T>* ;
		using size_type				= size_t;
		using difference_type		= ptrdiff_t;

	private:
		const PNODE ptr;

	public:
		const_reverse_list_iterator(PNODE p = nullptr) : ptr(p) {}
		const_reverse_list_iterator(const const_reverse_list_iterator & p) : ptr(p.ptr) {}
		~const_reverse_list_iterator() {}

		bool operator==(const const_reverse_list_iterator & it) const {
			return ptr == it.ptr;
		}

		bool operator!=(const const_reverse_list_iterator & it) const {
			return ptr != it.ptr;
		}

		reference operator*() const {
			return ptr->getData();
		}

		const_reverse_list_iterator operator--(){
			ptr = ptr -> getNext();
			return const_reverse_list_iterator(ptr);
		}

		const_reverse_list_iterator operator--(int){
			const_reverse_list_iterator tmp = const_reverse_list_iterator(ptr);
			ptr = ptr -> getNext();
			return tmp;
		}

		const_reverse_list_iterator operator++(){
			ptr = ptr -> getPrev();
			return const_reverse_list_iterator(ptr);
		}

		const_reverse_list_iterator operator++(int){
			const_reverse_list_iterator tmp = const_reverse_list_iterator(ptr);
			ptr = ptr -> getPrev();
			return tmp;
		}
		
		const_reverse_list_iterator operator-(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getNext();
			}
			return const_reverse_list_iterator(tmp);
		}

		const_reverse_list_iterator operator+(const difference_type & diff){
			PNODE tmp = ptr;
			for(int i=0; i<diff; ++i){
				tmp = tmp->getPrev();
			}
			return const_reverse_list_iterator(tmp);
		}

		PNODE getPtr(){
			return ptr;
		}
	};
	//iterator class::------------------------------------------------------------------------------------------------------------------------------


	//jlist class:----------------------------------------------------------------------------------------------------------------------------------
	template<class T>
	class jlist{
	public:
		using value_type			= T;
		using NODE					= list_node<T>;
		using PNODE					= list_node<T>*;
		using iterator 				= list_iterator<T>;
		using const_iterator 		= const_list_iterator<T>;
		using reverse_iterator 		= reverse_list_iterator<T>;
		using const_reverse_iterator= const_reverse_list_iterator<T>;
		using size_type				= size_t;

	private:
		int rec;
		size_type len;
		PNODE head;
		PNODE back;
		void change_size(const size_type & num){
			len=num;
		}
		void sort_assign(value_type *, PNODE, PNODE);
		void sort_merge(value_type *, PNODE, PNODE, PNODE);
		PNODE getmid(PNODE ,PNODE);
	public:
		//constructor
		jlist();
		explicit jlist(size_type, const T&);
		explicit jlist(size_type);
		jlist(const jlist &);
		// jlist(jlist &&);右值引用
		jlist(std::initializer_list<T>);
		~jlist();


		iterator begin() const;
		// iterator begin() noexcept;
		const_iterator cbegin() const;
		// const_iterator begin() const noexcept;
		// const_iterator cbegin() const noexcept;

		iterator end() const;
		// iterator end() noexcept;
		const_iterator cend() const;
		// const_iterator end() const noexcept;
		// const_iterator cend() const noexcept;

		reverse_iterator rbegin() const;
		// reverse_iterator rbegin() noexcept;
		const_reverse_iterator crbegin() const;
		// const_reverse_iterator rbegin() const noexcept;
		// const_reverse_iterator crbegin() const noexcept;

		reverse_iterator rend() const;
		// reverse_iterator rend() noexcept;
		const_reverse_iterator crend() const;
		// const_reverse_iterator rend() const noexcept;
		// const_reverse_iterator crend() const noexcept;

		// //empty
		bool empty() const;
		// bool empty() const noexcept;

		// //size
		size_type size() const;
		// size_type size() const noexcept;

		// //max_size
		// size_type max_size() const;
		// size_type max_size() const noexcept;

		// //clear
		void clear();
		// void clear() noexcept;

		// //insert
		iterator insert(iterator, const T&);
		iterator insert(const_iterator, const T&);
		// iterator insert(const_iterator pos, T && value);
		// void insert(iterator pos, size_type count, const T& value);
		// iterator insert(const_iterator pos, size_type count, const T& value)
		// // template< class InputIt >
		// // void insert( iterator pos, InputIt first, InputIt last);
		// // template< class InputIt >
		// // iterator insert( const_iterator pos, InputIt first, InputIt last );
		// iterator insert(const_iterator pos, std::initializer_list<T> ilist);
		// //原位构造元素 emplace	

		// //erase
		iterator erase(iterator pos);
		// iterator erase(const_iterator pos);
		// iterator erase(iterator first, iterator last);
		// iterator erase(const_iterator first, const_iterator last);

		// //push_back
		void push_back(const T&);
		// void push_back(T && value);//????
		// //emplace_back  在容器末尾就地构造元素 

		// //pop
		void pop_back();
		void pop_front();

		// //push_front
		void push_front(const T& value);
		// void push_front(T && value);
		// //emplace_front  在容器头部就地构造元素 

		// //resize
		void resize(size_type, const size_type);
		void resize(size_type);

		// //swap
		void swap(jlist & oth);
		// void swap(jlist & oth) noexcept;

		// //merge
		void merge(jlist & oth);
		// void merge(jlist && oth);//???
		// // template<class Compare>
		// // void merge(list & oth);
		// // template<class Compare>
		// // void merge(list && oth)

		// //splice
		void splice(const_iterator, jlist &);
		// void splice(const_iterator pos, jlist && oth);
		// void splice(const_iterator, jlist &, const_iterator);
		// void splice(const_iterator pos, jlist && oth, const_iterator it);
		// void splice(const_iterator pos, jlist & oth, const_iterator first, const_iterator last);
		// void splice(const_iterator pos, jlist && oth, const_iterator first, const_iterator last);

		// //remove
		size_type remove(const T&);

		// //reverse
		void reverse();
		// void reverse() noexcept;

		// //sort
		void sort();
		// template<class Compare>
		// void sort(Compare comp);
		void setlen(size_type);
	};

	//默认构造
	template <class T>
	jlist<T>::jlist() : len(0) , head(new NODE(back, nullptr, 0)), back(new NODE(nullptr, head, 0)) {}

	//n值构造
	template <class T>
	jlist<T>::jlist(size_type n, const T& value) : len(0) , head(new NODE(back, nullptr, 0)), back(new NODE(nullptr, head, 0)) {
		for(int i=0; i<n; ++i){
			push_back(value);
		}
	}

	//n值构造(默认)
	template <class T>
	jlist<T>::jlist(size_type n) : len(0) , head(new NODE(back, nullptr, 0)), back(new NODE(nullptr, head, 0)) {
		T value = T();
		for(int i=0; i<n; ++i){
			push_back(value);
		}
	}

	//拷贝构造
	template <class T>
	jlist<T>::jlist(const jlist & oth) : len(0) , head(new NODE(back, nullptr, 0)), back(new NODE(nullptr, head, 0)) {
		for(auto i=oth.begin(); i!=oth.end(); ++i){
			push_back(*i);
		}
	}

	//列表初始化构造
	template <class T>
	jlist<T>::jlist(std::initializer_list<T> li) : len(0) , head(new NODE(back, nullptr, 0)), back(new NODE(nullptr, head, 0)) {
		for(auto i : li){
			push_back(i);
		}
	}

	//析构函数
	template <class T>
	jlist<T>::~jlist(){
		delete [] head;
	}

	//返回begin迭代器
	template <class T>
	typename jlist<T>::iterator jlist<T>::begin() const {
		return iterator(head->getNext());
	}

	//返回cbegin常迭代器
	template <class T>
	typename jlist<T>::const_iterator jlist<T>::cbegin() const{
		return const_iterator(head->getNext());
	}

	//返回rbegin反迭代器
	template <class T>
	typename jlist<T>::reverse_iterator jlist<T>::rbegin() const{
		return reverse_iterator(back->getPrev());
	}

	//返回crbegin常反迭代器
	template <class T>
	typename jlist<T>::const_reverse_iterator jlist<T>::crbegin() const{
		return const_reverse_iterator(back->getPrev());
	}

	//返回end迭代器
	template <class T>
	typename jlist<T>::iterator jlist<T>::end() const {
		return iterator(back);
	}

	//返回begin常迭代器
	template <class T>
	typename jlist<T>::const_iterator jlist<T>::cend() const{
		return const_iterator(back);
	}

	//返回rend反迭代器
	template <class T>
	typename jlist<T>::reverse_iterator jlist<T>::rend() const{
		return reverse_iterator(head);
	}

	//返回crend常反迭代器
	template <class T>
	typename jlist<T>::const_reverse_iterator jlist<T>::crend() const{
		return const_reverse_iterator(head);
	}

	//是否为空
	template <class T>
	bool jlist<T>::empty() const {
		return len == 0;
	}

	//返回长度
	template <class T>
	typename jlist<T>::size_type jlist<T>::size() const {
		return len;
	}

	//置长度
	template <class T>
	void jlist<T>::setlen(size_type l){
		this->len = l;
	}

	//向后插入元素
	template <class T>
	void jlist<T>::push_back(const T & value){
		if(len){
			PNODE pnew = new NODE(back->getPrev(), back, value);
			back->getPrev()->setNext(pnew);
			back->setPrev(pnew);
		}
		else{
			PNODE pnew = new NODE(head, back, value);
			head->setNext(pnew);
			back->setPrev(pnew);
		}
		++this->len;
	}

	//向前插入元素
	template <class T>
	void jlist<T>::push_front(const T & value){
		if(len){
			PNODE pnew = new NODE(head, head->getNext(), value);
			head->getNext()->setPrev(pnew);
			head->setNext(pnew);
		}
		else{
			PNODE pnew = new NODE(head, back, value);
			head->setNext(pnew);
			back->setPrev(pnew);
		}
		++this->len;
	}

	//指定迭代器位置元素插入
	template <class T>
	typename jlist<T>::iterator jlist<T>::insert(iterator pos, const T& value){
		PNODE tmp = head->getNext();
		while(tmp != pos.getPtr()){
			tmp = tmp->getNext();
		}
		PNODE pnew = new NODE(tmp->getPrev(), tmp, value);
		tmp->getPrev()->setNext(pnew);
		tmp->setPrev(pnew);
		++len;
		return iterator(pnew);
	}
	template <class T>
	typename jlist<T>::iterator jlist<T>::insert(const_iterator pos, const T& value){
		PNODE tmp = head->getNext();
		while(tmp != pos.getPtr()){
			tmp = tmp->getNext();
		}
		PNODE pnew = new NODE(tmp->getPrev(), tmp, value);
		tmp->getPrev()->setNext(pnew);
		tmp->setPrev(pnew);
		++this->len;
		return iterator(pnew);
	}

	//指定迭代器位置元素移除
	template <class T>
	typename jlist<T>::iterator jlist<T>::erase(iterator pos){
		if(len == 0) return this->end();
		PNODE rec = pos.getPtr();
		PNODE ans = rec->getPrev();
		rec->getPrev()->setNext(rec->getNext());
		rec->getNext()->setPrev(rec->getPrev());
		delete [] rec;
		--this->len;
		return iterator(ans);
	}

	//删除所有值为value的元素并返回删除数量
	template <class T>
	typename jlist<T>::size_type jlist<T>::remove(const T& value){
		iterator tmp = this->begin();
		size_type ans = 0;
		while(tmp != this->end()){
			if(*(tmp) == value){
				erase(tmp);
				++ans;
			}
			++tmp;
		}
		return ans;
	}

	//向后移除元素
	template <class T>
	void jlist<T>::pop_back(){
		if(len == 0) return;
		PNODE rec = back->getPrev();
		back->setPrev(back->getPrev()->getPrev());
		back->getPrev()->setNext(back);
		delete [] rec;
		--this->len;
	}

	//向前移除元素
	template <class T>
	void jlist<T>::pop_front(){
		if(len == 0) return;
		PNODE rec = head->getNext();
		head->setNext(head->getNext()->getNext());
		head->getNext()->setPrev(head);
		delete [] rec;
		--this->len;
	}

	//重新分配
	template <class T>
	void jlist<T>::resize(size_type count){
		T tmp = T();
		if(count > this->len){
			while(len<count){
				push_back(tmp);
			}
		}
		else if(count < this->len){
			while(len>count){
				pop_back();
			}
		}
	}

	//重新分配(指定值)
	template <class T>
	void jlist<T>::resize(size_type count, const size_type value){
		if(count > this->len){
			while(this->len < count){
				push_back(value);
			}
		}
		else if(count < this->len){
			while(this->len > count){
				pop_back();
			}
		}
	}

	//反转双向链表
	template <class T>
	void jlist<T>::reverse(){
		if(this->len < 2) return;
		PNODE last = this->back->getPrev(), first = this->head->getNext();
		this->head->setNext(last);
		last->setNext(head);
		this->back->setPrev(first);
		first->setPrev(back);
		PNODE cur = back->getPrev(), tmp;
		while(cur != head){
			tmp = cur->getNext();
			cur->setNext(cur->getPrev());
			cur->setPrev(tmp);
			cur = cur->getPrev();
		}
	}

	//交换链表
	template <class T>
	void jlist<T>::swap(jlist & oth){
		PNODE oth_head = oth.begin().getPtr()->getPrev(), oth_back = oth.end().getPtr();
		oth_head->getNext()->setPrev(this->head);
		this->head->getNext()->setPrev(oth_head);
		PNODE tmp = this->head->getNext();
		this->head->setNext(oth_head->getNext());
		oth_head->setNext(tmp);

		oth_back->getPrev()->setNext(this->back);
		this->back->getPrev()->setNext(oth_back);
		tmp = this->back->getPrev();
		this->back->setPrev(oth_back->getPrev());
		oth_head->setPrev(tmp);

		size_type tmpl = this->len;
		this->len = oth.size();
		oth.setlen(tmpl);
	}

	//归并双向链表
	template <class T>
	void jlist<T>::merge(jlist & oth){
		iterator curi = this->begin(), curj = oth.begin();
		while(curi != this->end() && curj != oth.end()){
			if(*curi > *curj){
				this->insert(curi, *curj);
				++curj;
			}
			else{
				++curi;
			}
		}
		while(curj != oth.end()){
			this->push_back(*curj);
			++curj;
		}
	}
	
	//转移双向链表
	template <class T>
	void jlist<T>::splice(const_iterator pos, jlist & oth){
		jlist<T>::iterator fron;
		while(oth.size()){
			fron = oth.begin();
			insert(pos, *fron);
			oth.pop_front();
		}
	}

	//双向链表归并排序------------
	template <class T>
	typename jlist<T>::PNODE jlist<T>::getmid(PNODE left, PNODE right){
		int rec = 0;
		PNODE i = left, j = left;
		while(j != right){
			j = j->getNext();
			if(++rec == 2) i = i->getNext();
			if(rec == 2) rec = 0;
		}
		return i;
	}
	template <class T>
	void jlist<T>::sort_merge(value_type * tmparr, PNODE lpos, PNODE rpos, PNODE rend){
		PNODE cur = lpos, lend = rpos->getPrev();
		size_t tmpcur = 0;
		while(lpos != lend->getNext() && rpos != rend->getNext()){
			if(lpos->getData() < rpos->getData()){
				tmparr[tmpcur++] = lpos->getData();
				lpos = lpos->getNext();
			}
			else{
				tmparr[tmpcur++] = rpos->getData();
				rpos = rpos->getNext();
			}
		}
		while(lpos != lend->getNext()){
			tmparr[tmpcur++] = lpos->getData();
			lpos = lpos->getNext();
		}
		while(rpos != rend->getNext()){
			tmparr[tmpcur++] = rpos->getData();
			rpos = rpos->getNext();
		}
		for(size_t i=0; i<tmpcur; ++i){
			cur->setValue(tmparr[i]);
			cur = cur->getNext();
		}
	}
	template <class T>
	void jlist<T>::sort_assign(value_type * tmparr, PNODE pleft, PNODE pright){
		PNODE pmid;
		if(pleft != pright){
			pmid = this->getmid(pleft, pright);
			this->sort_assign(tmparr, pleft, pmid);
			this->sort_assign(tmparr, pmid->getNext(), pright);
			this->sort_merge(tmparr, pleft, pmid->getNext(), pright);
		}
	}
	template <class T>
	void jlist<T>::sort(){
		if(this->len < 2) return;
		value_type tmparr[this->len];
		this->sort_assign(tmparr, this->head->getNext(), this->back->getPrev());
	}
	//-------------------

	//清空链表
	template <class T>
	void jlist<T>::clear(){
		while(this->len){
			this->pop_back();
		}
	}

	//jlist class:----------------------------------------------------------------------------------------------------------------------------------
}

#endif