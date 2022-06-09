#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "set.hpp"
#include <fstream>
#include <sstream>
#include <ctime>

#define namespace	ft

int main()
{
	int start_c = clock();


	std::ofstream fileout ("myContainers.txt");
	fileout << "************** TESTING VECTOR **************\n" << std::endl;

	namespace::vector<int> vec1(5,100);
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	namespace::vector<int> vec2(arr, arr+10);

	fileout << "Printing content: \n";
	namespace::vector<int>::iterator it1;
	namespace::vector<int>::reverse_iterator rit1;
	fileout << "size : " << vec1.size() << std::endl;
	fileout << "max_size : " << vec1.max_size() << std::endl;

	for(it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1] : " << *it1 << std::endl;
	vec1.push_back(200);
	fileout << "[vec1] contents after push back : " << std::endl;
	for(namespace::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1]  : " << *it1 << std::endl;
	vec1.pop_back();
	fileout << "[vec1] contents after pop back : " << std::endl;
	for(namespace::vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); ++it1)
		fileout << "[vec1] : " << *it1 << std::endl;
	try
	{
		fileout << "Element at position 6: " << vec1.at(6) << std::endl;
		/* code */
	}
	catch(const std::out_of_range& e)
	{
		fileout << e.what() << std::endl;
	}

	fileout << std::endl;
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(rit1 = vec2.rbegin(); rit1 != vec2.rend(); ++rit1)
		fileout << "[vec2] : " << *rit1 << std::endl;

	fileout << "\n\nTESTING COPY CONSTRUCTOR\n" << std::endl;

	namespace::vector<int> vec3(vec2);
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;


	fileout << "\n\nTESTING ASSIGN\n" << std::endl;
	vec2.assign(20, 20);
	fileout << "Printing content: \n";
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "capacity : " << vec2.capacity() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;

	fileout << "\n\nTESTING ERASE\n" << std::endl;
	vec3.erase(++(++(++vec3.begin())), --(--(--vec3.end())));
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;

	fileout << "\n\nTESTING INSERT\n" << std::endl;
	vec3.insert(++(++(++vec3.begin())), vec2.begin(), vec2.begin()+4);
	fileout << "Printing content: \n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "capacity : " << vec3.capacity() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;
	vec3.insert(vec3.end(), 42);
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "capacity : " << vec3.capacity() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;
	int myInserts [] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vec3.insert(vec3.begin(), myInserts, myInserts+21);
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "capacity : " << vec3.capacity() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;
	int Inserts [] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
		vec3.insert(vec3.begin(), Inserts, Inserts+21);
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "capacity : " << vec3.capacity() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;

	fileout << "\n\nTESTING OPERATORS\n" << std::endl;
	fileout << "vec3 at(5) = " << vec3.at(5) << std::endl;
	fileout << "vec3 [9] = " << vec3[9] << std::endl;
	fileout << "vec3 front = " << vec3.front() << std::endl;
	fileout << "vec3 back = " << vec3.back() << std::endl;

	fileout << "\n\nTESTING SWAP\n" << std::endl;
	vec2.swap(vec3);
	fileout << "Printing content: \n";
	fileout << "size : " << vec2.size() << std::endl;
	fileout << "max_size : " << vec2.max_size() << std::endl;
	for(it1 = vec2.begin(); it1 != vec2.end(); ++it1)
		fileout << "[vec2] : " << *it1 << std::endl;
	fileout << "\n\n";
	fileout << "size : " << vec3.size() << std::endl;
	fileout << "capacity : " << vec3.capacity() << std::endl;
	fileout << "max_size : " << vec3.max_size() << std::endl;
	for(it1 = vec3.begin(); it1 != vec3.end(); ++it1)
		fileout << "[vec3] : " << *it1 << std::endl;

	fileout << "\n\nTESTING RESERVE and RESIZE\n" << std::endl;
	vec3.resize(30);
	fileout << "vec3 size after resize: " << vec3.size() << std::endl;
	vec3.reserve(100);
	fileout << "vec3 capacity after reserve: " << vec3.capacity() << std::endl;
	try
	{
		fileout << "Attempt to reserve space exceeding max size -> ERROR : " << " ";
		vec3.reserve(vec3.max_size() + 10000);
	}
	catch(const std::length_error& e)
	{
		fileout << e.what() << std::endl;
	}

	fileout << "\n\nTESTING GET_ALLOCATOR\n" << std::endl;
	namespace::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++)
		myvector.get_allocator().construct(&p[i],i);
	fileout << "[myvector] - The allocated array contains : " << std::endl;
	for (i=0; i<5; i++) //std::cout << ' ' << p[i];
		fileout << "[myvector] : " << p[i] << std::endl;

	// destroy and deallocate:
	for (i=0; i<5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);	
	fileout << "[myvector] - The allocated array was destroyed and deallocated." << std::endl;


	fileout << "\n\n************** TESTING STACK **************\n" << std::endl;
	namespace::stack<int> mystack;
	for (int i=10; i<15; ++i)
		mystack.push(i);
	fileout << "Pushed elements : " << i << std::endl;
	fileout << "[mystack] size : " << mystack.size() << std::endl;
	fileout << "Popping out elements..." << std::endl;
	while (!mystack.empty())
	{
		fileout << "[mystack] : " <<  mystack.top() << std::endl;
		mystack.pop();
	}

	fileout << "\n\n************** TESTING MAP **************\n" << std::endl;
	namespace::map<int, std::string> map1;
	map1.insert(namespace::pair<int, std::string>(3, "c"));
	map1.insert(namespace::pair<int, std::string>(1, "a"));
	map1.insert(namespace::pair<int, std::string>(2, "b"));
	map1.insert(namespace::pair<int, std::string>(4, "d"));
	map1.insert(namespace::pair<int, std::string>(5, "e"));
	map1.insert(namespace::pair<int, std::string>(6, "f"));
	map1.insert(namespace::pair<int, std::string>(7, "g"));
	fileout << "Printing content: \n";
	fileout << "size : " << map1.size() << std::endl;
	fileout << "max_size : " << map1.max_size() << std::endl;
	for(namespace::map<int, std::string>::iterator it1 = map1.begin(); it1 != map1.end(); ++it1)
		fileout << "[map1] key = " << it1->first << "  value = " << it1->second << std::endl;

	fileout << "\n\n TESTING OPERATOR[] \n" << std::endl;
	map1[6] = "changed";
	map1[2] = "changed";
	map1[10] = "added with operator[]";
	for(namespace::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
		fileout << "[map1] key = " << it2->first << "  value = " << it2->second << std::endl;

	fileout << "\n\n TESTING REVERSE ITERATOR \n" << std::endl;
	namespace::map<char,int> mymap1;

	mymap1['x'] = 100;
	mymap1['y'] = 200;
	mymap1['z'] = 300;

	namespace::map<char,int>::reverse_iterator rit;
	for (rit=mymap1.rbegin(); rit!=mymap1.rend(); ++rit)
		fileout << "[map1] key = " << rit->first << "  value = " << rit->second << std::endl;


	fileout << "\n\n TESTING COPY CONSTRUCTOR \n" << std::endl;
	namespace::map<int, std::string> map2(map1);
	fileout << "Printing content: \n";
	fileout << "size : " << map2.size() << std::endl;
	fileout << "max_size : " << map2.max_size() << std::endl;
	for(namespace::map<int, std::string>::iterator it3 = map2.begin(); it3 != map2.end(); ++it3)
		fileout << "[map2] key = " << it3->first << "  value = " << it3->second << std::endl;

	fileout << "\n\n TESTING EQUAL RANGE \n" << std::endl;
	namespace::map<char,int> mymap;
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	namespace::pair<namespace::map<char,int>::iterator,namespace::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	fileout << "lower bound points to: ";
	fileout << ret.first->first << " => " << ret.first->second << std::endl;

	fileout << "upper bound points to: ";
	fileout << ret.second->first << " => " << ret.second->second << std::endl;

	fileout << "\n\n TESTING LOWER/UPPER BOUND \n" << std::endl;
	namespace::map<char,int> mymap4;
	namespace::map<char,int>::iterator itlow,itup;

	mymap4['a']=20;
	mymap4['b']=40;
	mymap4['c']=60;
	mymap4['d']=80;
	mymap4['e']=100;

	itlow=mymap4.lower_bound ('b');  // itlow points to b
	itup=mymap4.upper_bound ('d');   // itup points to e (not d!)

	mymap4.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (namespace::map<char,int>::iterator it=mymap4.begin(); it!=mymap4.end(); ++it)
	fileout << it->first << " => " << it->second << std::endl;

	fileout << "\n\n TESTING KEY_COMP \n" << std::endl;
	namespace::map<char,int> mymap5;

	namespace::map<char,int>::key_compare mycomp = mymap5.key_comp();

	mymap5['a']=100;
	mymap5['b']=200;
	mymap5['c']=300;

	fileout << "mymap contains:\n";

	char highest = mymap5.rbegin()->first;     // key value of last element

	namespace::map<char,int>::iterator it = mymap5.begin();
	do {
	fileout << it->first << " => " << it->second << std::endl;
	} while ( mycomp((*it++).first, highest) );
	fileout << "\n\n TESTING VALUE_COMP\n" << std::endl;
	namespace::map<char,int> mymap6;

	mymap6['x']=1001;
	mymap6['y']=2002;
	mymap6['z']=3003;

	fileout << "mymap contains:\n";

	namespace::pair<char,int> highest1 = *mymap6.rbegin();          // last element

	namespace::map<char,int>::iterator itt = mymap6.begin();
	do {
	fileout << itt->first << " => " << itt->second << '\n';
	} while ( mymap6.value_comp()(*itt++, highest1) );

	fileout << "\n\n TESTING GET_ALLOCATOR \n" << std::endl;
	int psize;
	namespace::map<char,int> mymap7;
	namespace::pair<const char,int>* p1;

	// allocate an array of 5 elements using mymap's allocator:
	p1=mymap7.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(namespace::map<char,int>::value_type)*5;

	fileout << "The allocated array has a size of " << psize << " bytes." << std::endl;

	mymap7.get_allocator().deallocate(p1,5);
	

	fileout << "\n\n TESTING ERASE \n" << std::endl;
	map1.erase(map1.begin(), ++(++(map1.begin())));
	fileout << "Printing content: \n";
	fileout << "size : " << map1.size() << std::endl;
	fileout << "max_size : " << map1.max_size() << std::endl;
	for(namespace::map<int, std::string>::iterator it4 = map1.begin(); it4 != map1.end(); ++it4)
		fileout << "[map1] key = " << it4->first << "  value = " << it4->second << std::endl;

	fileout << "\n\n TESTING COUNT\n" << std::endl;
	namespace::map<char,int> mymap9;
	char c;

	mymap9 ['a']=101;
	mymap9 ['c']=202;
	mymap9 ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		fileout << c;
		if (mymap9.count(c)>0)
			fileout << " is an element of mymap." << std::endl;
		else 
			fileout << " is not an element of mymap" << std::endl;
	}

	fileout << "\n\n TESTING SWAP\n" << std::endl;

	namespace::map<int, std::string> map3(map2);

	map3.find(5)->second = "changed with find()";
	map3.lower_bound(9)->second = "changed with lower()";
	map3.swap(map2);
	fileout << "Printing content: \n";
	for(namespace::map<int, std::string>::iterator it5 = map2.begin(); it5!= map2.end(); ++it5)
		fileout << "[map2] key = " << it5->first << "  value = " << it5->second << std::endl;
	fileout << std::endl;
	for(namespace::map<int, std::string>::iterator it6 = map3.begin(); it6 != map3.end(); ++it6)
		fileout << "[map3] key = " << it6->first << "  value = " << it6->second << std::endl;


	fileout << "\n\n************** TESTING SET **************\n" << std::endl;
	namespace::set<int> set1;
	set1.insert(100);
	set1.insert(300);
	set1.insert(200);
	set1.insert(400);
	set1.insert(500);
	set1.insert(600);
	set1.insert(7);
	fileout << "Printing content: \n";
	fileout << "size : " << set1.size() << std::endl;
	fileout << "max_size : " << set1.max_size() << std::endl;
	for(namespace::set<int>::iterator ite12 = set1.begin(); ite12 != set1.end(); ++ite12)
		fileout << "[set1] = " << *ite12 << std::endl;

	fileout << "\n\n TESTING SET REVERSE ITERATOR\n" << std::endl;
	for (namespace::set<int>::reverse_iterator rit = set1.rbegin(); rit != set1.rend(); ++rit)
		fileout << "[set1] = " << *rit << std::endl;

	fileout << "\n\n TESTING COPY CONSTRUCTOR \n" << std::endl;
	namespace::set<int> setTest(set1);
	for(namespace::set<int>::iterator ite = setTest.begin(); ite != setTest.end(); ++ite)
		fileout << "[setTest] = " << *ite << std::endl;
	
	namespace::set<int> set2(set1);
	fileout << "Printing content: \n";
	fileout << "size : " << set2.size() << std::endl;
	fileout << "max_size : " << set2.max_size() << std::endl;
	for(namespace::set<int>::iterator ite2 = set2.begin(); ite2 != set2.end(); ++ite2)
		fileout << "[set2] = " << *ite2 << std::endl;

	fileout << "\n\n TESTING EQUAL RANGE \n" << std::endl;
	namespace::set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	namespace::pair<namespace::set<int>::const_iterator,namespace::set<int>::const_iterator> ret1;
	ret1 = myset.equal_range(30);

	fileout << "the lower bound points to: " << *ret1.first << std::endl;
	fileout << "the upper bound points to: " << *ret1.second << std::endl;

	fileout << "\n\n TESTING FIND \n" << std::endl;
	namespace::set<int> myset1;
 	namespace::set<int>::iterator itt1;

  // set some initial values:
	for (int i=1; i<=5; i++) myset1.insert(i*10);    // set: 10 20 30 40 50

	itt1=myset1.find(20);
	myset1.erase (itt1);
	myset1.erase (myset1.find(40));

	fileout << "myset contains:" << std::endl;
	for (itt1=myset1.begin(); itt1!=myset1.end(); ++itt1)
		fileout << ' ' << *itt1 << std::endl;

	fileout << "\n\n TESTING ERASE \n" << std::endl;
	set1.erase(set1.begin(), ++(++(set1.begin())));
	fileout << "Printing content: \n";
	fileout << "size : " << set1.size() << std::endl;
	fileout << "max_size : " << set1.max_size() << std::endl;
	for(namespace::set<int>::iterator ite3 = set1.begin(); ite3 != set1.end(); ++ite3)
		fileout << "[set1] = " << *ite3 << std::endl;

	fileout << "\n\n TESTING GET_ALLOCATOR\n" << std::endl;
	namespace::set<int> myset2;
	int * p2;
	unsigned int ii;

	// allocate an array of 5 elements using myset's allocator:
	p2=myset2.get_allocator().allocate(5);

	// assign some values to array
	for (ii=0; ii<5; ii++) p2[ii]=(ii+1)*10;

	fileout << "The allocated array contains:" << std::endl;
	for (ii=0; ii<5; ii++)
		fileout << ' ' << p2[ii] << std::endl;

	myset2.get_allocator().deallocate(p2,5);

	fileout << "\n\n TESTING KEY_COMP\n" << std::endl;
	namespace::set<int> myset3;
	int highest3;

	namespace::set<int>::key_compare mycomp1 = myset3.key_comp();

	for (int i=0; i<=5; i++) myset3.insert(i);

	fileout << "myset contains:"<< std::endl;

	highest3=*myset3.rbegin();
	namespace::set<int>::iterator it3=myset3.begin();
	do {
		fileout << ' ' << *it3 << std::endl;
	} while ( mycomp1(*(++it3),highest3) );

	fileout << "\n\n TESTING LOWER/UPPER BOUND\n" << std::endl;
	namespace::set<int> myset4;
	namespace::set<int>::iterator itlow1,itup1;

	for (int i=1; i<10; i++) myset4.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow1=myset4.lower_bound (30);                //       ^
	itup1=myset4.upper_bound (60);                 //                   ^

	myset4.erase(itlow1,itup1);                     // 10 20 70 80 90

	fileout << "myset contains:" << std::endl;
	for (namespace::set<int>::iterator itt4=myset4.begin(); itt4!=myset4.end(); ++itt4)
		fileout << ' ' << *itt4 << std::endl;

	fileout << "\n\n TESTING VALUE_COMP\n" << std::endl;
	namespace::set<int> myset5;

	namespace::set<int>::value_compare mycomp2 = myset5.value_comp();

	for (int i=0; i<=5; i++) myset5.insert(i);

	fileout << "myset contains:" << std::endl;

	int highest5=*myset5.rbegin();
	namespace::set<int>::iterator itt5=myset5.begin();
	do {
		fileout << ' ' << *itt5 << std::endl;
	} while ( mycomp2(*(++itt5),highest5) );

	fileout << "\n\n TESTING OPERATOR=\n" << std::endl;
	int myints5[]={ 12,82,37,64,15 };
	namespace::set<int> first (myints5,myints5+5);   // set with 5 ints
	namespace::set<int> second;                    // empty set

	second = first;                          // now second contains the 5 ints
	first = namespace::set<int>();                 // and first is empty

	fileout << "Size of first: " << int (first.size()) << std::endl;
	fileout << "Size of second: " << int (second.size()) << std::endl;

	fileout << "\n\n TESTING COUNT\n" << std::endl;
	namespace::set<int> myset6;

	// set some initial values:
	for (int i=1; i<5; ++i) myset6.insert(i*3);    // set: 3 6 9 12

	for (int i=0; i<10; ++i)
	{
		fileout << i;
		if (myset6.count(i)!=0)
			fileout << " is an element of myset." << std::endl;
		else
			fileout << " is not an element of myset." << std::endl;
	}

	fileout << "\n\n TESTING SWAP\n" << std::endl;
	namespace::set<int> set3;
	set3.insert(1);
	set3.insert(2);
	set3.insert(3);
	set3.insert(4);
	set3.insert(5);
	set3.insert(6);
	set3.insert(7);
	set3.swap(set2);

	fileout << "Printing content: \n";
	fileout << "size : " << set2.size() << std::endl;
	fileout << "max_size : " << set2.max_size() << std::endl;
	for(namespace::set<int>::iterator ite4 = set2.begin(); ite4 != set2.end(); ++ite4)
		fileout << "[set2] = " << *ite4 << std::endl;
	fileout << std::endl;
	for(namespace::set<int>::iterator ite5 = set3.begin(); ite5 != set3.end(); ++ite5)
		fileout << "[set3] = " << *ite5 << std::endl;

	int stop_c = clock();
	fileout << std::endl;
	fileout << "MY containers execution in microseconds : " <<(stop_c-start_c)/double(CLOCKS_PER_SEC)*1000000 << std::endl; // microseconds

	//system("leaks containers");
	return (0);

}
