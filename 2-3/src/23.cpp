#include "trees/23.hpp"
#include <iostream>
#include <queue>

namespace trees {

tt::tt():root(nullptr) {
	// TODO Auto-generated constructor stub
}

int isLeaf(ttNode* node){
	if(node->getLeft()== nullptr){
		if(node->getMiddle()== nullptr){
			if(node->getRight()== nullptr){
				return 1;
			}
		}
	}
	return 0;
}

void tt::insert_rec(int val, ttNode* node){
	if (node->getData2() == -1) {
        if (val < node->getData()) {
            //LEFT
            if (node->getLeft() == nullptr) {
                node->setLeft(new ttNode(val));
				//std::cout<<val << " inserted on left" << std::endl;
            } else {
                insert_rec(val, node->getLeft());
            }
        } else{
            //RIGHT
            if (node->getRight() == nullptr) {
                node->setRight(new ttNode(val));
				//std::cout<<val << " inserted on right" << std::endl;
            } else {
                insert_rec(val, node->getRight());
            }
        }
	} else { // If the node has two data elements
        if (val < node->getData()) {
            //LEFT
            if (node->getLeft() == nullptr) {
                node->setLeft(new ttNode(val));
            } else {
                insert_rec(val, node->getLeft());
            }
        } else if (val > node->getData2()) {
            //RIGHT
            if (node->getRight() == nullptr) {
                node->setRight(new ttNode(val));
            } else {
                insert_rec(val, node->getRight());
            }
        } else {
            //MIDDLE
            if (node->getMiddle() == nullptr) {
                node->setMiddle(new ttNode(val));
            } else {
                insert_rec(val, node->getMiddle());
            }
        }
	}
}

void tt::insert(int val){
	if (root == nullptr){
		root = new ttNode(val);
	}
	else{
		insert_rec(val, root);
	}
}

ttNode* tt::find_rec(int val, ttNode* node){
	ttNode* ans = nullptr;

	if (node->getData() == val){
		ans = node;
	} else if (node->getData2() == val){
		ans = node;
	}

	else{
		if (val < node->getData()){
			ans = find_rec(val, node->getLeft());
		}
		else if (val > node->getData() && val < node->getData2()){
			ans = find_rec(val, node->getMiddle());
		}
		else{
			ans = find_rec(val, node->getRight());
		}
	}

	return ans;
}

ttNode* tt::find(int val){
	ttNode* ans = nullptr;
	ans = find_rec(val, root);
	return ans;
}

void tt::traverse_rec(ttNode* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout << node->getData() << " | s = " << node->getSize() << std::endl;
		traverse_rec(node->getLeft(), level + 1);
		traverse_rec(node->getRight(), level + 1);
	}
}

void tt::traverse(){
    if (root == nullptr) {
        return;
    }

    std::queue<ttNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            ttNode* current = q.front();
            q.pop();

            // Print the data of the current node
            std::cout << std::string(i * 2, '-') << current->getData();
            if (current->getData2() != -1) {
                std::cout << " " << current->getData2();
            }
            std::cout << " | s = " << current->getSize() << std::endl;

            // Enqueue the children of the current node
            if (current->getLeft() != nullptr) {
                q.push(current->getLeft());
            }
            if (current->getMiddle() != nullptr) {
                q.push(current->getMiddle());
            }
            if (current->getRight() != nullptr) {
                q.push(current->getRight());
            }
        }
    }
}

/*extras*/
void tt::showASC_rec(ttNode* node){
	if (node != nullptr){
		showASC_rec(node->getLeft());
		std::cout << node->getData() << " " << std::flush;
		showASC_rec(node->getRight());
	}
}
void tt::showASC(){
	showASC_rec(root);
	std::cout << std::endl;
}

void tt::updateSize_rec(ttNode* node){
	if (node != nullptr){
		updateSize_rec(node->getLeft());
		updateSize_rec(node->getRight());
		int lSize = 0;
		int rSize = 0;
		if (node->getLeft() != nullptr){
			lSize = node->getLeft()->getSize();
		}
		if (node->getRight() != nullptr){
			rSize = node->getRight()->getSize();
		}
		node->setSize(lSize + rSize + 1);
	}
}

void tt::updateSize(){
	updateSize_rec(root);
}


ttNode* tt::k_element_rec(int k, ttNode* node){
	ttNode* ans = nullptr;
	if (node != nullptr){
		int lSize = 0;
		int posNode = 0;
		if (node->getLeft() != nullptr){
			lSize = node->getLeft()->getSize();
		}
		posNode = lSize + 1;

		if (k == posNode){
			ans = node;
		}
		else if  (k > posNode ){
			ans = k_element_rec( k - posNode, node->getRight());
		}
		else{
			ans = k_element_rec( k, node->getLeft());
		}
	}
	return ans;

}

ttNode* tt::k_element(int k){
	return k_element_rec(k, root);
}

tt::~tt() {
	delete root;
}

} /* namespace trees */
