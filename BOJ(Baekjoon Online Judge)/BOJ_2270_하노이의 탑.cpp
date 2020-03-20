#include <stdio.h>
#define MAXN 100001
#define MOD 1000000
   
int N,cnt;
int pow2[MAXN],p[MAXN];
void move(int disc, int dst){ 
    int src = p[disc];
    int aux = 1 + 2 + 3 - src - dst;
      
    if(disc<1) return;
    if(dst!=src){
        move(disc-1,aux);
        cnt = (cnt + pow2[disc-1]) % MOD;        
    }else  move(disc-1,dst);    
}
  
int main(){ 
    int i;
     
    //pow2 미리 계산 
    pow2[0]=1;
    for(i=1;i<MAXN;++i) pow2[i] = (pow2[i-1]<<1)%MOD;
  
    scanf("%d",&N);
      
    int a,b,c,x;
    scanf("%d %d %d",&a,&b,&c);     
    for(i=1;i<=a;++i) {  scanf("%d",&x); p[x]=1; }
    for(i=1;i<=b;++i) {  scanf("%d",&x); p[x]=2; }
    for(i=1;i<=c;++i) {  scanf("%d",&x); p[x]=3; }
              
    printf("%d\n",p[N]);
      
    cnt=0;      
    move(N-1,p[N]);
    printf("%d\n",cnt);
    return 0;
}