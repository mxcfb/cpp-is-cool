#ifndef GUARD_median_h
#define GUARD_median_h

#include "Vec.h"

//以下是多个自定义的泛型函数，
//放在自定义的命名空间MySpace中。
//需要使用的这些函数的时候，
//可以在文件开始使用“using MySpace::find;”等语句
//或者直接在函数名前加“MySpace::”。
namespace MySpace{

//泛型函数swap，交换两个变量的值
template <class X>
void swap(X & x, X & y){
	X tmp=x;
	x=y;
	y=tmp;
}

//泛型函数sort，用冒泡法排序
template<class Ran>
void sort(Ran begin, Ran end)
{
//	std::cout << "sort...\n";
	for(Ran i=begin;i!=end;i++)
		for(Ran j=begin;j+1+(i-begin)!=end;j++)
			if(*j>*(j+1))
				swap(*j,*(j+1));
}

//泛型函数median，求中值
template<class T>
T median(Vec<T> vec)
{
//	std::cout << "median...\n";
	typedef typename Vec<T>::size_type vec_sz;
	vec_sz size = vec.size();
	if(size == 0)
		throw std::domain_error("median of an empty vector");
	sort(vec.begin(),vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}

//泛型函数average，求均值
template<class T>
T average(Vec<T> vec)
{
//	std::cout << "average...\n";
	//TODO
	typedef typename Vec<T>::size_type vec_sz;
    typedef typename Vec<T>::iterator vec_cit;
    vec_sz size = vec.size();
	if(size == 0)
        throw std::domain_error("average of an empty vector");
	vec_cit it = vec.begin();
	T sum=*it++;
	while(it!=vec.end())
		sum+=*it++;
	return sum/size;
}

//泛型函数find，实现查找功能
template <class In, class X> 
In find(In begin, In end, const X&x){
//	std::cout << "find...\n";
	//TODO
	while(begin!=end && *begin != x)
		++begin;

	return begin;
}

//泛型函数remove_copy，
//把所有与x不匹配的原素复制到输出迭代器dest表示的目标地址中。
template <class In, class Out, class X> 
Out remove_copy(In begin, In end, Out dest,const X&x){
//	std::cout << "remove_copy...\n";
	//TODO
	while(begin!=end){
		if(*begin!=x) *dest++=*begin++;
		else begin++;
	}

	return dest;

}

//泛型函数transform，
//在输入迭代器begin和end表示的序列的元素上调用函数f，
//结果保存到输出迭代器d表示的目标地址中。
template <class In, class Out, class F> 
Out transform(In begin,In end, Out dest, F func){
//	std::cout << "transform...\n";
	//TODO
	while(begin!=end)
		*dest=func(*begin++);

	return dest;
}

}
#endif