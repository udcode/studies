#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H
struct IndexException {
	unsigned int index;
	unsigned int maxIndex;
	IndexException(int ind, int max) : index(ind), maxIndex(max) {}
};

#endif // !__EXCEPTIONS_H

