#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	
	//(1)
	static int obj_num;
	int num;
	int _data;
			
public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif