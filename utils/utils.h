#ifndef utils_h__
#define utils_h__

/* simple test frame */

/* example :
 
   TEST(fun1)
   {
     printf("test fun1.");
   } 
*/
#define TEST(test_name) \
void test_fun_##test_name(); \
namespace self_test_frame_##test_name{ \
class self_simple_test_##test_name{ \
public: \
	self_simple_test_##test_name(){ \
			test_fun_##test_name(); \
		}\
	}self_test_class_inst_##test_name;\
} \
void test_fun_##test_name()


void printarray(int a[], int len);
#endif // utils_h__