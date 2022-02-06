#include "ListQueue.h"
#include <iostream>

using namespace std;
using namespace data_structures;



bool Queue_Enqueue_Test1()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);

	
	if (list.Peek() == 1)
	{
		return true;
	}
	return false;

}
bool Queue_Enqueue_Test2()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(3);


	if (list.Peek() == 3)
	{
		return true;
	}
	return false;

}
bool Queue_EnqueueNegative_Test3()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(-3);


	if (list.Peek() == -3)
	{
		return true;
	}
	return false;

}

bool Queue_Dequeue_Test1()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(3);
	list.Enqueue(5);
	list.Dequeue();
	int temp = list.Front();


	if (temp == 3)
	{
		return true;
	}
	return false;

}
bool Queue_Dequeue_Test2()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(3);
	list.Enqueue(5);
	list.Enqueue(7);
	list.Enqueue(4);
	list.Enqueue(2);
	list.Dequeue();
	list.Dequeue();
	int temp = list.Front();


	if (temp == 5)
	{
		return true;
	}
	return false;

}

bool Queue_Front_Test1()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(3);
	list.Enqueue(5);
	int temp = list.Front();


	if (temp == 1)
	{
		return true;
	}
	return false;

}
bool Queue_Front_Test2()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(10);
	list.Enqueue(5);
	list.Enqueue(3);
	int temp = list.Front();


	if (temp == 10)
	{
		return true;
	}
	return false;

}
bool Queue_Peek_Test1()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(2);


	if (list.Peek() == 2)
	{
		return true;
	}
	return false;

}
bool Queue_Peek_Test2()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(3);


	if (list.Peek() == 3)
	{
		return true;
	}
	return false;

}

bool String_Test()
{
	auto list = ListQueue<string>();
	list.Enqueue("Strings");
	list.Enqueue("Are");
	list.Enqueue("Fun");


	if (list.Peek() == "Fun")
	{
		return true;
	}
	return false;

}

bool ClearTest()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Clear();


	if (list.Peek() == NULL);
	{
		return true;
	}
	return false;

}

bool ClearTest2()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(15);
	list.Enqueue(23);
	list.Enqueue(23);
	list.Enqueue(45);
	list.Dequeue();
	list.Dequeue();
	list.Clear();

	if (list.Peek() == NULL);
	{
		return true;
	}
	return false;

}
bool test_default_ctor()
{
	bool pass = true;
	int default_length = 0;
	ListQueue<int> val_len;
	if (val_len.Size() != default_length)
		pass = false;
	return pass;
}

bool test_copy_ctor()
{
	auto list = ListQueue<size_t>();
	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(3);
	list.Enqueue(4);
	list.Enqueue(5);
	// list has 5,4,3,2,1

	auto list2 = list;
	for (int i = 1; i < 6; i++)
	{
		if (list.Peek() != list2.Peek())
		{
			return false;
		}
		list.Dequeue();
		list2.Dequeue();
	}
	return true;
}


bool test_complex_copy_ctor()
{
	auto list = ListQueue<string>();
	list.Enqueue("I");
	list.Enqueue("Am");
	list.Enqueue("A");
	list.Enqueue("String");
	list.Enqueue("Queue");
	// list has 5,4,3,2,1

	auto list2 = list;
	for (int i = 1; i < 6; i++)
	{
		if (list.Peek() != list2.Peek())
		{
			return false;
		}
		list.Dequeue();
		list2.Dequeue();
	}
	return true;
}
int main()
{


	if (Queue_Enqueue_Test1())
	{
		cout << "PASSED Enqueue test1!" << endl;
	}
	else cout << "failed enqueue test1" << endl;
	if (Queue_Enqueue_Test2())
	{
		cout << "PASSED Enqueue test2!" << endl;
	}
	else cout << "failed enqueue test2" << endl;
	
	if (Queue_EnqueueNegative_Test3())
	{
		cout << "PASSED Enqueue test3!" << endl;
	}
	else cout << "failed enqueue test3" << endl;

	if (Queue_Dequeue_Test1())
	{
		cout << "PASSED Dequeue test1!" << endl;
	}
	else cout << "failed Dequeue test1" << endl;
	if (Queue_Dequeue_Test2())
	{
		cout << "PASSED Dequeue test2!" << endl;
	}
	else cout << "failed Dequeue test2" << endl;
	if (Queue_Front_Test1())
	{
		cout << "PASSED Front test1!" << endl;
	}
	else cout << "failed Front test1" << endl;
	if (Queue_Front_Test2())
	{
		cout << "PASSED Front test2!" << endl;
	}
	else cout << "failed Front test2" << endl;


	if (Queue_Peek_Test1())
	{
		cout << "PASSED Peek test1!" << endl;
	}
	else cout << "failed peek test1" << endl;

	if (ClearTest())
	{
		cout << "PASSED Clear test!" << endl;
	}
	else cout << "failed Clear test!" << endl;

	if (ClearTest2())
	{
		cout << "PASSED Clear test2!" << endl;
	}
	else cout << "failed Clear test2!" << endl;
	if (test_default_ctor())
	{
		cout << "PASSED default ctor test!" << endl;
	}
	else cout << "failed default ctor!" << endl;
	if (test_copy_ctor())
	{
		cout << "PASSED copy ctor test!" << endl;
	}
	else cout << "failed copy ctor!" << endl;
	if (test_complex_copy_ctor())
	{
		cout << "PASSED string copy ctor test!" << endl;
	}
	else cout << "failed string copy ctor!" << endl;
	if (String_Test())
	{
		cout << "PASSED string test!" << endl;
	}
	else cout << "failed string test!" << endl;

}

