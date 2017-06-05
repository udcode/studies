#ifndef __ITERATORS_H
#define __ITERATORS_H
template <typename T, typename R>
class ForwardIterator {
protected:
	T* p;
public:
	using ValueType = R;
	using Pointer = T*;
	using Reference = R&;
	ForwardIterator(Pointer p) : p(p) {}
	virtual void advance() = 0;
	Reference operator*() const { return *p; }
	bool operator==(const ForwardIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const ForwardIterator& rhs) const { return p != rhs.p; }
	ForwardIterator& operator++() { advance(); return *this; }
};
template<typename T,typename R>
class BidirectionalIterator :public ForwardIterator<T,R> {
	T* p;
public:
	using ValueType = R;
	using Pointer = T*;
	using Reference = R&;
	BidirectionalIterator(Pointer p):ForwardIterator(p) {
		virtual void goBack() = 0;
		BidirectionalIterator& operator--() { goBack(); return *this; }
	}
};
#endif // __ITERATORS_H
