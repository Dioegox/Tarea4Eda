#include "trees/23Node.hpp"

namespace trees {

ttNode::ttNode():
		ptrLeft(nullptr), data1(-1), data2(-1), ptrMiddle(nullptr), ptrRight(nullptr) {
	// TODO Auto-generated constructor stub
}

ttNode::ttNode(int val):
		ptrLeft(nullptr), data1(val), data2(-1), ptrMiddle(nullptr), ptrRight(nullptr){

}

void ttNode::setLeft(ttNode* node){
	ptrLeft = node;
}

void ttNode::setMiddle(ttNode* node){
	ptrMiddle = node;
}

void ttNode::setRight(ttNode* node){
	ptrRight = node;
}

void ttNode::setData(int val){
	data1 = val;
}
void ttNode::setData2(int val){
	data2 = val;
}

void ttNode::setSize(int s){
	size = s;
}

ttNode* ttNode::getLeft(){
	return ptrLeft;
}

ttNode* ttNode::getMiddle(){
	return ptrMiddle;
}

ttNode* ttNode::getRight(){
	return ptrRight;
}

int ttNode::getData(){
	return data1;
}
int ttNode::getData2(){
	return data2;
}

int ttNode::getSize(){
	return size;
}

ttNode::~ttNode() {
	if (ptrLeft != nullptr){
		delete ptrLeft;
	}
	if (ptrRight != nullptr){
		delete ptrRight;
	}
}

} /* namespace trees */
