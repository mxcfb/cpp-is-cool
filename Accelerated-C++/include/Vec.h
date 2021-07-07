#ifndef __VEC_H
#define __VEC_H
#include <memory>

template <class T> 
class Vec{
	public:
		//TODO
        //请定义iterator和const_iterator类型
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef size_t size_type;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T& reference;
		typedef const T& const_reference;

		Vec(){create();}
		explicit Vec(size_t n, const T& Val=T()){create(n,Val);}
		Vec(const Vec&v);
		~Vec();

		size_type size() const {return avail-data;}
		T& operator[](size_type i){return data[i];}
		const T&operator[](size_type i) const {return data[i];}

		iterator begin(){return data;}
		const_iterator begin()const{return data;}
		iterator end(){return avail;}
		const_iterator end()const{return avail;}

		void push_back(const T& val){
			//TODO
			if(avail==limit)
				grow();
			unchecked_append(val);
		}
		
		Vec & operator=(const Vec &);
		void clear(){
			//TODO
			avail=data;
		}

	private:
		T * data;
		T * avail;
		T * limit;

		std::allocator<T> alloc;
		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		void uncreate();
		void grow();
		void unchecked_append(const T&);
};

//TODO
//实现复制构造函数Vec
template <class T>
Vec<T>::Vec(const Vec&v){
	create(v.begin(),v.end());
}

//TODO
//实现赋值操作符重载函数operator=
template <class T>
Vec<T> & Vec<T>::operator=(const Vec &rhs)
{
	if(&rhs != this){
		uncreate();
		create(rhs.begin(),rhs.end());
	}
	return *this;
}

//TODO
//实现析构函数~Vec
template <class T>
Vec<T>::~Vec(){
	uncreate();
}

template <class T>
void Vec<T>::create()
{
	data=avail=limit=0;
}

template <class T>
void Vec<T>::create(size_type n, const T&val)
{
	data=alloc.allocate(n,0);
	avail=limit=data+n;
	std::uninitialized_fill(data,limit,val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data=alloc.allocate(j-i,0);
	avail=limit=std::uninitialized_copy(i,j,data);
}

template <class T>
void Vec<T>::uncreate()
{
	if(data){
		iterator it=avail;
		while(it!=data)
			alloc.destroy(--it);
		alloc.deallocate(data,limit-data);
	}
	data=avail=limit=0;
}

template <class T>
void Vec<T>::grow()
{
	size_type new_size=1;
	if(limit!=data) new_size=2*(limit-data);
	iterator new_data = alloc.allocate(new_size,0);
    iterator new_avail = std::uninitialized_copy(data,avail,new_data);
	
	uncreate();
	data=new_data;
	avail=new_avail;
	limit=data+new_size;
}
template <class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++,val);
}
#endif
