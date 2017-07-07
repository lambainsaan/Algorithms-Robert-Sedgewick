/*
 * Root of i is N[N[N[...N[i]...]]]
 *
 * Connected - Check if p and q have the same root.
 * Union -  To merge components containing p and q,
 *          set the id of p's root to the id of q's root.
 *
 */

 UF::UF(int size){
   /*
     Initialization of the union data structure.
    */
   int i = 0;
   this->N = new int[size];
   this->height = new int[size];
   this->size = size;
   while(i < size ) {
     this->height [i] = 1;
     this->N [i] = i++;
   };
 };

void UF::union_UF(int p, int q){
  int rootp = this->root(p), rootq = this->root(q);
  if (this->height[rootp] > this->height[rootq]){
    this->N[rootq] = rootp;
  }
  else if(this->height[rootp] < this->height[rootq]){
    this->N[rootp] = rootq;
  }
  else{
    this->N[rootq] = rootp;
    this->height[rootp]++;
  };
};

bool UF::connected(int p, int q){
  return this->root(p) == this->root(q);
};
