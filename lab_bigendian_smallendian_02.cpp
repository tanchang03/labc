#include <iostream>
using namespace std;
int main()
{
 int x=0x00001234;//十进制为4660
 char tp=*((char*)&x);//取tp等于x的低地址部分

//char tp=(char)x;这样也是可以的。
 if (tp==0x00)//如果低地址部分取出的值是高字节的值，则为大端
 {
  cout<<tp<<"大端"<<endl;
 }
 else
 if (tp==0x34)//如果低地址部分取出的值是低字节的值，则为小端
 {
  cout<<tp<<"小端"<<endl;//0x34即十进制52，所以输出tp值为4
 }//注：本人电脑小端
 return 0;
}

