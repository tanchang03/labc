extern int shared22;
extern void swap(int*,int*);
int main(){
    int a = 100;
    swap(&a,&shared22);
}