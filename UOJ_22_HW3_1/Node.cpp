#include "Node.h"

int Node::num_createfunc = 0, Node::num_copyfunc = 0, Node::num_movefunc = 0;
int Node::num_copyassign = 0, Node::num_moveassign = 0, Node::num_delfunc = 0;

Node::Node(int v): val(v) {
	//std::cout<<"!"<<std::endl;
	num_createfunc++;
}
Node::~Node() {
	num_delfunc++;
}
Node::Node(const Node &y): val(y.val) {
	num_copyfunc++;
}
Node::Node(Node &&y): val(y.val) {
	y.val = 0;
	num_movefunc++;
}
Node& Node::operator=(const Node &y) {
	val = y.val;
	num_copyassign++;
	return *this;
}
Node& Node::operator=(Node &&y) {
	val = y.val;
	y.val = 0;
	num_moveassign++;
	return *this;
}

void Node::outputResult(int ref_ans) {
	std::cout << Node::num_createfunc << " " << Node::num_copyfunc << " " << 
		Node::num_movefunc << " " << Node::num_copyassign << " " << 
		Node::num_moveassign << " " << Node::num_delfunc << std::endl;
	int tmp = (Node::num_createfunc+Node::num_copyfunc+Node::num_copyassign)*10+Node::num_movefunc+Node::num_moveassign;
	if (tmp <= ref_ans)
	{
		std::cout << "YES" << std::endl;
	}	
	else
	{
		std::cout << "NO" << std::endl;
	}
}

std::istream& operator>>(std::istream& in, Node& x){
	std::cin >> x.val;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Node& x){
	std::cout << x.val;
	return out;
}

