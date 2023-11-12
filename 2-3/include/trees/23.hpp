#ifndef tt_HPP_
#define tt_HPP_

#include "trees/23Node.hpp"

namespace trees {

class tt {
private:
	ttNode* root;
	int treesize;
public:
	tt();
	void insert_rec(int val, ttNode* node);
	void insert(int val);
	ttNode* find_rec(int val, ttNode* node);
	ttNode* find(int val);
	void traverse_rec(ttNode* node, int level);
	void traverse();
	void showASC_rec(ttNode* node);
	void showASC();
	void updateSize_rec(ttNode* node);
	void updateSize();
	ttNode* k_element_rec(int k, ttNode* node);
	ttNode* k_element(int k);
	virtual ~tt();

	void splitNode(ttNode* parent, int index);
};

} /* namespace trees */

#endif /* tt_HPP_ */
