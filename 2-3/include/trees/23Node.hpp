#ifndef NODEtt_HPP_
#define NODEtt_HPP_

namespace trees {

class ttNode {
private:
	ttNode* ptrLeft;
	int data1;
	ttNode* ptrRight;
	int size;
	ttNode* ptrMiddle;
	int data2;
	int level;
public:
	ttNode();
	ttNode(int val);
	void setLeft(ttNode* node);
	void setRight(ttNode* node);
	void setData(int val);
	void setSize(int s);
	ttNode* getLeft();
	ttNode* getRight();
	int getData();
	int getSize();
	virtual ~ttNode();

	void setMiddle(ttNode* node);
    void setData2(int val);
    ttNode* getMiddle();
    int getData2();
};

} /* namespace trees */

#endif /* NODEtt_H_ */
