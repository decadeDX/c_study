#include <stdio.h>

int main() {
/* 
这个代码中&a的类型实际上是const int*，强转成int*类型，但在c和cpp文件中的修改方式不一样
出现这个情况的原因是编译器进行了寄存器优化的操作，在编译器运行过程中，经常会将一些变量认定为可以放
在寄存器中的值，以此来加快变量的读取速度，其中const经常会被优化。
*p表示的内存中的空间，a被寄存器优化了，所以*p是从内存中获取，a是从寄存器中获取
可以通过使用volatile 来阻止寄存器优化

*/
	volatile const int a = 10;
	//&a类型是const int*，需要强转
	int* p = (int*)&a;
	*p = 8;
	printf("%d\t%d", *p, a);
}